#include <stdio.h>
#include "binary_search.h"
#include "merge_sort.h"
#include "quick_sort.h"
#include "karatsuba.h"
#include "strassen.h"
#include "closest_pair.h"
#include "convex_hull.h"
#include "fft.h"

"""
gcc 
test_divide_and_conquer.c binary_search.c
merge_sort.c quick_sort.c karatsuba.c strassen.c closest_pair.c convex_hull.c fft.c -lm -o test_divide_and_conquer
"""

int main(void) {
    int a[] = {7, 2, 9, 1, 5};
    merge_sort(a, 0, 4);
    printf("Merge sort: ");
    for (int i = 0; i < 5; i++) printf("%d ", a[i]);
    printf("\n");

    int b[] = {7, 2, 9, 1, 5};
    quick_sort(b, 0, 4);
    printf("Quick sort: ");
    for (int i = 0; i < 5; i++) printf("%d ", b[i]);
    printf("\n");

    int c[] = {1, 3, 5, 7, 9};
    printf("Binary search 7: %d\n", binary_search(c, 5, 7));
    printf("Karatsuba 1234*5678 = %lld\n", karatsuba(1234, 5678));

    int A[STRASSEN_MAX][STRASSEN_MAX] = {{0}}, B[STRASSEN_MAX][STRASSEN_MAX] = {{0}}, C[STRASSEN_MAX][STRASSEN_MAX] = {{0}};
    A[0][0]=1; A[0][1]=2; A[1][0]=3; A[1][1]=4;
    B[0][0]=5; B[0][1]=6; B[1][0]=7; B[1][1]=8;
    strassen_multiply(2, A, B, C);
    printf("Strassen: %d %d %d %d\n", C[0][0], C[0][1], C[1][0], C[1][1]);

    Point pts[] = {{2,3},{12,30},{40,50},{5,1},{12,10},{3,4}};
    printf("Closest pair: %.3f\n", closest_pair(pts, 6));

    Point hull_in[] = {{0,3},{2,2},{1,1},{2,1},{3,0},{0,0},{3,3}};
    Point hull[20];
    int hn = convex_hull(hull_in, 7, hull);
    printf("Convex hull: ");
    for (int i = 0; i < hn; i++) printf("(%.0f,%.0f) ", hull[i].x, hull[i].y);
    printf("\n");

    Complex f[] = {{1,0},{2,0},{3,0},{4,0}};
    fft(f, 4, 0);
    printf("FFT: ");
    for (int i = 0; i < 4; i++) printf("(%.2f,%.2f) ", f[i].re, f[i].im);
    printf("\n");
    return 0;
}