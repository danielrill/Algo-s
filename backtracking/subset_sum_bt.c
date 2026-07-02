#include "subset_sum_bt.h"

static int util(int arr[], int n, int sum, int idx, int chosen[], int count) {
    if (sum == 0) return 1;
    if (idx == n || sum < 0) return 0;
    chosen[count] = idx;
    if (util(arr, n, sum - arr[idx], idx + 1, chosen, count + 1)) return 1;
    if (util(arr, n, sum, idx + 1, chosen, count)) return 1;
    return 0;
}

int subset_sum_bt(int arr[], int n, int sum, int chosen[]) {
    return util(arr, n, sum, 0, chosen, 0);
}

int subset_sum_bt_exists(int arr[], int n, int sum) {
    int chosen[SS_MAX];
    return subset_sum_bt(arr, n, sum, chosen);
}