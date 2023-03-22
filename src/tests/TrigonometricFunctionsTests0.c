#include "Tests.h"


START_TEST(test5_0) {
    char input[512] = "sin(cos(tan(sqrt(x^(x^(x))))))";
    char x_input_str[512] = "1.5";
    char output[512] = "";

    long double x_input_num = 0;
    sscanf(x_input_str, "%Lf", &x_input_num);

    FromInfixToPostfix(input, output);
    long double result = Calculation(output, x_input_num);
    long double original = sinl(cosl(tanl(sqrtl(powl(x_input_num, powl(x_input_num, x_input_num))))));

    if (isnan(original)) {
        ck_assert_ldouble_nan(result);
    } else if (isinf(original)) {
        ck_assert_ldouble_infinite(result);
    } else {
        ck_assert_double_eq_tol(result, original, ACCURACY);
    }
}
END_TEST

START_TEST(test5_1) {
    char input[512] = "sin(cos(tan(sqrt(x^(x^(x))))))";
    char x_input_str[512] = "-1.25";
    char output[512] = "";

    long double x_input_num = 0;
    sscanf(x_input_str, "%Lf", &x_input_num);

    FromInfixToPostfix(input, output);
    long double result = Calculation(output, x_input_num);
    long double original = sinl(cosl(tanl(sqrtl(powl(x_input_num, powl(x_input_num, x_input_num))))));

    if (isnan(original)) {
        ck_assert_ldouble_nan(result);
    } else if (isinf(original)) {
        ck_assert_ldouble_infinite(result);
    } else {
        ck_assert_double_eq_tol(result, original, ACCURACY);
    }
}
END_TEST

START_TEST(test5_2) {
    char input[512] = "sin(cos(tan(sqrt(x^(x^(x))))))";
    char x_input_str[512] = "123456789.987654321";
    char output[512] = "";

    long double x_input_num = 0;
    sscanf(x_input_str, "%Lf", &x_input_num);

    FromInfixToPostfix(input, output);
    long double result = Calculation(output, x_input_num);
    long double original = sinl(cosl(tanl(sqrtl(powl(x_input_num, powl(x_input_num, x_input_num))))));

    if (isnan(original)) {
        ck_assert_ldouble_nan(result);
    } else if (isinf(original)) {
        ck_assert_ldouble_infinite(result);
    } else {
        ck_assert_double_eq_tol(result, original, ACCURACY);
    }
}
END_TEST

START_TEST(test5_3) {
    char input[512] = "sin(cos(tan(sqrt(x^(x^(x))))))";
    char x_input_str[512] = "-1.23456789987654321";
    char output[512] = "";

    long double x_input_num = 0;
    sscanf(x_input_str, "%Lf", &x_input_num);

    FromInfixToPostfix(input, output);
    long double result = Calculation(output, x_input_num);
    long double original = sinl(cosl(tanl(sqrtl(powl(x_input_num, powl(x_input_num, x_input_num))))));

    if (isnan(original)) {
        ck_assert_ldouble_nan(result);
    } else if (isinf(original)) {
        ck_assert_ldouble_infinite(result);
    } else {
        ck_assert_double_eq_tol(result, original, ACCURACY);
    }
}
END_TEST

START_TEST(test5_4) {
    char input[512] = "sin(cos(tan(sqrt(x^(x^(x))))))";
    char x_input_str[512] = "0";
    char output[512] = "";

    long double x_input_num = 0;
    sscanf(x_input_str, "%Lf", &x_input_num);

    FromInfixToPostfix(input, output);
    long double result = Calculation(output, x_input_num);
    long double original = sinl(cosl(tanl(sqrtl(powl(x_input_num, powl(x_input_num, x_input_num))))));

    if (isnan(original)) {
        ck_assert_ldouble_nan(result);
    } else if (isinf(original)) {
        ck_assert_ldouble_infinite(result);
    } else {
        ck_assert_double_eq_tol(result, original, ACCURACY);
    }
}
END_TEST


Suite *test5(void) {
  Suite *s;
  TCase *tc;

  s = suite_create("test5");
  tc = tcase_create("core");

    suite_add_tcase(s, tc);
    tcase_add_test(tc, test5_0);
    tcase_add_test(tc, test5_1);
    tcase_add_test(tc, test5_2);
    tcase_add_test(tc, test5_3);
    tcase_add_test(tc, test5_4);

  return s;
}