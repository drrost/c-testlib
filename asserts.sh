#  c-testlib
#
#  Created by Rostyslav Druzhchenko on 25/4/2020.
#  Copyright © 2020 Rostyslav Druzhchenko. All rights reserved.
#

# VARIABLES
FAILED=0
TASK_NAME=${PWD##*/}
TEST_FILE="UNKNOWN"

# FUNCTIONS
ASSERT_EQUAL() {
  if [ "$1" != "$2" ]
  then
    FAILED=1
    echo -e "\033[31mFALIED\033[0m: in \"$TEST_FILE:$3\": " \
     "Values are not equal. \n  EXP: \"$1\", \n  ACR: \"$2\""
  fi
}

# Print OK
PRINT_OK() {
  if [ $FAILED -eq 0 ]; then
    echo -e "$TASK_NAME | \033[32mOK\033[0m"
  fi
}
