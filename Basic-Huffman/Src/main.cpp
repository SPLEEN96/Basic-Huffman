#include "Parser.h"
#include "Tree.h"

using namespace std;

int main() {
  string buffer =
      "aaabre";

  std::vector<freq_pair> sorted_chars;

  CharFrequency(buffer, sorted_chars);
  Sort(sorted_chars);
  //Display(sorted_chars);

  GreedyHuffman(sorted_chars);
  
  return 0;
}
