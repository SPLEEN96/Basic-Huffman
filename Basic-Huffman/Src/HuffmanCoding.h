#include "DataIO.h"
#include "HUFFMAN_CORE.h"
#include "Tree.h"

#include <bitset>

namespace Huffman {

void GenerateBytecode(Heap::Node *curr_node, char code[16],
                      std::map<char, std::string> &bytecodes, uint16 len) {
  code[len] = '\0';
  bytecodes[curr_node->character] = code;
}

void GenerateBytecodes(Heap::Node *root, std::map<char, std::string> &bytecodes,
                       uint16 len) {
  Tree::FindLeafNodes(root, bytecodes, len, &GenerateBytecode);
}

void EncodeStringToFile(const char *filename, const std::string &input,
                        std::map<char, std::string> &bytewords) {
  FILE *file = nullptr;
  file = fopen(filename, "wb");
  uint8 bit_buffer = 0U;
  uint8 bit_count = 0;

  /* Go through the content of the File to Encode. */
  for (const char &c : input) {
    /* Convert each Chars in its Byteword equivalent. */
    std::string byteword = bytewords[c];
    /* Go through each Bits in the Byteword and write them to the File. */
    for (const char &charbit : byteword) {
      IO::WriteBit(file, charbit, bit_buffer, bit_count);
    }
  }

  /* The Last few Bits may not have been Written */
  /* If the number of Bits in the Input File is not Divisible by 8. */
  if (bit_count > 0) {
    bit_buffer <<= (7 - bit_count);
    bit_count = 8;
    IO::WriteBit(file, '0', bit_buffer, bit_count);
  }

  fclose(file);
}

void DecodeStringToFile(const char *filename, std::string &input,
                        const Heap::Node *const root) {
  static std::string result = "";
  const Heap::Node *curr_node = root;

  for (const char &c : input) {
    /* Convert the Current Char to a Byte. */
    std::string curr_byte = std::bitset<8>(c).to_string();
    /* Go through each Bits of the Converted Char. */
    for (const char &bit : curr_byte) {
      if (bit == '0' && curr_node->lchild) {
        curr_node = curr_node->lchild;
      }
      if (bit == '1' && curr_node->rchild) {
        curr_node = curr_node->rchild;
      }
      if (!curr_node->lchild && !curr_node->rchild) {
        result += curr_node->character;
        curr_node = root;
      }
    }
  }
  result += '\0';
  IO::WriteFile(filename, result.c_str());
}

}; // namespace Huffman
