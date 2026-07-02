#include "sudoku.h"
#include <stdio.h>

static int is_valid(int board[9][9], int row, int col, int num) {
    for (int x = 0; x < 9; x++) if (board[row][x] == num || board[x][col] == num) return 0;
    int sr = row - row % 3, sc = col - col % 3;
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (board[sr + i][sc + j] == num) return 0;
    return 1;
}

static int solve_util(int board[9][9]) {
    for (int row = 0; row < 9; row++) {
        for (int col = 0; col < 9; col++) {
            if (board[row][col] == 0) {
                for (int num = 1; num <= 9; num++) {
                    if (is_valid(board, row, col, num)) {
                        board[row][col] = num;
                        if (solve_util(board)) return 1;
                        board[row][col] = 0;
                    }
                }
                return 0;
            }
        }
    }
    return 1;
}

int solve_sudoku(int board[9][9]) {
    return solve_util(board);
}

void print_sudoku(int board[9][9]) {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) printf("%d ", board[i][j]);
        printf("\n");
    }
}