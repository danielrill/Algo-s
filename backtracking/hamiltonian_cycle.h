#ifndef HAMILTONIAN_CYCLE_H
#define HAMILTONIAN_CYCLE_H

#define HC_MAX 20

int solve_hamiltonian_cycle(int n, int graph[HC_MAX][HC_MAX], int path[]);
void print_hamiltonian_cycle(int n, int path[]);

#endif