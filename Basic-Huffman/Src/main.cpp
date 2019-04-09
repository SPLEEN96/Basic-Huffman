#include "DataTransfer.h"
#include "HuffmanCoding.h"
#include "Tree.h"

/*
-TREE IN FILE
-JPG
-DISPLAY
 */

using namespace std;

int main() {
  string buffer = ReadFile("./Data/harry.txt");
  std::string encoded;
  Heap heap;
  Tree tree;
  map<char, string> codewords;
  std::vector<char> bytecode;

  GenerateHeap(buffer, heap);
  GenerateHuffmanTree(heap, tree);

  GenerateCodewords(tree.root, codewords, 0);

  EncodeString(buffer, codewords, encoded);
  cout << "\n==========\nString Encoded: \n" << encoded << "\n";
  WriteBit("./Data/harry_encoded.bin", encoded);

  bytecode = ReadBit("./Data/harry_encoded.bin");
  DecodeBinaryToString(bytecode, tree.root, encoded);
  cout << "\n==========\nString Decoded: \n" << encoded << "\n\n\n";
  //WriteFile("./Data/harry_decoded.txt", encoded.c_str());
  WriteFile("./Data/WOD.txt", encoded.c_str());
  return 0;
}
