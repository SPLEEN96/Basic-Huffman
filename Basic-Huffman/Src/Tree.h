#pragma once
#include "HUFFMAN_CORE.h"
#include "Heap.h"

/* Character for each Non-Leaf Nodes */
#define NON_LEAF '\0'

namespace Tree {

struct Tree {
  Heap::Node *root;
  uint16 leaf_count;
};

void DisplayTree(const Tree &target) { /* TODO? */
}

void GenerateHuffmanTree(Heap::Heap &input, Tree &target) {
  /* Repeat until there is only one Node in the Heap */
  while (RootOnly(input)) {
    /* Extract the First Min from the Heap */
    Heap::Node *min1 = Heap::ExtractMinFromHeap(input);

    /* Extract the Second Min from the Heap */
    Heap::Node *min2 = Heap::ExtractMinFromHeap(input);

    /* Create a  New Node with Min1 and Min 2 as its Left and Right Child */
    Heap::Node *new_node = Heap::NewNode(
        NON_LEAF, (min1->frequency + min2->frequency), min1, min2);

    /* Add the newly created Node in the Heap */
    Heap::InsertInHeap(new_node, input);
  }

  target.root = input.nodes.back();
}

/* Recursive Function that finds all Leaf Nodes and */
/* then makes an action based on the Function pass as Parameter. */
/* It also saves the path taken for each Leafs in a bytecode */
/* (Left Branch:0; Right Branch:1) */
void FindLeafNodes(const Heap::Node *root,
                   std::map<char, std::string> &bytecodes, uint16 len,
                   void (*FoundLeaf)(const Heap::Node *, char[16],
                                     std::map<char, std::string> &, uint16)) {
  const Heap::Node *curr_node = root;
  static char code[16] = {};

  if (curr_node->lchild) {
    code[len] = '0';
    FindLeafNodes(curr_node->lchild, bytecodes, len + 1, FoundLeaf);
  }
  if (curr_node->rchild) {
    code[len] = '1';
    FindLeafNodes(curr_node->rchild, bytecodes, len + 1, FoundLeaf);
  }

  /* If the Node has no Childs. */
  if (!curr_node->lchild && !curr_node->rchild) {
    FoundLeaf(curr_node, code, bytecodes, len);
    return;
  }
}

void DeleteNode(const Heap::Node *curr_node, char code[16],
                std::map<char, std::string> &bytecodes, uint16 len) {
  /* TODO */
}
void DeleteNodes(const Heap::Node *root, std::map<char, std::string> &bytecodes,
                 uint16 len) {
  FindLeafNodes(root, bytecodes, len, &DeleteNode);
}

}; // namespace Tree
