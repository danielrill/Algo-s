#include "n_queens.h"
#include <stdio.h>

static int is_safe(int n, int board[][20], int row, int col) {
    for (int i = 0; i < col; i++) if (board[row][i]) return 0;
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) if (board[i][j]) return 0;
    for (int i = row, j = col; i < n && j >= 0; i++, j--) if (board[i][j]) return 0;
    return 1;
}

static int solve_util(int n, int board[][20], int col) {
    if (col >= n) return 1;
    for (int i = 0; i < n; i++) {
        if (is_safe(n, board, i, col)) {
            board[i][col] = 1;
            if (solve_util(n, board, col + 1)) return 1;
            board[i][col] = 0;
        }
    }
    return 0;
}

int solve_n_queens(int n, int board[][20]) {
    for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) board[i][j] = 0;
    return solve_util(n, board, 0);
}

void print_n_queens(int n, int board[][20]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) printf("%d ", board[i][j]);
        printf("\n");
    }
}