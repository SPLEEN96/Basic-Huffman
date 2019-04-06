#pragma once
#include "HUFFMAN_CORE.h"
#include "Parser.h"

#include <cstdlib>

struct Node {
  char character;
  uint16 frequency;
  struct Node *left;
  struct Node *right;
};

Node *NewNode(const char &character, const uint16 &frequency) {
  Node *new_node = (Node *)malloc(sizeof(Node));

  new_node->character = character;
  new_node->frequency = frequency;
  new_node->left = nullptr;
  new_node->right = nullptr;

  return new_node;
}
Node *NewNode(const char &character, const uint16 &frequency, Node *left_node,
              Node *right_node) {
  Node *new_node = (Node *)malloc(sizeof(Node));

  new_node->character = character;
  new_node->frequency = frequency;
  new_node->left = left_node;
  new_node->right = right_node;

  return new_node;
}

struct Tree {
  Node *root;
  std::vector<Node *> nodes;
};

void GenerateHuffmanTree(std::vector<freq_pair> input, Tree target) {
  while (input.size() > 1) {
    /* Get the First Min in the Sorted Vector */
    Node *min1 = NewNode(input.back().first, input.back().second);
    input.pop_back();
    std::cout << "\nMIN1:" << min1->frequency << "\tCHAR:" << min1->character;

    /* Get the Second Min the Sorted Vector */
    Node *min2 = NewNode(input.back().first, input.back().second);
    input.pop_back();
    std::cout << "\nMIN2:" << min2->frequency << "\tCHAR:" << min2->character
              << "\n\n";

    /* Create a New Node with Min1 as its Left and Min2 as its Right */
    Node *new_node = NewNode('\0',(min1->frequency + min2->frequency), min1, min2);

    /* Add the newly created Node in the Sorted Vector */
    freq_pair node_pair;
    node_pair.first = new_node->character;
    node_pair.second = new_node->frequency;
    input.push_back(node_pair);
    Sort(input);

    /* Add it also in the Huffman Tree */
    target.nodes.push_back(new_node);
  }

  target.root = target.nodes.back();
  std::cout << "\n=====\nROOT:" << target.root->frequency << "\n";
}
