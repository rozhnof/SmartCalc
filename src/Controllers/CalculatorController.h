#pragma once

#include <QString>

#include "../Models/CalculatorModel.h"
#include "Validators/InfixNotationValidator.h"

class CalculatorController {
 private:
  InfixNotationValidator validator_;
  CalculatorModel model_;

 public:
  CalculatorController();

  bool Validate(QString &input);

  double GetResult(QString &input, double x);
};
