#include "Tests.h"


START_TEST(test9_0) {
    Credit annuity_result = {0};
    Credit dif_result = {0};

    Credit annuity_original = {0};
    Credit dif_original = {0};

    annuity_result.sum = 1000000;
    annuity_result.term = 15;
    annuity_result.percent = 10;

    dif_result.sum = 1000000;
    dif_result.term = 15;
    dif_result.percent = 10;


    annuity_original.total_payment = 1067957.25;
    annuity_original.monthly_payment = 71197.15;
    annuity_original.overpayment = 67957.25;

    dif_original.total_payment = 1066666.67;
    dif_original.first_monthly_payment = 75000;
    dif_original.monthly_payment = 67222.22;
    dif_original.overpayment = 66666.67;

    AnnuityLoan(&annuity_result);
    DifferentiatedLoan(&dif_result);

    ck_assert_double_eq_tol(dif_original.total_payment, dif_result.total_payment, 1e-2);
    ck_assert_double_eq_tol(dif_original.first_monthly_payment, dif_result.first_monthly_payment, 1e-2);
    ck_assert_double_eq_tol(dif_original.monthly_payment, dif_result.monthly_payment, 1e-2);
    ck_assert_double_eq_tol(dif_original.overpayment, dif_result.overpayment, 1e-2);

    ck_assert_double_eq_tol(annuity_original.total_payment, annuity_result.total_payment, 1e-2);
    ck_assert_double_eq_tol(annuity_original.monthly_payment, annuity_result.monthly_payment, 1e-2);
    ck_assert_double_eq_tol(annuity_original.overpayment, annuity_result.overpayment, 1e-2);
}
END_TEST


Suite *test9(void) {
  Suite *s;
  TCase *tc;

  s = suite_create("test9");
  tc = tcase_create("core");

    suite_add_tcase(s, tc);
    tcase_add_test(tc, test9_0);


  return s;
}