#include "test_lib.h"

#include <stdio.h>

void test_print_fail(const char *message) {
    printf("%s | ", tXX);
    printf("\033[0;31m");
    printf("%s", "FAILED: ");
    printf("\033[0m");
    printf("%s", message);

    is_failed = 1;
}

void test_print_ok() {
    printf("%s | ", tXX);
    printf("\033[0;32m");
    printf("%s", "OK\n");
    printf("\033[0m");
}

void test_finalize() {
    if (!is_failed) {
        test_print_ok();
    }
}
