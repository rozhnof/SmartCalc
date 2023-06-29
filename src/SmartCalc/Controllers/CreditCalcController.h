#pragma once


#include "../Models/CreditCalcModel.h"
#include "Validators/CreditCalcValidator.h"


class CreditCalcController {

private:

    CreditCalcModel *model;

public:

    CreditCalcController() {
        model = new CreditCalcModel;
    }

    void setInput(CreditCalculatorInput input) {
        model->setInput(input);
    }

    bool Validate(CreditCalculatorInput input) {
        CreditCalcValidator validator(input);
        return validator.Validate();
    }

    CreditCalculatorOutput Calculate(Service::CreditPaymentsType type) {
        model->Calculate(type);
    }

};
