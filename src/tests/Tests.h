#ifndef TESTS_S21_TESTS_H
#define TESTS_S21_TESTS_H

#include <check.h>
#include <stdio.h>
#include <stdlib.h>

#include "../Services/calc.h"

#define ACCURACY 1e-6

SRunner *default_srunner_create();

Suite *test0(void);
Suite *test1(void);
Suite *test2(void);
Suite *test3(void);
Suite *test4(void);
Suite *test5(void);
Suite *test6(void);
Suite *test7(void);

double readStr(char *input, char *x_input_str);

#endif  // TESTS_S21_TESTS_H
