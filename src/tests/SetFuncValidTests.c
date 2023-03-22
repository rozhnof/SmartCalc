#include "Tests.h"


START_TEST(test14_0) {
    char input[512] = "1";

    int result = SetFuncValid(input);

    ck_assert_int_eq(0, result);
}
END_TEST

START_TEST(test14_1) {
    char input[512] = "!";

    int result = SetFuncValid(input);

    ck_assert_int_eq(0, result);
}
END_TEST

START_TEST(test14_2) {
    char input[512] = "x";

    int result = SetFuncValid(input);

    ck_assert_int_eq(0, result);
}
END_TEST

START_TEST(test14_3) {
    char input[512] = ".";

    int result = SetFuncValid(input);

    ck_assert_int_eq(0, result);
}
END_TEST

START_TEST(test14_4) {
    char input[512] = ")";

    int result = SetFuncValid(input);

    ck_assert_int_eq(0, result);
}
END_TEST



Suite *test14(void) {
  Suite *s;
  TCase *tc;

  s = suite_create("test14");
  tc = tcase_create("core");

    suite_add_tcase(s, tc);
    tcase_add_test(tc, test14_0);
    tcase_add_test(tc, test14_1);
    tcase_add_test(tc, test14_2);
    tcase_add_test(tc, test14_3);
    tcase_add_test(tc, test14_4);

  return s;
}