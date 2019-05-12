#pragma once
#include "HUFFMAN_CORE.h"

#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <vector>

namespace Heap {

typedef std::pair<char, uint16> freq_pair;

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

/* -Count the number of repetition of each char in the input string */
/* -Store the character and its frequency in a Heap */
void GenerateHeapFromFile(const char *filename, std::string &content,
                          Heap &target) {
  FILE *file = nullptr;
  char c = '\0';
  content = "";
  std::map<char, uint16> char_count;

  file = fopen(filename, "r");
  if (!file) {
    std::cout << "\nFailed to read from file.\n";
    return;
  }

  /* For each Characters c in the File, */
  /* Increment by 1 the Frequency at the Key c in the Map */
  /* And Save the content of the file in a String */
  while (fscanf(file, "%c", &c) == 1) {
    content += c;
    char_count[c]++;
  }

  /* Transfer the map into the Heap */
  for (auto it = char_count.begin(); it != char_count.end(); it++) {
    // target.nodes.push_back(NewNode(*it));
    InsertInHeap(NewNode(*it), target);
  }

  fclose(file);
}

/* Get the Node with the Lowest Frequency and Remove it from the Heap */
Node *ExtractMinFromHeap(Heap &target) {
  Node *tmp = target.nodes.back();
  target.nodes.pop_back();

  return tmp;
}

/* Return true if there is only a Node left (The Root) in the Heap */
bool RootOnly(Heap &input) {
  if (input.nodes.size() > 1) {
    return true;
  } else {
    return false;
  }
}

}; // namespace Heap
