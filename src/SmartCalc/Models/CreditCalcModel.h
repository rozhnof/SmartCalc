#ifndef CREDITCALCMODELH
#define CREDITCALCMODELH

#include "../Services/Service.h"


class CreditCalcModel {
private:
    Service service;

    CreditCalculatorInput _input;
    CreditCalculatorOutput _output;

public:
    void setInput(CreditCalculatorInput input) {
        _input = input;
    }

    void Calculate(Service::CreditPaymentsType type) {
        _output = service.GetCreditCalculationResult(_input, type);
    }

    double getTotalPayment() {
        return _output.totalPayment;
    }

    double getOverpayment() {
        return _output.overpayment;
    }

    std::vector<double> getMonthlyPayments() {
        return _output.monthlyPayments;
    }

    std::vector<double> getMonthlyBodyPayments() {
        return _output.monthlyBodyPayments;
    }

    std::vector<double> getMonthlyPercentPayments() {
        return _output.monthlyPercentPayments;
    }
};


#endif // CREDITCALCMODELH
