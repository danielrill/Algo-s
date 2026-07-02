#ifndef HUFFMAN_H
#define HUFFMAN_H

typedef struct HuffmanNode {
    char ch;
    int freq;
    struct HuffmanNode *left;
    struct HuffmanNode *right;
} HuffmanNode;

HuffmanNode *huffman_build(char chars[], int freq[], int n);
void huffman_print_codes(HuffmanNode *root, int arr[], int top);
void huffman_free(HuffmanNode *root);

#endif