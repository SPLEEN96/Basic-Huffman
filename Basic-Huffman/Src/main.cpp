#include "Bytecode.h"
#include "Tree.h"

using namespace std;

int main() {
  string buffer =
      "Mr . and Mrs . Dursley , of number four , Privet Drive , were proud to "
      "say that they were perfectly normal , thank you very much . They were "
      "the last people you'd expect to be involved in anything strange or "
      "mysterious , because they just didn't hold with such nonsense .";
  string encoded = "";
  Heap heap;
  Tree tree;
  map<char, string> codewords;

  GenerateHeap(buffer, heap);
  GenerateHuffmanTree(heap, tree);

  GenerateCodewords(tree.root, codewords, 0);

  EncodeString(buffer, codewords, encoded);
  cout << "\n" << encoded << "\n";

  DecodeString(tree.root, encoded);
  cout << "\n" << encoded << "\n";

  return 0;
}
