#include <stdio.h>
#include "n_queens.h"
#include "sudoku.h"
#include "hamiltonian_cycle.h"
#include "graph_coloring.h"
#include "subset_sum_bt.h"
#include "knights_tour.h"

"""
gcc test_backtracking.c n_queens.c sudoku.c hamiltonian_cycle.c graph_coloring.c subset_sum_bt.c knights_tour.c -o test_backtracking
"""

int main(void) {
    int nq[20][20];
    if (solve_n_queens(4, nq)) {
        printf("N-Queens:\n");
        print_n_queens(4, nq);
    }

    int sudoku_board[9][9] = {
        {3,0,6,5,0,8,4,0,0},
        {5,2,0,0,0,0,0,0,0},
        {0,8,7,0,0,0,0,3,1},
        {0,0,3,0,1,0,0,8,0},
        {9,0,0,8,6,3,0,0,5},
        {0,5,0,0,9,0,6,0,0},
        {1,3,0,0,0,0,2,5,0},
        {0,0,0,0,0,0,0,7,4},
        {0,0,5,2,0,6,3,0,0}
    };
    if (solve_sudoku(sudoku_board)) {
        printf("Sudoku:\n");
        print_sudoku(sudoku_board);
    }

    int graph[HC_MAX][HC_MAX] = {{0}};
    graph[0][1]=graph[1][0]=1;
    graph[1][2]=graph[2][1]=1;
    graph[2][3]=graph[3][2]=1;
    graph[3][0]=graph[0][3]=1;
    graph[0][2]=graph[2][0]=1;
    int path[HC_MAX];
    if (solve_hamiltonian_cycle(4, graph, path)) {
        printf("Hamiltonian cycle:\n");
        print_hamiltonian_cycle(4, path);
    }

    int gc[GC_MAX][GC_MAX] = {{0}};
    gc[0][1]=gc[1][0]=1;
    gc[1][2]=gc[2][1]=1;
    gc[2][3]=gc[3][2]=1;
    gc[3][0]=gc[0][3]=1;
    gc[0][2]=gc[2][0]=1;
    int color[GC_MAX];
    if (graph_coloring(4, gc, 3, color)) {
        printf("Graph coloring:\n");
        print_graph_coloring(4, color);
    }

    int arr[] = {3, 34, 4, 12, 5, 2};
    int chosen[SS_MAX];
    if (subset_sum_bt(arr, 6, 9, chosen)) {
        printf("Subset sum found.\n");
    }

    int kt[KT_MAX][KT_MAX];
    if (knights_tour(5, kt, 0, 0)) {
        printf("Knight's tour:\n");
        print_knights_tour(5, kt);
    }
    return 0;
}