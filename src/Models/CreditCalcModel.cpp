#include "CreditCalcModel.h"

void CreditCalcModel::setInput(CreditCalculatorInput input) { input_ = input; }

void CreditCalcModel::Calculate(Service::CreditPaymentsType type) {
  output_ = service_.GetCreditCalculationResult(input_, type);
}

double CreditCalcModel::getTotalPayment() { return output_.totalPayment; }

double CreditCalcModel::getOverpayment() { return output_.overpayment; }

std::vector<double> CreditCalcModel::getMonthlyPayments() {
  return output_.monthlyPayments;
}

std::vector<double> CreditCalcModel::getMonthlyBodyPayments() {
  return output_.monthlyBodyPayments;
}

std::vector<double> CreditCalcModel::getMonthlyPercentPayments() {
  return output_.monthlyPercentPayments;
}
