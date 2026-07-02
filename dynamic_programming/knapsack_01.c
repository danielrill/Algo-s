#include "knapsack_01.h"

int knapsack_01(int weights[], int values[], int n, int capacity) {
    int dp[n + 1][capacity + 1];
    for (int i = 0; i <= n; i++)
        for (int w = 0; w <= capacity; w++)
            dp[i][w] = 0;
    for (int i = 1; i <= n; i++) {
        for (int w = 0; w <= capacity; w++) {
            dp[i][w] = dp[i - 1][w];
            if (weights[i - 1] <= w) {
                int cand = values[i - 1] + dp[i - 1][w - weights[i - 1]];
                if (cand > dp[i][w]) dp[i][w] = cand;
            }
        }
    }
    return dp[n][capacity];
}