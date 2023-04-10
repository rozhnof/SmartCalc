#include "calc.h"

class Model {

private:
    char postfix[1024] = {0};


public:
    void Convert(char* infix) {
        FromInfixToPostfix(infix, postfix);
    }

    double Calculate(double x) {
        return Calculation(postfix, x);
    }    
};
