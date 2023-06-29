#pragma once


#include <iostream>
#include <algorithm>
#include <QString>
#include "../../Services/Service.h"


class CreditCalcValidator {
private:
    CreditCalculatorInput _input;

public:
    CreditCalcValidator(CreditCalculatorInput &input) : _input(input) {}

    bool Validate() {
        return (_input.creditSum > 0 && _input.creditTerm > 0 && _input.interestRate >= 0);
    }
};
