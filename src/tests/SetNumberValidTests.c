#include "Tests.h"


START_TEST(test8_0) {
    char input[512] = "x1";

    int result = SetNumberValid(input);

    ck_assert_int_eq(0, result);
}
END_TEST

START_TEST(test8_1) {
    char input[512] = "1!1";

    int result = SetNumberValid(input);

    ck_assert_int_eq(0, result);
}
END_TEST

START_TEST(test8_2) {
    char input[512] = "(1)1";

    int result = SetNumberValid(input);

    ck_assert_int_eq(0, result);
}
END_TEST

START_TEST(test8_3) {
    char input[512] = "mod1";

    int result = SetNumberValid(input);

    ck_assert_int_eq(1, result);
}
END_TEST

START_TEST(test8_4) {
    char input[512] = "01";

    int result = SetNumberValid(input);

    ck_assert_int_eq(2, result);
}
END_TEST

START_TEST(test8_5) {
    char input[512] = "+01";

    int result = SetNumberValid(input);

    ck_assert_int_eq(2, result);
}
END_TEST


Suite *test8(void) {
  Suite *s;
  TCase *tc;

  s = suite_create("test8");
  tc = tcase_create("core");

    suite_add_tcase(s, tc);
    tcase_add_test(tc, test8_0);
    tcase_add_test(tc, test8_1);
    tcase_add_test(tc, test8_2);
    tcase_add_test(tc, test8_3);
    tcase_add_test(tc, test8_4);
    tcase_add_test(tc, test8_5);

  return s;
}