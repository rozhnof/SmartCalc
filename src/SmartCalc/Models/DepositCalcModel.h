#ifndef DEPOSITCALCMODELH
#define DEPOSITCALCMODELH

#include <QVector>
#include "Model.h"

class DepositCalcModel {

public:
    double depositSum;
    double interestRate;
    double depositTerm;

    double totalPayment;
    double overpayment;

    QVector<double> monthlyPayments;
    QVector<double> monthlyBodyPayments;
    QVector<double> monthlyPercentPayments;

    DepositCalcModel() {}

    void ClearData() {
        monthlyPayments.clear();
        monthlyBodyPayments.clear();
        monthlyPercentPayments.clear();
        totalPayment = 0;
        overpayment = 0;
    }

    void AnnuityLoan() {
        ClearData();

        double monthlyInterestRate = interestRate / 12 / 100;
        double monthlyPayment = depositSum * monthlyInterestRate * pow(1 + monthlyInterestRate, depositTerm) / (pow(1 + monthlyInterestRate, depositTerm) - 1);

        monthlyPayments.append(monthlyPayment);
        totalPayment = monthlyPayment * depositTerm;
        overpayment = totalPayment - depositSum;

        for (int i = 0; i < depositTerm; i++) {
            monthlyPercentPayments.append(depositSum * monthlyInterestRate);
            monthlyBodyPayments.append(monthlyPayment - monthlyPercentPayments[i]);
            depositSum -= monthlyBodyPayments[i];
        }
    }

    void DifferentiatedLoan() {
        ClearData();

        double monthlyBodyPayment = depositSum / depositTerm;
        double monthlyInterestRate = interestRate / 12 / 100;

        for (int i = 0; i < depositTerm; i++) {
            monthlyPercentPayments.append((depositSum - (monthlyBodyPayment * (i))) * monthlyInterestRate);
            monthlyPayments.append(monthlyBodyPayment + monthlyPercentPayments[i]);
            monthlyBodyPayments.append(monthlyBodyPayment);
            totalPayment += monthlyPayments[i];
        }
        overpayment = totalPayment - depositSum;
    }
};

#endif // DEPOSITCALCMODELH
