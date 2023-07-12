#include "Tests.h"


START_TEST(test5_0) {
    char input[] = "asin(acos(atan(sqrt(x))))";
    char x_input_str[512] = "1.5";
    

    double x_input_num = 0;
    sscanf(x_input_str, "%lf", &x_input_num);

    char *postfix = FromInfixToPostfix(input);
    double result = Calculation(postfix, x_input_num);
    free(postfix);
    double original = asinl(acosl(atanl(sqrtl(x_input_num))));

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
    char input[] = "asin(acos(atan(sqrt(x)";
    char x_input_str[512] = "-1.25";
    

    double x_input_num = 0;
    sscanf(x_input_str, "%lf", &x_input_num);

    char *postfix = FromInfixToPostfix(input);
    double result = Calculation(postfix, x_input_num);
    free(postfix);
    double original = asinl(acosl(atanl(sqrtl(x_input_num))));

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
    char input[] = "asin(acos(atan(sqrt(x)";
    char x_input_str[512] = "1000000";
    

    double x_input_num = 0;
    sscanf(x_input_str, "%lf", &x_input_num);

    char *postfix = FromInfixToPostfix(input);
    double result = Calculation(postfix, x_input_num);
    free(postfix);
    double original = asinl(acosl(atanl(sqrtl(x_input_num))));

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
    char input[] = "asin(acos(atan(sqrt(x)";
    char x_input_str[512] = "-1005000.5";
    

    double x_input_num = 0;
    sscanf(x_input_str, "%lf", &x_input_num);

    char *postfix = FromInfixToPostfix(input);
    double result = Calculation(postfix, x_input_num);
    free(postfix);
    double original = asinl(acosl(atanl(sqrtl(x_input_num))));

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
    char input[] = "asin(acos(atan(sqrt(x)";
    char x_input_str[512] = "0";
    

    double x_input_num = 0;
    sscanf(x_input_str, "%lf", &x_input_num);

    char *postfix = FromInfixToPostfix(input);
    double result = Calculation(postfix, x_input_num);
    free(postfix);
    double original = asinl(acosl(atanl(sqrtl(x_input_num))));

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