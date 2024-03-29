#include "DepositCalcController.h"

bool DepositCalcController::setInput(double depositAmount, double interestRate,
                                     bool interestCapitalization,
                                     double taxRate, QDate startDate,
                                     QDate endDate, QVector<QDate> paymentDays,
                                     std::multimap<QDate, double> topUpList,
                                     std::multimap<QDate, double> takeOffList) {
  DepositCalculatorInput input;

  input.depositAmount = depositAmount;
  input.interestRate = interestRate;
  input.interestCapitalization = interestCapitalization;
  input.taxRate = taxRate;
  input.daysInPeriod =
      ConvertPeriod(startDate, endDate, paymentDays, topUpList, takeOffList);

  bool status = Validate(input);

  if (status) {
    model_.setInput(input);
  }

  return status;
}

std::vector<Day> DepositCalcController::ConvertPeriod(
    QDate startDate, QDate endDate, QVector<QDate> paymentDays,
    std::multimap<QDate, double> topUpList,
    std::multimap<QDate, double> takeOffList) {
  std::vector<Day> days;

  for (QDate itDate = startDate; itDate <= endDate;
       itDate = itDate.addDays(1)) {
    Day currentDay = {};

    currentDay.day = itDate.day();
    currentDay.month = itDate.month();
    currentDay.year = itDate.year();

    currentDay.daysInYear = itDate.daysInYear();

    auto rangeTopUp = topUpList.equal_range(itDate);
    for (auto it = rangeTopUp.first; it != rangeTopUp.second; ++it) {
      currentDay.topUpList.push_back(it->second);
    }

    auto rangeTakeOff = takeOffList.equal_range(itDate);
    for (auto it = rangeTakeOff.first; it != rangeTakeOff.second; ++it) {
      currentDay.takeOffList.push_back(it->second);
    }

    if (paymentDays.indexOf(itDate) >= 0) {
      currentDay.isPaymentDay = true;
    }

    days.push_back(currentDay);
  }
  return days;
}

bool DepositCalcController::Validate(const DepositCalculatorInput& input) {
  return validator_.Validate(input);
}

void DepositCalcController::Calculate() { model_.Calculate(); }

double DepositCalcController::getTotalAmount() {
  return model_.getTotalAmount();
}

double DepositCalcController::getTaxAmount() { return model_.getTaxAmount(); }

double DepositCalcController::getAccuredInterest() {
  return model_.getAccuredInterest();
}

std::vector<std::tuple<QDate, QString, double, double>>
DepositCalcController::getGeneralList() {
  std::vector<std::tuple<Day, std::string, double, double>> generalList =
      model_.getGeneralList();
  std::vector<std::tuple<QDate, QString, double, double>> generalListUI;

  for (const auto& tuple : generalList) {
    QDate date = QDate(std::get<0>(tuple).year, std::get<0>(tuple).month,
                       std::get<0>(tuple).day);
    QString operation = QString::fromStdString(std::get<1>(tuple));
    double operationSum = std::get<2>(tuple);
    double depositSum = std::get<3>(tuple);

    generalListUI.push_back(
        std::make_tuple(date, operation, operationSum, depositSum));
  }
  return generalListUI;
}
