#include "Parser.h"
#include "Tree.h"
#include "Bytecode.h"

using namespace std;

int main() {
  string buffer = "aaaaabbbbcccdd";
  Heap heap;
  Tree tree;
  
  GenerateHeap(buffer, heap);
  GenerateHuffmanTree(heap, tree);
 
  std::cout << "TreeROOT:" << tree.root->frequency;

  return 0;
}
