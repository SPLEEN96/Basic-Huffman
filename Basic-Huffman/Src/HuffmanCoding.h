#include "HUFFMAN_CORE.h"
#include "Tree.h"

#include <bitset>

/* Recursive Function that finds all Leaf Nodes and */
/* Generate a Codeword with the Path taken (Left Branch:0; Right Branch:1)*/
void GenerateCodewords(const Node *root, std::map<char, std::string> &codewords,
                       uint16 len) {
  const Node *curr_node = root;
  static char code[16] = {};

  if (curr_node->lchild) {
    code[len] = '0';
    GenerateCodewords(curr_node->lchild, codewords, len + 1);
  }
  if (curr_node->rchild) {
    code[len] = '1';
    GenerateCodewords(curr_node->rchild, codewords, len + 1);
  }

  if (!curr_node->lchild && !curr_node->rchild) {
    code[len] = '\0';
    codewords[curr_node->character] = code;

    std::cout << "\n\n" << codewords[curr_node->character];
    std::cout << "\t" << curr_node->character << ":" << curr_node->frequency;
  }
}

void EncodeString(const std::string &input,
                  std::map<char, std::string> &codewords, std::string &target) {
  target = "";
  for (const char &c : input) {
    target += codewords[c];
  }
}

void DecodeBinaryToString(const std::vector<char> &input, const Node *root,
                          std::string &target) {
  static std::string result = "";
  const Node *initial_root = root;

  for (const char &c : input) {
    /* Convert the Char to a Byte */
    std::string curr_byte = std::bitset<8>(c).to_string();
    /* Go through each Bits of the Char */
    for (const char &bit : curr_byte) {
      if (bit == '0' && root->lchild) {
        root = root->lchild;
      }
      if (bit == '1' && root->rchild) {
        root = root->rchild;
      }
      if (!root->lchild && !root->rchild) {
        result += root->character;
        root = initial_root;
      }
    }
  }
  result+='\0';
  target = result;
}
