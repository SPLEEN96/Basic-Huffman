#pragma once
#include <cstdint>

typedef int64_t int64;
typedef int32_t int32;
typedef int16_t int16;

typedef uint64_t uint64;
typedef uint32_t uint32;
typedef uint16_t uint16;
typedef uint8_t  uint8;


#define ASSERT(x,...)					\
  {							\
    if(!x){						\
      cout<<"Assertion Failed: "<<__VA_ARGS__<<"\n";	\
      *(int*)0 = 0;					\
    }							\
  }


#define Kilobytes(x) ((x)*1024)
#define Megabytes(x) (Kilobytes(x) * 1024)
#define Gigabytes(x) (Megabytes(x) * 1024)