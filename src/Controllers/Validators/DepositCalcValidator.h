#pragma once


#include <iostream>
#include <algorithm>
#include <QString>
#include "../../Services/Service.h"


class DepositCalcValidator {
public:
    bool Validate(const DepositCalculatorInput &input);
};
