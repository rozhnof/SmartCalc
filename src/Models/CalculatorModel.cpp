#include "CalculatorModel.h"

double CalculatorModel::Calculate(std::string infix, double x) {
  infix_ = infix;
  postfix_ = service_.GetPostfixNotation(infix_);
  result_ = service_.GetCalculationResult(postfix_, x);
  return result_;
}
