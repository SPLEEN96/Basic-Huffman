#include "Parser.h"

using namespace std;

int main() {
  string buffer = "aaabreoginerononrioniorwoirwoirwoirwoierwnogrwingorwingvoingroirwnifrififkdldkndglkgkgkgkkkkkkkkkkkkkkkkkkkkkkkoooaaaaaaaaavoiubreoibrovberbioiobokvvvvvvvvvvvvvvvvvvddddddddddddooooooooooooooooooihdsogihdosihgoishdgoidshogihsdogidshgodsihgsodihgoiherwnnnnnnnnnnnnnnnnnnnnnnnnnxccccccccccccccobbbccdddddddd";

  std::vector<std::pair<char, uint16>> sorted_chars;

  CountChar(buffer, sorted_chars);
  Sort(sorted_chars);
  Display(sorted_chars);

  return 0;
}
