#include <CalculatorModel.h"



double CalculatorModel::Calculate(std::string infix, double x) {
    _infix = infix;
    _postfix = service.GetPostfixNotation(_infix);
    _result = service.GetCalculationResult(_postfix, x);
    return _result;
}
