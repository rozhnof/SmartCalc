#ifndef CREDITCALCMODELH
#define CREDITCALCMODELH

#include "../Services/Service.h"


class CreditCalcModel {
private:
    Service service;

    CreditCalculatorInput _input;
    CreditCalculatorOutput _output;

public:

    CreditCalcModel() {}

    void setInput(const CreditCalculatorInput &input) {
        _input = input;
    }

    CreditCalculatorOutput Calculate(Service::CreditPaymentsType type) {
        return service.GetCreditCalculationResult(_input, type);
    }
};


#endif // CREDITCALCMODELH
