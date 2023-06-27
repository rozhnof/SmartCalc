#ifndef DEPOSITCALCMODELH
#define DEPOSITCALCMODELH

#include "../Services/Service.h"


class DepositCalcModel {
private:
    Service service;

    DepositCalculatorInput _input;
    DepositCalculatorOutput _output;

public:

    CreditCalcModel() {}

    void setInput(const DepositCalculatorInput &input) {
        _input = input;
    }

    DepositCalculatorOutput Calculate() {
        return service.GetDepositCalculationResult(_input);
    }
};

#endif // DEPOSITCALCMODELH
