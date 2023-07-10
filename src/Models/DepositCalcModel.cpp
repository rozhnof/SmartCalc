#include "DepositCalcModel.h"



DepositCalcModel::DepositCalcModel() {}

void DepositCalcModel::setInput(DepositCalculatorInput input) {
    _input = input;
}

void DepositCalcModel::Calculate() {
    _output =  service.GetDepositCalculationResult(_input);
}

double DepositCalcModel::getTotalAmount() {
    return _output.totalAmount;
}

double DepositCalcModel::getTaxAmount() {
    return _output.taxAmount;
}

double DepositCalcModel::getAccuredInterest() {
    return _output.accuredInterest;
}

std::vector<std::tuple<Day, std::string, double, double> > DepositCalcModel::getGeneralList() {
    return _output.generalList;
}
