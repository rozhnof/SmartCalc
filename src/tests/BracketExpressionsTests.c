#include "Tests.h"


START_TEST(test7_0) {
    char input[512] = "1.5+2.5*3.5/4.5^5.5+1.5*(2.5+(3.5*(4.5/-5.5+(+10.5)-(-20.5))/x))";
    char x_input_str[512] = "1.5";
    char output[512] = "";

    long double x_input_num = 0;
    sscanf(x_input_str, "%Lf", &x_input_num);

    FromInfixToPostfix(input, output);
    long double result = Calculation(output, x_input_num);
    long double original = 1.5 + 2.5 * 3.5 / powl(4.5,5.5) + 1.5 * (2.5 + (3.5 * (4.5 / (-5.5) + (+10.5) - (-20.5)) / x_input_num));

    if (isnan(original)) {
        ck_assert_ldouble_nan(result);
    } else if (isinf(original)) {
        ck_assert_ldouble_infinite(result);
    } else {
        ck_assert_double_eq_tol(result, original, ACCURACY);
    }
}
END_TEST

START_TEST(test7_1) {
    char input[512] = "1.5+2.5*3.5/4.5^5.5+1.5*(2.5+(3.5*(4.5/(-5.5)+(+10.5)-(-20.5))/x))";
    char x_input_str[512] = "-1.25";
    char output[512] = "";

    long double x_input_num = 0;
    sscanf(x_input_str, "%Lf", &x_input_num);

    FromInfixToPostfix(input, output);
    long double result = Calculation(output, x_input_num);
    long double original = 1.5 + 2.5 * 3.5 / powl(4.5,5.5) + 1.5 * (2.5 + (3.5 * (4.5 / (-5.5) + (+10.5) - (-20.5)) / x_input_num));

    if (isnan(original)) {
        ck_assert_ldouble_nan(result);
    } else if (isinf(original)) {
        ck_assert_ldouble_infinite(result);
    } else {
        ck_assert_double_eq_tol(result, original, ACCURACY);
    }
}
END_TEST

START_TEST(test7_2) {
    char input[512] = "1.5+2.5*3.5/4.5^5.5+1.5*(2.5+(3.5*(4.5/(-5.5)+(+10.5)-(-20.5))/x!))";
    char x_input_str[512] = "5";
    char output[512] = "";

    long double x_input_num = 0;
    sscanf(x_input_str, "%Lf", &x_input_num);

    FromInfixToPostfix(input, output);
    long double result = Calculation(output, x_input_num);
    long double original = 1.5 + 2.5 * 3.5 / powl(4.5,5.5) + 1.5 * (2.5 + (3.5 * (4.5 / (-5.5) + (+10.5) - (-20.5)) / 120));

    if (isnan(original)) {
        ck_assert_ldouble_nan(result);
    } else if (isinf(original)) {
        ck_assert_ldouble_infinite(result);
    } else {
        ck_assert_double_eq_tol(result, original, ACCURACY);
    }
}
END_TEST

START_TEST(test7_3) {
    char input[512] = "-223.5mod135.3-x";
    char x_input_str[512] = "4";
    char output[512] = "";

    long double x_input_num = 0;
    sscanf(x_input_str, "%Lf", &x_input_num);

    FromInfixToPostfix(input, output);
    long double result = Calculation(output, x_input_num);
    long double original = fmodl(-223.5, 135.3)-x_input_num;

    if (isnan(original)) {
        ck_assert_ldouble_nan(result);
    } else if (isinf(original)) {
        ck_assert_ldouble_infinite(result);
    } else {
        ck_assert_double_eq_tol(result, original, ACCURACY);
    }
}
END_TEST

START_TEST(test7_4) {
    char input[512] = "1.5+2.5*3.5/4.5^5.5+1.5*(2.5+(3.5*(4.5/(-5.5)+(+10.5)-(-20.5))/x!))";
    char x_input_str[512] = "0";
    char output[512] = "";

    long double x_input_num = 0;
    sscanf(x_input_str, "%Lf", &x_input_num);

    FromInfixToPostfix(input, output);
    long double result = Calculation(output, x_input_num);
    long double original = 1.5 + 2.5 * 3.5 / powl(4.5,5.5) + 1.5 * (2.5 + (3.5 * (4.5 / (-5.5) + (+10.5) - (-20.5)) / 1));

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

  s = suite_create("test7");
  tc = tcase_create("core");

    suite_add_tcase(s, tc);
    tcase_add_test(tc, test7_0);
    tcase_add_test(tc, test7_1);
    tcase_add_test(tc, test7_2);
    tcase_add_test(tc, test7_3);
    tcase_add_test(tc, test7_4);

  return s;
}