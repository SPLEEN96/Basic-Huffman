#pragma once
#include "HUFFMAN_CORE.h"

#include <iostream>
#include <stdio.h>
#include <string>

std::string ReadFile(const char* filename, const char* read_mode) {
  FILE *file = nullptr;
  char c = '\0';
  std::string content = "";

  file = fopen(filename, read_mode);
  if (!file) {
    std::cout << "\nFailed to read from file.\n";
    return "";
  }

  while (fscanf(file, "%c", &c) == 1) {
    content += c;
  }

  fclose(file);
  return content;
}

void WriteFile(const char *filename, const char* data){
  FILE *file = nullptr;

  file = fopen(filename, "w");

  fprintf(file, "%s",data);

  fclose(file);
}

void WriteBit(FILE *fileptr, const char &c, uint8 &bit_buffer,
              uint8 &bit_count) {
  bit_count++;

  /* Convert the Char into an Integer */
  uint8 charbit = c - '0';
  /* Concatenate the charbit into the bit_buffer */
  /* Ex: 0010 | 0001 = 0011 */
  bit_buffer |= charbit;

  /* When the Bit Buffer (1Byte) is full */
  /* Write to file */
  if (bit_count >= 8) {
    fwrite(&bit_buffer, sizeof(bit_buffer), 1, fileptr);
    bit_buffer = 0U;
    bit_count = 0;
  }

  /* Shift the Bits to one position to the Left */
  /* Ex: 0011 << 1 = 0110 */
  bit_buffer <<= 1;
}
