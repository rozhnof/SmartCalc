#pragma once

#include <QString>
#include <algorithm>
#include <iostream>
#include <unordered_map>

#define SIN 's'
#define COS 'c'
#define TAN 't'
#define ASIN 'S'
#define ACOS 'C'
#define ATAN 'T'
#define SQRT 'Q'
#define LN 'l'
#define LOG 'L'

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
    EXP_OPERATOR = 0b100000000000,
    CONST_E = 0b10000000000
  };

  struct Status {
    int lexemaStatus;
    bool functionStatus;
    bool expStatus;
    int bracketCount;
    int dotCount;
    int expCount;
  };

  Status status_ = {};

 public:
  bool Validate(QString &input);

 private:
  bool FinalValidation(QString &input);

  bool isUnaryOperator(QChar &lexema);
  bool isExponentOperator(QChar lexema);
  bool isOperator(const QChar &lexema);
  bool isNumber(const QChar &symbol);
  int isFunction(QString &lexema, int startIndex);

  void setNumber();
  void setOperator();
  void setUnaryOperator();
  void setFunction();
  void setFactorial();
  void setX();
  void setOpenBracket();
  void setCloseBracket();
  void setDot();
  void setExp();
};
