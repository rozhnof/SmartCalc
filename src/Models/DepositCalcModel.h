#pragma once

#include "../Services/Service.h"

class DepositCalcModel {
 private:
  Service service;

  DepositCalculatorInput _input;
  DepositCalculatorOutput _output;

 public:
  DepositCalcModel();

  void setInput(DepositCalculatorInput input);

  void Calculate();

  double getTotalAmount();

  double getTaxAmount();

  double getAccuredInterest();

  std::vector<std::tuple<Day, std::string, double, double>> getGeneralList();
};
