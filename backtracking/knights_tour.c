#include "knights_tour.h"
#include <stdio.h>

static int dx[8] = {2,1,-1,-2,-2,-1,1,2};
static int dy[8] = {1,2,2,1,-1,-2,-2,-1};

static int is_safe(int n, int board[KT_MAX][KT_MAX], int x, int y) {
    return x >= 0 && y >= 0 && x < n && y < n && board[x][y] == -1;
}

static int util(int n, int board[KT_MAX][KT_MAX], int x, int y, int movei) {
    if (movei == n * n) return 1;
    for (int k = 0; k < 8; k++) {
        int nx = x + dx[k], ny = y + dy[k];
        if (is_safe(n, board, nx, ny)) {
            board[nx][ny] = movei;
            if (util(n, board, nx, ny, movei + 1)) return 1;
            board[nx][ny] = -1;
        }
    }
    return 0;
}

int knights_tour(int n, int board[KT_MAX][KT_MAX], int sr, int sc) {
    for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) board[i][j] = -1;
    board[sr][sc] = 0;
    return util(n, board, sr, sc, 1);
}

void print_knights_tour(int n, int board[KT_MAX][KT_MAX]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) printf("%2d ", board[i][j]);
        printf("\n");
    }
}