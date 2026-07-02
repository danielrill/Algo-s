#include "set_cover_approx.h"

int set_cover_approx(unsigned long long universe_mask, unsigned long long sets[], int m, int chosen[]) {
    int count = 0;
    while (universe_mask) {
        int best = -1, best_gain = 0;
        for (int i = 0; i < m; i++) {
            unsigned long long gain = sets[i] & universe_mask;
            int bits = __builtin_popcountll(gain);
            if (bits > best_gain) best_gain = bits, best = i;
        }
        if (best == -1 || best_gain == 0) break;
        chosen[count++] = best;
        universe_mask &= ~sets[best];
    }
    return count;
}