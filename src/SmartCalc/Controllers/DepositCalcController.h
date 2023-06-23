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

    void setDepositCalculatorInput(const double &depositAmount, const double &interestRate, const int &placementPeriod, const QVector<QDate> &frequencyOfPaymentsList, const QDate &startDate, const bool &interestCapitalization) {
        model->setDepositAmount(depositAmount);
        model->setInterestRate(interestRate);
        model->setPlacementPeriod(placementPeriod);
        model->setFrequencyOfPayments(frequencyOfPaymentsList);
        model->setStartDate(startDate);
        model->setInterestCapitalization(interestCapitalization);
    }

    void getDepositCalculatorOutput(double &accuredInterest, double &totalAmount, double &taxAmount) {
        accuredInterest = model->getAccuredInterest();
        totalAmount = model->getTotalAmount();
        taxAmount = model->getTaxAmount();
    }

    void DepositCalculate() {
        model->Calculate();
    }
};

#endif // DEPOSITCALCCONTROLLERH
