#ifndef SET_COVER_APPROX_H
#define SET_COVER_APPROX_H

#define SET_MAX_UNIVERSE 64
#define SET_MAX_SETS 64

int set_cover_approx(unsigned long long universe_mask, unsigned long long sets[], int m, int chosen[]);

#endif