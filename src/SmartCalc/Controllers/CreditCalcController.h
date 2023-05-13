#ifndef CREDITCALCCONTROLLERH
#define CREDITCALCCONTROLLERH

#include "../Models/CreditCalcModel.h"

using namespace std;

class CreditCalcController {

private:

    CreditCalcModel *model;

public:

    CreditCalcController() {
        model = new CreditCalcModel;
    }

    void SetCreditSum(double creditSum) {
        model->creditSum = creditSum;
    }

    void SetCreditTerm(double creditTerm) {
        model->creditTerm = creditTerm;
    }

    void SetInterestRate(double interestRate) {
        model->interestRate = interestRate;
    }

    double GetTotalPayment() {
        return model->totalPayment;
    }

    double GetOverpayment() {
        return model->overpayment;
    }

    QVector<double> GetMonthlyPayments() {
        return model->monthlyPayments;
    }

    QVector<double> GetMonthlyBodyPayments() {
        return model->monthlyBodyPayments;
    }

    QVector<double> GetMonthlyPercentPayments() {
        return model->monthlyPercentPayments;
    }

    void AnnuityLoan() {
        model->AnnuityLoan();
    }

    void DifferentiatedLoan() {
        model->DifferentiatedLoan();
    }
};

#endif // CREDITCALCCONTROLLERH
