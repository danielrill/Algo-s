#include "strassen.h"
#include <string.h>

static void add(int n, int A[STRASSEN_MAX][STRASSEN_MAX], int B[STRASSEN_MAX][STRASSEN_MAX], int C[STRASSEN_MAX][STRASSEN_MAX]) {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            C[i][j] = A[i][j] + B[i][j];
}

static void sub(int n, int A[STRASSEN_MAX][STRASSEN_MAX], int B[STRASSEN_MAX][STRASSEN_MAX], int C[STRASSEN_MAX][STRASSEN_MAX]) {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            C[i][j] = A[i][j] - B[i][j];
}

void strassen_multiply(int n, int A[STRASSEN_MAX][STRASSEN_MAX], int B[STRASSEN_MAX][STRASSEN_MAX], int C[STRASSEN_MAX][STRASSEN_MAX]) {
    if (n <= 2) {
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++) {
                C[i][j] = 0;
                for (int k = 0; k < n; k++) C[i][j] += A[i][k] * B[k][j];
            }
        return;
    }
    int m = n / 2;
    int A11[STRASSEN_MAX][STRASSEN_MAX] = {{0}}, A12[STRASSEN_MAX][STRASSEN_MAX] = {{0}};
    int A21[STRASSEN_MAX][STRASSEN_MAX] = {{0}}, A22[STRASSEN_MAX][STRASSEN_MAX] = {{0}};
    int B11[STRASSEN_MAX][STRASSEN_MAX] = {{0}}, B12[STRASSEN_MAX][STRASSEN_MAX] = {{0}};
    int B21[STRASSEN_MAX][STRASSEN_MAX] = {{0}}, B22[STRASSEN_MAX][STRASSEN_MAX] = {{0}};
    for (int i = 0; i < m; i++) for (int j = 0; j < m; j++) {
        A11[i][j]=A[i][j]; A12[i][j]=A[i][j+m]; A21[i][j]=A[i+m][j]; A22[i][j]=A[i+m][j+m];
        B11[i][j]=B[i][j]; B12[i][j]=B[i][j+m]; B21[i][j]=B[i+m][j]; B22[i][j]=B[i+m][j+m];
    }
    int M1[STRASSEN_MAX][STRASSEN_MAX] = {{0}}, M2[STRASSEN_MAX][STRASSEN_MAX] = {{0}}, M3[STRASSEN_MAX][STRASSEN_MAX] = {{0}}, M4[STRASSEN_MAX][STRASSEN_MAX] = {{0}}, M5[STRASSEN_MAX][STRASSEN_MAX] = {{0}}, M6[STRASSEN_MAX][STRASSEN_MAX] = {{0}}, M7[STRASSEN_MAX][STRASSEN_MAX] = {{0}};
    int T1[STRASSEN_MAX][STRASSEN_MAX] = {{0}}, T2[STRASSEN_MAX][STRASSEN_MAX] = {{0}};
    add(m, A11, A22, T1); add(m, B11, B22, T2); strassen_multiply(m, T1, T2, M1);
    add(m, A21, A22, T1); strassen_multiply(m, T1, B11, M2);
    sub(m, B12, B22, T2); strassen_multiply(m, A11, T2, M3);
    sub(m, B21, B11, T2); strassen_multiply(m, A22, T2, M4);
    add(m, A11, A12, T1); strassen_multiply(m, T1, B22, M5);
    sub(m, A21, A11, T1); add(m, B11, B12, T2); strassen_multiply(m, T1, T2, M6);
    sub(m, A12, A22, T1); add(m, B21, B22, T2); strassen_multiply(m, T1, T2, M7);
    int C11[STRASSEN_MAX][STRASSEN_MAX] = {{0}}, C12[STRASSEN_MAX][STRASSEN_MAX] = {{0}}, C21[STRASSEN_MAX][STRASSEN_MAX] = {{0}}, C22[STRASSEN_MAX][STRASSEN_MAX] = {{0}};
    for (int i = 0; i < m; i++) for (int j = 0; j < m; j++) {
        C11[i][j] = M1[i][j] + M4[i][j] - M5[i][j] + M7[i][j];
        C12[i][j] = M3[i][j] + M5[i][j];
        C21[i][j] = M2[i][j] + M4[i][j];
        C22[i][j] = M1[i][j] - M2[i][j] + M3[i][j] + M6[i][j];
        C[i][j] = C11[i][j];
        C[i][j+m] = C12[i][j];
        C[i+m][j] = C21[i][j];
        C[i+m][j+m] = C22[i][j];
    }
}