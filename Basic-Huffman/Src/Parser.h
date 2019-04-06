#pragma once
#include "HUFFMAN_CORE.h"

#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <vector>

void Sort(std::vector<std::pair<char, uint16>> &in);
void Display(std::vector<std::pair<char, uint16>> input);

void CountChar(std::string input, std::string target) {
  std::map<char, uint16> char_count;
  std::vector<std::pair<char, uint16>> sorted;

  /* Count the number of repetition of each char in the input string */
  for (char &c : input) {
    char_count[c]++;
  }

  /* Transfer the map into a Vector for easier sorting */
  for (auto it = char_count.begin(); it != char_count.end(); it++) {
    sorted.push_back(*it);
  }
  Sort(sorted);

  Display(sorted);
}

/* Sort by Increasing Order of Value */
void Sort(std::vector<std::pair<char, uint16>> &input) {
  std::sort(input.begin(), input.end(),
            [](std::pair<char, uint16> lhs, std::pair<char, uint16> rhs) {
              return lhs.second > rhs.second;
            });
}

/* Display the Sorted Vector */
void Display(std::vector<std::pair<char, uint16>> input) {
  for (size_t i = 0; i < input.size(); i++) {
    std::cout << input[i].first << ":" << input[i].second << "\n";
  }
}
