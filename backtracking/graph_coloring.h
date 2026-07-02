#ifndef GRAPH_COLORING_H
#define GRAPH_COLORING_H

#define GC_MAX 20

int graph_coloring(int n, int graph[GC_MAX][GC_MAX], int m, int color[]);
void print_graph_coloring(int n, int color[]);

#endif