#ifndef FRACTIONAL_KNAPSACK_H
#define FRACTIONAL_KNAPSACK_H

typedef struct {
    int value;
    int weight;
    double ratio;
} Item;

double fractional_knapsack(Item items[], int n, int capacity);

#endif