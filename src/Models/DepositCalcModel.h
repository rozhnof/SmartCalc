#pragma once

#include "../Services/Service.h"

class DepositCalcModel {
 private:
  Service service_;
  DepositCalculatorInput input_;
  DepositCalculatorOutput output_;

 public:
  DepositCalcModel();

  void setInput(DepositCalculatorInput input);

  double getTotalAmount();
  double getTaxAmount();
  double getAccuredInterest();
  std::vector<std::tuple<Day, std::string, double, double>> getGeneralList();

  void Calculate();
};
