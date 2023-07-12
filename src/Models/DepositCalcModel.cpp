#include "DepositCalcModel.h"

DepositCalcModel::DepositCalcModel() {}

void DepositCalcModel::setInput(DepositCalculatorInput input) {
  input_ = input;
}

void DepositCalcModel::Calculate() {
  output_ = service_.GetDepositCalculationResult(input_);
}

double DepositCalcModel::getTotalAmount() { return output_.totalAmount; }

double DepositCalcModel::getTaxAmount() { return output_.taxAmount; }

double DepositCalcModel::getAccuredInterest() {
  return output_.accuredInterest;
}

std::vector<std::tuple<Day, std::string, double, double> >
DepositCalcModel::getGeneralList() {
  return output_.generalList;
}
