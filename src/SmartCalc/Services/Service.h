#include "calc.h"
#include <string>
#include <vector>

class GraphInput {
    std::string infix;

    int countPoints;
    double xMin;
    double xMax;
    double yMin;
    double yMax;
};

class GraphOutput {
    std::vector xPoints;
    std::vector yPoints;
};

class CreditCalculatorInput {
public:
    double creditSum;
    double creditTerm;
    double interestRate;

    CreditCalculatorInput operator=(const CreditCalculatorInput &other) {
        creditSum = other.creditSum;
        creditTerm = other.creditTerm;
        interestRate = other.interestRate;
    }
};

class CreditCalculatorOutput {
    double totalPayment;
    double overpayment;
    std::vector<double> monthlyPayments;
    std::vector<double> monthlyBodyPayments;
    std::vector<double> monthlyPercentPayments;
};

class DepositCalculatorInput {
    double depositSum;
    double depositTerm;
    double interestRate;
    double taxRate;

    bool interestCapitalization;

    std::chrono::time_point<std::chrono::system_clock> startDate;
    std::chrono::time_point<std::chrono::system_clock> frequencyOfPayments;

    std::vector<std::pair<double, double>> topUpList;
    std::vector<std::pair<double, double>> takeOffList;
};

class DepositCalculatorOutput {
    double accuredInterest;
    double totalSum;
    double taxSum;

    std::tuple<double, double, double, double> generalList;
};

class Service
{
private:
public:
    Service() {}
    ~Service() {}

    enum CreditPaymentsType {
        ANNUITY,
        DIFFERENTIATED
    };

    std::string GetPostfixNotation(const std::string &infix) {
        char *infixChr = new char[infix.size() + 1];
        char *postfixChr = new char[infix.size() + 1];

        strcpy(infixChr, infix.c_str());
        FromInfixToPostfix(infixChr, postfixChr);

        std::string postfix{postfixChr};

        delete[] infixChr;
        delete[] postfixChr;

        return postfix;
    }

    double GetCalculationResult(const std::string &postfix, const double &x) {
        char *postfixChr = new char[postfix.size() + 1];

        double calcResult = Calculation(postfixChr, x);
        delete[] postfixChr;

        return calcResult;
    }

    GraphOutput GetGraphResult(const GraphInput &input, const std::string &postfix) {
        GraphOutput output;

        double stepX = (fabs(input.xMin) + fabs(input.xMax)) / input.countPoints;
        for (int i = 0; i < input.countPoints; i++)
        {
            output.xPoints.append(xMin + stepX * i)
            output.yPoints.append(GetCalculationResult(postfix, output.xPoints[i]))

            if (output.yPoints[i] > input.yMax || output.yPoints[i] < input.yMin) {
                output.yPoints[i] = qQNaN();
            }
        }
        return output;
    }

    CreditCalculatorOutput GetCreditCalculationResult(const CreditCalculatorInput &input, const CreditPaymentsType &type) {
        CreditCalculatorOutput output;

        switch (type)
        {
        case ANNUITY:
            output = AnnuityLoan(input);

        case DIFFERENTIATED:
            output = DifferentiatedLoan(input);
        
        default:
            break;
        }
        return output;
    }

    DepositCalculatorOutput GetDepositCalculationResult(const DepositCalculatorInput &input) {
        DepositCalculatorOutput output;

        // void Calculate() {
        //     ClearData();

        //     QDate currentDate = _startDate;
        //     double accumulatedInterestForPeriod = 0;
        //     double depositSum = _depositAmount;

        //     while (currentDate <= _endDate) {
        //         double dailyInterestRate = _interestRate / currentDate.daysInYear() / 100;

        //         for (int year = currentDate.year(); currentDate <= _endDate && year == currentDate.year();) {
        //             currentDate = currentDate.addDays(1);
        //             accumulatedInterestForPeriod += depositSum * dailyInterestRate;

        //             if (_frequencyOfPaymentsList.contains(currentDate)) {
        //                 QString operation_type;
        //                 if (_interestCapitalization == true) {
        //                     depositSum += accumulatedInterestForPeriod;
        //                     operation_type = "Капитализация процентов";
        //                 } else {
        //                     operation_type = "Начисление процентов";
        //                 }
        //                 _generalList.append(std::make_tuple(currentDate, operation_type, accumulatedInterestForPeriod, depositSum));
        //                 _accuredInterest += accumulatedInterestForPeriod;
        //                 accumulatedInterestForPeriod = 0;
        //             }

        //             auto rangeTopUp = _topUpList.equal_range(currentDate);
        //             for (auto it = rangeTopUp.first; it != rangeTopUp.second; ++it) {
        //                 depositSum += it->second;
        //                 _generalList.append(std::make_tuple(currentDate, "Пополнение", it->second, depositSum));
        //             }

        //             auto rangeTakeOff = _takeOffList.equal_range(currentDate);
        //             for (auto it = rangeTakeOff.first; it != rangeTakeOff.second; ++it) {
        //                 depositSum -= it->second;
        //                 _generalList.append(std::make_tuple(currentDate, "Снятие", it->second, depositSum));
        //             }
        //         }
        //     }
        //     _taxAmount = _accuredInterest / 100 * _taxRate;
        //     _accuredInterest -= _taxAmount;
        //     _totalAmount = depositSum + _accuredInterest;
        // }

        return output;
    }

private:

    CreditCalculatorOutput& AnnuityLoan(const CreditCalculatorInput &input) {
        CreditCalculatorOutput output;

        double monthlyInterestRate = input.interestRate / 12 / 100;
        double tmp = pow(1 + input.monthlyInterestRate, input.creditTerm);
        double monthlyPayment = input.creditSum * input.monthlyInterestRate * tmp / (tmp - 1);

        output.monthlyPayments.append(monthlyPayment);
        output.totalPayment = monthlyPayment * input.creditTerm;
        output.overpayment = output.totalPayment - input.creditSum;

        for (int i = 0; i < input.creditTerm; i++) {
            output.monthlyPercentPayments.append(input.creditSum * monthlyInterestRate);
            output.monthlyBodyPayments.append(output.monthlyPayment - output.monthlyPercentPayments[i]);
            input.creditSum -= output.monthlyBodyPayments[i];
        }
        return output;
    }

    CreditCalculatorOutput& DifferentiatedLoan(const CreditCalculatorInput &input) {
        CreditCalculatorOutput output;

        double monthlyBodyPayment = input.creditSum / input.creditTerm;
        double monthlyInterestRate = input.interestRate / 12 / 100;

        for (int i = 0; i < input.creditTerm; i++) {
            output.monthlyPercentPayments.append((input.creditSum - (monthlyBodyPayment * (i))) * input.monthlyInterestRate);
            output.monthlyPayments.append(monthlyBodyPayment + output.monthlyPercentPayments[i]);
            output.monthlyBodyPayments.append(monthlyBodyPayment);
            output.totalPayment += output.monthlyPayments[i];
        }
        output.overpayment = output.totalPayment - input.creditSum;

        return output;
    }


};


