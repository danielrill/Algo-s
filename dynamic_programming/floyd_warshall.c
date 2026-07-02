#include "floyd_warshall.h"

void floyd_warshall(int n, int dist[FW_MAX][FW_MAX]) {
    for (int k = 0; k < n; k++)
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                if (dist[i][k] < FW_INF && dist[k][j] < FW_INF &&
                    dist[i][k] + dist[k][j] < dist[i][j])
                    dist[i][j] = dist[i][k] + dist[k][j];
}