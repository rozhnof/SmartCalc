#include "Tests.h"

START_TEST(test2_0) {
  char input[] =
      "1.5+2.5*3.5/4.5^5.5+1.5*(2.5+(3.5*(4.5/-5.5+(+10.5)-(-20.5))/x))";
  char x_input_str[512] = "1.5";

  double x_input_num = 0;
  sscanf(x_input_str, "%lf", &x_input_num);

  char *postfix = FromInfixToPostfix(input);
  double result = Calculation(postfix, x_input_num);
  free(postfix);
  double original =
      1.5 + 2.5 * 3.5 / powl(4.5, 5.5) +
      1.5 * (2.5 + (3.5 * (4.5 / (-5.5) + (+10.5) - (-20.5)) / x_input_num));

  if (isnan(original)) {
    ck_assert_ldouble_nan(result);
  } else if (isinf(original)) {
    ck_assert_ldouble_infinite(result);
  } else {
    ck_assert_double_eq_tol(result, original, ACCURACY);
  }
}
END_TEST

START_TEST(test2_1) {
  char input[] =
      "1.5+2.5*3.5/4.5^5.5+1.5*(2.5+(3.5*(4.5/(-5.5)+(+10.5)-(-20.5))/x))";
  char x_input_str[512] = "-1.25";

  double x_input_num = 0;
  sscanf(x_input_str, "%lf", &x_input_num);

  char *postfix = FromInfixToPostfix(input);
  double result = Calculation(postfix, x_input_num);
  free(postfix);
  double original =
      1.5 + 2.5 * 3.5 / powl(4.5, 5.5) +
      1.5 * (2.5 + (3.5 * (4.5 / (-5.5) + (+10.5) - (-20.5)) / x_input_num));

  if (isnan(original)) {
    ck_assert_ldouble_nan(result);
  } else if (isinf(original)) {
    ck_assert_ldouble_infinite(result);
  } else {
    ck_assert_double_eq_tol(result, original, ACCURACY);
  }
}
END_TEST

START_TEST(test2_2) {
  char input[] =
      "1.5+2.5*3.5/4.5^5.5+1.5*(2.5+(3.5*(4.5/(-5.5)+(+10.5)-(-20.5))/x!))";
  char x_input_str[512] = "5";

  double x_input_num = 0;
  sscanf(x_input_str, "%lf", &x_input_num);

  char *postfix = FromInfixToPostfix(input);
  double result = Calculation(postfix, x_input_num);
  free(postfix);
  double original =
      1.5 + 2.5 * 3.5 / powl(4.5, 5.5) +
      1.5 * (2.5 + (3.5 * (4.5 / (-5.5) + (+10.5) - (-20.5)) / 120));

  if (isnan(original)) {
    ck_assert_ldouble_nan(result);
  } else if (isinf(original)) {
    ck_assert_ldouble_infinite(result);
  } else {
    ck_assert_double_eq_tol(result, original, ACCURACY);
  }
}
END_TEST

START_TEST(test2_3) {
  char input[] = "-223.5mod135.3-x";
  char x_input_str[512] = "4";

  double x_input_num = 0;
  sscanf(x_input_str, "%lf", &x_input_num);

  char *postfix = FromInfixToPostfix(input);
  double result = Calculation(postfix, x_input_num);
  free(postfix);
  double original = fmodl(-223.5, 135.3) - x_input_num;

  if (isnan(original)) {
    ck_assert_ldouble_nan(result);
  } else if (isinf(original)) {
    ck_assert_ldouble_infinite(result);
  } else {
    ck_assert_double_eq_tol(result, original, ACCURACY);
  }
}
END_TEST

START_TEST(test2_4) {
  char input[] =
      "1.5+2.5*3.5/4.5^5.5+1.5*(2.5+(3.5*(4.5/(-5.5)+(+10.5)-(-20.5))/x!))";
  char x_input_str[512] = "0";

  double x_input_num = 0;
  sscanf(x_input_str, "%lf", &x_input_num);

  char *postfix = FromInfixToPostfix(input);
  double result = Calculation(postfix, x_input_num);
  free(postfix);
  double original =
      1.5 + 2.5 * 3.5 / powl(4.5, 5.5) +
      1.5 * (2.5 + (3.5 * (4.5 / (-5.5) + (+10.5) - (-20.5)) / 1));

  if (isnan(original)) {
    ck_assert_ldouble_nan(result);
  } else if (isinf(original)) {
    ck_assert_ldouble_infinite(result);
  } else {
    ck_assert_double_eq_tol(result, original, ACCURACY);
  }
}
END_TEST

Suite *test7(void) {
  Suite *s;
  TCase *tc;

  s = suite_create("test2");
  tc = tcase_create("core");

  suite_add_tcase(s, tc);
  tcase_add_test(tc, test2_0);
  tcase_add_test(tc, test2_1);
  tcase_add_test(tc, test2_2);
  tcase_add_test(tc, test2_3);
  tcase_add_test(tc, test2_4);

  return s;
}