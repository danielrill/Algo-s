#include "convex_hull.h"
#include <stdlib.h>

static double cross(Point O, Point A, Point B) {
    return (A.x - O.x) * (B.y - O.y) - (A.y - O.y) * (B.x - O.x);
}

static int cmp_point(const void *a, const void *b) {
    const Point *p = (const Point *)a;
    const Point *q = (const Point *)b;
    if (p->x != q->x) return (p->x > q->x) - (p->x < q->x);
    return (p->y > q->y) - (p->y < q->y);
}

int convex_hull(Point pts[], int n, Point hull[]) {
    qsort(pts, n, sizeof(Point), cmp_point);
    int k = 0;
    for (int i = 0; i < n; i++) {
        while (k >= 2 && cross(hull[k - 2], hull[k - 1], pts[i]) <= 0) k--;
        hull[k++] = pts[i];
    }
    int t = k + 1;
    for (int i = n - 2; i >= 0; i--) {
        while (k >= t && cross(hull[k - 2], hull[k - 1], pts[i]) <= 0) k--;
        hull[k++] = pts[i];
    }
    return k - 1;
}