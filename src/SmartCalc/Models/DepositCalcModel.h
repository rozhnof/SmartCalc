#ifndef DEPOSITCALCMODELH
#define DEPOSITCALCMODELH

#include <QVector>
#include "Model.h"
#include <iostream>
#include <QDate>

class DepositCalcModel {
private:
    double _depositAmount;
    double _interestRate;
    int _placementPeriod;
    QVector<QDate> _frequencyOfPaymentsList;
    QDate _startDate;
    bool _interestCapitalization = false;

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

    void setPlacementPeriod(const int &placementPeriod) {
        _placementPeriod = placementPeriod;
    }

    void setFrequencyOfPayments(const QVector<QDate> &frequencyOfPaymentsList) {
        _frequencyOfPaymentsList = frequencyOfPaymentsList;
    }

    void setStartDate(const QDate &startDate) {
        _startDate = startDate;
    }

    void setInterestCapitalization(const bool &interestCapitalization) {
        _interestCapitalization = interestCapitalization;
    }

    double getAccuredInterest() const {
        return _accuredInterest;
    }

    double getTotalAmount() const {
        return _totalAmount;
    }

    double getTaxAmount() const {
        return _taxAmount;
    }

    void Calculate() {
        QDate currentDate = _startDate;
        QDate endDate = _startDate.addDays(_placementPeriod);
        int accumulatedInterestForPeriod = 0;
        _accuredInterest = 0;

        _totalAmount = _depositAmount;
        while (currentDate <= endDate) {
            double dailyInterestRate = _interestRate / currentDate.daysInYear() / 100;
            for (int year = currentDate.year(); currentDate <= endDate && year == currentDate.year(); currentDate = currentDate.addDays(1)) {
                accumulatedInterestForPeriod += _totalAmount * dailyInterestRate;
                if (_frequencyOfPaymentsList.contains(currentDate)) {
                    if (_interestCapitalization == true) {
                        _totalAmount += accumulatedInterestForPeriod;
                    }
                    _accuredInterest += accumulatedInterestForPeriod;
                    accumulatedInterestForPeriod = 0;
                }
            }
        }
        _accuredInterest += accumulatedInterestForPeriod;
        if (_interestCapitalization == false) {
            _totalAmount += accumulatedInterestForPeriod;
        } else {
            _totalAmount += _accuredInterest;
        }
    }
};

#endif // DEPOSITCALCMODELH
