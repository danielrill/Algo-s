#include "karatsuba.h"

static long long pow10_int(int n) {
    long long p = 1;
    while (n--) p *= 10;
    return p;
}

static int digits(long long x) {
    int d = 0;
    if (x == 0) return 1;
    while (x) { d++; x /= 10; }
    return d;
}

long long karatsuba(long long x, long long y) {
    if (x < 10 || y < 10) return x * y;
    int n = digits(x > y ? x : y);
    int m = n / 2;
    long long p = pow10_int(m);
    long long a = x / p, b = x % p;
    long long c = y / p, d = y % p;
    long long ac = karatsuba(a, c);
    long long bd = karatsuba(b, d);
    long long adbc = karatsuba(a + b, c + d) - ac - bd;
    return ac * pow10_int(2 * m) + adbc * p + bd;
}