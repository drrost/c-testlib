#ifndef __TEST_LIB_H__
#define __TEST_LIB_H__

extern int is_failed;
extern char *tXX;

void test_print_fail(const char *message);
void test_print_ok();
void test_finalize();

// Asserts

#define ASSERT_EQUALS(exp, act) if (exp != act) { char sss[256]; \
    sprintf(sss, "in %s():  EXP: '%d', ACR: '%d'\n", __func__, exp, act); \
    test_print_fail(sss); }

#endif // __TEST_LIB_H__
