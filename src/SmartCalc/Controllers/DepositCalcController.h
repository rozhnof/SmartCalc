#ifndef DEPOSITCALCCONTROLLERH
#define DEPOSITCALCCONTROLLERH

#include "Controller.h"
#include "../Models/DepositCalcModel.h"

using namespace std;

class DepositCalcController : public Controller {

private:

    DepositCalcModel *model;

public:

    DepositCalcController() {
        model = new DepositCalcModel;
    }

    void setDepositCalculatorInput(const double &depositAmount, const double &interestRate, const QVector<QDate> &frequencyOfPaymentsList, const QDate &startDate, const QDate &endDate, const bool &interestCapitalization, const double &taxRate) {
        model->setDepositAmount(depositAmount);
        model->setInterestRate(interestRate);
        model->setFrequencyOfPayments(frequencyOfPaymentsList);
        model->setStartDate(startDate);
        model->setEndDate(endDate);
        model->setInterestCapitalization(interestCapitalization);
        model->setTaxRate(taxRate);
    }

    void setTopUpList(const multimap<QDate, double> &topUpList) {
        model->setTopUpList(topUpList);
    }

    void setTakeOffList(const multimap<QDate, double> &takeOffList) {
        model->setTakeOffList(takeOffList);
    }

    void getDepositCalculatorOutput(double &accuredInterest, double &totalAmount, double &taxAmount) {
        accuredInterest = model->getAccuredInterest();
        totalAmount = model->getTotalAmount();
        taxAmount = model->getTaxAmount();
    }

    QVector<std::tuple<QDate, QString, double, double>> getGeneralList() const {
        return model->getGeneralList();
    }

    void DepositCalculate() {
        model->Calculate();
    }

    bool Validate(const double &depositAmount, const double &interestRate, const QVector<QDate> &frequencyOfPaymentsList, const QDate &startDate, const QDate &endDate, const bool &interestCapitalization, const double &taxRate, const multimap<QDate, double> &topUpList, const multimap<QDate, double> &takeOffList) {

    }
};

#endif // DEPOSITCALCCONTROLLERH
