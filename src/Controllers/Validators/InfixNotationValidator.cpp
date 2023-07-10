#include <InfixNotationValidator.h>



bool InfixNotationValidator::isUnaryOperator(QChar &lexema) {
    bool res = false;

    if (lexema == '+') {
        lexema = ' ';
        res = true;
    } else if (lexema == '-') {
        lexema = '~';
        res = true;
    }
    return res;
}

bool InfixNotationValidator::isExponentOperator(QChar lexema) {
    return isUnaryOperator(lexema);
}

bool InfixNotationValidator::isOperator(const QChar &lexema) {
    bool res = false;
    QString operators = "+-/*^%";

    if (operators.indexOf(lexema) != -1) {
        res = true;
    } else {
        res = false;
    }
    return res;
}

bool InfixNotationValidator::isNumber(const QChar &symbol) {
    return (symbol >= '0' && symbol <= '9');
}

int InfixNotationValidator::isFunction(QString &lexema, int startIndex) {
    bool res = false;

    std::unordered_map<QChar, QString> functions{{SIN,"sin"}, {COS, "cos"}, {TAN, "tan"}, {ASIN, "asin"}, {ACOS, "acos"}, {ATAN, "atan"}, {SQRT, "sqrt"}, {LN, "ln"}, {LOG, "log"}};

    for (auto &it : functions) {
        int funtionSize = it.second.size();
        if (lexema.size() >= funtionSize && lexema.mid(startIndex, funtionSize) == it.second) {
            lexema.replace(startIndex, funtionSize, it.first);
            res = true;
            break;
        }
    }

    return res;
}

bool InfixNotationValidator::Validate(QString &input) {
    status.lexemaStatus = NUMBER | UNARY_OPERATOR | FUNCTION | OPEN_BRACKET | VAR_X | CONST_E;
    status.functionStatus = true;
    status.expStatus = true;
    status.bracketCount = 0;
    status.dotCount = 0;
    status.expCount = 0;

    if (input.size() == 0) {
        status.lexemaStatus = 0;
    }

    for (int i = 0; i < input.size() && status.lexemaStatus; i++) {
        if (isNumber(input[i])) {
            SetNumber();
        } else if (isOperator(input[i])) {
            if (status.lexemaStatus & OPERATOR) {
                SetOperator();
            } else if (status.lexemaStatus & EXP_OPERATOR) {
                SetUnaryOperator();
            } else if (isUnaryOperator(input[i])) {
                SetUnaryOperator();
            } else {
                status.lexemaStatus = 0;
            }
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

        if (status.expCount > 1) {
            status.lexemaStatus = 0;
        }
    }

    return FinalValidation(input);
}

bool InfixNotationValidator::FinalValidation(QString &input) {
    bool res = false;

    if (!status.lexemaStatus || !status.functionStatus || !status.expStatus || status.bracketCount != 0) {
        res =  false;
    } else if (input.back() == '(' || input.back() == '.' || isOperator(input.back())) {
        res =  false;
    } else {
        res =  true;
    }
    return res;
}

void InfixNotationValidator::SetNumber() {
    if (status.lexemaStatus & NUMBER) {
        status.lexemaStatus = NUMBER | OPERATOR | DOT | EXP | CLOSE_BRACKET;
        if (status.dotCount == 0) {
            status.lexemaStatus |= FACTORIAL;
        }
        status.expStatus = true;
    } else {
        status.lexemaStatus = 0;
    }
}

void InfixNotationValidator::SetOperator() {
    if (status.lexemaStatus & OPERATOR) {
        status.lexemaStatus = NUMBER | FUNCTION | OPEN_BRACKET | VAR_X | CONST_E | UNARY_OPERATOR;
        status.expStatus = true;
        status.expCount = 0;
    } else {
        status.lexemaStatus = 0;
    }
    status.dotCount = 0;
}

void InfixNotationValidator::SetUnaryOperator() {
    if (status.lexemaStatus & (UNARY_OPERATOR | EXP_OPERATOR)) {
        status.lexemaStatus = NUMBER | FUNCTION | OPEN_BRACKET | VAR_X | CONST_E;
    } else {
        status.lexemaStatus = 0;
    }
}

void InfixNotationValidator::SetFunction() {
    if (status.lexemaStatus & FUNCTION) {
        status.lexemaStatus = OPEN_BRACKET;
        status.functionStatus = false;
    } else {
        status.lexemaStatus = 0;
    }
}

void InfixNotationValidator::SetFactorial() {
    if (status.lexemaStatus & FACTORIAL) {
        status.lexemaStatus = OPERATOR;
    } else {
        status.lexemaStatus = 0;
    }
}

void InfixNotationValidator::SetX() {
    if (status.lexemaStatus & VAR_X) {
        status.lexemaStatus = OPERATOR | CLOSE_BRACKET;
    } else {
        status.lexemaStatus = 0;
    }
}

void InfixNotationValidator::SetOpenBracket() {
    if (status.lexemaStatus & OPEN_BRACKET) {
        status.lexemaStatus = NUMBER | FUNCTION | OPEN_BRACKET | VAR_X | CONST_E| UNARY_OPERATOR;
        status.functionStatus = true;
        status.bracketCount++;
    } else {
        status.lexemaStatus = 0;
    }
}

void InfixNotationValidator::SetCloseBracket() {
    if (status.lexemaStatus & CLOSE_BRACKET) {
        status.lexemaStatus = OPERATOR | CLOSE_BRACKET;
        status.bracketCount--;
    } else {
        status.lexemaStatus = 0;
    }
}

void InfixNotationValidator::SetDot() {
    if (status.lexemaStatus & DOT) {
        status.lexemaStatus = NUMBER;
        status.dotCount++;
    } else {
        status.lexemaStatus = 0;
    }
}

void InfixNotationValidator::SetExp() {
    if (status.lexemaStatus & EXP) {
        status.lexemaStatus = EXP_OPERATOR | NUMBER;
        status.dotCount = 0;
        status.expCount++;
        status.expStatus = false;
    } else if (status.lexemaStatus & CONST_E) {
        status.lexemaStatus = OPERATOR | CLOSE_BRACKET;
    } else {
        status.lexemaStatus = 0;
    }
}
