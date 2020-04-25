#  c-testlib
#
#  Created by Rostyslav Druzhchenko on 25/4/2020.
#  Copyright © 2020 Rostyslav Druzhchenko. All rights reserved.
#

ASSERT_EQUAL() {
  if [ "$1" != "$2" ]
  then
    $FAILED=1
    echo -e "\033[31mFALIED\033[0m:" \
     "Values are not equal. \n  EXP: \"$1\", \n  ACR: \"$2\""
  fi
}
