#pragma once


#include <iostream>
#include <algorithm>
#include <QString>
#include <unordered_map>


class InfixNotationValidator {
private:
    enum Lexema {
        NUMBER = 0b0000000001,
        OPERATOR = 0b0000000010,
        UNARY_OPERATOR = 0b0000000100,
        FUNCTION = 0b0000001000,
        OPEN_BRACKET = 0b0000010000,
        CLOSE_BRACKET = 0b0000100000,
        VAR_X = 0b0001000000,
        DOT = 0b0010000000,
        FACTORIAL = 0b0100000000,
        EXP = 0b1000000000,
        CONST_E = 0b10000000000
    };

    struct Status {
        int lexemaStatus;
        bool functionStatus;
        bool expStatus;
        int bracketCount;
        int dotCount;
    };

    Status status = {};

public:
    InfixNotationValidator() {}

    bool isUnaryOperator(QChar &lexema) {
        if (lexema == '+') {
            lexema = ' ';
            return true;
        } else if (lexema == '-') {
            lexema = '~';
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
        std::unordered_map<QChar, QString> functions{{SIN,"sin"}, {COS, "cos"}, {TAN, "tan"}, {ASIN, "asin"}, {ACOS, "acos"}, {ATAN, "atan"}, {SQRT, "sqrt"}, {LN, "ln"}, {LOG, "log"}};

        for (auto &it : functions) {
            int funtionSize = it.second.size();
            if (lexema.size() >= funtionSize && lexema.mid(startIndex, funtionSize) == it.second) {
                lexema.replace(startIndex, funtionSize, it.first);
                return true;
            }
        }

        return false;
    }

    bool Validate(QString &input) {
        status.lexemaStatus = NUMBER | UNARY_OPERATOR | FUNCTION | OPEN_BRACKET | VAR_X;
        status.functionStatus = true;
        status.expStatus = true;
        status.bracketCount = 0;
        status.dotCount = 0;

        if (input.size() == 0) {
            status.lexemaStatus = 0;
        }

        for (int i = 0; i < input.size() && status.lexemaStatus; i++) {
            if (isNumber(input[i])) {
                SetNumber();
            } else if (isOperator(input[i])) {
                SetOperator();
            } else if (isFunction(input, i)) {
                SetFunction();
            } else if (input[i] == 'x') {
                SetX();
            } else if (input[i] == '(') {
                SetOpenBracket();
            } else if (input[i] == ')') {
                SetCloseBracket();
            } else if (input[i] == '.') {
                SetDot();
            } else if (input[i] == '!') {
                SetFactorial();
            } else if (input[i] == 'e' || input[i] == 'E') {
                SetExp();
            } else {
                status.lexemaStatus = 0;
            }
        }

        return FinalValidation(input);
    }

    bool FinalValidation(QString &input) {
        if (!status.lexemaStatus || !status.functionStatus || !status.expStatus || status.bracketCount != 0) {
            return false;
        } else if (input.back() == '(' || input.back() == '.' || isOperator(input.back())) {
            return false;
        } else {
            return true;
        }
    }

    void SetNumber() {
        if (status.lexemaStatus & NUMBER) {
            status.lexemaStatus = NUMBER | OPERATOR | DOT | EXP | CLOSE_BRACKET;
            if (status.dotCount == 0) {
                status.lexemaStatus |= FACTORIAL;
                status.expStatus = true;
            } else {
                status.expStatus = false;
            }
        } else {
            status.lexemaStatus = 0;
        }
    }

    void SetOperator() {
        if (status.lexemaStatus & OPERATOR) {
            status.lexemaStatus = NUMBER | FUNCTION | OPEN_BRACKET | VAR_X | CONST_E | UNARY_OPERATOR;
        } else if (status.lexemaStatus & UNARY_OPERATOR) {
            status.lexemaStatus = NUMBER | FUNCTION | OPEN_BRACKET | VAR_X | CONST_E;
        } else {
            status.lexemaStatus = 0;
        }
        status.dotCount = 0;
    }

    void SetFunction() {
        if (status.lexemaStatus & FUNCTION) {
            status.lexemaStatus = OPEN_BRACKET;
            status.functionStatus = false;
        } else {
            status.lexemaStatus = 0;
        }
    }

    void SetFactorial() {
        if (status.lexemaStatus & FACTORIAL) {
            status.lexemaStatus = OPERATOR;
        } else {
            status.lexemaStatus = 0;
        }
    }

    void SetX() {
        if (status.lexemaStatus & VAR_X) {
            status.lexemaStatus = OPERATOR | CLOSE_BRACKET;
        } else {
            status.lexemaStatus = 0;
        }
    }

    void SetOpenBracket() {
        if (status.lexemaStatus & OPEN_BRACKET) {
            status.lexemaStatus = NUMBER | FUNCTION | OPEN_BRACKET | VAR_X | CONST_E| UNARY_OPERATOR;
            status.functionStatus = true;
            status.bracketCount++;
        } else {
            status.lexemaStatus = 0;
        }
    }

    void SetCloseBracket() {
        if (status.lexemaStatus & CLOSE_BRACKET) {
            status.lexemaStatus = OPERATOR | CLOSE_BRACKET;
            status.bracketCount--;
        } else {
            status.lexemaStatus = 0;
        }
    }

    void SetDot() {
        if (status.lexemaStatus & DOT) {
            status.lexemaStatus = NUMBER;
            status.dotCount++;
        } else {
            status.lexemaStatus = 0;
        }
    }

    void SetExp() {
        if (status.lexemaStatus & EXP) {
            status.lexemaStatus = UNARY_OPERATOR | NUMBER;
            status.dotCount = 0;
            status.expStatus = false;
        } else if (status.lexemaStatus & CONST_E) {
            status.lexemaStatus = OPERATOR | CLOSE_BRACKET;
        } else {
            status.lexemaStatus = 0;
        }
    }
};



