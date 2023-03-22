#include "Tests.h"


START_TEST(test10_0) {
    char input[512] = "mod+";

    int result = SetOperatorValid(input);

    ck_assert_int_eq(0, result);
}
END_TEST

START_TEST(test10_1) {
    char input[512] = "1.-";

    int result = SetOperatorValid(input);

    ck_assert_int_eq(0, result);
}
END_TEST

START_TEST(test10_2) {
    char input[512] = "(*";

    int result = SetOperatorValid(input);

    ck_assert_int_eq(0, result);
}
END_TEST

START_TEST(test10_3) {
    char input[512] = "1+/";

    int result = SetOperatorValid(input);

    ck_assert_int_eq(0, result);
}
END_TEST

START_TEST(test10_4) {
    char input[512] = "+++";

    int result = SetOperatorValid(input);

    ck_assert_int_eq(2, result);
}
END_TEST

START_TEST(test10_5) {
    char input[512] = "!!";

    int result = SetOperatorValid(input);

    ck_assert_int_eq(0, result);
}
END_TEST

START_TEST(test10_6) {
    char input[512] = "1.5!";

    int result = SetOperatorValid(input);

    ck_assert_int_eq(0, result);
}
END_TEST

START_TEST(test10_7) {
    char input[512] = "1.5555!";

    int result = SetOperatorValid(input);

    ck_assert_int_eq(0, result);
}
END_TEST

Suite *test10(void) {
  Suite *s;
  TCase *tc;

  s = suite_create("test10");
  tc = tcase_create("core");

    suite_add_tcase(s, tc);
    tcase_add_test(tc, test10_0);
    tcase_add_test(tc, test10_1);
    tcase_add_test(tc, test10_2);
    tcase_add_test(tc, test10_3);
    tcase_add_test(tc, test10_4);
    tcase_add_test(tc, test10_5);

  return s;
}