#include "tsp_dp.h"
#include <limits.h>

int tsp_dp(int n, int dist[TSP_MAX][TSP_MAX]) {
    int N = 1 << n;
    static int dp[1 << 12][TSP_MAX];
    for (int mask = 0; mask < N; mask++)
        for (int i = 0; i < n; i++)
            dp[mask][i] = TSP_INF;
    dp[1][0] = 0;
    for (int mask = 1; mask < N; mask++) {
        for (int u = 0; u < n; u++) {
            if (!(mask & (1 << u))) continue;
            for (int v = 0; v < n; v++) {
                if (mask & (1 << v)) continue;
                int nm = mask | (1 << v);
                int cand = dp[mask][u] + dist[u][v];
                if (cand < dp[nm][v]) dp[nm][v] = cand;
            }
        }
    }
    int ans = TSP_INF;
    for (int i = 1; i < n; i++) {
        int cand = dp[N - 1][i] + dist[i][0];
        if (cand < ans) ans = cand;
    }
    return ans;
}