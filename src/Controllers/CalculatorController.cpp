#include <CalculatorController.h>



CalculatorController::CalculatorController() {}

bool CalculatorController::Validate(QString &input) {
    return _validator.Validate(input);
}

double CalculatorController::GetResult(QString &input, double x) {
    return _model.Calculate(input.toStdString(), x);
}
