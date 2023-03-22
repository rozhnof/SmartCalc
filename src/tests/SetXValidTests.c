#include "Tests.h"


START_TEST(test16_0) {
    char input[512] = "";

    int result = SetXValid(input);

    ck_assert_int_eq(1, result);
}
END_TEST

START_TEST(test16_1) {
    char input[512] = "+";

    int result = SetXValid(input);

    ck_assert_int_eq(1, result);
}
END_TEST

START_TEST(test16_2) {
    char input[512] = "mod";

    int result = SetXValid(input);

    ck_assert_int_eq(1, result);
}
END_TEST

START_TEST(test16_3) {
    char input[512] = "(";

    int result = SetXValid(input);

    ck_assert_int_eq(1, result);
}
END_TEST


Suite *test16(void) {
  Suite *s;
  TCase *tc;

  s = suite_create("test16");
  tc = tcase_create("core");

    suite_add_tcase(s, tc);
    tcase_add_test(tc, test16_0);
    tcase_add_test(tc, test16_1);
    tcase_add_test(tc, test16_2);
    tcase_add_test(tc, test16_3);

  return s;
}