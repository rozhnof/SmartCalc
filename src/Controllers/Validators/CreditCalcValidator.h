#pragma once


#include <iostream>
#include <algorithm>
#include <QString>
#include "../../Services/Service.h"


class CreditCalcValidator {
public:
    bool Validate(const CreditCalculatorInput &input) {
        return (input.creditSum > 0 && input.creditTerm > 0 && input.interestRate >= 0);
    }
};
