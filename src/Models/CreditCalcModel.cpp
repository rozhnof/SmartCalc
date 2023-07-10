#include <CreditCalcModel.h>



void CreditCalcModel::setInput(CreditCalculatorInput input) {
    _input = input;
}

void CreditCalcModel::Calculate(Service::CreditPaymentsType type) {
    _output = service.GetCreditCalculationResult(_input, type);
}

double CreditCalcModel::getTotalPayment() {
    return _output.totalPayment;
}

double CreditCalcModel::getOverpayment() {
    return _output.overpayment;
}

std::vector<double> CreditCalcModel::getMonthlyPayments() {
    return _output.monthlyPayments;
}

std::vector<double> CreditCalcModel::getMonthlyBodyPayments() {
    return _output.monthlyBodyPayments;
}

std::vector<double> CreditCalcModel::getMonthlyPercentPayments() {
    return _output.monthlyPercentPayments;
}
