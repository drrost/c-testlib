//
//  test_lib.c
//  c-testlib
//
//  Created by Rostyslav Druzhchenko on 14/4/20.
//  Copyright © 2020 Rostyslav Druzhchenko. All rights reserved.
//

#include "test_lib.h"

#include <stdio.h>

void test_print_fail(const char *message) {
    printf("%s | ", tXX);
    printf("\033[0;31m");
    printf("%s", "FAILED: ");
    printf("\033[0m |");
    printf("\033[1m %s\033[0m\n", test_case_name);
    printf("%s", message);

    is_failed = 1;
}

void test_print_ok() {
    printf("%s | ", tXX);
    printf("\033[0;32m");
    printf("%s", "OK\033[0m");
    printf(" |\033[1m %s\033[0m\n", test_case_name);
}

void test_finalize() {
    if (!is_failed) {
        test_print_ok();
    }
}
