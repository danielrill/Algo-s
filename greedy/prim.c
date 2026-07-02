#include "prim.h"
#include <limits.h>

void prim_mst(int n, int graph[PRIM_MAX][PRIM_MAX], int parent[]) {
    int key[PRIM_MAX];
    int mst[PRIM_MAX] = {0};
    for (int i = 0; i < n; i++) {
        key[i] = INT_MAX;
        parent[i] = -1;
    }
    key[0] = 0;
    for (int c = 0; c < n - 1; c++) {
        int min = INT_MAX, u = -1;
        for (int v = 0; v < n; v++)
            if (!mst[v] && key[v] < min) min = key[v], u = v;
        mst[u] = 1;
        for (int v = 0; v < n; v++) {
            if (graph[u][v] && !mst[v] && graph[u][v] < key[v]) {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }
}