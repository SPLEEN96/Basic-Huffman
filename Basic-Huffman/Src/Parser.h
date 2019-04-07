#pragma once
#include "HUFFMAN_CORE.h"
#include "Tree.h"

#include <map>
#include <string>

void CharFrequency(const std::string &input, Tree &target) {
  std::map<char, uint16> char_count;

  /* Count the number of repetition of each char in the input string */
  for (const char &c : input) {
    char_count[c]++;
  }

  /* Transfer the map into the Tree for easier sorting */
  for (auto it = char_count.begin(); it != char_count.end(); it++) {
    target.nodes.push_back(NewNode(*it));
  }
}
