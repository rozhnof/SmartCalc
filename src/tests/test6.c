#include "s21_tests.h"


START_TEST(test6_0) {
    char input[512] = "asin(acos(atan(sqrt(x))))";
    char x_input_str[512] = "1.5";
    char output[512] = "";

    long double x_input_num = 0;
    sscanf(x_input_str, "%Lf", &x_input_num);

    FromInfixToPostfix(input, output);
    long double result = Calculation(output, x_input_num);
    long double original = asinl(acosl(atanl(sqrtl(x_input_num))));

    if (isnan(original)) {
        ck_assert_ldouble_nan(result);
    } else if (isinf(original)) {
        ck_assert_ldouble_infinite(result);
    } else {
        ck_assert_double_eq_tol(result, original, ACCURACY);
    }
}
END_TEST

START_TEST(test6_1) {
    char input[512] = "asin(acos(atan(sqrt(x)";
    char x_input_str[512] = "-1.25";
    char output[512] = "";

    long double x_input_num = 0;
    sscanf(x_input_str, "%Lf", &x_input_num);

    FromInfixToPostfix(input, output);
    long double result = Calculation(output, x_input_num);
    long double original = asinl(acosl(atanl(sqrtl(x_input_num))));

    if (isnan(original)) {
        ck_assert_ldouble_nan(result);
    } else if (isinf(original)) {
        ck_assert_ldouble_infinite(result);
    } else {
        ck_assert_double_eq_tol(result, original, ACCURACY);
    }
}
END_TEST

START_TEST(test6_2) {
    char input[512] = "asin(acos(atan(sqrt(x)";
    char x_input_str[512] = "1000000";
    char output[512] = "";

    long double x_input_num = 0;
    sscanf(x_input_str, "%Lf", &x_input_num);

    FromInfixToPostfix(input, output);
    long double result = Calculation(output, x_input_num);
    long double original = asinl(acosl(atanl(sqrtl(x_input_num))));

    if (isnan(original)) {
        ck_assert_ldouble_nan(result);
    } else if (isinf(original)) {
        ck_assert_ldouble_infinite(result);
    } else {
        ck_assert_double_eq_tol(result, original, ACCURACY);
    }
}
END_TEST

START_TEST(test6_3) {
    char input[512] = "asin(acos(atan(sqrt(x)";
    char x_input_str[512] = "-1005000.5";
    char output[512] = "";

    long double x_input_num = 0;
    sscanf(x_input_str, "%Lf", &x_input_num);

    FromInfixToPostfix(input, output);
    long double result = Calculation(output, x_input_num);
    long double original = asinl(acosl(atanl(sqrtl(x_input_num))));

    if (isnan(original)) {
        ck_assert_ldouble_nan(result);
    } else if (isinf(original)) {
        ck_assert_ldouble_infinite(result);
    } else {
        ck_assert_double_eq_tol(result, original, ACCURACY);
    }
}
END_TEST

START_TEST(test6_4) {
    char input[512] = "asin(acos(atan(sqrt(x)";
    char x_input_str[512] = "0";
    char output[512] = "";

    long double x_input_num = 0;
    sscanf(x_input_str, "%Lf", &x_input_num);

    FromInfixToPostfix(input, output);
    long double result = Calculation(output, x_input_num);
    long double original = asinl(acosl(atanl(sqrtl(x_input_num))));

    if (isnan(original)) {
        ck_assert_ldouble_nan(result);
    } else if (isinf(original)) {
        ck_assert_ldouble_infinite(result);
    } else {
        ck_assert_double_eq_tol(result, original, ACCURACY);
    }
}
END_TEST




Suite *test6(void) {
  Suite *s;
  TCase *tc;

  s = suite_create("test6");
  tc = tcase_create("core");

    suite_add_tcase(s, tc);
    tcase_add_test(tc, test6_0);
    tcase_add_test(tc, test6_1);
    tcase_add_test(tc, test6_2);
    tcase_add_test(tc, test6_3);
    tcase_add_test(tc, test6_4);

  return s;
}