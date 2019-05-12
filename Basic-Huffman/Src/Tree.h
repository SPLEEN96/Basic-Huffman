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

}; // namespace Tree
