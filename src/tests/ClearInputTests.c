#include "Tests.h"


START_TEST(test18_0) {
    char input[512] = "10";
    char input_after_clear[512] = "1";
    ClearInput(input);
    ck_assert_str_eq(input_after_clear, input);
}
END_TEST

START_TEST(test18_1) {
    char input[512] = "1+xmodsin(";
    char input_after_clear[512] = "1+xmod";
    ClearInput(input);
    ck_assert_str_eq(input_after_clear, input);
}
END_TEST

START_TEST(test18_2) {
    char input[512] = "1+xmod";
    char input_after_clear[512] = "1+x";
    ClearInput(input);
    ck_assert_str_eq(input_after_clear, input);
}
END_TEST

START_TEST(test18_3) {
    char input[512] = "1+x";
    char input_after_clear[512] = "1+";
    ClearInput(input);
    ck_assert_str_eq(input_after_clear, input);
}
END_TEST

START_TEST(test18_4) {
    char input[512] = "1+";
    char input_after_clear[512] = "1";
    ClearInput(input);
    ck_assert_str_eq(input_after_clear, input);
}
END_TEST

START_TEST(test18_5) {
    char input[512] = "1";
    char input_after_clear[512] = "";
    ClearInput(input);
    ck_assert_str_eq(input_after_clear, input);
}
END_TEST


Suite *test18(void) {
  Suite *s;
  TCase *tc;

  s = suite_create("test18");
  tc = tcase_create("core");

    suite_add_tcase(s, tc);
    tcase_add_test(tc, test18_0);


  return s;
}