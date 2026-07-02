#include "edit_distance.h"
#include <string.h>

static int min3(int a, int b, int c) {
    int m = a < b ? a : b;
    return m < c ? m : c;
}

int edit_distance(const char *a, const char *b) {
    int n = strlen(a), m = strlen(b);
    int dp[n + 1][m + 1];
    for (int i = 0; i <= n; i++) dp[i][0] = i;
    for (int j = 0; j <= m; j++) dp[0][j] = j;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            dp[i][j] = (a[i - 1] == b[j - 1]) ? dp[i - 1][j - 1] :
                       1 + min3(dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]);
    return dp[n][m];
}