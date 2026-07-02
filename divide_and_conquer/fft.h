#ifndef FFT_H
#define FFT_H

typedef struct {
    double re, im;
} Complex;

void fft(Complex a[], int n, int invert);

#endif