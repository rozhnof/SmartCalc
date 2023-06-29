#pragma once


#include "../Models/CalculatorModel.h"
#include "Validators/CalcValidator.h"
#include <QString>


class CalculatorController {

public:

    CalculatorController() {}

    bool Validate(QString &input) {
        InfixNotationValidator validator(input);
        return validator.Validate();
    }

    double GetResult(QString &input, double &x) {
        CalculatorModel model;
        return model.Calculate(input.toStdString(), x);
    }
};

