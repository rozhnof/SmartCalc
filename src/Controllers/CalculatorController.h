#pragma once


#include "../Models/CalculatorModel.h"
#include "Validators/InfixNotationValidator.h"
#include <QString>


class CalculatorController {
private:
    InfixNotationValidator _validator;
    CalculatorModel _model;

public:

    CalculatorController();

    bool Validate(QString &input);

    double GetResult(QString &input, double x);
};

