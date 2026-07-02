#include "closest_pair.h"
#include <stdlib.h>
#include <math.h>

static double dist(Point a, Point b) {
    double dx = a.x - b.x, dy = a.y - b.y;
    return sqrt(dx * dx + dy * dy);
}

static int cmpx(const void *a, const void *b) {
    Point *p = (Point *)a, *q = (Point *)b;
    return (p->x > q->x) - (p->x < q->x);
}

static double brute(Point pts[], int n) {
    double best = 1e100;
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++) {
            double d = dist(pts[i], pts[j]);
            if (d < best) best = d;
        }
    return best;
}

static double rec(Point pts[], int n) {
    if (n <= 3) return brute(pts, n);
    int mid = n / 2;
    double dl = rec(pts, mid);
    double dr = rec(pts + mid, n - mid);
    double d = dl < dr ? dl : dr;
    Point strip[1024];
    int m = 0;
    for (int i = 0; i < n; i++) if (fabs(pts[i].x - pts[mid].x) < d) strip[m++] = pts[i];
    for (int i = 0; i < m; i++)
        for (int j = i + 1; j < m && (strip[j].y - strip[i].y) < d; j++) {
            double dd = dist(strip[i], strip[j]);
            if (dd < d) d = dd;
        }
    return d;
}

double closest_pair(Point pts[], int n) {
    qsort(pts, n, sizeof(Point), cmpx);
    return rec(pts, n);
}