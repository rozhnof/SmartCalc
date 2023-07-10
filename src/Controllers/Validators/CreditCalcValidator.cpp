#include <CreditCalcValidator.h>



bool CreditCalcValidator::Validate(const CreditCalculatorInput &input) {
    return (input.creditSum > 0 && input.creditTerm > 0 && input.interestRate >= 0);
}
