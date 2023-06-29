#pragma once


#include "../Services/Service.h"


class DepositCalcModel {
private:
    Service service;

    DepositCalculatorInput _input;
    DepositCalculatorOutput _output;

public:

    DepositCalcModel() {}

    void setInput(const DepositCalculatorInput &input) {
        _input = input;
    }

    DepositCalculatorOutput Calculate() {
        return service.GetDepositCalculationResult(_input);
    }
};
