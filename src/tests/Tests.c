#include "Tests.h"


SRunner *default_srunner_create() {
  SRunner *sr;

  sr = srunner_create(test0());
  srunner_add_suite(sr, test1());
  srunner_add_suite(sr, test2());
  srunner_add_suite(sr, test3());
  srunner_add_suite(sr, test4());
  srunner_add_suite(sr, test5());
  srunner_add_suite(sr, test6());
  srunner_add_suite(sr, test7());
  srunner_add_suite(sr, test8());
  srunner_add_suite(sr, test9());
  srunner_add_suite(sr, test10());
  srunner_add_suite(sr, test11());
  srunner_add_suite(sr, test12());
  srunner_add_suite(sr, test13());
  srunner_add_suite(sr, test14());
  srunner_add_suite(sr, test15());
  srunner_add_suite(sr, test16());
  srunner_add_suite(sr, test17());
  srunner_add_suite(sr, test18());

  return sr;
}

long double readStr(char* input, char* x_input_str) {
    char output[1024] = "";
    long double x_input_value = 0;

    FromInfixToPostfix(input, output);
    sscanf(x_input_str, "%Lf", &x_input_value);
    long double result = Calculation(output, x_input_value);;
    return result;
}

int main(void) {
  int exit_status = 1;
  int number_failed = 0;
  SRunner *sr = NULL;

  sr = default_srunner_create();

  srunner_set_log(sr, "test.log");
  srunner_run_all(sr, CK_NORMAL);

  number_failed = srunner_ntests_failed(sr);
  srunner_free(sr);

  if (number_failed == 0) {
    exit_status = 0;
  }

  return exit_status;
}
