#ifndef STRASSEN_H
#define STRASSEN_H

#define STRASSEN_MAX 64

void strassen_multiply(int n, int A[STRASSEN_MAX][STRASSEN_MAX], int B[STRASSEN_MAX][STRASSEN_MAX], int C[STRASSEN_MAX][STRASSEN_MAX]);

#endif