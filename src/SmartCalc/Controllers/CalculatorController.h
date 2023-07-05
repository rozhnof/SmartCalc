#pragma once


#include "../Models/CalculatorModel.h"
#include "Validators/InfixNotationValidator.h"
#include <QString>


class CalculatorController {

    InfixNotationValidator validator;
public:

    CalculatorController() {}

    bool Validate(QString &input) {
        return validator.Validate(input);
    }

    double GetResult(QString &input, double &x) {
        CalculatorModel model;
        return model.Calculate(input.toStdString(), x);
    }
};

