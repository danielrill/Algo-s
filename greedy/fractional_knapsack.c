#include "fractional_knapsack.h"
#include <stdlib.h>

static int cmp_item(const void *a, const void *b) {
    const Item *x = (const Item *)a;
    const Item *y = (const Item *)b;
    if (y->ratio > x->ratio) return 1;
    if (y->ratio < x->ratio) return -1;
    return 0;
}

double fractional_knapsack(Item items[], int n, int capacity) {
    for (int i = 0; i < n; i++) items[i].ratio = (double)items[i].value / items[i].weight;
    qsort(items, n, sizeof(Item), cmp_item);
    double total = 0.0;
    for (int i = 0; i < n && capacity > 0; i++) {
        if (items[i].weight <= capacity) {
            total += items[i].value;
            capacity -= items[i].weight;
        } else {
            total += items[i].ratio * capacity;
            capacity = 0;
        }
    }
    return total;
}