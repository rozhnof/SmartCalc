#include "Tests.h"


START_TEST(test11_0) {
    char input[512] = ".";

    int result = SetDotValid(input);

    ck_assert_int_eq(0, result);
}
END_TEST

START_TEST(test11_1) {
    char input[512] = "(.";

    int result = SetDotValid(input);

    ck_assert_int_eq(0, result);
}
END_TEST

START_TEST(test11_2) {
    char input[512] = "+.";

    int result = SetDotValid(input);

    ck_assert_int_eq(0, result);
}
END_TEST

START_TEST(test11_3) {
    char input[512] = "1..";

    int result = SetDotValid(input);

    ck_assert_int_eq(0, result);
}
END_TEST


Suite *test11(void) {
  Suite *s;
  TCase *tc;

  s = suite_create("test11");
  tc = tcase_create("core");

    suite_add_tcase(s, tc);
    tcase_add_test(tc, test11_0);
    tcase_add_test(tc, test11_1);
    tcase_add_test(tc, test11_2);
    tcase_add_test(tc, test11_3);

  return s;
}