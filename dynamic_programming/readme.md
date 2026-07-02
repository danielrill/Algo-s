# Dynamic Programming

This folder contains dynamic programming implementations in C.

Dynamic programming solves problems by storing results of overlapping subproblems and reusing them.

Included algorithms:
- Fibonacci
- 0-1 Knapsack
- Longest Common Subsequence
- Longest Increasing Subsequence
- Matrix Chain Multiplication
- Edit Distance
- Rod Cutting
- Floyd-Warshall
- Coin Change
- Subset Sum DP
- Traveling Salesman Problem (bitmask DP)

## Algorithm overview and complexity

| Algorithm | Short explanation | Time complexity |
|---|---|---|
| Fibonacci | Computes Fibonacci numbers iteratively using stored previous results. | O(n), Θ(n), Ω(n) |
| 0-1 Knapsack | Chooses items to maximize value under a capacity constraint. | O(nW), Θ(nW), Ω(nW) |
| LCS | Finds the longest subsequence common to two strings. | O(nm), Θ(nm), Ω(nm) |
| LIS | Finds the longest increasing subsequence in an array. | O(n^2), Θ(n^2), Ω(n^2) |
| Matrix Chain Multiplication | Finds the cheapest way to parenthesize matrix products. | O(n^3), Θ(n^3), Ω(n^3) |
| Edit Distance | Computes minimum insert/delete/replace operations between strings. | O(nm), Θ(nm), Ω(nm) |
| Rod Cutting | Maximizes revenue by cutting a rod into pieces. | O(n^2), Θ(n^2), Ω(n^2) |
| Floyd-Warshall | Computes all-pairs shortest paths. | O(V^3), Θ(V^3), Ω(V^3) |
| Coin Change | Finds the minimum number of coins for a target amount. | O(amount·coins), Θ(amount·coins), Ω(amount·coins) |
| Subset Sum DP | Checks whether a subset reaches a target sum. | O(nS), Θ(nS), Ω(nS) |
| TSP DP | Solves TSP with bitmask dynamic programming. | O(n^2 2^n), Θ(n^2 2^n), Ω(n^2 2^n) |

DP is useful when the same subproblems appear many times and optimal substructure holds. The tradeoff is usually higher memory usage, because the table of subproblem answers must be stored [web:39][web:47].