#pragma once

#include <string>
#include <vector>

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
