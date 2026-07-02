#include "kruskal.h"
#include <stdlib.h>

static int cmp_edge(const void *a, const void *b) {
    const Edge *x = (const Edge *)a;
    const Edge *y = (const Edge *)b;
    return x->w - y->w;
}

static int find(int parent[], int x) {
    if (parent[x] != x) parent[x] = find(parent, parent[x]);
    return parent[x];
}

static void unite(int parent[], int rank[], int x, int y) {
    x = find(parent, x);
    y = find(parent, y);
    if (x == y) return;
    if (rank[x] < rank[y]) parent[x] = y;
    else if (rank[x] > rank[y]) parent[y] = x;
    else parent[y] = x, rank[x]++;
}

int kruskal_mst(Edge edges[], int m, int n, Edge result[]) {
    qsort(edges, m, sizeof(Edge), cmp_edge);
    int parent[n], rank[n];
    for (int i = 0; i < n; i++) parent[i] = i, rank[i] = 0;
    int count = 0;
    for (int i = 0; i < m && count < n - 1; i++) {
        int ru = find(parent, edges[i].u);
        int rv = find(parent, edges[i].v);
        if (ru != rv) {
            result[count++] = edges[i];
            unite(parent, rank, ru, rv);
        }
    }
    return count;
}