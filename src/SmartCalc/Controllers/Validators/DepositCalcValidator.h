#pragma once


#include <iostream>
#include <algorithm>
#include <QString>
#include "../../Services/Service.h"


class DepositCalcValidator {
private:
    DepositCalculatorInput _input;

public:
    DepositCalcValidator(DepositCalculatorInput &input) : _input(input) {}

    bool Validate() {
        bool status = true;

        if (_input.depositSum <= 0) {
            status = false;
        } else if (_input.depositTerm <= 0) {
            status = false;
        } else if (_input.interestRate < 0) {
            status = false;
        } else if (_input.taxRate < 0) {
            status = false;
        }

        return status;
    }
};
