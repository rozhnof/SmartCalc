#ifndef DEPOSITCALCMODELH
#define DEPOSITCALCMODELH

#include <QVector>
#include "Model.h"
#include <iostream>
#include <QDate>
#include <tuple>
#include <map>


class DepositCalcModel {
private:
    double _depositAmount;
    double _interestRate;
    QVector<QDate> _frequencyOfPaymentsList;
    QDate _startDate;
    QDate _endDate;
    bool _interestCapitalization;
    double _taxRate;

    multimap<QDate, double> _topUpList;
    multimap<QDate, double> _takeOffList;
    QVector<std::tuple<QDate, QString, double, double>> _generalList;

    double _accuredInterest = 0;
    double _totalAmount = 0;
    double _taxAmount = 0;

public:
    void setDepositAmount(const double &depositAmount) {
        _depositAmount = depositAmount;
    }

    void setInterestRate(const double &interestRate) {
        _interestRate = interestRate;
    }

    void setFrequencyOfPayments(const QVector<QDate> &frequencyOfPaymentsList) {
        _frequencyOfPaymentsList = frequencyOfPaymentsList;
    }

    void setStartDate(const QDate &startDate) {
        _startDate = startDate;
    }

    void setEndDate(const QDate &endDate) {
        _endDate = endDate;
    }

    void setInterestCapitalization(const bool &interestCapitalization) {
        _interestCapitalization = interestCapitalization;
    }

    void setTaxRate(const double &taxRate) {
        _taxRate = taxRate;
    }

    void setTopUpList(const multimap<QDate, double> &topUpList) {
        _topUpList = topUpList;
    }

    void setTakeOffList(const multimap<QDate, double> &takeOffList) {
        _takeOffList = takeOffList;
    }

    double getAccuredInterest() {
        return _accuredInterest;
    }

    double getTotalAmount() {
        return _totalAmount;
    }

    double getTaxAmount() {
        return _taxAmount;
    }

    QVector<std::tuple<QDate, QString, double, double>> getGeneralList() const {
        return _generalList;
    }

    void ClearData() {
        _accuredInterest = 0;
        _totalAmount = 0;
        _taxAmount = 0;
        _generalList.clear();
    }

    void Calculate() {
        ClearData();

        QDate currentDate = _startDate;
        double accumulatedInterestForPeriod = 0;
        double depositSum = _depositAmount;

        while (currentDate <= _endDate) {
            double dailyInterestRate = _interestRate / currentDate.daysInYear() / 100;

            for (int year = currentDate.year(); currentDate <= _endDate && year == currentDate.year();) {
                currentDate = currentDate.addDays(1);
                accumulatedInterestForPeriod += depositSum * dailyInterestRate;

                if (_frequencyOfPaymentsList.contains(currentDate)) {
                    QString operation_type;
                    if (_interestCapitalization == true) {
                        depositSum += accumulatedInterestForPeriod;
                        operation_type = "Капитализация процентов";
                    } else {
                        operation_type = "Начисление процентов";
                    }
                    _generalList.append(std::make_tuple(currentDate, operation_type, accumulatedInterestForPeriod, depositSum));
                    _accuredInterest += accumulatedInterestForPeriod;
                    accumulatedInterestForPeriod = 0;
                }

                auto rangeTopUp = _topUpList.equal_range(currentDate);
                for (auto it = rangeTopUp.first; it != rangeTopUp.second; ++it) {
                    depositSum += it->second;
                    _generalList.append(std::make_tuple(currentDate, "Пополнение", it->second, depositSum));
                }

                auto rangeTakeOff = _takeOffList.equal_range(currentDate);
                for (auto it = rangeTakeOff.first; it != rangeTakeOff.second; ++it) {
                    depositSum -= it->second;
                    _generalList.append(std::make_tuple(currentDate, "Снятие", it->second, depositSum));
                }
            }
        }
        _taxAmount = _accuredInterest / 100 * _taxRate;
        _accuredInterest -= _taxAmount;
        _totalAmount = depositSum + _accuredInterest;
    }
};

#endif // DEPOSITCALCMODELH
