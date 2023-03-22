#include "Tests.h"


START_TEST(test15_0) {
    char input[512] = "1";

    int result = SetModValid(input);

    ck_assert_int_eq(1, result);
}
END_TEST

START_TEST(test15_1) {
    char input[512] = "x";

    int result = SetModValid(input);

    ck_assert_int_eq(1, result);
}
END_TEST

START_TEST(test15_2) {
    char input[512] = ")";

    int result = SetModValid(input);

    ck_assert_int_eq(1, result);
}
END_TEST

START_TEST(test15_3) {
    char input[512] = "(";

    int result = SetModValid(input);

    ck_assert_int_eq(0, result);
}
END_TEST


Suite *test15(void) {
  Suite *s;
  TCase *tc;

  s = suite_create("test15");
  tc = tcase_create("core");

    suite_add_tcase(s, tc);
    tcase_add_test(tc, test15_0);
    tcase_add_test(tc, test15_1);
    tcase_add_test(tc, test15_2);
    tcase_add_test(tc, test15_3);

  return s;
}