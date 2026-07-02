#ifndef CLOSEST_PAIR_H
#define CLOSEST_PAIR_H

typedef struct {
    double x, y;
} Point;

double closest_pair(Point pts[], int n);

#endif