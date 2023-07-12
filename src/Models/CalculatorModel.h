#pragma once

#include <iostream>

#include "../Services/Service.h"

class CalculatorModel {
 private:
  Service service_;
  std::string infix_;
  std::string postfix_;
  double result_;

 public:
  double Calculate(std::string infix, double x);
};
