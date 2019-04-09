#pragma once
#include "HUFFMAN_CORE.h"

#include <vector>
#include <algorithm>
#include <map>
#include <string>

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

Node *NewNode(const char &character, const uint16 &frequency, Node *left_child,
              Node *right_child) {
  Node *new_node = (Node *)malloc(sizeof(Node));

  new_node->character = character;
  new_node->frequency = frequency;
  new_node->lchild = left_child;
  new_node->rchild = right_child;

  return new_node;
}

/* ============== HEAP  ============== */
struct Heap {
  std::vector<Node *> nodes;
};

/* -Count the number of repetition of each char in the input string */
/* -Store the character and its frequency in a Heap */
void GenerateHeap(const std::string &input, Heap &target) {
  std::map<char, uint16> char_count;

  /* For each Characters c in the Input String */
  /* Increment by 1 the Frequency at the Key c */
  for (const char &c : input) {
    char_count[c]++;
  }

  /* Transfer the map into the Heap */
  for (auto it = char_count.begin(); it != char_count.end(); it++) {
    target.nodes.push_back(NewNode(*it));
  }
}

/* Sort the content of the Heap in Descending Order */
void SortHeap(Heap &target) {
  std::sort(target.nodes.begin(), target.nodes.end(), [](Node *lhs, Node *rhs) {
    return lhs->frequency > rhs->frequency;
  });
}

/* Insert a Node into the Heap and Sort it */
void InsertInHeap(Node *data, Heap &target) {
  target.nodes.push_back(data);
  SortHeap(target);
}

/* Get the Node with the Lowest Frequency and Remove it from the Heap */
Node *ExtractMinFromHeap(Heap &target) {
  Node *tmp = target.nodes.back();
  target.nodes.pop_back();

  return tmp;
}

/* Return true if there is only a Node left in the Heap */
bool RootOnly(Heap &input) {
  if (input.nodes.size() > 1) {
    return true;
  } else {
    return false;
  }
}
