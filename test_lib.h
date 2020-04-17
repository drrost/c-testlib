//
//  test_lib.h
//  c-testlib
//
//  Created by Rostyslav Druzhchenko on 14/4/20.
//  Copyright © 2019 Rostyslav Druzhchenko. All rights reserved.
//

#ifndef __TEST_LIB_H__
#define __TEST_LIB_H__

extern int is_failed;
extern char *tXX;

void test_print_fail(const char *message);
void test_print_ok();
void test_finalize();

// Asserts

#define ASSERT_NOT_NIL(exp) if ((exp) == 0) { char sss[256]; \
    sprintf(sss, "In file \"%s: %d\", function %s(): | Passed value is nil | EXP: Not nil, ACR: 0x%x\n", \
    __FILE__, __LINE__, __func__, (unsigned int)exp); \
    test_print_fail(sss); }

#define ASSERT_TRUE(exp) if ((exp) == 0) { char sss[256]; \
    sprintf(sss, "In file \"%s: %d\", function %s(): EXP: TRUE, ACR: FALSE\n", \
    __FILE__, __LINE__, __func__); \
    test_print_fail(sss); }

#define ASSERT_EQUALS(exp, act) if (exp != act) { char sss[256]; \
    sprintf(sss, "In file \"%s: %d\", function %s(): EXP: '%d', ACR: '%d'\n", \
    __FILE__, __LINE__, __func__, exp, act); \
    test_print_fail(sss); }



#endif // __TEST_LIB_H__
