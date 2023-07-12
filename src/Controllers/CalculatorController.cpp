#include "CalculatorController.h"

CalculatorController::CalculatorController() {}

bool CalculatorController::Validate(QString &input) {
  return validator_.Validate(input);
}

double CalculatorController::GetResult(QString &input, double x) {
  return model_.Calculate(input.toStdString(), x);
}
