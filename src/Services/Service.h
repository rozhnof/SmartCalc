#pragma once

#include <string>
#include <tuple>
#include <vector>

#include "IO.h"
#include "calc.h"

class Service {
 public:
  enum CreditPaymentsType { ANNUITY, DIFFERENTIATED };

  std::string GetPostfixNotation(const std::string &infix);
  double GetCalculationResult(const std::string &postfix, const double &x);

  GraphOutput GetGraphResult(const GraphInput &input);

  CreditCalculatorOutput GetCreditCalculationResult(
      const CreditCalculatorInput &input, const CreditPaymentsType &type);

  DepositCalculatorOutput GetDepositCalculationResult(
      const DepositCalculatorInput &input);

 private:
  CreditCalculatorOutput AnnuityLoan(const CreditCalculatorInput &input);
  CreditCalculatorOutput DifferentiatedLoan(const CreditCalculatorInput &input);
};
