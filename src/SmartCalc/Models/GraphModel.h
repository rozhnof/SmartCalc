#ifndef GRAPHMODEL_H
#define GRAPHMODEL_H

#include "Model.h"
#include "Calc.h"

class GraphModel {

private:

    char _infix[256];
    char _postfix[256];
    double _x;

public:

    GraphModel() {}
    ~GraphModel() {}

    void SetInput(string infix) {
        strcpy(_infix, infix.c_str());
        FromInfixToPostfix(_infix, _postfix);
    }

    double Calculate(double x) {
        return Calculation(_postfix, x);
    }
};


#endif // GRAPHMODEL_H
