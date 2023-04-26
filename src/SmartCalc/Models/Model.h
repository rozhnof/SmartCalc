#include "calc.h"
#include <string>

using namespace std;

class Model {

private:

    char* _infix;
    char* _postfix;
    double _x;

public:

    Model() {}

    void SetInput(string infix) {
        _infix = toCharArray(infix);
        _postfix = new char[1024];
        FromInfixToPostfix(_infix, _postfix);
    }

    double Calculate(double x) {
        return Calculation(_postfix, x);
    }    

    char* toCharArray(string str) {
        char *_postfix = new char[str.size()];
        strcpy(_postfix, str.c_str());
        return _postfix;
    }

    string toString(char* charArray) {
        return charArray;
    }

    ~Model() {
        delete[] _infix;
        delete[] _postfix;
    }
};
