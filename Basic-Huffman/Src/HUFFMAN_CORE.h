#pragma once

#include <stdint.h>

typedef uint16_t uint16;
typedef uint8_t uint8;

#define Kilobytes(x) ((x)*1024)
#define Megabytes(x) (Kilobytes(x) * 1024)
#define Gigabytes(x) (Megabytes(x) * 1024)
