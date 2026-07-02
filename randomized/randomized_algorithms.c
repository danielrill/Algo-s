#include "randomized_algorithms.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

/* Tauscht zwei Integer-Werte */
static void swap_int(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

/* Erzeugt eine Zufallszahl im Bereich [min, max] */
static int random_range_int(int min, int max) {
    return min + rand() % (max - min + 1);
}

/* ============================================================
   Miller-Rabin Hilfsfunktionen
   ============================================================ */

/* Führt sichere Multiplikation modulo mod aus, um Overflow zu vermeiden */
static uint64_t mod_mul(uint64_t a, uint64_t b, uint64_t mod) {
    uint64_t result = 0;
    a %= mod;

    while (b > 0) {
        if (b & 1ULL) {
            result = (result + a) % mod;
        }
        a = (a * 2ULL) % mod;
        b >>= 1ULL;
    }

    return result;
}

/* Schnelle modulare Exponentiation: berechnet (base^exp) mod mod */
static uint64_t mod_pow(uint64_t base, uint64_t exp, uint64_t mod) {
    uint64_t result = 1;
    base %= mod;

    while (exp > 0) {
        if (exp & 1ULL) {
            result = mod_mul(result, base, mod);
        }
        base = mod_mul(base, base, mod);
        exp >>= 1ULL;
    }

    return result;
}

/* Prüft, ob a ein Zeuge dafür ist, dass n zusammengesetzt ist */
static int miller_rabin_witness(uint64_t a, uint64_t s, uint64_t d, uint64_t n) {
    uint64_t x = mod_pow(a, d, n);

    if (x == 1 || x == n - 1) {
        return 0;
    }

    for (uint64_t r = 1; r < s; ++r) {
        x = mod_mul(x, x, n);
        if (x == n - 1) {
            return 0;
        }
    }

    return 1;
}

/* Prüft probabilistisch, ob n wahrscheinlich prim ist */
int is_probably_prime(uint64_t n, int iterations) {
    if (n < 2) {
        return 0;
    }
    if (n == 2 || n == 3) {
        return 1;
    }
    if ((n % 2ULL) == 0ULL) {
        return 0;
    }

    uint64_t d = n - 1;
    uint64_t s = 0;

    while ((d % 2ULL) == 0ULL) {
        d /= 2ULL;
        s++;
    }

    for (int i = 0; i < iterations; ++i) {
        uint64_t a = 2ULL + (uint64_t)(rand() % (int)(n > 4 ? (n - 3) : 1));
        if (a >= n) {
            a = n - 2;
        }

        if (miller_rabin_witness(a, s, d, n)) {
            return 0;
        }
    }

    return 1;
}

/* ============================================================
   Matrix-Hilfsfunktionen
   ============================================================ */

/* Reserviert Speicher für eine n x n Matrix */
int **allocate_matrix(int n) {
    int **matrix = (int **)malloc(n * sizeof(int *));
    if (!matrix) {
        return NULL;
    }

    for (int i = 0; i < n; ++i) {
        matrix[i] = (int *)calloc((size_t)n, sizeof(int));
        if (!matrix[i]) {
            for (int j = 0; j < i; ++j) {
                free(matrix[j]);
            }
            free(matrix);
            return NULL;
        }
    }

    return matrix;
}

/* Gibt Speicher einer n x n Matrix frei */
void free_matrix(int **matrix, int n) {
    if (!matrix) {
        return;
    }

    for (int i = 0; i < n; ++i) {
        free(matrix[i]);
    }
    free(matrix);
}

/* Klassische Matrixmultiplikation C = A * B */
void multiply_matrix_classic(int **A, int **B, int **C, int n) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            C[i][j] = 0;
            for (int k = 0; k < n; ++k) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

/* ============================================================
   Freivalds' Algorithm
   ============================================================ */

/* Prüft probabilistisch, ob C = A * B gilt */
int freivalds_verify(int **A, int **B, int **C, int n, int iterations) {
    int *r = (int *)malloc((size_t)n * sizeof(int));
    int *Br = (int *)malloc((size_t)n * sizeof(int));
    int *ABr = (int *)malloc((size_t)n * sizeof(int));
    int *Cr = (int *)malloc((size_t)n * sizeof(int));

    if (!r || !Br || !ABr || !Cr) {
        free(r);
        free(Br);
        free(ABr);
        free(Cr);
        return 0;
    }

    for (int t = 0; t < iterations; ++t) {
        for (int i = 0; i < n; ++i) {
            r[i] = rand() % 2; /* Zufallsvektor aus 0 und 1 */
        }

        for (int i = 0; i < n; ++i) {
            Br[i] = 0;
            Cr[i] = 0;
            for (int j = 0; j < n; ++j) {
                Br[i] += B[i][j] * r[j];
                Cr[i] += C[i][j] * r[j];
            }
        }

        for (int i = 0; i < n; ++i) {
            ABr[i] = 0;
            for (int j = 0; j < n; ++j) {
                ABr[i] += A[i][j] * Br[j];
            }
        }

        for (int i = 0; i < n; ++i) {
            if (ABr[i] != Cr[i]) {
                free(r);
                free(Br);
                free(ABr);
                free(Cr);
                return 0;
            }
        }
    }

    free(r);
    free(Br);
    free(ABr);
    free(Cr);
    return 1;
}

/* ============================================================
   Randomized Quicksort
   ============================================================ */

/* Partitioniert den Bereich und liefert die Pivot-Endposition */
static int partition_randomized(int *arr, int low, int high) {
    int pivot_index = random_range_int(low, high);
    int pivot_value;

    swap_int(&arr[pivot_index], &arr[high]);
    pivot_value = arr[high];

    int i = low - 1;
    for (int j = low; j < high; ++j) {
        if (arr[j] <= pivot_value) {
            i++;
            swap_int(&arr[i], &arr[j]);
        }
    }

    swap_int(&arr[i + 1], &arr[high]);
    return i + 1;
}

/* Sortiert ein Array in-place mit randomisiertem Quicksort */
void randomized_quicksort(int *arr, int low, int high) {
    if (low < high) {
        int pivot = partition_randomized(arr, low, high);
        randomized_quicksort(arr, low, pivot - 1);
        randomized_quicksort(arr, pivot + 1, high);
    }
}

/* ============================================================
   Randomized Quickselect für k-tes größtes Element
   ============================================================ */

/* Liefert das k-te größte Element, k ist 1-basiert */
int randomized_kth_largest(int *arr, int n, int k) {
    int target = n - k; /* Umrechnung auf Index im aufsteigend partitionierten Array */
    int low = 0;
    int high = n - 1;

    while (low <= high) {
        int pivot = partition_randomized(arr, low, high);

        if (pivot == target) {
            return arr[pivot];
        } else if (pivot < target) {
            low = pivot + 1;
        } else {
            high = pivot - 1;
        }
    }

    return 0;
}

/* ============================================================
   Karger's Algorithmus
   ============================================================ */

/* Find-Struktur für Union-Find */
static int uf_find(int *parent, int x) {
    if (parent[x] != x) {
        parent[x] = uf_find(parent, parent[x]); /* Pfadkompression */
    }
    return parent[x];
}

/* Vereinigt zwei Mengen */
static void uf_union(int *parent, int *rank, int a, int b) {
    int root_a = uf_find(parent, a);
    int root_b = uf_find(parent, b);

    if (root_a == root_b) {
        return;
    }

    if (rank[root_a] < rank[root_b]) {
        parent[root_a] = root_b;
    } else if (rank[root_a] > rank[root_b]) {
        parent[root_b] = root_a;
    } else {
        parent[root_b] = root_a;
        rank[root_a]++;
    }
}

/* Führt einen einzelnen Karger-Durchlauf aus */
static int karger_single_run(int vertices, const int *edges_u, const int *edges_v, int edge_count) {
    int *parent = (int *)malloc((size_t)vertices * sizeof(int));
    int *rank = (int *)calloc((size_t)vertices, sizeof(int));
    if (!parent || !rank) {
        free(parent);
        free(rank);
        return -1;
    }

    for (int i = 0; i < vertices; ++i) {
        parent[i] = i;
    }

    int components = vertices;

    while (components > 2) {
        int edge_index = rand() % edge_count;
        int u = edges_u[edge_index];
        int v = edges_v[edge_index];

        int set_u = uf_find(parent, u);
        int set_v = uf_find(parent, v);

        if (set_u != set_v) {
            uf_union(parent, rank, set_u, set_v);
            components--;
        }
    }

    int cut_edges = 0;
    for (int i = 0; i < edge_count; ++i) {
        int set_u = uf_find(parent, edges_u[i]);
        int set_v = uf_find(parent, edges_v[i]);

        if (set_u != set_v) {
            cut_edges++;
        }
    }

    free(parent);
    free(rank);
    return cut_edges;
}

/* Wiederholt Karger mehrfach und liefert den besten gefundenen Schnitt */
int karger_min_cut(int vertices, const int *edges_u, const int *edges_v, int edge_count, int trials) {
    int best_cut = -1;

    for (int i = 0; i < trials; ++i) {
        int cut = karger_single_run(vertices, edges_u, edges_v, edge_count);
        if (cut >= 0 && (best_cut == -1 || cut < best_cut)) {
            best_cut = cut;
        }
    }

    return best_cut;
}
