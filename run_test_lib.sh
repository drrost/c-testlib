#!/bin/bash

#  c-testlib
#
#  Created by Rostyslav Druzhchenko on 06/06/20.
#  Copyright © 2020 Rostyslav Druzhchenko. All rights reserved.
#
#  Usage:
#    run_test_lib.sh lib_o_path lib_h_path test_folder_path
#

LIB_O_PATH=$1
LIB_H_PATH=$2

PATH_SUT=$3

MAIN_FILE="main.c"
TESTS_FILE="tests.c"

rm -f $MAIN_FILE

# Generate 'main.c' file

echo "" >> $MAIN_FILE
echo "#include <unistd.h>" >> $MAIN_FILE
echo "#include <stdio.h>" >> $MAIN_FILE
echo "#include <stdlib.h>" >> $MAIN_FILE
echo "#include <string.h>" >> $MAIN_FILE

echo "" >> $MAIN_FILE
echo "#include \"../../lib/rd_random.h\"" >> $MAIN_FILE

echo "" >> $MAIN_FILE
echo "#include \"$TESTS_FILE\"" >> $MAIN_FILE

# Handle main function
echo "
int main(void) {
    tests_run_all();
}
" >> $MAIN_FILE

# Generate 'tests.c' file
rm -f $TESTS_FILE

echo "int is_failed = 0;" >> $TESTS_FILE
echo "char *tXX = \"$(basename $PATH_SUT)\";" >> $TESTS_FILE
echo "" >> $TESTS_FILE
echo "#include \"../../lib/test_lib.h\"" >> $TESTS_FILE
echo "" >> $TESTS_FILE

TEST_FILES=$(ls ./ | grep test_)
for file in $TEST_FILES
do
  echo "#include \"$file\"" >> $TESTS_FILE
done

echo "// Run all

void tests_run_all(void) {
    " >> $TESTS_FILE

for file in $TEST_FILES
do
  TEST_FUNCTIONS=$(grep "void test_" $file | awk '{print $2}')
  for func in $TEST_FUNCTIONS
  do
    echo "    $func;" >> $TESTS_FILE
  done
done

echo "

    test_finalize();
}
" >> $TESTS_FILE

# RUN
OUT_NAME=app
rm -f $OUT_NAME

clang -std=c11 -Wall -Wextra -Werror -Wpedantic ./main.c \
    ../../lib/test_lib.c \
    ../../lib/rd_random.c -o $OUT_NAME \
    $LIB_O_PATH

rm $MAIN_FILE $TESTS_FILE

./$OUT_NAME "${@:3}"

# Detect memory leaks
leaks -atExit -- ./$OUT_NAME "${@:3}" > leaks
cat leaks | grep LEAK:
rm -f leaks

rm $OUT_NAME
