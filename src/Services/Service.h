#pragma once


#include "calc.h"
#include "IO.h"
#include <string>
#include <vector>
#include <tuple>


class Service
{
public:
    Service();
    ~Service();

    enum CreditPaymentsType {
        ANNUITY,
        DIFFERENTIATED
    };

    std::string GetPostfixNotation(const std::string &infix);

    double GetCalculationResult(const std::string &postfix, const double &x);

    GraphOutput GetGraphResult(const GraphInput &input);

    CreditCalculatorOutput GetCreditCalculationResult(const CreditCalculatorInput &input, const CreditPaymentsType &type);

    DepositCalculatorOutput GetDepositCalculationResult(const DepositCalculatorInput &input);

private:
    CreditCalculatorOutput AnnuityLoan(const CreditCalculatorInput &input);

    CreditCalculatorOutput DifferentiatedLoan(const CreditCalculatorInput &input);
};


