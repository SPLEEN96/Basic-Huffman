#include "Parser.h"
#include "Tree.h"

using namespace std;

int main() {
  string buffer =
      "aaaaabbbbcccrrz";

  std::vector<freq_pair> sorted_vec;
  std::vector<uint16> sorted_heap;
  
  CharFrequency(buffer, sorted_vec);
  Sort(sorted_vec);

  /* Create the Heap */
  for (auto x : sorted_vec) {
    sorted_heap.push_back(x.second);
  }
  SortHeap(sorted_heap);

  Display(sorted_vec);

  GenerateHuffmanTree(sorted_heap);
  
  return 0;
}
