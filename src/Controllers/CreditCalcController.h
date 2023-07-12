#pragma once

#include <QVector>

#include "../Models/CreditCalcModel.h"
#include "Validators/CreditCalcValidator.h"

class CreditCalcController {
 private:
  CreditCalcModel _model;
  CreditCalcValidator _validator;

 public:
  bool setInput(double creditSum, double creditTerm, double interestRate);

  bool Validate(CreditCalculatorInput &input);

  void Calculate(Service::CreditPaymentsType type);

  double getTotalPayment();

  double getOverpayment();

  QVector<double> getMonthlyPayments();

  QVector<double> getMonthlyBodyPayments();

  QVector<double> getMonthlyPercentPayments();
};
