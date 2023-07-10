#ifndef CREDITCALCMODELH
#define CREDITCALCMODELH

#include "../Services/Service.h"


class CreditCalcModel {
private:
    Service service;

    CreditCalculatorInput _input;
    CreditCalculatorOutput _output;

public:
    void setInput(CreditCalculatorInput input);

    void Calculate(Service::CreditPaymentsType type);

    double getTotalPayment();

    double getOverpayment();

    std::vector<double> getMonthlyPayments();

    std::vector<double> getMonthlyBodyPayments();

    std::vector<double> getMonthlyPercentPayments();
};


#endif // CREDITCALCMODELH
