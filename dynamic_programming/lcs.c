#include "lcs.h"
#include <string.h>

int lcs_length(const char *x, const char *y) {
    int n = strlen(x), m = strlen(y);
    int dp[n + 1][m + 1];
    for (int i = 0; i <= n; i++)
        for (int j = 0; j <= m; j++)
            dp[i][j] = 0;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            dp[i][j] = (x[i - 1] == y[j - 1]) ? dp[i - 1][j - 1] + 1 :
                       (dp[i - 1][j] > dp[i][j - 1] ? dp[i - 1][j] : dp[i][j - 1]);
    return dp[n][m];
}

void lcs_reconstruct(const char *x, const char *y, char *out) {
    int n = strlen(x), m = strlen(y);
    int dp[n + 1][m + 1];
    for (int i = 0; i <= n; i++)
        for (int j = 0; j <= m; j++)
            dp[i][j] = 0;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            dp[i][j] = (x[i - 1] == y[j - 1]) ? dp[i - 1][j - 1] + 1 :
                       (dp[i - 1][j] > dp[i][j - 1] ? dp[i - 1][j] : dp[i][j - 1]);
    int i = n, j = m, k = dp[n][m];
    out[k] = '\0';
    while (i > 0 && j > 0) {
        if (x[i - 1] == y[j - 1]) out[--k] = x[i - 1], i--, j--;
        else if (dp[i - 1][j] >= dp[i][j - 1]) i--;
        else j--;
    }
}