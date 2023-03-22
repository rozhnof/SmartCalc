#include "Tests.h"


START_TEST(test17_0) {
    char input[512] = "";

    int result = ResultInputValid(input);

    ck_assert_int_eq(0, result);
}
END_TEST

START_TEST(test17_1) {
    char input[512] = "1.";

    int result = ResultInputValid(input);

    ck_assert_int_eq(0, result);
}
END_TEST

START_TEST(test17_2) {
    char input[512] = "1mod";

    int result = ResultInputValid(input);

    ck_assert_int_eq(0, result);
}
END_TEST

START_TEST(test17_3) {
    char input[512] = "1+";

    int result = ResultInputValid(input);

    ck_assert_int_eq(0, result);
}
END_TEST


Suite *test17(void) {
  Suite *s;
  TCase *tc;

  s = suite_create("test17");
  tc = tcase_create("core");

    suite_add_tcase(s, tc);
    tcase_add_test(tc, test17_0);
    tcase_add_test(tc, test17_1);
    tcase_add_test(tc, test17_2);
    tcase_add_test(tc, test17_3);

  return s;
}