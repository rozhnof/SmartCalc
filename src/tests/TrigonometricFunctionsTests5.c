#include "Tests.h"


START_TEST(test1_0) {
    char input[] = "asin(acos(atan(sqrt(x))))";
    char x_input_str[512] = "1.5";
    

    long double x_input_num = 0;
    sscanf(x_input_str, "%Lf", &x_input_num);

    char *postfix = FromInfixToPostfix(input);
    long double result = Calculation(postfix, x_input_num);
    free(postfix);
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

START_TEST(test1_1) {
    char input[] = "asin(acos(atan(sqrt(x)";
    char x_input_str[512] = "-1.25";
    

    long double x_input_num = 0;
    sscanf(x_input_str, "%Lf", &x_input_num);

    char *postfix = FromInfixToPostfix(input);
    long double result = Calculation(postfix, x_input_num);
    free(postfix);
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

START_TEST(test1_2) {
    char input[] = "asin(acos(atan(sqrt(x)";
    char x_input_str[512] = "1000000";
    

    long double x_input_num = 0;
    sscanf(x_input_str, "%Lf", &x_input_num);

    char *postfix = FromInfixToPostfix(input);
    long double result = Calculation(postfix, x_input_num);
    free(postfix);
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

START_TEST(test1_3) {
    char input[] = "asin(acos(atan(sqrt(x)";
    char x_input_str[512] = "-1005000.5";
    

    long double x_input_num = 0;
    sscanf(x_input_str, "%Lf", &x_input_num);

    char *postfix = FromInfixToPostfix(input);
    long double result = Calculation(postfix, x_input_num);
    free(postfix);
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

START_TEST(test1_4) {
    char input[] = "asin(acos(atan(sqrt(x)";
    char x_input_str[512] = "0";
    

    long double x_input_num = 0;
    sscanf(x_input_str, "%Lf", &x_input_num);

    char *postfix = FromInfixToPostfix(input);
    long double result = Calculation(postfix, x_input_num);
    free(postfix);
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




Suite *test1(void) {
  Suite *s;
  TCase *tc;

  s = suite_create("test1");
  tc = tcase_create("core");

    suite_add_tcase(s, tc);
    tcase_add_test(tc, test1_0);
    tcase_add_test(tc, test1_1);
    tcase_add_test(tc, test1_2);
    tcase_add_test(tc, test1_3);
    tcase_add_test(tc, test1_4);

  return s;
}