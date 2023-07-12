#pragma once

#include <QVector>

#include "../Models/CreditCalcModel.h"
#include "Validators/CreditCalcValidator.h"

class CreditCalcController {
 private:
  CreditCalcModel model_;
  CreditCalcValidator validator_;

 public:
  bool setInput(double creditSum, double creditTerm, double interestRate);

  double getTotalPayment();
  double getOverpayment();
  QVector<double> getMonthlyPayments();
  QVector<double> getMonthlyBodyPayments();
  QVector<double> getMonthlyPercentPayments();

  bool Validate(CreditCalculatorInput &input);

  void Calculate(Service::CreditPaymentsType type);
};
