/**
 ******************************************************************************
 * Xenia : Xbox 360 Emulator Research Project                                 *
 ******************************************************************************
 * Copyright 2020 Ben Vanik. All rights reserved.                             *
 * Released under the BSD license - see LICENSE in the root for more details. *
 ******************************************************************************
 */

#include "xenia/base/string_buffer.h"

#include <algorithm>
#include <cstdarg>

#include "xenia/base/assert.h"
#include "xenia/base/literals.h"
#include "xenia/base/math.h"

namespace xe {

using namespace xe::literals;

StringBuffer::StringBuffer(size_t initial_capacity) {
  buffer_capacity_ = std::max(initial_capacity, static_cast<size_t>(16_KiB));
  buffer_ = reinterpret_cast<char*>(std::malloc(buffer_capacity_));
  assert_not_null(buffer_);
  buffer_[0] = 0;
}

StringBuffer::~StringBuffer() {
  free(buffer_);
  buffer_ = nullptr;
}

void StringBuffer::Reset() {
  buffer_offset_ = 0;
  buffer_[0] = 0;
}

void StringBuffer::Reserve(size_t reservation_size) {
  if (buffer_capacity_ >= reservation_size) {
    return;
  }
  size_t new_capacity = reservation_size;
  auto new_buffer = std::realloc(buffer_, new_capacity);
  assert_not_null(new_buffer);
  buffer_ = reinterpret_cast<char*>(new_buffer);
  buffer_capacity_ = new_capacity;
}

void StringBuffer::Grow(size_t additional_length) {
  if (buffer_offset_ + additional_length <= buffer_capacity_) {
    return;
  }
  size_t new_capacity =
      std::max(xe::round_up(buffer_offset_ + additional_length, 16_KiB),
               buffer_capacity_ * 2);
  Reserve(new_capacity);
}

void StringBuffer::Append(char c) {
  AppendBytes(reinterpret_cast<const uint8_t*>(&c), 1);
}

void StringBuffer::Append(char c, size_t count) {
  Grow(count + 1);
  std::memset(buffer_ + buffer_offset_, c, count);
  buffer_offset_ += count;
  buffer_[buffer_offset_] = 0;
}

void StringBuffer::Append(const char* value) {
  AppendBytes(reinterpret_cast<const uint8_t*>(value), std::strlen(value));
}

void StringBuffer::Append(const std::string_view value) {
  AppendBytes(reinterpret_cast<const uint8_t*>(value.data()), value.size());
}

void StringBuffer::AppendVarargs(const char* format, va_list args) {
  int result = vsnprintf(nullptr, 0, format, args);
  if (result <= 0) {
    return;
  }
  auto length = static_cast<size_t>(result);
  Grow(length + 1);
  vsnprintf(buffer_ + buffer_offset_, buffer_capacity_, format, args);
  buffer_offset_ += length;
  buffer_[buffer_offset_] = 0;
}

void StringBuffer::AppendBytes(const uint8_t* buffer, size_t length) {
  Grow(length + 1);
  memcpy(buffer_ + buffer_offset_, buffer, length);
  buffer_offset_ += length;
  buffer_[buffer_offset_] = 0;
}

std::string StringBuffer::to_string() {
  return std::string(buffer_, buffer_offset_);
}

std::string_view StringBuffer::to_string_view() const {
  return std::string_view(buffer_, buffer_offset_);
}

std::vector<uint8_t> StringBuffer::to_bytes() const {
  std::vector<uint8_t> bytes(buffer_offset_);
  std::memcpy(bytes.data(), buffer_, buffer_offset_);
  return bytes;
}
#if XE_ARCH_AMD64 == 1
static __m128i ToHexUpper(__m128i value) {
  __m128i w = _mm_cvtepu8_epi16(value);

  __m128i msk =
      _mm_and_si128(_mm_or_si128(_mm_srli_epi16(w, 4), _mm_bslli_si128(w, 1)),
                    _mm_set1_epi16(0x0F0F));

  __m128i conv =
      _mm_shuffle_epi8(_mm_setr_epi8('0', '1', '2', '3', '4', '5', '6', '7',
                                     '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'),
                       msk);
  return conv;
}
#endif

void StringBuffer::AppendHexUInt64(uint64_t value) {
#if XE_ARCH_AMD64 == 1
  __m128i conv = ToHexUpper(_mm_cvtsi64_si128(static_cast<long long>(value)));

  AppendBytes(reinterpret_cast<const uint8_t*>(&conv), 16);
#else
  AppendFormat("{:016X}", value);
#endif
}

void StringBuffer::AppendHexUInt32(uint32_t value) {
#if XE_ARCH_AMD64 == 1
  __m128i conv = ToHexUpper(_mm_cvtsi32_si128(static_cast<int>(value)));

  uint64_t low = _mm_cvtsi128_si64(conv);

  AppendBytes(reinterpret_cast<const uint8_t*>(&low), 8);
#else
  AppendFormat("{:08X}", value);
#endif
}

void StringBuffer::AppendParenthesizedHexUInt32(uint32_t value) {
#if XE_ARCH_AMD64 == 1
  Grow(10);

  buffer_[buffer_offset_] = '(';
  *reinterpret_cast<long long*>(&buffer_[buffer_offset_ + 1]) =
      _mm_cvtsi128_si64(ToHexUpper(_mm_cvtsi32_si128(value)));
  buffer_[buffer_offset_ + 9] = ')';
  buffer_offset_ += 10;
  buffer_[buffer_offset_] = 0;
#else
  AppendFormat("({:08X})", value);
#endif
}


void StringBuffer::AppendParenthesizedHexUInt64(uint64_t value) {
#if XE_ARCH_AMD64 == 1
  Grow(18);

  buffer_[buffer_offset_] = '(';
  __m128i conv = ToHexUpper(_mm_cvtsi64_si128(static_cast<long long>(value)));
  _mm_storeu_si128(reinterpret_cast<__m128i*>(&buffer_[buffer_offset_ + 1]),
                   conv);

  buffer_[buffer_offset_ + 17] = ')';
  buffer_offset_ += 18;
  buffer_[buffer_offset_] = 0;
#else
  AppendFormat("({:016X})", value);
#endif
}
}  // namespace xe
