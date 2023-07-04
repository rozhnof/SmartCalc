#pragma once


#include "../Models/calc.h"
#include <string>
#include <vector>
#include <iostream>


struct Day {
    int day;
    int month;
    int year;
    
    int daysInYear;

    std::vector<double> topUpList;
    std::vector<double> takeOffList;

    bool isPaymentDay;
};


struct GraphInput {
    std::string infix;
    std::string postfix;

    int countPoints;
    double xMin;
    double xMax;
    double yMin;
    double yMax;
};

struct GraphOutput {
    std::vector<double> xPoints;
    std::vector<double> yPoints;
};

struct CreditCalculatorInput {
public:
    double creditSum;
    double creditTerm;
    double interestRate;
};

struct CreditCalculatorOutput {
    double totalPayment;
    double overpayment;
    
    std::vector<double> monthlyPayments;
    std::vector<double> monthlyBodyPayments;
    std::vector<double> monthlyPercentPayments;
};

struct DepositCalculatorInput {
    double depositAmount;
    double interestRate;
    double taxRate;
    bool interestCapitalization;
    std::vector<Day> daysInPeriod;
};

struct DepositCalculatorOutput {
    double accuredInterest;
    double totalAmount;
    double taxAmount;

    std::vector<std::tuple<Day, std::string, double, double>> generalList;
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
        char *postfixChr = new char[infix.size() + 3];

        strcpy(infixChr, infix.c_str());
        FromInfixToPostfix(infixChr, postfixChr);

        std::string postfix{postfixChr};

        delete[] infixChr;
        delete[] postfixChr;

        return postfix;
    }

    double GetCalculationResult(const std::string &postfix, const double &x) {
        const char* postfixChr = postfix.c_str();
        return Calculation(postfixChr, x);
    }

    GraphOutput GetGraphResult(const GraphInput &input) {
        GraphOutput output;

        double stepX = (fabs(input.xMin) + fabs(input.xMax)) / input.countPoints;
        for (int i = 0; i < input.countPoints; i++)
        {
            output.xPoints.push_back(input.xMin + stepX * i);
            output.yPoints.push_back(GetCalculationResult(input.postfix, output.xPoints[i]));

            if (output.yPoints[i] > input.yMax || output.yPoints[i] < input.yMin) {
                output.yPoints[i] = NAN;
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

        double accumulatedInterestForPeriod = 0;
        output.totalAmount = input.depositAmount;

        for (auto itDay : input.daysInPeriod) {
            double dailyInterestRate = input.interestRate / itDay.daysInYear / 100;

            if (itDay.isPaymentDay) {
                std::string operationType;
                if (input.interestCapitalization == true) {
                    output.totalAmount += accumulatedInterestForPeriod;
                    operationType = "Капитализация процентов";
                } else {
                    operationType = "Начисление процентов";
                }

                output.generalList.push_back(std::make_tuple(itDay, operationType, accumulatedInterestForPeriod, output.totalAmount));
                output.accuredInterest += accumulatedInterestForPeriod;
                accumulatedInterestForPeriod = 0;
            }

            for (auto it : itDay.topUpList) {
                output.totalAmount += it;
                output.generalList.push_back(std::make_tuple(itDay, "Пополнение", it, output.totalAmount));
            }

            for (auto it : itDay.takeOffList) {
                output.totalAmount -= it;
                output.generalList.push_back(std::make_tuple(itDay, "Снятие", it, output.totalAmount));
            }

            accumulatedInterestForPeriod += output.totalAmount * dailyInterestRate;
        }
        output.taxAmount = output.accuredInterest / 100 * input.taxRate;
        output.accuredInterest -= output.taxAmount;
        output.totalAmount -= output.taxAmount;

        return output;
    }

private:

    CreditCalculatorOutput AnnuityLoan(const CreditCalculatorInput &input) {
        CreditCalculatorOutput output;

        double monthlyInterestRate = input.interestRate / 12 / 100;
        double tmp = pow(1 + monthlyInterestRate, input.creditTerm);
        double monthlyPayment = input.creditSum * monthlyInterestRate * tmp / (tmp - 1);
        double creditSum = input.creditSum;

        output.monthlyPayments.push_back(monthlyPayment);
        output.totalPayment = monthlyPayment * input.creditTerm;
        output.overpayment = output.totalPayment - creditSum;

        for (int i = 0; i < input.creditTerm; i++) {
            output.monthlyPercentPayments.push_back(creditSum * monthlyInterestRate);
            output.monthlyBodyPayments.push_back(monthlyPayment - output.monthlyPercentPayments[i]);
            creditSum -= output.monthlyBodyPayments[i];
        }
        return output;
    }

    CreditCalculatorOutput DifferentiatedLoan(const CreditCalculatorInput &input) {
        CreditCalculatorOutput output;

        double monthlyBodyPayment = input.creditSum / input.creditTerm;
        double monthlyInterestRate = input.interestRate / 12 / 100;

        for (int i = 0; i < input.creditTerm; i++) {
            output.monthlyPercentPayments.push_back((input.creditSum - (monthlyBodyPayment * (i))) * monthlyInterestRate);
            output.monthlyPayments.push_back(monthlyBodyPayment + output.monthlyPercentPayments[i]);
            output.monthlyBodyPayments.push_back(monthlyBodyPayment);
            output.totalPayment += output.monthlyPayments[i];
        }
        output.overpayment = output.totalPayment - input.creditSum;

        return output;
    }
};


