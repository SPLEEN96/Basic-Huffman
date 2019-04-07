#pragma once
#include "HUFFMAN_CORE.h"

#include <algorithm>
#include <cstdlib>

/* ============== NODE  ============== */
struct Node {
  char character;
  uint16 frequency;
  struct Node *lchild; /* Left Child */
  struct Node *rchild; /* Right Child */
};

Node *NewNode(const freq_pair &data) {
  Node *new_node = (Node *)malloc(sizeof(Node));

  new_node->character = data.first;
  new_node->frequency = data.second;
  new_node->lchild = nullptr;
  new_node->rchild = nullptr;

  return new_node;
}

Node *NewNode(Node *node) {
  Node *new_node = (Node *)malloc(sizeof(Node));

  new_node->character = node->character;
  new_node->frequency = node->frequency;
  new_node->left = node->left;
  new_node->right = node->right;

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

/* ============== TREE  ============== */
struct Tree {
  Node *root;
  std::vector<Node *> nodes;

  void Sort() {
    std::sort(this->nodes.begin(), this->nodes.end(), [](Node *lhs, Node *rhs) {
      return lhs->frequency > rhs->frequency;
    });
  }

  void Display() {
    for (auto x : this->nodes) {
      std::cout << x->character << ":" << x->frequency << "\n";
    }
  }

  Node *Back() { return this->nodes.back(); }
  void PushBack(Node *node) { this->nodes.push_back(node); }
  void PopBack() { this->nodes.pop_back(); }
};

void GenerateHuffmanTree(Tree &target) {
  Tree tmp_heap;

  /* Copy the Data from the Huffman Tree to the Temporary Heap */
  for (auto x : target.nodes) {
    tmp_heap.PushBack(x);
  }
  tmp_heap.Sort();

  while (tmp_heap.nodes.size() > 1) {
    /* Get the First Min in the Heap */
    Node *min1 = NewNode(tmp_heap.Back());
    tmp_heap.PopBack();
    std::cout << "\nMIN1:" << min1->frequency << "\tCHAR:" << min1->character;

    /* Get the Second Min the Heap */
    Node *min2 = NewNode(tmp_heap.Back());
    tmp_heap.nodes.PopBack();
    std::cout << "\nMIN2:" << min2->frequency << "\tCHAR:" << min2->character
              << "\n\n";

    /* Create a  New Node with Min1 and Min 2 as its Left and Right Child */
    Node *new_node =
        NewNode('.', (min1->frequency + min2->frequency), min1, min2);

    /* Add the newly created Node in the Heap */
    tmp_heap.nodes.push_back(new_node);
    tmp_heap.Sort();

    /* Add it also in the Huffman Tree */
    target.nodes.push_back(new_node);
  }

  target.root = target.nodes.back();
  std::cout << "\n=====\nROOT:" << target.root->frequency << "\n=====\n\n";
}

