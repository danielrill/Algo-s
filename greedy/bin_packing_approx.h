#ifndef BIN_PACKING_APPROX_H
#define BIN_PACKING_APPROX_H

#define BIN_MAX_ITEMS 256

int bin_packing_first_fit(int weights[], int n, int capacity, int bin_of_item[]);

#endif