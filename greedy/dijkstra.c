#include "dijkstra.h"

void dijkstra(int n, int graph[DIJKSTRA_MAX][DIJKSTRA_MAX], int src, int dist[], int parent[]) {
    int vis[DIJKSTRA_MAX] = {0};
    for (int i = 0; i < n; i++) {
        dist[i] = DIJKSTRA_INF;
        parent[i] = -1;
    }
    dist[src] = 0;
    for (int c = 0; c < n; c++) {
        int u = -1, best = DIJKSTRA_INF;
        for (int i = 0; i < n; i++)
            if (!vis[i] && dist[i] < best) best = dist[i], u = i;
        if (u == -1) break;
        vis[u] = 1;
        for (int v = 0; v < n; v++) {
            if (graph[u][v] > 0 && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
                parent[v] = u;
            }
        }
    }
}