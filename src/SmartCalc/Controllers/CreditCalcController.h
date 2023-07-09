#pragma once


#include "../Models/CreditCalcModel.h"
#include "Validators/CreditCalcValidator.h"
#include <QVector>

class CreditCalcController {
private:
    CreditCalcModel _model;
    CreditCalcValidator _validator;

public:
    bool setInput(double creditSum, double creditTerm, double interestRate) {
        CreditCalculatorInput input;

        input.creditSum = creditSum;
        input.creditTerm = creditTerm;
        input.interestRate = interestRate;

        bool status = Validate(input);

        if (status) {
            _model.setInput(input);
        }

        return status;
    }

    bool Validate(CreditCalculatorInput &input) {
        return _validator.Validate(input);
    }

    void Calculate(Service::CreditPaymentsType type) {
        _model.Calculate(type);
    }

    double getTotalPayment() {
        return _model.getTotalPayment();
    }

    double getOverpayment() {
        return _model.getOverpayment();
    }

    QVector<double> getMonthlyPayments() {
        std::vector<double> monthlyPayments = _model.getMonthlyPayments();
        return QVector<double>(monthlyPayments.begin(), monthlyPayments.end());
    }

    QVector<double> getMonthlyBodyPayments() {
        std::vector<double> monthlyBodyPayments = _model.getMonthlyBodyPayments();
        return QVector<double>(monthlyBodyPayments.begin(), monthlyBodyPayments.end());
    }

    QVector<double> getMonthlyPercentPayments() {
        std::vector<double> monthlyPercentPayments = _model.getMonthlyPercentPayments();
        return QVector<double>(monthlyPercentPayments.begin(), monthlyPercentPayments.end());
    }
};
