#include "activity_selection.h"
#include <stdlib.h>

int cmp_activity_finish(const void *a, const void *b) {
    const Activity *x = (const Activity *)a;
    const Activity *y = (const Activity *)b;
    if (x->finish != y->finish) return x->finish - y->finish;
    return x->start - y->start;
}

int activity_selection(Activity activities[], int n, int selected_ids[]) {
    if (n <= 0) return 0;
    qsort(activities, n, sizeof(Activity), cmp_activity_finish);
    int count = 0;
    selected_ids[count++] = activities[0].id;
    int last_finish = activities[0].finish;
    for (int i = 1; i < n; i++) {
        if (activities[i].start >= last_finish) {
            selected_ids[count++] = activities[i].id;
            last_finish = activities[i].finish;
        }
    }
    return count;
}