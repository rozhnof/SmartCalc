#include "Tests.h"


SRunner *default_srunner_create() {
  SRunner *sr;

  sr = srunner_create(test0());
  srunner_add_suite(sr, test1());
  srunner_add_suite(sr, test2());
  srunner_add_suite(sr, test3());
  srunner_add_suite(sr, test4());
  srunner_add_suite(sr, test5());

  return sr;
}

double readStr(char* input, char* x_input_str) {
    double x_input_value = 0;
    char *postfix = FromInfixToPostfix(input);
    sscanf(x_input_str, "%lf", &x_input_value);
    double result = Calculation(postfix, x_input_value);
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
