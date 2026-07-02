# Divide and Conquer

This folder contains divide-and-conquer implementations in C.

Divide and conquer splits a problem into smaller subproblems, solves them recursively, and combines the results.

Included algorithms:
- Binary Search
- Merge Sort
- Quick Sort
- Karatsuba Multiplication
- Strassen Matrix Multiplication
- Closest Pair of Points
- Convex Hull
- FFT

## Algorithm overview and complexity

| Algorithm | Short explanation | Time complexity |
|---|---|---|
| Binary Search | Repeatedly halves a sorted array to find a target value. | O(log n), Θ(log n), Ω(1) |
| Merge Sort | Recursively splits the array and merges sorted halves. | O(n log n), Θ(n log n), Ω(n log n) |
| Quick Sort | Partitions around a pivot and sorts the subarrays recursively. | O(n^2), Θ(n log n), Ω(n log n) |
| Karatsuba Multiplication | Multiplies large numbers by recursive splitting. | O(n^log2(3)), Θ(n^log2(3)), Ω(n^log2(3)) |
| Strassen Matrix Multiplication | Multiplies matrices using 7 recursive subproducts instead of 8. | O(n^log2(7)), Θ(n^log2(7)), Ω(n^log2(7)) |
| Closest Pair of Points | Splits points by x-coordinate and checks a narrow middle strip. | O(n log n), Θ(n log n), Ω(n log n) |
| Convex Hull | Builds the hull by recursive/geometric divide steps or monotone chain style. | O(n log n), Θ(n log n), Ω(n log n) |
| FFT | Computes the discrete Fourier transform recursively. | O(n log n), Θ(n log n), Ω(n log n) |

This paradigm is especially strong for sorting, searching, matrix multiplication, and geometric problems. In your implementation, quick sort uses a fixed pivot rule, so its worst case remains quadratic [web:33][web:65].