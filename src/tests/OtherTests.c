#include "Tests.h"

START_TEST(test0_0) {
  char input[] = "e";
  char x_input_str[512] = "0";

  double x_input_num = 0;
  sscanf(x_input_str, "%lf", &x_input_num);

  char *postfix = FromInfixToPostfix(input);
  double result = Calculation(postfix, x_input_num);
  free(postfix);
  double original = M_E;

  if (isnan(original)) {
    ck_assert_ldouble_nan(result);
  } else if (isinf(original)) {
    ck_assert_ldouble_infinite(result);
  } else {
    ck_assert_double_eq_tol(result, original, ACCURACY);
  }
}
END_TEST

START_TEST(test0_1) {
  char input[] = "+12.34e-2+12.34e+2-123.456";
  char x_input_str[512] = "0";

  double x_input_num = 0;
  sscanf(x_input_str, "%lf", &x_input_num);

  char *postfix = FromInfixToPostfix(input);
  double result = Calculation(postfix, x_input_num);
  free(postfix);
  double original = 12.34e-2 + 12.34e+2 - 123.456;

  if (isnan(original)) {
    ck_assert_ldouble_nan(result);
  } else if (isinf(original)) {
    ck_assert_ldouble_infinite(result);
  } else {
    ck_assert_double_eq_tol(result, original, ACCURACY);
  }
}
END_TEST

Suite *test8(void) {
  Suite *s;
  TCase *tc;

  s = suite_create("test0");
  tc = tcase_create("core");

  suite_add_tcase(s, tc);
  tcase_add_test(tc, test0_0);
  tcase_add_test(tc, test0_1);

  return s;
}