#pragma once
#include "HUFFMAN_CORE.h"

#include <algorithm>
#include <map>
#include <stack>
#include <string>

void CharFrequency(const std::string &input, std::vector<freq_pair> &target) {
  std::map<char, uint16> char_count;

  /* Count the number of repetition of each char in the input string */
  for (const char &c : input) {
    char_count[c]++;
  }

  /* Transfer the map into a Vector for easier sorting */
  for (auto it = char_count.begin(); it != char_count.end(); it++) {
    target.push_back(*it);
  }
}

/* Sort by Increasing Order of Value */
void Sort(std::vector<freq_pair> &input) {
  std::sort(input.begin(), input.end(), [](freq_pair lhs, freq_pair rhs) {
    return lhs.second > rhs.second;
  });
}

/* Display the Sorted Vector */
void Display(const std::vector<freq_pair> &input) {
  for (size_t i = 0; i < input.size(); i++) {
    std::cout << input[i].first << ":" << input[i].second << "\n";
  }
}
