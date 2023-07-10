#pragma once


#include <iostream>
#include <algorithm>
#include <QString>
#include "../../Services/Service.h"


class CreditCalcValidator {
public:
    bool Validate(const CreditCalculatorInput &input);
};
