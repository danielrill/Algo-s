#include "rod_cutting.h"

int rod_cutting(int prices[], int n) {
    int dp[n + 1];
    dp[0] = 0;
    for (int i = 1; i <= n; i++) {
        int best = prices[i];
        for (int j = 1; j < i; j++) {
            int cand = prices[j] + dp[i - j];
            if (cand > best) best = cand;
        }
        dp[i] = best;
    }
    return dp[n];
}