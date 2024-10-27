/**
 ******************************************************************************
 * Xenia : Xbox 360 Emulator Research Project                                 *
 ******************************************************************************
 * Copyright 2024 Xenia Canary. All rights reserved.                          *
 * Released under the BSD license - see LICENSE in the root for more details. *
 ******************************************************************************
 */

#ifndef XENIA_APU_AUDIO_MEDIA_PLAYER_H_
#define XENIA_APU_AUDIO_MEDIA_PLAYER_H_

#include "xenia/apu/audio_system.h"
#include "xenia/kernel/xam/apps/xmp_app.h"

namespace xe {
namespace apu {

using XmpApp = kernel::xam::apps::XmpApp;

class AudioMediaPlayer {
 public:
  AudioMediaPlayer(apu::AudioSystem* audio_system,
                   kernel::KernelState* kernel_state);
  ~AudioMediaPlayer();

  void Setup();

  X_STATUS Play(uint32_t playlist_handle, uint32_t song_handle);
  X_STATUS Next();
  X_STATUS Previous();

  void Stop();
  void Pause();
  void Continue();

  XmpApp::State GetState() const { return state_; }

  X_STATUS SetVolume(float volume);
  float GetVolume() const { return volume_; }

  void SetPlaybackMode(XmpApp::PlaybackMode playback_mode) {
    playback_mode_ = playback_mode;
  }
  XmpApp::PlaybackMode GetPlaybackMode() const { return playback_mode_; }

  void SetRepeatMode(XmpApp::RepeatMode repeat_mode) {
    repeat_mode_ = repeat_mode;
  }
  XmpApp::RepeatMode GetRepeatMode() { return repeat_mode_; }

  void SetPlaybackFlags(XmpApp::PlaybackFlags playback_flags) {
    playback_flags_ = playback_flags;
  }
  XmpApp::PlaybackFlags GetPlaybackFlags() const { return playback_flags_; }

  void SetPlaybackClient(XmpApp::PlaybackClient playback_client) {
    playback_client_ = playback_client;
  }

  XmpApp::PlaybackClient GetPlaybackClient() const { return playback_client_; }

  bool IsTitleInPlaybackControl() const {
    return playback_client_ == XmpApp::PlaybackClient::kTitle ||
           is_title_rendering_enabled_;
  }

  void SetCaptureCallback(uint32_t callback, uint32_t context,
                          bool title_render);

  void AddPlaylist(uint32_t handle, std::unique_ptr<XmpApp::Playlist> playlist);
  void RemovePlaylist(uint32_t handle);

  XmpApp::Song* GetCurrentSong() const { return active_song_; }

  void ProcessAudioBuffer(std::vector<float>* buffer);

 private:
  void OnStateChanged();

  void Play();
  void WorkerThreadMain();
  bool LoadSongToMemory(std::vector<uint8_t>* buffer);

  XmpApp::State state_ = XmpApp::State::kIdle;
  XmpApp::PlaybackClient playback_client_ = XmpApp::PlaybackClient::kSystem;
  XmpApp::PlaybackMode playback_mode_ = XmpApp::PlaybackMode::kInOrder;
  XmpApp::RepeatMode repeat_mode_ = XmpApp::RepeatMode::kPlaylist;
  XmpApp::PlaybackFlags playback_flags_ = XmpApp::PlaybackFlags::kDefault;
  float volume_ = 1.0f;

  std::unordered_map<uint32_t, std::unique_ptr<XmpApp::Playlist>> playlists_;
  XmpApp::Playlist* active_playlist_;
  XmpApp::Song* active_song_;

  size_t song_index_ = 0;

  uint32_t callback_ = 0;
  uint32_t callback_context_ = 0;
  uint32_t sample_buffer_ptr_ = 0;
  bool is_title_rendering_enabled_ = false;

  AudioSystem* audio_system_ = nullptr;
  kernel::KernelState* kernel_state_ = nullptr;

  xe::global_critical_region global_critical_region_;
  std::atomic<bool> worker_running_ = {false};
  kernel::object_ref<kernel::XHostThread> worker_thread_;
  xe::threading::Fence resume_fence_;  // Signaled when resume requested.

  // Driver part - This should be integrated into audio_system, but it isn't
  // really compatible with it.
  std::unique_ptr<AudioDriver> driver_ = nullptr;
  std::unique_ptr<xe::threading::Semaphore> driver_semaphore_ = {};
  xe::xe_fast_mutex driver_mutex_ = {};

  bool SetupDriver(uint32_t sample_rate, uint32_t channels);
  void DeleteDriver();
};

}  // namespace apu
}  // namespace xe

#endif
