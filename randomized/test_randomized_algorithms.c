#include "randomized_algorithms.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

static double elapsed_ms(clock_t start, clock_t end) {
    return ((double)(end - start) * 1000.0) / (double)CLOCKS_PER_SEC;
}

static void print_separator(const char *title) {
    printf("\n============================================================\n");
    printf("%s\n", title);
    printf("============================================================\n");
}

static void print_array(const int *arr, int n) {
    printf("[");
    for (int i = 0; i < n; ++i) {
        printf("%d", arr[i]);
        if (i + 1 < n) {
            printf(", ");
        }
    }
    printf("]\n");
}

static void test_primality(void) {
    print_separator("1. Randomized Primality Testing (Miller-Rabin)");

    uint64_t test_numbers[] = {
        2ULL, 3ULL, 4ULL, 5ULL, 17ULL, 19ULL, 21ULL, 97ULL, 561ULL, 1105ULL, 7919ULL
    };
    int count = (int)(sizeof(test_numbers) / sizeof(test_numbers[0]));
    int iterations = 10;

    for (int i = 0; i < count; ++i) {
        clock_t start = clock();
        int result = is_probably_prime(test_numbers[i], iterations);
        clock_t end = clock();

        printf("n = %-6llu | Ergebnis: %-18s | Laufzeit: %8.3f ms\n",
               (unsigned long long)test_numbers[i],
               result ? "wahrscheinlich prim" : "zusammengesetzt",
               elapsed_ms(start, end));
    }
}

static void test_freivalds(void) {
    print_separator("2. Freivalds' Algorithm for Matrix Product Verification");

    int n = 3;
    int iterations = 8;

    int **A = allocate_matrix(n);
    int **B = allocate_matrix(n);
    int **C = allocate_matrix(n);
    int **WrongC = allocate_matrix(n);

    if (!A || !B || !C || !WrongC) {
        printf("Fehler bei Matrixspeicher.\n");
        free_matrix(A, n);
        free_matrix(B, n);
        free_matrix(C, n);
        free_matrix(WrongC, n);
        return;
    }

    int a_data[3][3] = {
        {1, 2, 3},
        {0, 1, 4},
        {5, 6, 0}
    };

    int b_data[3][3] = {
        {7, 8, 9},
        {2, 3, 4},
        {1, 0, 2}
    };

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            A[i][j] = a_data[i][j];
            B[i][j] = b_data[i][j];
        }
    }

    multiply_matrix_classic(A, B, C, n);
    multiply_matrix_classic(A, B, WrongC, n);
    WrongC[1][1] += 1; /* Absichtlich Fehler einbauen */

    clock_t start_ok = clock();
    int result_ok = freivalds_verify(A, B, C, n, iterations);
    clock_t end_ok = clock();

    clock_t start_bad = clock();
    int result_bad = freivalds_verify(A, B, WrongC, n, iterations);
    clock_t end_bad = clock();

    printf("Korrekte Matrix C   | Ergebnis: %-12s | Laufzeit: %8.3f ms\n",
           result_ok ? "akzeptiert" : "abgelehnt",
           elapsed_ms(start_ok, end_ok));

    printf("Falsche Matrix C    | Ergebnis: %-12s | Laufzeit: %8.3f ms\n",
           result_bad ? "akzeptiert" : "abgelehnt",
           elapsed_ms(start_bad, end_bad));

    free_matrix(A, n);
    free_matrix(B, n);
    free_matrix(C, n);
    free_matrix(WrongC, n);
}

static void test_randomized_quicksort(void) {
    print_separator("3. Randomized Quicksort");

    int arr[] = {9, 4, 7, 3, 1, 2, 8, 5, 6, 0};
    int n = (int)(sizeof(arr) / sizeof(arr[0]));

    printf("Vorher: ");
    print_array(arr, n);

    clock_t start = clock();
    randomized_quicksort(arr, 0, n - 1);
    clock_t end = clock();

    printf("Nachher: ");
    print_array(arr, n);
    printf("Laufzeit: %.3f ms\n", elapsed_ms(start, end));
}

static void test_kth_largest(void) {
    print_separator("4. Randomized Computation of kth Largest Element");

    int original[] = {12, 3, 5, 7, 19, 26, 4, 11};
    int n = (int)(sizeof(original) / sizeof(original[0]));
    int k_values[] = {1, 2, 3, 5, 8};
    int k_count = (int)(sizeof(k_values) / sizeof(k_values[0]));

    printf("Array: ");
    print_array(original, n);

    for (int i = 0; i < k_count; ++i) {
        int k = k_values[i];
        int temp[8];
        memcpy(temp, original, sizeof(original));

        clock_t start = clock();
        int value = randomized_kth_largest(temp, n, k);
        clock_t end = clock();

        printf("k = %d | %d-tes groesstes Element = %d | Laufzeit: %8.3f ms\n",
               k, k, value, elapsed_ms(start, end));
    }
}

static void test_karger(void) {
    print_separator("5. Karger's Algorithm for Minimum Cut");

    /* Beispielgraph:
       0--1
       |\ |
       | \|
       2--3

       Kanten:
       (0,1), (0,2), (0,3), (1,3), (2,3)
       Ein Min-Cut hat hier Groesse 2.
    */
    int vertices = 4;
    int edges_u[] = {0, 0, 0, 1, 2};
    int edges_v[] = {1, 2, 3, 3, 3};
    int edge_count = (int)(sizeof(edges_u) / sizeof(edges_u[0]));
    int trials = 50;

    clock_t start = clock();
    int min_cut = karger_min_cut(vertices, edges_u, edges_v, edge_count, trials);
    clock_t end = clock();

    printf("Knoten: %d | Kanten: %d | Wiederholungen: %d\n", vertices, edge_count, trials);
    printf("Gefundener Min-Cut: %d\n", min_cut);
    printf("Laufzeit: %.3f ms\n", elapsed_ms(start, end));
}

int main(void) {
    srand((unsigned int)time(NULL));

    printf("Testprogramm fuer randomisierte Algorithmen in C\n");
    printf("Zufallsbasierte Algorithmen koennen bei jedem Lauf leicht variieren.\n");

    test_primality();
    test_freivalds();
    test_randomized_quicksort();
    test_kth_largest();
    test_karger();

    printf("\nAlle Tests abgeschlossen.\n");
    return 0;
}
