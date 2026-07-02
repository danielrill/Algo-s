#include "subset_sum_dp.h"

int subset_sum_dp(int arr[], int n, int sum) {
    int dp[n + 1][sum + 1];
    for (int i = 0; i <= n; i++) dp[i][0] = 1;
    for (int s = 1; s <= sum; s++) dp[0][s] = 0;
    for (int i = 1; i <= n; i++) {
        for (int s = 1; s <= sum; s++) {
            dp[i][s] = dp[i - 1][s];
            if (arr[i - 1] <= s && dp[i - 1][s - arr[i - 1]]) dp[i][s] = 1;
        }
    }
    return dp[n][sum];
}