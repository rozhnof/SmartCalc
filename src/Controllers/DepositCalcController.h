#pragma once


#include "../Models/DepositCalcModel.h"
#include "Validators/DepositCalcValidator.h"
#include <QDate>


class DepositCalcController {
private:
    DepositCalcModel _model;
    DepositCalcValidator _validator;

public:

    bool setInput(double depositAmount, double interestRate, bool interestCapitalization, double taxRate, QDate startDate, QDate endDate, QVector<QDate> paymentDays, std::multimap<QDate, double> topUpList, std::multimap<QDate, double> takeOffList);

    std::vector<Day> ConvertPeriod(QDate startDate, QDate endDate, QVector<QDate> paymentDays, std::multimap<QDate, double> topUpList, std::multimap<QDate, double> takeOffList);

    bool Validate(const DepositCalculatorInput &input);

    void Calculate();

    double getTotalAmount();

    double getTaxAmount();

    double getAccuredInterest();

    std::vector<std::tuple<QDate, QString, double, double>> getGeneralList();
};

