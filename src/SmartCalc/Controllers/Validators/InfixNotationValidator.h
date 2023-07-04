#pragma once


#include <iostream>
#include <algorithm>
#include <QString>
#include <unordered_map>


class InfixNotationValidator {
private:
    int status = 0;

    enum Lexemas {
        NUMBER = 0b0000000001,
        OPERATOR = 0b0000000010,
        UNARY_OPERATOR = 0b0000000100,
        FUNCTION = 0b0000001000,
        OPEN_BRACKET = 0b0000010000,
        CLOSE_BRACKET = 0b0000100000,
        X = 0b0001000000,
        DOT = 0b0010000000,
        FACTORIAL = 0b0100000000,
        EXP = 0b1000000000
    };

    int _bracketCount = 0;
    int _dotCount = 0;

    bool _functionStatus = true;

    QString &_input;

public:
    InfixNotationValidator(QString &input) : _input(input) {}

    bool isUnaryOperator(QChar &lexema) {
        if (lexema == '+' || lexema == '-') {
            return true;
        }
        return false;
    }

    bool isOperator(const QChar &lexema) {
        QString operators = "+-/*^%";

        if (operators.indexOf(lexema) != -1) {
            return true;
        } else {
            return false;
        }
    }

    bool isNumber(const QChar &symbol) {
        return (symbol >= '0' && symbol <= '9');
    }

    int isFunction(QString &lexema, int startIndex) {
        std::unordered_map<QChar, QString> functions{{'s',"sin"}, {'c', "cos"}, {'t', "tan"}, {'S', "asin"}, {'C', "acos"}, {'T', "atan"}, {'q', "sqrt"}, {'l', "ln"}, {'L', "log"}};

        for (auto &it : functions) {
            int funtionSize = it.second.size();
            if (lexema.size() >= funtionSize && lexema.mid(startIndex, funtionSize) == it.second) {
                lexema.replace(startIndex, funtionSize, it.first);
                return true;
            }
        }

        return false;
    }

    bool Validate() {
        status = NUMBER | UNARY_OPERATOR | FUNCTION | OPEN_BRACKET | X;

        if (_input.size() == 0) {
            return false;
        }

        for (int i = 0; i < _input.size(); i++) {
            if (isNumber(_input[i])) {
                SetNumber();
            } else if (isOperator(_input[i])) {
                SetOperator();
            } else if (isFunction(_input, i)) {
                SetFunction();
            } else if (_input[i] == 'x') {
                SetX();
            } else if (_input[i] == '(') {
                SetOpenBracket();
            } else if (_input[i] == ')') {
                SetCloseBracket();
            } else if (_input[i] == '.') {
                SetDot();
            } else if (_input[i] == '!') {
                SetFactorial();
            } else if (_input[i] == 'e' || _input[i] == 'E') {
                SetExp();
            } else {
                return false;
            }

            if (!status) {
                return false;
            }
        }

        if (_bracketCount != 0 || _input.back() == '(' || isOperator(_input.back()) || !(status)) {
            return false;
        }

        return (status && _functionStatus);
    }

    void SetNumber() {
        if (status & NUMBER) {
            status = NUMBER | OPERATOR | DOT | EXP | CLOSE_BRACKET;

            if (_dotCount == 0) {
                status |= FACTORIAL;
            }
        } else {
            status = 0;
        }
    }

    void SetOperator() {
        if (status & OPERATOR) {
            status = NUMBER | FUNCTION | OPEN_BRACKET | X | UNARY_OPERATOR;
            _dotCount = 0;
        } else if (status & UNARY_OPERATOR) {
            status = NUMBER | FUNCTION | OPEN_BRACKET | X;
            _dotCount = 0;
        } else {
            status = 0;
        }
    }

    void SetFunction() {
        if (status & FUNCTION) {
            status = OPEN_BRACKET;
            _functionStatus = false;
        } else {
            status = 0;
        }
    }

    void SetFactorial() {
        if (status & FACTORIAL) {
            status = OPERATOR;
        } else {
            status = 0;
        }
    }

    void SetX() {
        if (status & X) {
            status = OPERATOR | CLOSE_BRACKET;
        } else {
            status = 0;
        }
    }

    void SetOpenBracket() {
        if (status & OPEN_BRACKET) {
            status = NUMBER | FUNCTION | OPEN_BRACKET | X | UNARY_OPERATOR;

            _bracketCount++;
        } else {
            status = 0;
        }
    }

    void SetCloseBracket() {
        if (status & CLOSE_BRACKET) {
            status = OPERATOR | CLOSE_BRACKET;
            _functionStatus = true;

            _bracketCount--;
        } else {
            status = 0;
        }
    }

    void SetDot() {
        if (status & DOT) {
            status = NUMBER;
            _dotCount++;
        } else {
            status = 0;
        }
    }

    void SetExp() {
        if (status & EXP) {
            status = UNARY_OPERATOR | NUMBER;
        } else {
            status = 0;
        }
    }
};



