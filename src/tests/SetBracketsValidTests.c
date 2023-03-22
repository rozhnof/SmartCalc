#include "Tests.h"


START_TEST(test12_0) {
    char input[512] = "1(";

    int result = SetOpenBracketValid(input);

    ck_assert_int_eq(0, result);
}
END_TEST

START_TEST(test12_1) {
    char input[512] = ")(";

    int result = SetOpenBracketValid(input);

    ck_assert_int_eq(0, result);
}
END_TEST

START_TEST(test12_2) {
    char input[512] = ".(";

    int result = SetOpenBracketValid(input);

    ck_assert_int_eq(0, result);
}
END_TEST

START_TEST(test12_3) {
    char input[512] = "!(";

    int result = SetOpenBracketValid(input);

    ck_assert_int_eq(0, result);
}
END_TEST

START_TEST(test12_4) {
    char input[512] = "x(";

    int result = SetOpenBracketValid(input);

    ck_assert_int_eq(0, result);
}
END_TEST

START_TEST(test12_5) {
    char input[512] = "1+(2+(3+(4+5)))";

    int result = SetCloseBracketValid(input);

    ck_assert_int_eq(1, result);
}
END_TEST

START_TEST(test12_6) {
    char input[512] = "1+(2+(3+()";

    int result = SetCloseBracketValid(input);

    ck_assert_int_eq(0, result);
}
END_TEST

START_TEST(test12_7) {
    char input[512] = "(1+)";

    int result = SetCloseBracketValid(input);

    ck_assert_int_eq(0, result);
}
END_TEST

Suite *test12(void) {
  Suite *s;
  TCase *tc;

  s = suite_create("test12");
  tc = tcase_create("core");

    suite_add_tcase(s, tc);
    tcase_add_test(tc, test12_0);
    tcase_add_test(tc, test12_1);
    tcase_add_test(tc, test12_2);
    tcase_add_test(tc, test12_3);
    tcase_add_test(tc, test12_4);
    tcase_add_test(tc, test12_5);
    tcase_add_test(tc, test12_6);
    tcase_add_test(tc, test12_7);

  return s;
}