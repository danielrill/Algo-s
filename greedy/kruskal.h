#ifndef KRUSKAL_H
#define KRUSKAL_H

#define KRUSKAL_MAX_EDGES 1000

typedef struct {
    int u, v, w;
} Edge;

int kruskal_mst(Edge edges[], int m, int n, Edge result[]);

#endif