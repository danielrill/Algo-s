#include <stdio.h>
#include "activity_selection.h"
#include "huffman.h"
#include "prim.h"
#include "kruskal.h"
#include "dijkstra.h"
#include "fractional_knapsack.h"
#include "set_cover_approx.h"
#include "bin_packing_approx.h"


"""
gcc 
test_greedy.c activity_selection.c huffman.c prim.c kruskal.c 
dijkstra.c fractional_knapsack.c set_cover_approx.c bin_packing_approx.c -o test_greedy
"""

int main(void) {
    Activity acts[] = {{1,2,1},{3,4,2},{0,6,3},{5,7,4},{8,9,5},{5,9,6}};
    int selected[10];
    int cnt = activity_selection(acts, 6, selected);
    printf("Activity Selection: ");
    for (int i = 0; i < cnt; i++) printf("%d ", selected[i]);
    printf("\n");

    char chars[] = {'a','b','c','d','e','f'};
    int freq[] = {5,9,12,13,16,45};
    HuffmanNode *root = huffman_build(chars, freq, 6);
    int arr[100];
    printf("Huffman Codes:\n");
    huffman_print_codes(root, arr, 0);
    huffman_free(root);

    int graph[PRIM_MAX][PRIM_MAX] = {{0}};
    graph[0][1]=2; graph[1][0]=2; graph[0][3]=6; graph[3][0]=6;
    graph[1][2]=3; graph[2][1]=3; graph[1][3]=8; graph[3][1]=8;
    graph[1][4]=5; graph[4][1]=5; graph[2][4]=7; graph[4][2]=7;
    graph[3][4]=9; graph[4][3]=9;
    int parent[5];
    prim_mst(5, graph, parent);
    printf("Prim parent array: ");
    for (int i = 0; i < 5; i++) printf("%d ", parent[i]);
    printf("\n");

    Edge edges[] = {{0,1,2},{0,3,6},{1,2,3},{1,3,8},{1,4,5},{2,4,7},{3,4,9}};
    Edge res[10];
    int ecount = kruskal_mst(edges, 7, 5, res);
    printf("Kruskal edges: ");
    for (int i = 0; i < ecount; i++) printf("(%d,%d,%d) ", res[i].u, res[i].v, res[i].w);
    printf("\n");

    int dg[DIJKSTRA_MAX][DIJKSTRA_MAX] = {{0}};
    dg[0][1]=10; dg[0][2]=3; dg[1][2]=1; dg[1][3]=2; dg[2][1]=4; dg[2][3]=8; dg[2][4]=2; dg[3][4]=7; dg[4][3]=9;
    int dist[5], par[5];
    dijkstra(5, dg, 0, dist, par);
    printf("Dijkstra dist: ");
    for (int i = 0; i < 5; i++) printf("%d ", dist[i]);
    printf("\n");

    Item items[] = {{60,10,0},{100,20,0},{120,30,0}};
    double best = fractional_knapsack(items, 3, 50);
    printf("Fractional knapsack: %.2f\n", best);

    unsigned long long universe = (1ULL<<5)-1;
    unsigned long long sets[] = {(1ULL<<0)|(1ULL<<1), (1ULL<<1)|(1ULL<<2)|(1ULL<<3), (1ULL<<3)|(1ULL<<4)};
    int chosen[10];
    int sc = set_cover_approx(universe, sets, 3, chosen);
    printf("Set cover chosen: ");
    for (int i = 0; i < sc; i++) printf("%d ", chosen[i]);
    printf("\n");

    int weights[] = {4,8,1,4,2,1};
    int bin_of_item[6];
    int bins = bin_packing_first_fit(weights, 6, 10, bin_of_item);
    printf("Bins used: %d\n", bins);
    return 0;
}