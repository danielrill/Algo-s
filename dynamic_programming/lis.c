#include "lis.h"

int lis_length(int arr[], int n) {
    int dp[n];
    for (int i = 0; i < n; i++) dp[i] = 1;
    int best = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (arr[j] < arr[i] && dp[j] + 1 > dp[i]) dp[i] = dp[j] + 1;
        }
        if (dp[i] > best) best = dp[i];
    }
    return best;
}