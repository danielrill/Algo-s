
---

## randomized_algorithms.h

```c
#ifndef RANDOMIZED_ALGORITHMS_H
#define RANDOMIZED_ALGORITHMS_H

#include <stddef.h>
#include <stdint.h>

/* ============================================================
   Randomized Primality Testing (Miller-Rabin)
   Input:
   - n: zu testende Zahl
   - iterations: Anzahl zufälliger Testdurchläufe
   Output:
   - 1, wenn n wahrscheinlich prim ist
   - 0, wenn n sicher zusammengesetzt ist
   Zweck:
   - Schneller probabilistischer Primzahltest
   ============================================================ */
int is_probably_prime(uint64_t n, int iterations);

/* ============================================================
   Freivalds' Algorithm for Matrix Product Verification
   Input:
   - A, B, C: n x n Matrizen
   - n: Matrixdimension
   - iterations: Anzahl zufälliger Prüfungen
   Output:
   - 1, wenn C wahrscheinlich A*B ist
   - 0, wenn C sicher nicht A*B ist
   Zweck:
   - Probabilistische Verifikation einer Matrixmultiplikation
   ============================================================ */
int freivalds_verify(int **A, int **B, int **C, int n, int iterations);

/* ============================================================
   Randomized Quicksort
   Input:
   - arr: zu sortierendes Array
   - low, high: Bereichsgrenzen
   Output:
   - Array wird in-place sortiert
   Zweck:
   - Effizientes Sortieren mit zufälliger Pivot-Wahl
   ============================================================ */
void randomized_quicksort(int *arr, int low, int high);

/* ============================================================
   Randomized kth Largest Element (Quickselect)
   Input:
   - arr: Array
   - n: Länge
   - k: k-tes größtes Element, 1-basiert
   Output:
   - Wert des k-ten größten Elements
   Zweck:
   - Auswahl eines Rangstatistik-Elements ohne Vollsortierung
   ============================================================ */
int randomized_kth_largest(int *arr, int n, int k);

/* ============================================================
   Karger's Minimum Cut
   Input:
   - vertices: Anzahl Knoten
   - edges_u, edges_v: Endpunkte der Kanten
   - edge_count: Anzahl Kanten
   - trials: Anzahl unabhängiger Wiederholungen
   Output:
   - Größe des kleinsten gefundenen Schnitts
   Zweck:
   - Probabilistische Berechnung eines globalen Min-Cuts
   ============================================================ */
int karger_min_cut(int vertices, const int *edges_u, const int *edges_v, int edge_count, int trials);

/* Hilfsfunktionen für Matrizen */
int **allocate_matrix(int n);
void free_matrix(int **matrix, int n);
void multiply_matrix_classic(int **A, int **B, int **C, int n);

#endif
