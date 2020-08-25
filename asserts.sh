#  c-testlib
#
#  Created by Rostyslav Druzhchenko on 25/4/2020.
#  Copyright © 2020 Rostyslav Druzhchenko. All rights reserved.
#

# VARIABLES
TEST_FAILED=0
TASK_NAME=${PWD##*/}
TEST_FILE=$(basename $0)

# FUNCTIONS
ASSERT_EQUAL() {
  # $1 - expected text.
  # $2 - actual result text.
  # $3 - if "-h" passed - hides output.
  if [ "$1" != "$2" ]; then
    TEST_FAILED=1
    if [ "$3" != "-h" ]; then
      echo -e "\033[31mFAILED\033[0m: in \"$TEST_FILE:$3\": " \
        "Values are not equal. \n  EXP: \"$1\", \n  ACR: \"$2\""
    fi
  fi
}

# Print OK
PRINT_OK() {
  if [ $TEST_FAILED -eq 0 ]; then
    echo -e "$TASK_NAME | \033[32mOK\033[0m"
  fi
}

function run_leaks_check() {
  leaks -atExit -- ./$1 $2 "${@:3}" 2> /dev/null > leaks
  cat leaks | grep LEAK:
  rm -f leaks
}
