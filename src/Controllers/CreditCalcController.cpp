#include "CreditCalcController.h"

bool CreditCalcController::setInput(double creditSum, double creditTerm,
                                    double interestRate) {
  CreditCalculatorInput input;

  input.creditSum = creditSum;
  input.creditTerm = creditTerm;
  input.interestRate = interestRate;

  bool status = Validate(input);

  if (status) {
    model_.setInput(input);
  }

  return status;
}

bool CreditCalcController::Validate(CreditCalculatorInput &input) {
  return validator_.Validate(input);
}

void CreditCalcController::Calculate(Service::CreditPaymentsType type) {
  model_.Calculate(type);
}

double CreditCalcController::getTotalPayment() {
  return model_.getTotalPayment();
}

double CreditCalcController::getOverpayment() {
  return model_.getOverpayment();
}

QVector<double> CreditCalcController::getMonthlyPayments() {
  std::vector<double> monthlyPayments = model_.getMonthlyPayments();
  return QVector<double>(monthlyPayments.begin(), monthlyPayments.end());
}

QVector<double> CreditCalcController::getMonthlyBodyPayments() {
  std::vector<double> monthlyBodyPayments = model_.getMonthlyBodyPayments();
  return QVector<double>(monthlyBodyPayments.begin(),
                         monthlyBodyPayments.end());
}

QVector<double> CreditCalcController::getMonthlyPercentPayments() {
  std::vector<double> monthlyPercentPayments =
      model_.getMonthlyPercentPayments();
  return QVector<double>(monthlyPercentPayments.begin(),
                         monthlyPercentPayments.end());
}
