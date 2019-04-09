#pragma once
#include "HUFFMAN_CORE.h"

#include <fstream>
#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>

std::string ReadFile(const char* filename) {
  FILE *file = nullptr;
  char c = '\0';
  std::string content = "";

  file = fopen(filename, "r");
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

std::vector<char> ReadBit(const std::string& filename) {
  std::ifstream file(filename, std::ios::ate|std::ios::binary);
  size_t file_size = (size_t)file.tellg();
  std::vector<char> buffer(file_size);

  if (!file.is_open()) {
    std::cout << "Failed to read from Binary File.\n";
    return buffer;
  }

  file.seekg(0);
  file.read(buffer.data(), file_size);

  file.close();
  return buffer;
}

void WriteFile(const char *filename, const char* data){
  FILE *file = nullptr;

  file = fopen(filename, "w");

  fprintf(file, "%s",data);

  fclose(file);
}

void WriteBit(const char *filename, const std::string &encoded){
  uint8 bit_buffer = 0U;
  uint8 bit_count = 0;
  bool complete_byte = false;
  
  FILE *file = nullptr;
  file = fopen(filename, "wb");

  for (const char &c : encoded) {
    bit_count++;
    complete_byte = false;

    /* Convert the Char into an Integer */
    uint8 charbit = c - '0';
    /* Ex: 0010 | 0001 = 0011 */
    bit_buffer |= charbit;
    
    /* When the Bit Buffer (1Byte) is full */
    /* Write to file */
    if(bit_count>=8){
      fwrite(&bit_buffer, sizeof(bit_buffer), 1, file);
      bit_buffer = 0U;
      bit_count = 0;

      complete_byte = true;
    }

    /* Ex: 0011 << 1 = 0110 */
    bit_buffer <<= 1;
  }

  fclose(file);
}
