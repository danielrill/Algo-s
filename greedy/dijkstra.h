#ifndef DIJKSTRA_H
#define DIJKSTRA_H

#define DIJKSTRA_MAX 100
#define DIJKSTRA_INF 1000000000

void dijkstra(int n, int graph[DIJKSTRA_MAX][DIJKSTRA_MAX], int src, int dist[], int parent[]);

#endif