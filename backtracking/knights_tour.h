#ifndef KNIGHTS_TOUR_H
#define KNIGHTS_TOUR_H

#define KT_MAX 20

int knights_tour(int n, int board[KT_MAX][KT_MAX], int sr, int sc);
void print_knights_tour(int n, int board[KT_MAX][KT_MAX]);

#endif