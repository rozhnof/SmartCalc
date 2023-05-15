#ifndef DEPOSITCALCCONTROLLERH
#define DEPOSITCALCCONTROLLERH

#include "Controller.h"
#include "../Models/DepositCalcModel.h"

using namespace std;

class DepositCalcController : public Controller {

private:

    DepositCalcModel *model;

public:

    DepositCalcController() {
        model = new DepositCalcModel;
    }

    void SetDepositSum(double depositSum) {
        model->depositSum = depositSum;
    }

    void SetDepositTerm(double depositTerm) {
        model->depositTerm = depositTerm;
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

#endif // DEPOSITCALCCONTROLLERH
