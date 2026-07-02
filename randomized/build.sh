#!/bin/sh
gcc -std=c11 -O2 -Wall -Wextra -pedantic randomized_algorithms.c test_randomized_algorithms.c -o randomized_algorithms_test
