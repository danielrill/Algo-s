#include "graph_coloring.h"
#include <stdio.h>

static int is_safe(int v, int graph[GC_MAX][GC_MAX], int color[], int c, int n) {
    for (int i = 0; i < n; i++) if (graph[v][i] && color[i] == c) return 0;
    return 1;
}

static int util(int n, int graph[GC_MAX][GC_MAX], int m, int color[], int v) {
    if (v == n) return 1;
    for (int c = 1; c <= m; c++) {
        if (is_safe(v, graph, color, c, n)) {
            color[v] = c;
            if (util(n, graph, m, color, v + 1)) return 1;
            color[v] = 0;
        }
    }
    return 0;
}

int graph_coloring(int n, int graph[GC_MAX][GC_MAX], int m, int color[]) {
    for (int i = 0; i < n; i++) color[i] = 0;
    return util(n, graph, m, color, 0);
}

void print_graph_coloring(int n, int color[]) {
    for (int i = 0; i < n; i++) printf("%d ", color[i]);
    printf("\n");
}