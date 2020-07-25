//
//  test_lib.h
//  c-testlib
//
//  Created by Rostyslav Druzhchenko on 14/4/20.
//  Copyright © 2020 Rostyslav Druzhchenko. All rights reserved.
//

#ifndef __TEST_LIB_H__
#define __TEST_LIB_H__

extern int is_failed;
extern char *tXX;
extern char *test_case_name;

void test_print_fail(const char *message);
void test_print_ok();
void test_finalize();

// Asserts

static const int BUFF_SIZE = 4096;

#define ASSERT_NOT_NULL(exp) if ((exp) == 0) { \
    char *s = (char *) malloc(BUFF_SIZE); \
    sprintf(s, "In file \"%s: %d\", function %s(): |" \
    " Passed value is nil | EXP: Not nil, ACR: 0x%x\n", \
    __FILE__, __LINE__, __func__, (unsigned int)exp); \
    test_print_fail(s); \
    free(s); \
}

#define ASSERT_NULL(act) if ((act) != 0) { \
    char *s = (char *) malloc(BUFF_SIZE); \
    sprintf(s, "In file \"%s: %d\", function %s(): | Passed value is not " \
    "NULL | EXP: NULL, ACR: 0x%x\n", \
    __FILE__, __LINE__, __func__, (unsigned int)act); \
    test_print_fail(s); \
    free(s); \
}

#define ASSERT_TRUE(exp) if ((exp) == 0) { \
    char *s = (char *) malloc(BUFF_SIZE); \
    sprintf(s, "     In file \"%s: %d\", function %s():\n" \
    "     EXP: TRUE\n     ACR: FALSE\n", \
    __FILE__, __LINE__, __func__); \
    test_print_fail(s); \
    free(s); \
}

#define ASSERT_EQUALS(exp, act) if (exp != act) { \
    char *s = (char *) malloc(BUFF_SIZE); \
    sprintf(s, "     In file \"%s: %d\", function %s():\n" \
    "     EXP: '%ld'\n     ACR: '%ld'\n", \
    __FILE__, __LINE__, __func__, (unsigned long)exp, (unsigned long)act); \
    test_print_fail(s); \
    free(s); \
}

#define ASSERT_EQUALS_STR(exp, act) if (strcmp(exp, act) != 0) { \
    char *s = (char *) malloc(BUFF_SIZE); \
    sprintf(s, "     In file \"%s: %d\", function %s():\n" \
    "     EXP: '%s'\n     ACR: '%s'\n", \
    __FILE__, __LINE__, __func__, (char *)exp, (char *)act); \
    test_print_fail(s); \
    free(s); \
}

// Intercept STDOUT

#define INTERCEPT_STDOUT int stdout_bk = dup(fileno(stdout)); \
    int pipefd[2];\
    pipe(pipefd); \
    dup2(pipefd[1], fileno(stdout));

#define RESTORE_STDOUT fflush(stdout); \
    close(pipefd[1]); \
    dup2(stdout_bk, fileno(stdout)); \
    char buf[101]; \
    read(pipefd[0], buf, 100);

#define ASSERT_STDOUT_EQUALS(s) \
for (int i = 0; s[i]; i++) { \
    if (s[i] != buf[i]) { \
        ASSERT_TRUE(0); \
    } \
}

// Helpers

#define print(s) printf("%s\n", s)

#endif // __TEST_LIB_H__
