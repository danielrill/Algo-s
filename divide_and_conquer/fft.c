#include "fft.h"
#include <math.h>

static Complex addc(Complex a, Complex b) { return (Complex){a.re + b.re, a.im + b.im}; }
static Complex subc(Complex a, Complex b) { return (Complex){a.re - b.re, a.im - b.im}; }
static Complex mulc(Complex a, Complex b) { return (Complex){a.re*b.re - a.im*b.im, a.re*b.im + a.im*b.re}; }

void fft(Complex a[], int n, int invert) {
    if (n == 1) return;
    Complex a0[1024], a1[1024];
    for (int i = 0; i < n / 2; i++) {
        a0[i] = a[2 * i];
        a1[i] = a[2 * i + 1];
    }
    fft(a0, n / 2, invert);
    fft(a1, n / 2, invert);
    double ang = 2 * M_PI / n * (invert ? -1 : 1);
    Complex w = {1, 0}, wn = {cos(ang), sin(ang)};
    for (int i = 0; i < n / 2; i++) {
        Complex t = mulc(w, a1[i]);
        a[i] = addc(a0[i], t);
        a[i + n / 2] = subc(a0[i], t);
        if (invert) {
            a[i].re /= 2; a[i].im /= 2;
            a[i + n / 2].re /= 2; a[i + n / 2].im /= 2;
        }
        w = mulc(w, wn);
    }
}