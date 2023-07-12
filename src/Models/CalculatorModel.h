#pragma once

#include <iostream>

#include "../Services/Service.h"

class CalculatorModel {
 private:
  Service service;

  std::string _infix;
  std::string _postfix;

  double _result;

 public:
  double Calculate(std::string infix, double x);
};
