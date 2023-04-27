#include "calc.h"
#include <string>

using namespace std;

class Model {

private:

    char _infix[256];
    char _postfix[256];
    double _x;

public:

    Model() {}

    void SetInput(string infix) {
        strcpy(_infix, infix.c_str());
        FromInfixToPostfix(_infix, _postfix);
    }


    double Calculate(double x) {
        return Calculation(_postfix, x);
    }    


    ~Model() {

    }
};
