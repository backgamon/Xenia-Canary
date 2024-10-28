/**
 ******************************************************************************
 * Xenia : Xbox 360 Emulator Research Project                                 *
 ******************************************************************************
 * Copyright 2024 Xenia Canary. All rights reserved.                          *
 * Released under the BSD license - see LICENSE in the root for more details. *
 ******************************************************************************
 */

#include "xenia/apu/audio_media_player.h"
#include "xenia/apu/audio_driver.h"
#include "xenia/apu/audio_system.h"
#include "xenia/apu/xma_context.h"
#include "xenia/base/logging.h"

#include <XAudio2.h>

extern "C" {
#if XE_COMPILER_MSVC
#pragma warning(push)
#pragma warning(disable : 4101 4244 5033)
#endif
#include "third_party/FFmpeg/libavcodec/avcodec.h"
#include "third_party/FFmpeg/libavformat/avformat.h"
#include "third_party/FFmpeg/libavformat/avio.h"
#if XE_COMPILER_MSVC
#pragma warning(pop)
#endif
}  // extern "C"

DEFINE_bool(enable_xmp, true, "Enables Music Player playback.", "APU");
DEFINE_int32(xmp_default_volume, 70,
             "Default music volume if game doesn't set it [0-100].", "APU");

namespace xe {
namespace apu {

int32_t InitializeAndOpenAvCodec(std::vector<uint8_t>* song_data,
                                 AVFormatContext*& format_context,
                                 AVCodecContext*& av_context) {
  AVIOContext* io_ctx =
      avio_alloc_context(song_data->data(), (int)song_data->size(), 0, nullptr,
                         nullptr, nullptr, nullptr);

  format_context = avformat_alloc_context();
  format_context->pb = io_ctx;

  int ret = avformat_open_input(&format_context, nullptr, nullptr, nullptr);
  if (ret < 0) {
    return ret;
  }
  // Processing data
  ret = avformat_find_stream_info(format_context, nullptr);
  if (ret < 0) {
    return ret;
  }
  AVStream* stream = format_context->streams[0];

  // find & open codec
  AVCodecParameters* codec = stream->codecpar;
  auto decoder = avcodec_find_decoder(codec->codec_id);
  av_context = avcodec_alloc_context3(decoder);

  // Fill codec context with codec parameters
  ret = avcodec_parameters_to_context(av_context, codec);
  if (ret < 0) {
    return ret;
  }

  ret = avcodec_open2(av_context, decoder, NULL);
  return ret;
}

void ConvertAudioFrame(AVFrame* frame, int channel_count,
                       std::vector<float>* framebuffer) {
  framebuffer->reserve(frame->nb_samples * channel_count);

  if (frame->format == AV_SAMPLE_FMT_FLTP) {
    for (int sample = 0; sample < frame->nb_samples; sample++) {
      for (int ch = 0; ch < channel_count; ch++) {
        float sampleValue = reinterpret_cast<float*>(frame->data[ch])[sample];
        framebuffer->push_back(sampleValue);
      }
    }
    return;
  }

  if (frame->format == AV_SAMPLE_FMT_FLT) {
    float* frameData = reinterpret_cast<float*>(frame->data[0]);
    framebuffer->insert(framebuffer->end(), frameData,
                        frameData + frame->nb_samples * channel_count);
    return;
  }
  return;
}

void ProcessAudioData(AudioMediaPlayer* player, AudioDriver* driver,
                      AVFormatContext* s, AVCodecContext* avctx,
                      int streamIndex) {
  AVPacket* packet = av_packet_alloc();
  AVFrame* frame = av_frame_alloc();
  std::vector<float> frameBuffer;

  while (av_read_frame(s, packet) >= 0 &&
         player->GetState() != XmpApp::State::kIdle) {
    if (packet->stream_index == streamIndex) {
      int ret = avcodec_send_packet(avctx, packet);
      if (ret < 0) {
        XELOGE("Error sending packet for decoding: {:X}", ret);
        break;
      }

      while (ret >= 0 && player->GetState() != XmpApp::State::kIdle) {
        ret = avcodec_receive_frame(avctx, frame);
        if (ret == AVERROR(EAGAIN) || ret == AVERROR_EOF) break;
        if (ret < 0) {
          XELOGW("Error during decoding: {:X}", ret);
          break;
        }

        ConvertAudioFrame(frame, avctx->channels, &frameBuffer);
        player->ProcessAudioBuffer(&frameBuffer);
      }
    }
    av_packet_unref(packet);
  }

  if (!frameBuffer.empty()) {
    while (frameBuffer.size() < xe::apu::AudioDriver::kFrameSamplesMax) {
      frameBuffer.push_back(0.0f);
    }

    driver->SubmitFrame(frameBuffer.data());
  }

  av_frame_free(&frame);
  av_packet_free(&packet);
}

AudioMediaPlayer::AudioMediaPlayer(apu::AudioSystem* audio_system,
                                   kernel::KernelState* kernel_state)
    : audio_system_(audio_system),
      kernel_state_(kernel_state),
      active_playlist_(nullptr),
      active_song_(nullptr) {};

AudioMediaPlayer::~AudioMediaPlayer() { Stop(); };

void AudioMediaPlayer::WorkerThreadMain() {
  while (worker_running_) {
    if (state_ != XmpApp::State::kPlaying) {
      resume_fence_.Wait();
    }

    if (!active_playlist_) {
      xe::threading::Sleep(std::chrono::milliseconds(500));
      continue;
    }

    if (active_song_) {
      Play();
    }
  }
}

void AudioMediaPlayer::Setup() {
  if (!cvars::enable_xmp) {
    return;
  }

  sample_buffer_ptr_ = kernel_state_->memory()->SystemHeapAlloc(
      xe::apu::AudioDriver::kFrameSamplesMax);

  worker_running_ = true;

  worker_thread_ =
      kernel::object_ref<kernel::XHostThread>(new kernel::XHostThread(
          kernel_state_, 128 * 1024, 0,
          [this]() {
            WorkerThreadMain();
            return 0;
          },
          kernel_state_->GetSystemProcess()));

  worker_thread_->set_name("Audio Media Player");
  worker_thread_->set_can_debugger_suspend(true);
  worker_thread_->Create();
};

X_STATUS AudioMediaPlayer::Play(uint32_t playlist_handle,
                                uint32_t song_handle) {
  auto playlist_itr = playlists_.find(playlist_handle);
  if (playlist_itr == playlists_.cend()) {
    return X_STATUS_UNSUCCESSFUL;
  }

  active_playlist_ = playlist_itr->second.get();

  if (!song_handle) {
    active_song_ = active_playlist_->songs.begin()->second.get();
    resume_fence_.Signal();
    return X_STATUS_SUCCESS;
  }

  auto song_itr = active_playlist_->songs.find(song_handle);
  if (song_itr == active_playlist_->songs.cend()) {
    return X_STATUS_UNSUCCESSFUL;
  }

  active_song_ = song_itr->second.get();
  resume_fence_.Signal();
  return X_STATUS_SUCCESS;
}

void AudioMediaPlayer::Play() {
  if (state_ == XmpApp::State::kPlaying) {
    Stop();
  }

  std::vector<uint8_t>* song_buffer = new std::vector<uint8_t>();

  if (!LoadSongToMemory(song_buffer)) {
    return;
  }

  AVFormatContext* formatContext = nullptr;
  AVCodecContext* codecContext = nullptr;
  InitializeAndOpenAvCodec(song_buffer, formatContext, codecContext);

  if (!SetupDriver(codecContext->sample_rate, codecContext->channels)) {
    XELOGE("Driver initialization failed!");
    avcodec_free_context(&codecContext);
    avformat_close_input(&formatContext);
    av_freep(&formatContext->pb->buffer);
    avio_context_free(&formatContext->pb);
    return;
  }

  state_ = XmpApp::State::kPlaying;
  song_index_ = active_song_->handle;
  OnStateChanged();

  if (volume_ == 0.0f) {
    volume_ = cvars::xmp_default_volume / 100.0f;
    SetVolume(volume_);
  }

  ProcessAudioData(this, driver_.get(), formatContext, codecContext, 0);

  DeleteDriver();
};

void AudioMediaPlayer::Pause() {
  if (driver_) {
    driver_->Pause();
  }
  state_ = XmpApp::State::kPaused;
  OnStateChanged();
};

void AudioMediaPlayer::Stop() {
  if (driver_ && state_ == XmpApp::State::kPaused) {
    driver_->Resume();
  }

  state_ = XmpApp::State::kIdle;
  active_song_ = nullptr;
  OnStateChanged();
};

void AudioMediaPlayer::Continue() {
  state_ = XmpApp::State::kPlaying;
  resume_fence_.Signal();
  if (driver_) {
    driver_->Resume();
  }
  OnStateChanged();
}

X_STATUS AudioMediaPlayer::Next() {
  if (!active_playlist_) {
    return X_STATUS_UNSUCCESSFUL;
  }

  if (active_song_) {
    Stop();
  }

  auto itr = active_playlist_->songs.find((uint32_t)song_index_);
  itr++;

  if (itr != active_playlist_->songs.cend()) {
    active_song_ = itr->second.get();
    resume_fence_.Signal();
    return X_STATUS_SUCCESS;
  }

  active_song_ = active_playlist_->songs.begin()->second.get();
  resume_fence_.Signal();
  return X_STATUS_SUCCESS;
}

X_STATUS AudioMediaPlayer::Previous() {
  if (!active_playlist_) {
    return X_STATUS_UNSUCCESSFUL;
  }

  if (active_song_) {
    Stop();
  }

  auto itr = active_playlist_->songs.find((uint32_t)song_index_);
  itr--;
  if (itr == active_playlist_->songs.cend()) {
    active_song_ = active_playlist_->songs.crbegin()->second.get();
    resume_fence_.Signal();
    return X_STATUS_SUCCESS;
  }

  active_song_ = itr->second.get();
  resume_fence_.Signal();
  return X_STATUS_SUCCESS;
}

bool AudioMediaPlayer::LoadSongToMemory(std::vector<uint8_t>* buffer) {
  if (!active_song_) {
    return false;
  }

  // Find file based on provided path?
  vfs::File* vfs_file;
  vfs::FileAction file_action;
  X_STATUS result = kernel_state_->file_system()->OpenFile(
      nullptr, xe::to_utf8(active_song_->file_path),
      vfs::FileDisposition::kOpen, vfs::FileAccess::kGenericRead, false, true,
      &vfs_file, &file_action);

  if (result) {
    return false;
  }

  buffer->resize(vfs_file->entry()->size());
  size_t bytes_read = 0;
  result = vfs_file->ReadSync(buffer->data(), vfs_file->entry()->size(), 0,
                              &bytes_read);

  return !result;
}

void AudioMediaPlayer::AddPlaylist(uint32_t handle,
                                   std::unique_ptr<XmpApp::Playlist> playlist) {
  if (playlists_.count(handle) != 0) {
    return;
  }

  if (playback_mode_ == XmpApp::PlaybackMode::kShuffle) {
    // auto rng = std::default_random_engine{};
    // std::shuffle(playlist->songs.begin(), playlist->songs.end(), rng);
  }

  playlists_.insert({handle, std::move(playlist)});
}

void AudioMediaPlayer::RemovePlaylist(uint32_t handle) {
  if (playlists_.count(handle) == 0) {
    return;
  }

  // TODO: Check if currently played song is from that playlist and stop
  // playback.

  playlists_.erase(handle);
}

X_STATUS AudioMediaPlayer::SetVolume(float volume) {
  if (!IsTitleInPlaybackControl()) {
    return X_STATUS_SUCCESS;
  }

  volume_ = std::min(volume, 1.0f);

  std::unique_lock<xe::xe_fast_mutex> guard(driver_mutex_);
  if (!driver_) {
    return X_STATUS_UNSUCCESSFUL;
  }

  driver_->SetVolume(volume_);
  return X_STATUS_SUCCESS;
}

void AudioMediaPlayer::SetCaptureCallback(uint32_t callback, uint32_t context,
                                          bool title_render) {
  callback_ = callback;
  callback_context_ = context;
  is_title_rendering_enabled_ = false;  // title_render;
}

void AudioMediaPlayer::OnStateChanged() {
  kernel_state_->BroadcastNotification(kNotificationXmpStateChanged,
                                       static_cast<uint32_t>(state_));
}

void AudioMediaPlayer::ProcessAudioBuffer(std::vector<float>* buffer) {
  while (buffer->size() >= xe::apu::AudioDriver::kFrameSamplesMax) {
    xe::threading::Wait(driver_semaphore_.get(), true);

    if (state_ == XmpApp::State::kIdle) {
      buffer->clear();
      break;
    }

    if (callback_) {
      std::memcpy(kernel_state_->memory()->TranslateVirtual(sample_buffer_ptr_),
                  buffer->data(), xe::apu::AudioDriver::kFrameSamplesMax);

      uint64_t args[] = {sample_buffer_ptr_, callback_context_, true};
      audio_system_->processor()->Execute(worker_thread_->thread_state(),
                                          callback_, args, xe::countof(args));
    }

    if (is_title_rendering_enabled_) {
      driver_->SubmitFrame(
          std::array<float, xe::apu::AudioDriver::kFrameSamplesMax>().data());
    } else {
      driver_->SubmitFrame(buffer->data());
    }
    buffer->erase(buffer->begin(),
                  buffer->begin() + xe::apu::AudioDriver::kFrameSamplesMax);
  }
}

bool AudioMediaPlayer::SetupDriver(uint32_t sample_rate, uint32_t channels) {
  DeleteDriver();

  std::unique_lock<xe::xe_fast_mutex> guard(driver_mutex_);
  driver_semaphore_ = xe::threading::Semaphore::Create(
      AudioSystem::kMaximumQueuedFrames, AudioSystem::kMaximumQueuedFrames);

  if (!driver_semaphore_) {
    return false;
  }

  driver_ = std::unique_ptr<AudioDriver>(audio_system_->CreateDriver(
      driver_semaphore_.get(), sample_rate, channels, false));
  if (!driver_) {
    driver_semaphore_.release();
    return false;
  }

  if (!driver_->Initialize()) {
    driver_semaphore_.release();
    driver_->Shutdown();
    driver_.release();
    return false;
  }

  return true;
}

void AudioMediaPlayer::DeleteDriver() {
  std::unique_lock<xe::xe_fast_mutex> guard(driver_mutex_);
  if (driver_) {
    if (driver_semaphore_) {
      driver_semaphore_.release();
    }

    driver_->Shutdown();
    driver_.release();
  }
}

}  // namespace apu
}  // namespace xe