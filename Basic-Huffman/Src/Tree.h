#pragma once
#include "HUFFMAN_CORE.h"
#include "Parser.h"

#include <cstdlib>

struct Node {
  uint16 frequency;
  struct Node *left;
  struct Node *right;
};

Node *NewNode(const uint16 &data) {
  Node *new_node = (Node *)malloc(sizeof(Node));

  new_node->frequency = data;
  new_node->left = nullptr;
  new_node->right = nullptr;

  return new_node;
}
Node *NewNode(const uint16 &data, Node *left_node, Node *right_node) {
  Node *new_node = (Node *)malloc(sizeof(Node));

  new_node->frequency = data;
  new_node->left = left_node;
  new_node->right = right_node;

  return new_node;
}

struct Tree {
  Node *root;
  std::vector<Node *> nodes;
};

void GenerateHuffmanTree(std::vector<uint16> input) {
  Tree tree;

  while (input.size() > 1) {
    /* Get the First Min in the Sorted Heap */
    Node *min1 = NewNode(input.back());
    input.pop_back();
    std::cout << "\nMIN1:" << min1->frequency << "";

    /* Get the Second Min the Sorted Heap */
    Node *min2 = NewNode(input.back());
    input.pop_back();
    std::cout << "\nMIN2:" << min2->frequency << "\n\n";

    /* Create a New Node with Min1 as its Left and Min2 as its Right */
    Node *new_node = NewNode((min1->frequency + min2->frequency), min1, min2);

    /* Add the newly created Node in the heap */
    input.push_back(new_node->frequency);
    SortHeap(input);

    /* Add it also in the Huffman Tree */
    tree.nodes.push_back(new_node);
  }

  tree.root = tree.nodes.back();
  std::cout << "\n=====\nROOT:" << tree.root->frequency << "\n";
}
