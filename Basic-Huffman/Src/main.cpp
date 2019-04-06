#include "Parser.h"
#include "Tree.h"

using namespace std;

int main() {
  string buffer =
      "aaaINOVOINROWIERNowincvweoivneoInvoiwnvoeiwnvosidvnweoinevwoVWIONVWEIONE"
      "VIOAAAAAAAAAABBBBBBBBBBBBBBBBBBBBBBBVVVVVVVVVVVVVAAAAAAAAAAAAAACCCCCCCCG"
      "LDLKSHDFLKHDSLKHGDSLKHGVNEWVINEVPWIUBPUBWICWUEBPICUBEINEPIUNQZIUBAIUBSFI"
      "UBEFIUWGNIWUEGNIUEWNGEIWUGNPEIUNaabbbbcccrrzht";
  std::vector<freq_pair> sorted_vec;
  Tree tree;
  
  CharFrequency(buffer, sorted_vec);
  Sort(sorted_vec);

  Display(sorted_vec);
  
  GenerateHuffmanTree(sorted_vec, tree);
  
  return 0;
}
