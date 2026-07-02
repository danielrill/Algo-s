#ifndef ACTIVITY_SELECTION_H
#define ACTIVITY_SELECTION_H

typedef struct {
    int start;
    int finish;
    int id;
} Activity;

int cmp_activity_finish(const void *a, const void *b);
int activity_selection(Activity activities[], int n, int selected_ids[]);

#endif