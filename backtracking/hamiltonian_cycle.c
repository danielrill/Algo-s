#include "hamiltonian_cycle.h"
#include <stdio.h>

static int is_safe(int v, int graph[HC_MAX][HC_MAX], int path[], int pos) {
    if (!graph[path[pos - 1]][v]) return 0;
    for (int i = 0; i < pos; i++) if (path[i] == v) return 0;
    return 1;
}

static int util(int n, int graph[HC_MAX][HC_MAX], int path[], int pos) {
    if (pos == n) return graph[path[pos - 1]][path[0]];
    for (int v = 1; v < n; v++) {
        if (is_safe(v, graph, path, pos)) {
            path[pos] = v;
            if (util(n, graph, path, pos + 1)) return 1;
            path[pos] = -1;
        }
    }
    return 0;
}

int solve_hamiltonian_cycle(int n, int graph[HC_MAX][HC_MAX], int path[]) {
    for (int i = 0; i < n; i++) path[i] = -1;
    path[0] = 0;
    return util(n, graph, path, 1);
}

void print_hamiltonian_cycle(int n, int path[]) {
    for (int i = 0; i < n; i++) printf("%d ", path[i]);
    printf("%d\n", path[0]);
}