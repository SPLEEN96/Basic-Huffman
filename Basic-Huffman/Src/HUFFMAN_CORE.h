#pragma once
#include <cstdint>
#include <iostream>
#include <vector>

typedef int64_t int64;
typedef int32_t int32;
typedef int16_t int16;

typedef uint64_t uint64;
typedef uint32_t uint32;
typedef uint16_t uint16;
typedef uint8_t uint8;

typedef std::pair<char, uint16> freq_pair;

#define DEBUG_MODE
#ifdef DEBUG_MODE
#define ASSERT(x, ...)                                                         \
  {                                                                            \
    if (!x) {                                                                  \
      cout << "Assertion Failed: " << __VA_ARGS__ << "\n";                     \
      *(int *)0 = 0;                                                           \
    }                                                                          \
  }
#else
#define ASSERT(x, ...)                                                         \
  {}
#endif

#define Kilobytes(x) ((x)*1024)
#define Megabytes(x) (Kilobytes(x) * 1024)
#define Gigabytes(x) (Megabytes(x) * 1024)
