#include "Tests.h"

START_TEST(sinx_test) {
  char input[] = "s(x)";
  char x_input_str[512] = "-3463463.366343";

  double x_input_num = 0;
  sscanf(x_input_str, "%lf", &x_input_num);

  char *postfix = FromInfixToPostfix(input);
  double result = Calculation(postfix, x_input_num);
  free(postfix);
  double original = sinl(x_input_num);

  if (isnan(original)) {
    ck_assert_ldouble_nan(result);
  } else if (isinf(original)) {
    ck_assert_ldouble_infinite(result);
  } else {
    ck_assert_double_eq_tol(result, original, ACCURACY);
  }
}
END_TEST

START_TEST(cosx_test) {
  char input[] = "c(x)";
  char x_input_str[512] = "-3463463.366343";

  double x_input_num = 0;
  sscanf(x_input_str, "%lf", &x_input_num);

  char *postfix = FromInfixToPostfix(input);
  double result = Calculation(postfix, x_input_num);
  free(postfix);
  double original = cosl(x_input_num);

  if (isnan(original)) {
    ck_assert_ldouble_nan(result);
  } else if (isinf(original)) {
    ck_assert_ldouble_infinite(result);
  } else {
    ck_assert_double_eq_tol(result, original, ACCURACY);
  }
}
END_TEST

START_TEST(tanx_test) {
  char input[] = "t(x)";
  char x_input_str[512] = "-3463463.366343";

  double x_input_num = 0;
  sscanf(x_input_str, "%lf", &x_input_num);

  char *postfix = FromInfixToPostfix(input);
  double result = Calculation(postfix, x_input_num);
  free(postfix);
  double original = tanl(x_input_num);

  if (isnan(original)) {
    ck_assert_ldouble_nan(result);
  } else if (isinf(original)) {
    ck_assert_ldouble_infinite(result);
  } else {
    ck_assert_double_eq_tol(result, original, ACCURACY);
  }
}
END_TEST

START_TEST(asinx_test) {
  char input[] = "S(x)";
  char x_input_str[512] = "-3463463.366343";

  double x_input_num = 0;
  sscanf(x_input_str, "%lf", &x_input_num);

  char *postfix = FromInfixToPostfix(input);
  double result = Calculation(postfix, x_input_num);
  free(postfix);
  double original = asinl(x_input_num);

  if (isnan(original)) {
    ck_assert_ldouble_nan(result);
  } else if (isinf(original)) {
    ck_assert_ldouble_infinite(result);
  } else {
    ck_assert_double_eq_tol(result, original, ACCURACY);
  }
}
END_TEST

START_TEST(acosx_test) {
  char input[] = "C(x)";
  char x_input_str[512] = "-3463463.366343";

  double x_input_num = 0;
  sscanf(x_input_str, "%lf", &x_input_num);

  char *postfix = FromInfixToPostfix(input);
  double result = Calculation(postfix, x_input_num);
  free(postfix);
  double original = acosl(x_input_num);

  if (isnan(original)) {
    ck_assert_ldouble_nan(result);
  } else if (isinf(original)) {
    ck_assert_ldouble_infinite(result);
  } else {
    ck_assert_double_eq_tol(result, original, ACCURACY);
  }
}
END_TEST

START_TEST(atanx_test) {
  char input[] = "T(x)";
  char x_input_str[512] = "-3463463.366343";

  double x_input_num = 0;
  sscanf(x_input_str, "%lf", &x_input_num);

  char *postfix = FromInfixToPostfix(input);
  double result = Calculation(postfix, x_input_num);
  free(postfix);
  double original = atanl(x_input_num);

  if (isnan(original)) {
    ck_assert_ldouble_nan(result);
  } else if (isinf(original)) {
    ck_assert_ldouble_infinite(result);
  } else {
    ck_assert_double_eq_tol(result, original, ACCURACY);
  }
}
END_TEST

START_TEST(logx_test) {
  char input[] = "L(x)";
  char x_input_str[512] = "-3463463.366343";

  double x_input_num = 0;
  sscanf(x_input_str, "%lf", &x_input_num);

  char *postfix = FromInfixToPostfix(input);
  double result = Calculation(postfix, x_input_num);
  free(postfix);
  double original = log10l(x_input_num);

  if (isnan(original)) {
    ck_assert_ldouble_nan(result);
  } else if (isinf(original)) {
    ck_assert_ldouble_infinite(result);
  } else {
    ck_assert_double_eq_tol(result, original, ACCURACY);
  }
}
END_TEST

START_TEST(lnx_test) {
  char input[] = "l(x)";
  char x_input_str[512] = "-3463463.366343";

  double x_input_num = 0;
  sscanf(x_input_str, "%lf", &x_input_num);

  char *postfix = FromInfixToPostfix(input);
  double result = Calculation(postfix, x_input_num);
  free(postfix);
  double original = log(x_input_num);

  if (isnan(original)) {
    ck_assert_ldouble_nan(result);
  } else if (isinf(original)) {
    ck_assert_ldouble_infinite(result);
  } else {
    ck_assert_double_eq_tol(result, original, ACCURACY);
  }
}
END_TEST

START_TEST(sqrtx_test) {
  char input[] = "Q(x)";
  char x_input_str[512] = "-3463463.366343";

  double x_input_num = 0;
  sscanf(x_input_str, "%lf", &x_input_num);

  char *postfix = FromInfixToPostfix(input);
  double result = Calculation(postfix, x_input_num);
  free(postfix);
  double original = sqrtl(x_input_num);

  if (isnan(original)) {
    ck_assert_ldouble_nan(result);
  } else if (isinf(original)) {
    ck_assert_ldouble_infinite(result);
  } else {
    ck_assert_double_eq_tol(result, original, ACCURACY);
  }
}
END_TEST

Suite *test4(void) {
  Suite *s;
  TCase *tc;

  s = suite_create("test4");
  tc = tcase_create("core");

  suite_add_tcase(s, tc);
  tcase_add_test(tc, sinx_test);
  tcase_add_test(tc, cosx_test);
  tcase_add_test(tc, tanx_test);
  tcase_add_test(tc, asinx_test);
  tcase_add_test(tc, acosx_test);
  tcase_add_test(tc, atanx_test);
  tcase_add_test(tc, logx_test);
  tcase_add_test(tc, lnx_test);
  tcase_add_test(tc, sqrtx_test);

  return s;
}