#include "Parser.h"
#include "Tree.h"

using namespace std;

int main() {
  string buffer = "aaaDFOEWOiefwnoineOIFNEWPOIUfnwepiuobFPIEWUbiubfwpebiupIUBFE"
                  "WPIUBFWEPiubPIRUBFPIWUEBFEFWPIUbpiwubfipubwefpibpIUBFWEPIEWU"
                  "BFEFWBIEFWBIUPEFWBPIUEFWibupfwebbc";
  Tree tree;
  
  CharFrequency(buffer, tree);
  tree.Display();
  GenerateHuffmanTree(tree);

  std::cout << "TreeROOT:" << tree.root->frequency;
  
  return 0;
}
