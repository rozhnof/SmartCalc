#include "calc.h"

class Model {
    double Calculate(char* infix, double x) {
        char postfix[1024] = {0};
        FromInfixToPostfix(infix, postfix);
        return Calculation(postfix, x);
    }
};
