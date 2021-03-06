#include "DataIO.h"
#include "HuffmanCoding.h"
#include "Tree.h"

/*
====== TODO ======
-Image Compression
*/

using namespace std;

int main() {
  std::string file_content, txt_encoded;
  Heap::Heap heap;
  Tree::Tree tree;
  map<char, string> codewords;

  Heap::GenerateHeapFromFile("./Data/harry_fullchapter.txt", file_content,
                             heap);
  Tree::GenerateHuffmanTree(heap, tree);
  Huffman::GenerateBytecodes(tree.root, codewords, 0);

  /* Display the generated Bytecode for each Characters (Debug)*/
  cout << "\nBYTECODE:\n";
  for (std::map<char, string>::const_iterator it = codewords.begin();
       it != codewords.end(); it++) {
    std::cout << it->first << ":" << it->second << "\n";
  }

  Huffman::EncodeStringToFile("./Data/harry_fullchapter_encoded.bin",
                              file_content, codewords);
  txt_encoded = IO::ReadFile("./Data/harry_fullchapter_encoded.bin", "rb");
  Huffman::DecodeStringToFile("./Data/harry_fullchapter_decoded.txt",
                              txt_encoded, tree.root);

  Tree::FreeTree(codewords, 0, tree);
  return 0;
}
