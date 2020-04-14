//
//  rd_random.c
//  c-testlib
//
//  Created by Rostyslav Druzhchenko on 14/4/20.
//  Copyright © 2019 Rostyslav Druzhchenko. All rights reserved.
//

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
