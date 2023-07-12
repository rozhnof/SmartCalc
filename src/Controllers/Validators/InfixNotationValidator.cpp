#include "InfixNotationValidator.h"

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

  std::unordered_map<QChar, QString> functions{
      {SIN, "sin"},   {COS, "cos"},   {TAN, "tan"},
      {ASIN, "asin"}, {ACOS, "acos"}, {ATAN, "atan"},
      {SQRT, "sqrt"}, {LN, "ln"},     {LOG, "log"}};

  for (auto &it : functions) {
    int funtionSize = it.second.size();
    if (lexema.size() >= funtionSize &&
        lexema.mid(startIndex, funtionSize) == it.second) {
      lexema.replace(startIndex, funtionSize, it.first);
      res = true;
      break;
    }
  }

  return res;
}

bool InfixNotationValidator::Validate(QString &input) {
  status_.lexemaStatus =
      NUMBER | UNARY_OPERATOR | FUNCTION | OPEN_BRACKET | VAR_X | CONST_E;
  status_.functionStatus = true;
  status_.expStatus = true;
  status_.bracketCount = 0;
  status_.dotCount = 0;
  status_.expCount = 0;

  if (input.size() == 0) {
    status_.lexemaStatus = 0;
  }

  for (int i = 0; i < input.size() && status_.lexemaStatus; i++) {
    if (isNumber(input[i])) {
      setNumber();
    } else if (isOperator(input[i])) {
      if (status_.lexemaStatus & OPERATOR) {
        setOperator();
      } else if (status_.lexemaStatus & EXP_OPERATOR) {
        setUnaryOperator();
      } else if (isUnaryOperator(input[i])) {
        setUnaryOperator();
      } else {
        status_.lexemaStatus = 0;
      }
    } else if (isFunction(input, i)) {
      setFunction();
    } else if (input[i] == 'x') {
      setX();
    } else if (input[i] == '(') {
      setOpenBracket();
    } else if (input[i] == ')') {
      setCloseBracket();
    } else if (input[i] == '.') {
      setDot();
    } else if (input[i] == '!') {
      setFactorial();
    } else if (input[i] == 'e' || input[i] == 'E') {
      setExp();
    } else {
      status_.lexemaStatus = 0;
    }

    if (status_.expCount > 1) {
      status_.lexemaStatus = 0;
    }
  }

  return FinalValidation(input);
}

bool InfixNotationValidator::FinalValidation(QString &input) {
  bool res = false;

  if (!status_.lexemaStatus || !status_.functionStatus || !status_.expStatus ||
      status_.bracketCount != 0) {
    res = false;
  } else if (input.back() == '(' || input.back() == '.' ||
             isOperator(input.back())) {
    res = false;
  } else {
    res = true;
  }
  return res;
}

void InfixNotationValidator::setNumber() {
  if (status_.lexemaStatus & NUMBER) {
    status_.lexemaStatus = NUMBER | OPERATOR | DOT | EXP | CLOSE_BRACKET;
    if (status_.dotCount == 0) {
      status_.lexemaStatus |= FACTORIAL;
    }
    status_.expStatus = true;
  } else {
    status_.lexemaStatus = 0;
  }
}

void InfixNotationValidator::setOperator() {
  if (status_.lexemaStatus & OPERATOR) {
    status_.lexemaStatus =
        NUMBER | FUNCTION | OPEN_BRACKET | VAR_X | CONST_E | UNARY_OPERATOR;
    status_.expStatus = true;
    status_.expCount = 0;
  } else {
    status_.lexemaStatus = 0;
  }
  status_.dotCount = 0;
}

void InfixNotationValidator::setUnaryOperator() {
  if (status_.lexemaStatus & (UNARY_OPERATOR | EXP_OPERATOR)) {
    status_.lexemaStatus = NUMBER | FUNCTION | OPEN_BRACKET | VAR_X | CONST_E;
  } else {
    status_.lexemaStatus = 0;
  }
}

void InfixNotationValidator::setFunction() {
  if (status_.lexemaStatus & FUNCTION) {
    status_.lexemaStatus = OPEN_BRACKET;
    status_.functionStatus = false;
  } else {
    status_.lexemaStatus = 0;
  }
}

void InfixNotationValidator::setFactorial() {
  if (status_.lexemaStatus & FACTORIAL) {
    status_.lexemaStatus = OPERATOR;
  } else {
    status_.lexemaStatus = 0;
  }
}

void InfixNotationValidator::setX() {
  if (status_.lexemaStatus & VAR_X) {
    status_.lexemaStatus = OPERATOR | CLOSE_BRACKET;
  } else {
    status_.lexemaStatus = 0;
  }
}

void InfixNotationValidator::setOpenBracket() {
  if (status_.lexemaStatus & OPEN_BRACKET) {
    status_.lexemaStatus =
        NUMBER | FUNCTION | OPEN_BRACKET | VAR_X | CONST_E | UNARY_OPERATOR;
    status_.functionStatus = true;
    status_.bracketCount++;
  } else {
    status_.lexemaStatus = 0;
  }
}

void InfixNotationValidator::setCloseBracket() {
  if (status_.lexemaStatus & CLOSE_BRACKET) {
    status_.lexemaStatus = OPERATOR | CLOSE_BRACKET;
    status_.bracketCount--;
  } else {
    status_.lexemaStatus = 0;
  }
}

void InfixNotationValidator::setDot() {
  if (status_.lexemaStatus & DOT && status_.dotCount == 0) {
    status_.lexemaStatus = NUMBER;
    status_.dotCount++;
  } else {
    status_.lexemaStatus = 0;
  }
}

void InfixNotationValidator::setExp() {
  if (status_.lexemaStatus & EXP) {
    status_.lexemaStatus = EXP_OPERATOR | NUMBER;
    status_.dotCount = 0;
    status_.expCount++;
    status_.expStatus = false;
  } else if (status_.lexemaStatus & CONST_E) {
    status_.lexemaStatus = OPERATOR | CLOSE_BRACKET;
  } else {
    status_.lexemaStatus = 0;
  }
}
