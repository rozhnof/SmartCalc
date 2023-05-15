#ifndef CALCULATORMODEL_H
#define CALCULATORMODEL_H

#include "calc.h"
#include "Model.h"

using namespace std;

class CalculatorModel {

private:

    char _infix[256];
    char _postfix[256];
    double _x;

public:

    CalculatorModel() {}
    ~CalculatorModel() {}

    void SetInput(string infix) {
        strcpy(_infix, infix.c_str());
        FromInfixToPostfix(_infix, _postfix);
    }

    double Calculate(double x) {
        return Calculation(_postfix, x);
    }
};


#endif // CALCULATORMODEL_H
