#include "coin_change.h"
#include <limits.h>

int coin_change_min(int coins[], int n, int amount) {
    int dp[amount + 1];
    for (int i = 0; i <= amount; i++) dp[i] = INT_MAX / 2;
    dp[0] = 0;
    for (int i = 1; i <= amount; i++)
        for (int j = 0; j < n; j++)
            if (coins[j] <= i && dp[i - coins[j]] + 1 < dp[i])
                dp[i] = dp[i - coins[j]] + 1;
    return dp[amount] >= INT_MAX / 2 ? -1 : dp[amount];
}