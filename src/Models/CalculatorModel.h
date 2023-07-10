#pragma once


#include "../Services/Service.h"
#include <iostream>


class CalculatorModel {

private:
    Service service;

    std::string _infix;
    std::string _postfix;

    double _result;

public:
    double Calculate(std::string infix, double x) {
        _infix = infix;
        _postfix = service.GetPostfixNotation(_infix);
        _result = service.GetCalculationResult(_postfix, x);
        return _result;
    }
};
