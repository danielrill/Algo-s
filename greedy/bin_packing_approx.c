#include "bin_packing_approx.h"

int bin_packing_first_fit(int weights[], int n, int capacity, int bin_of_item[]) {
    int bin_remaining[BIN_MAX_ITEMS];
    int bins = 0;
    for (int i = 0; i < n; i++) {
        int placed = 0;
        for (int b = 0; b < bins; b++) {
            if (bin_remaining[b] >= weights[i]) {
                bin_remaining[b] -= weights[i];
                bin_of_item[i] = b;
                placed = 1;
                break;
            }
        }
        if (!placed) {
            bin_remaining[bins] = capacity - weights[i];
            bin_of_item[i] = bins;
            bins++;
        }
    }
    return bins;
}