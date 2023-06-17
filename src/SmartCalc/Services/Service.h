#include "calc.h"

class Converter
{
private:
public:
    Converter() {}
    ~Converter() {}

    std::string GetPostfixNotation(std::string infix) {
        char infixChr = new char[infix.size()];
        char postfixChr = new char[infix.size()];

        strcpy(_infix, infix.c_str());
        FromInfixToPostfix(infixChr, postfixChr);

        std::string postfix{postfixChr};

        delete infixChr[];
        delete postfixChr[];

        return postfix;
    }
};

class Calculator
{
private:
public:
    Calculator() {}
    ~Calculator() {}

    double GetCalculationResult(std::string postfix, double x = 0) {
        char postfixChr = new char[postfix.size()];
        double calcResult = Calculation(postfixChr, x);
        delete postfixChr[];
        return calcResult;
    }
};



