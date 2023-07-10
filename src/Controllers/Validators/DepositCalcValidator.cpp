#include "DepositCalcValidator.h"



bool DepositCalcValidator::Validate(const DepositCalculatorInput &input) {
    bool status = true;

    if (input.depositAmount <= 0) {
        status = false;
    } else if (input.interestRate < 0) {
        status = false;
    } else if (input.taxRate < 0) {
        status = false;
    }

    return status;
}
