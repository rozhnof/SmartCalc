#include "Tests.h"


START_TEST(test0_0) {
    char input[] = "sin(cos(tan(sqrt(x^(x^(x))))))";
    char x_input_str[512] = "1.5";
    

    double x_input_num = 0;
    sscanf(x_input_str, "%lf", &x_input_num);

    char *postfix = FromInfixToPostfix(input);
    double result = Calculation(postfix, x_input_num);
    free(postfix);
    double original = sin(cos(tan(sqrt(pow(x_input_num, pow(x_input_num, x_input_num))))));

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
    char input[] = "sin(cos(tan(sqrt(x^(x^(x))))))";
    char x_input_str[512] = "-1.25";
    

    double x_input_num = 0;
    sscanf(x_input_str, "%lf", &x_input_num);

    char *postfix = FromInfixToPostfix(input);
    double result = Calculation(postfix, x_input_num);
    free(postfix);
    double original = sin(cos(tan(sqrt(pow(x_input_num, pow(x_input_num, x_input_num))))));

    if (isnan(original)) {
        ck_assert_ldouble_nan(result);
    } else if (isinf(original)) {
        ck_assert_ldouble_infinite(result);
    } else {
        ck_assert_double_eq_tol(result, original, ACCURACY);
    }
}
END_TEST

START_TEST(test0_2) {
    char input[] = "sin(cos(tan(sqrt(x^(x^(x))))))";
    char x_input_str[512] = "123456789.987654321";
    

    double x_input_num = 0;
    sscanf(x_input_str, "%lf", &x_input_num);

    char *postfix = FromInfixToPostfix(input);
    double result = Calculation(postfix, x_input_num);
    free(postfix);
    double original = sin(cos(tan(sqrt(pow(x_input_num, pow(x_input_num, x_input_num))))));

    if (isnan(original)) {
        ck_assert_ldouble_nan(result);
    } else if (isinf(original)) {
        ck_assert_ldouble_infinite(result);
    } else {
        ck_assert_double_eq_tol(result, original, ACCURACY);
    }
}
END_TEST

START_TEST(test0_3) {
    char input[] = "sin(cos(tan(sqrt(x^(x^(x))))))";
    char x_input_str[512] = "-1.23456789987654321";
    

    double x_input_num = 0;
    sscanf(x_input_str, "%lf", &x_input_num);

    char *postfix = FromInfixToPostfix(input);
    double result = Calculation(postfix, x_input_num);
    free(postfix);
    double original = sin(cos(tan(sqrt(pow(x_input_num, pow(x_input_num, x_input_num))))));

    if (isnan(original)) {
        ck_assert_ldouble_nan(result);
    } else if (isinf(original)) {
        ck_assert_ldouble_infinite(result);
    } else {
        ck_assert_double_eq_tol(result, original, ACCURACY);
    }
}
END_TEST

START_TEST(test0_4) {
    char input[] = "sin(cos(tan(sqrt(x^(x^(x))))))";
    char x_input_str[512] = "0";
    

    double x_input_num = 0;
    sscanf(x_input_str, "%lf", &x_input_num);

    char *postfix = FromInfixToPostfix(input);
    double result = Calculation(postfix, x_input_num);
    free(postfix);
    double original = sin(cos(tan(sqrt(pow(x_input_num, pow(x_input_num, x_input_num))))));

    if (isnan(original)) {
        ck_assert_ldouble_nan(result);
    } else if (isinf(original)) {
        ck_assert_ldouble_infinite(result);
    } else {
        ck_assert_double_eq_tol(result, original, ACCURACY);
    }
}
END_TEST


Suite *test0(void) {
  Suite *s;
  TCase *tc;

  s = suite_create("test0");
  tc = tcase_create("core");

    suite_add_tcase(s, tc);
    tcase_add_test(tc, test0_0);
    tcase_add_test(tc, test0_1);
    tcase_add_test(tc, test0_2);
    tcase_add_test(tc, test0_3);
    tcase_add_test(tc, test0_4);

  return s;
}