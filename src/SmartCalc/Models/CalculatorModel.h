#ifndef CALCULATORMODEL_H
#define CALCULATORMODEL_H

#include "../Services/Service.h"


class CalculatorModel {

private:
    Service service;

    std::string _infix;
    std::string _postfix;
    double _x;

public:

    CalculatorModel() {}
    ~CalculatorModel() {}

    void setInfix(const std::string &infix) {
        _infix = infix;
    }

    void setPostfix(const std::string &postfix) {
        _postfix = postfix;
    }

    void setX(double x) {
        _x = x;
    }

    double Calculate() {
        return Calculate(_infix, _x);
    }

    double Calculate(const std::string &infix) {
        return Calculate(infix, _x);
    }

    double Calculate(const double &x) {
        return Calculate(_infix, x)
    }

    double Calculate(const std::string &infix, const double &x) {
        _postfix = service.GetPostfixNotation(infix);
        return service.GetCalculationResult(_postfix, x);
    }
};


#endif // CALCULATORMODEL_H
