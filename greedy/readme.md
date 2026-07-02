# Greedy Algorithms

This folder contains greedy algorithm implementations in C.

A greedy algorithm makes the locally best choice at each step and tries to build a globally good solution.

Included algorithms:
- Activity Selection
- Huffman Coding
- Prim's MST
- Kruskal's MST
- Dijkstra's Shortest Path
- Fractional Knapsack
- Set Cover Approximation
- Bin Packing Approximation

## Algorithm overview and complexity

| Algorithm | Short explanation | Time complexity |
|---|---|---|
| Activity Selection | Selects the maximum number of non-overlapping activities by sorting by finish time. | O(n log n), Θ(n log n), Ω(n log n) |
| Huffman Coding | Builds an optimal prefix code by repeatedly merging the two least frequent nodes. | O(n log n), Θ(n log n), Ω(n log n) |
| Prim's MST | Grows a minimum spanning tree by repeatedly adding the cheapest connecting edge. | O(V^2) in this implementation, Θ(V^2), Ω(V^2) |
| Kruskal's MST | Sorts edges and adds the next smallest edge that does not form a cycle. | O(E log E), Θ(E log E), Ω(E log E) |
| Dijkstra's Shortest Path | Finds shortest paths from one source with non-negative edge weights. | O(V^2) in this implementation, Θ(V^2), Ω(V^2) |
| Fractional Knapsack | Takes items by highest value-to-weight ratio and may take fractions. | O(n log n), Θ(n log n), Ω(n log n) |
| Set Cover Approximation | Repeatedly picks the set covering the most uncovered elements. | O(m·u), Θ(m·u), Ω(m·u) |
| Bin Packing Approximation | Places items into the first bin that fits. | O(n^2), Θ(n^2), Ω(n) |

The greedy approach works well when local choices can be proved to lead to a good or optimal result, such as activity selection or MST construction. It is not always optimal for 0-1 knapsack or set cover, which is why some problems only have approximation versions [web:25][web:61].