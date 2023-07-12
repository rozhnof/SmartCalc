#pragma once

#include <QString>

#include "../Models/CalculatorModel.h"
#include "Validators/InfixNotationValidator.h"

class CalculatorController {
 private:
  InfixNotationValidator _validator;
  CalculatorModel _model;

 public:
  CalculatorController();

  bool Validate(QString &input);

  double GetResult(QString &input, double x);
};
