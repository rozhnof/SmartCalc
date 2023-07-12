#pragma once

#include <QDate>

#include "../Models/DepositCalcModel.h"
#include "Validators/DepositCalcValidator.h"

class DepositCalcController {
 private:
  DepositCalcModel model_;
  DepositCalcValidator validator_;

 public:
  bool setInput(double depositAmount, double interestRate,
                bool interestCapitalization, double taxRate, QDate startDate,
                QDate endDate, QVector<QDate> paymentDays,
                std::multimap<QDate, double> topUpList,
                std::multimap<QDate, double> takeOffList);

  double getTotalAmount();
  double getTaxAmount();
  double getAccuredInterest();
  std::vector<std::tuple<QDate, QString, double, double>> getGeneralList();

  std::vector<Day> ConvertPeriod(QDate startDate, QDate endDate,
                                 QVector<QDate> paymentDays,
                                 std::multimap<QDate, double> topUpList,
                                 std::multimap<QDate, double> takeOffList);

  bool Validate(const DepositCalculatorInput &input);

  void Calculate();
};
