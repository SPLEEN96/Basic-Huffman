#pragma once
#include "HUFFMAN_CORE.h"
#include "Heap.h"

/* Character for each Non-Leaf Nodes */
#define NON_LEAF '\0' 


struct Tree {
  Node *root;
  uint16 leaf_count;
};

void DisplayTree(const Tree &target) {

}

void GenerateHuffmanTree(Heap &input, Tree &target) {
  /* Repeat until there is only one Node in the Heap */
  while (RootOnly(input)) {
    /* Extract the First Min from the Heap */
    Node *min1 = ExtractMinFromHeap(input);
    std::cout << "\nMIN1:" << min1->frequency << "\tCHAR:" << min1->character;

    /* Extract the Second Min from the Heap */
    Node *min2 = ExtractMinFromHeap(input);
    std::cout << "\nMIN2:" << min2->frequency << "\tCHAR:" << min2->character
              << "\n\n";

    /* Create a  New Node with Min1 and Min 2 as its Left and Right Child */
    Node *new_node =
        NewNode(NON_LEAF, (min1->frequency + min2->frequency), min1, min2);

    /* Add the newly created Node in the Heap */
    InsertInHeap(new_node, input);
  }

  target.root = input.nodes.back();
  std::cout << "\n=====\nROOT:" << target.root->frequency << "\n=====\n\n";
}
