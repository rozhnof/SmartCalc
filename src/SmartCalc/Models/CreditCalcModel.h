#ifndef CREDITCALCMODELH
#define CREDITCALCMODELH

#include <QVector>

class CreditCalcModel {

public:
    double creditSum;
    double interestRate;
    double creditTerm;

    double totalPayment;
    double overpayment;

    QVector<double> monthlyPayments;
    QVector<double> monthlyBodyPayments;
    QVector<double> monthlyPercentPayments;

    CreditCalcModel() {}

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
        double tmp = pow(1 + monthlyInterestRate, creditTerm);
        double monthlyPayment = creditSum * monthlyInterestRate * tmp / (tmp - 1);

        monthlyPayments.append(monthlyPayment);
        totalPayment = monthlyPayment * creditTerm;
        overpayment = totalPayment - creditSum;

        for (int i = 0; i < creditTerm; i++) {
            monthlyPercentPayments.append(creditSum * monthlyInterestRate);
            monthlyBodyPayments.append(monthlyPayment - monthlyPercentPayments[i]);
            creditSum -= monthlyPayment;
        }
    }

    void DifferentiatedLoan() {
        ClearData();

        double monthlyBodyPayment = creditSum / creditTerm;
        double monthlyInterestRate = interestRate / 12 / 100;

        for (int i = 0; i < creditTerm; i++) {
            monthlyPercentPayments.append((creditSum - (monthlyBodyPayment * (i))) * monthlyInterestRate);
            monthlyPayments.append(monthlyBodyPayment + monthlyPercentPayments[i]);
            monthlyBodyPayments.append(monthlyBodyPayment);
            totalPayment += monthlyPayments[i];
        }
        overpayment = totalPayment - creditSum;
    }
};

#endif // CREDITCALCMODELH
