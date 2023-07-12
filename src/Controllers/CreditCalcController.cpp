#include "CreditCalcController.h"

bool CreditCalcController::setInput(double creditSum, double creditTerm,
                                    double interestRate) {
  CreditCalculatorInput input;

  input.creditSum = creditSum;
  input.creditTerm = creditTerm;
  input.interestRate = interestRate;

  bool status = Validate(input);

  if (status) {
    _model.setInput(input);
  }

  return status;
}

bool CreditCalcController::Validate(CreditCalculatorInput &input) {
  return _validator.Validate(input);
}

void CreditCalcController::Calculate(Service::CreditPaymentsType type) {
  _model.Calculate(type);
}

double CreditCalcController::getTotalPayment() {
  return _model.getTotalPayment();
}

double CreditCalcController::getOverpayment() {
  return _model.getOverpayment();
}

QVector<double> CreditCalcController::getMonthlyPayments() {
  std::vector<double> monthlyPayments = _model.getMonthlyPayments();
  return QVector<double>(monthlyPayments.begin(), monthlyPayments.end());
}

QVector<double> CreditCalcController::getMonthlyBodyPayments() {
  std::vector<double> monthlyBodyPayments = _model.getMonthlyBodyPayments();
  return QVector<double>(monthlyBodyPayments.begin(),
                         monthlyBodyPayments.end());
}

QVector<double> CreditCalcController::getMonthlyPercentPayments() {
  std::vector<double> monthlyPercentPayments =
      _model.getMonthlyPercentPayments();
  return QVector<double>(monthlyPercentPayments.begin(),
                         monthlyPercentPayments.end());
}
