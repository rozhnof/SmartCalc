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
        double monthlyPayment = creditSum * monthlyInterestRate * pow(1 + monthlyInterestRate, creditTerm) / (pow(1 + monthlyInterestRate, creditTerm) - 1);

        monthlyPayments.append(monthlyPayment);
        totalPayment = monthlyPayment * creditTerm;
        overpayment = totalPayment - creditSum;

        for (int i = 0; i < creditTerm; i++) {
            monthlyPercentPayments.append(creditSum * monthlyInterestRate);
            monthlyBodyPayments.append(monthlyPayment - monthlyPercentPayments[i]);
            creditSum -= monthlyBodyPayments[i];
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
