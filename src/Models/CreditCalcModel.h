#pragma once

#include "../Services/Service.h"

class CreditCalcModel {
 private:
  Service service_;
  CreditCalculatorInput input_;
  CreditCalculatorOutput output_;

 public:
  void setInput(CreditCalculatorInput input);

  double getTotalPayment();
  double getOverpayment();
  std::vector<double> getMonthlyPayments();
  std::vector<double> getMonthlyBodyPayments();
  std::vector<double> getMonthlyPercentPayments();

  void Calculate(Service::CreditPaymentsType type);
};
