#pragma once


#include "../Services/Service.h"


class DepositCalcModel {
private:
    Service service;

    DepositCalculatorInput _input;
    DepositCalculatorOutput _output;

public:

    DepositCalcModel() {}

    void setInput(const DepositCalculatorInput &input) {
        _input = input;
    }

    void Calculate() {
        _output =  service.GetDepositCalculationResult(_input);
    }

    double getTotalAmount() {
        return _output.totalAmount;
    }

    double getTaxAmount() {
        return _output.taxAmount;
    }

    double getAccuredInterest() {
        return _output.accuredInterest;
    }

    std::vector<std::tuple<Day, std::string, double, double>> getGeneralList() {
        return _output.generalList;
    }
};
