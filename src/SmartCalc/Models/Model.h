#include "calc.h"

class Model {
    char postfix[1024] = {0};

    void Convert(char* infix) {
        FromInfixToPostfix(infix, postfix);
    }

    double Calculate(double x) {
        return Calculation(postfix, x);
    }

    
};
