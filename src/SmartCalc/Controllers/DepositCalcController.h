#pragma once


#include "../Models/DepositCalcModel.h"
#include "Validators/DepositCalcValidator.h"


class DepositCalcController {

private:

    DepositCalcModel *model;

public:

    DepositCalcController() {
        model = new DepositCalcModel;
    }

    void setInput(DepositCalculatorInput input) {
        model->setInput(input);
    }

    bool Validate(DepositCalculatorInput input) {
        DepositCalcValidator validator(input);
        return validator.Validate();
    }

    DepositCalculatorOutput Calculate() {
        model->Calculate();
    }
};

