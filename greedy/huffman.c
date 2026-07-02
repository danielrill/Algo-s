#include "huffman.h"
#include <stdlib.h>
#include <stdio.h>

static HuffmanNode *new_node(char ch, int freq) {
    HuffmanNode *node = (HuffmanNode *)malloc(sizeof(HuffmanNode));
    node->ch = ch;
    node->freq = freq;
    node->left = NULL;
    node->right = NULL;
    return node;
}

static void swap(HuffmanNode **a, HuffmanNode **b) {
    HuffmanNode *t = *a; *a = *b; *b = t;
}

static void heapify_down(HuffmanNode *heap[], int size, int i) {
    int smallest = i;
    int l = 2 * i + 1, r = 2 * i + 2;
    if (l < size && heap[l]->freq < heap[smallest]->freq) smallest = l;
    if (r < size && heap[r]->freq < heap[smallest]->freq) smallest = r;
    if (smallest != i) {
        swap(&heap[i], &heap[smallest]);
        heapify_down(heap, size, smallest);
    }
}

static void heapify_up(HuffmanNode *heap[], int i) {
    while (i > 0) {
        int p = (i - 1) / 2;
        if (heap[p]->freq <= heap[i]->freq) break;
        swap(&heap[p], &heap[i]);
        i = p;
    }
}

static void heap_push(HuffmanNode *heap[], int *size, HuffmanNode *node) {
    heap[*size] = node;
    heapify_up(heap, *size);
    (*size)++;
}

static HuffmanNode *heap_pop(HuffmanNode *heap[], int *size) {
    if (*size == 0) return NULL;
    HuffmanNode *min = heap[0];
    (*size)--;
    heap[0] = heap[*size];
    heapify_down(heap, *size, 0);
    return min;
}

HuffmanNode *huffman_build(char chars[], int freq[], int n) {
    if (n <= 0) return NULL;
    HuffmanNode **heap = (HuffmanNode **)malloc(sizeof(HuffmanNode *) * (2 * n));
    int size = 0;
    for (int i = 0; i < n; i++) heap_push(heap, &size, new_node(chars[i], freq[i]));
    while (size > 1) {
        HuffmanNode *x = heap_pop(heap, &size);
        HuffmanNode *y = heap_pop(heap, &size);
        HuffmanNode *z = new_node('$', x->freq + y->freq);
        z->left = x;
        z->right = y;
        heap_push(heap, &size, z);
    }
    HuffmanNode *root = heap_pop(heap, &size);
    free(heap);
    return root;
}

void huffman_print_codes(HuffmanNode *root, int arr[], int top) {
    if (!root) return;
    if (!root->left && !root->right) {
        printf("%c: ", root->ch);
        for (int i = 0; i < top; i++) printf("%d", arr[i]);
        printf("\n");
        return;
    }
    arr[top] = 0;
    huffman_print_codes(root->left, arr, top + 1);
    arr[top] = 1;
    huffman_print_codes(root->right, arr, top + 1);
}

void huffman_free(HuffmanNode *root) {
    if (!root) return;
    huffman_free(root->left);
    huffman_free(root->right);
    free(root);
}