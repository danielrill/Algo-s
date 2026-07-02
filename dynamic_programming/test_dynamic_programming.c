#include <stdio.h>
#include "fibonacci.h"
#include "knapsack_01.h"
#include "lcs.h"
#include "lis.h"
#include "matrix_chain.h"
#include "edit_distance.h"
#include "rod_cutting.h"
#include "floyd_warshall.h"
#include "coin_change.h"
#include "subset_sum_dp.h"
#include "tsp_dp.h"

"""
gcc 
test_dynamic_programming.c fibonacci.c knapsack_01.c lcs.c lis.c 
matrix_chain.c edit_distance.c rod_cutting.c floyd_warshall.c coin_change.c subset_sum_dp.c tsp_dp.c -o test_dynamic_programming
"""

int main(void) {
    printf("Fibonacci(10): %lld\n", fibonacci_dp(10));

    int w[] = {10, 20, 30};
    int v[] = {60, 100, 120};
    printf("Knapsack: %d\n", knapsack_01(w, v, 3, 50));

    char x[] = "ABCBDAB", y[] = "BDCABA", out[20];
    printf("LCS length: %d\n", lcs_length(x, y));
    lcs_reconstruct(x, y, out);
    printf("LCS: %s\n", out);

    int a[] = {10, 9, 2, 5, 3, 7, 101, 18};
    printf("LIS: %d\n", lis_length(a, 8));

    int p[] = {10, 20, 30, 40, 30};
    printf("Matrix chain: %d\n", matrix_chain_order(p, 5));

    printf("Edit distance: %d\n", edit_distance("kitten", "sitting"));

    int prices[] = {0, 1, 5, 8, 9, 10, 17, 17, 20};
    printf("Rod cutting: %d\n", rod_cutting(prices, 8));

    int dist[FW_MAX][FW_MAX] = {
        {0, 3, FW_INF, 7},
        {8, 0, 2, FW_INF},
        {5, FW_INF, 0, 1},
        {2, FW_INF, FW_INF, 0}
    };
    floyd_warshall(4, dist);
    printf("Floyd-Warshall d[0][2]: %d\n", dist[0][2]);

    int coins[] = {1, 3, 4};
    printf("Coin change min: %d\n", coin_change_min(coins, 3, 6));

    int ss[] = {3, 34, 4, 12, 5, 2};
    printf("Subset sum 9: %d\n", subset_sum_dp(ss, 6, 9));

    int tspn = 4;
    int g[TSP_MAX][TSP_MAX] = {
        {0, 10, 15, 20},
        {10, 0, 35, 25},
        {15, 35, 0, 30},
        {20, 25, 30, 0}
    };
    printf("TSP DP: %d\n", tsp_dp(tspn, g));
    return 0;
}