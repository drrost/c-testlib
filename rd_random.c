#include <time.h>
#include <stdlib.h>

static int is_initialized = 0;

int rd_random_int(int from, int to) {
    if (!is_initialized) {
        is_initialized = 1;
        srand(time(0));
    }
    return rand() % (to - from + 1) + from;
}

void rd_random_fill(int *arr, int n, int from, int to) {
    for (int i = 0; i < n; i++) {
        arr[i] = rd_random_int(from, to);
    }
}
