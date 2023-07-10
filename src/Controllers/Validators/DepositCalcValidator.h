#pragma once


#include <iostream>
#include <algorithm>
#include <QString>
#include "../../Services/Service.h"


class DepositCalcValidator {
public:
    bool Validate(const DepositCalculatorInput &input) {
        bool status = true;

        if (input.depositAmount <= 0) {
            status = false;
        } else if (input.interestRate < 0) {
            status = false;
        } else if (input.taxRate < 0) {
            status = false;
        }

        return status;
    }
};
