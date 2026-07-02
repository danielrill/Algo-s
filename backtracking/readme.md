# Backtracking

This folder contains backtracking implementations in C.

Backtracking tries partial solutions, and if a choice leads to a dead end, it undoes it and tries another option.

Included algorithms:
- N-Queens
- Sudoku Solver
- Hamiltonian Cycle
- Graph Coloring
- Subset Sum
- Knight's Tour

## Algorithm overview and complexity

| Algorithm | Short explanation | Time complexity |
|---|---|---|
| N-Queens | Places queens row by row while rejecting unsafe placements. | O(n!), Θ(n!), Ω(n!) |
| Sudoku Solver | Fills empty cells with valid numbers and backtracks on conflicts. | O(9^(empty cells)), Θ(9^(empty cells)), Ω(1) |
| Hamiltonian Cycle | Tries to build a cycle visiting every vertex exactly once. | O(V!), Θ(V!), Ω(V!) |
| Graph Coloring | Assigns colors to vertices so adjacent vertices differ. | O(m^V), Θ(m^V), Ω(1) |
| Subset Sum | Tries subsets recursively to match a target sum. | O(2^n), Θ(2^n), Ω(1) |
| Knight's Tour | Searches for a full knight move tour on the board. | O(8^(n^2)), Θ(8^(n^2)), Ω(1) |

Backtracking is powerful for constraint satisfaction problems, but worst-case runtime is usually exponential. It is often practical only with pruning or on small to medium input sizes [web:50][web:53][web:57].