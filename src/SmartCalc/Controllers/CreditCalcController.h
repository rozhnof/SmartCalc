#pragma once


#include "../Models/CreditCalcModel.h"
#include "Validators/CreditCalcValidator.h"
#include <QVector>

class CreditCalcController {
private:
    CreditCalcModel *model;

public:

    CreditCalcController() {
        model = new CreditCalcModel;
    }

    bool setInput(double creditSum, double creditTerm, double interestRate) {
        CreditCalculatorInput input;

        input.creditSum = creditSum;
        input.creditTerm = creditTerm;
        input.interestRate = interestRate;

        bool status = Validate(input);

        if (status) {
            model->setInput(input);
        }

        return status;
    }

    bool Validate(CreditCalculatorInput input) {
        CreditCalcValidator validator(input);
        return validator.Validate();
    }

    void Calculate(Service::CreditPaymentsType type) {
        model->Calculate(type);
    }

    double getTotalPayment() {
        return model->getTotalPayment();
    }

    double getOverpayment() {
        return model->getOverpayment();
    }

    QVector<double> getMonthlyPayments() {
        std::vector<double> monthlyPayments = model->getMonthlyPayments();
        return QVector<double>(monthlyPayments.begin(), monthlyPayments.end());
    }

    QVector<double> getMonthlyBodyPayments() {
        std::vector<double> monthlyBodyPayments = model->getMonthlyBodyPayments();
        return QVector<double>(monthlyBodyPayments.begin(), monthlyBodyPayments.end());
    }

    QVector<double> getMonthlyPercentPayments() {
        std::vector<double> monthlyPercentPayments = model->getMonthlyPercentPayments();
        return QVector<double>(monthlyPercentPayments.begin(), monthlyPercentPayments.end());
    }
};
