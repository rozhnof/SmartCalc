#pragma once

#include "../Models/Model.h"
#include <QString>
#include "Validate/Validate.h"

using namespace std;

class LexemaStatus {
private:
    bool _number = true;
    bool _operator = false;
    bool _function = true;
    bool _openBracket = true;
    bool _closeBracket = false;
    bool _x = true;
    bool _factorial = false;
    bool _dot = false;
    bool _functionStatus = true;

    int _countBrackets = 0;
    int _countDot = 0;

    string _currentFunction;

public:

    void SetDefaultStatus() {
        _number = true;
        _operator = false;
        _function = true;
        _openBracket = true;
        _closeBracket = false;
        _x = true;
        _factorial = false;
        _dot = false;

        _countBrackets = 0;
        _countDot = 0;

        _currentFunction.clear();
    }

    bool IsNumber(char symbol) {
        return (symbol >= '0' && symbol <= '9');
    }

    bool IsOperator(char symbol) {
        bool status = false;
        if (symbol == '+' || symbol == '-' || symbol == '/' || symbol == '*' || symbol == '^') {
            status = true;
        } else if (symbol == 'm') {
            status = true;
        }
        return status;
    }

    bool IsFunction(char symbol) {
        bool status = false;
        _functionStatus = false;

        if (_currentFunction.empty()) {
            if (symbol == 's' || symbol == 'c' || symbol == 't' || symbol == 'l') {
                status = true;
            }
        } else if (_currentFunction.size() == 1) {
            if (_currentFunction[0] == 's' && symbol == 'i') {
                status = true;
            } else if (_currentFunction[0] == 's' && symbol == 'q') {
                status = true;
            } else if (_currentFunction[0] == 'c' && symbol == 'o') {
                status = true;
            } else if (_currentFunction[0] == 't' && symbol == 'a') {
                status = true;
            } else if (_currentFunction[0] == 'l' && symbol == 'n') {
                status = true;
            } else if (_currentFunction[0] == 'l' && symbol == 'o') {
                status = true;
            }
        } else if (_currentFunction.size() == 2) {
            if (_currentFunction[0] == 's' && _currentFunction[1] == 'i' && symbol == 'n') {
                status = true;
            }else if (_currentFunction[0] == 's' && _currentFunction[1] == 'q' && symbol == 'r') {
                status = true;
            } else if (_currentFunction[0] == 'c' && _currentFunction[1] == 'o' && symbol == 's') {
                status = true;
            } else if (_currentFunction[0] == 't' &&  _currentFunction[1] == 'a' && symbol == 'n') {
                status = true;
            } else if (_currentFunction[0] == 'l' &&  _currentFunction[1] == 'o' && symbol == 'g') {
                status = true;
            }
        } else if (_currentFunction.size() == 3) {
            if (_currentFunction[0] == 's' && _currentFunction[1] == 'q' && _currentFunction[2] == 'r' && symbol == 't') {
                status = true;
            }
        }

        if (status == true) {
            _currentFunction += symbol;
        }

        return status;
    }

    bool IsX(char symbol) {
        return (symbol == 'x');
    }

    bool IsOpenBracket(char symbol) {
        return (symbol == '(');
    }

    bool IsCloseBracket(char symbol) {
        return (symbol == ')');
    }

    bool IsFactorial(char symbol) {
        return (symbol == '!');
    }

    bool IsDot(char symbol) {
        return (symbol == '.');
    }

    bool CurrentIsNumber() {
        bool status = false;

        if (_number == true) {
            _number = true;
            _operator = true;

            if (_countDot == 0) {
                _dot = true;
                _factorial = true;
            } else {
                _dot = false;
            }

            if (_countBrackets > 0) {
                _closeBracket = true;
            } else {
                _closeBracket = false;
            }

            _function = false;
            _openBracket = false;
            _x = false;

            status = true;
        }

        return status;
    }

    bool CurrentIsOperator() {
        bool status = false;

        if (_operator == true) {
            _number = true;
            _operator = false;
            _function = true;
            _openBracket = true;
            _closeBracket = false;
            _x = true;
            _factorial = false;
            _dot = false;

            _countDot = 0;
            status = true;
        }
        return status;
    }

    bool CurrentIsFunction() {
        bool status = false;

        if (_function == true) {
            _number = false;
            _operator = false;
            _function = true;
            _openBracket = true;
            _closeBracket = false;
            _x = false;
            _factorial = false;
            _dot = false;

            status = true;
        }
        return status;
    }

    bool CurrentIsOpenBracket() {
        bool status = false;

        if (_openBracket == true) {
            _number = true;
            _operator = false;
            _function = true;
            _openBracket = true;
            _closeBracket = false;
            _x = true;
            _factorial = false;
            _dot = false;

            _countBrackets++;
            _currentFunction.clear();
            _functionStatus = true;
            status = true;
        }
        return status;
    }

    bool CurrentIsCloseBracket() {
        bool status = false;

        if (_closeBracket == true && _countBrackets > 0) {
            _number = false;
            _operator = true;
            _function = false;
            _openBracket = false;
            _x = false;
            _factorial = false;
            _dot = false;

            _countBrackets--;

            if (_countBrackets == 0) {
                _closeBracket = false;
            }

            status = true;
        }
        return status;
    }

    bool CurrentIsX() {
        bool status = false;

        if (_x == true) {
            _number = false;
            _operator = true;
            _function = false;
            _openBracket = false;
            _closeBracket = true;
            _x = false;
            _factorial = false;
            _dot = false;

            status = true;
        }
        return status;
    }

    bool CurrentIsFactorial() {
        bool status = false;

        if (_factorial == true) {
            _number = false;
            _operator = true;
            _function = false;
            _openBracket = false;
            _closeBracket = true;
            _x = false;
            _factorial = false;
            _dot = false;

            status = true;
        }
        return status;
    }

    bool CurrentIsDot() {
        bool status = false;

        if (_dot == true) {
            _number = true;
            _operator = false;
            _function = false;
            _openBracket = false;
            _closeBracket = false;
            _x = false;
            _factorial = false;
            _dot = false;

            _countDot++;
            status = true;
        }
        return status;
    }

    int Validate(char symbol) {
        bool status = false;

        if (IsNumber(symbol)) {
            status = CurrentIsNumber();
        } else if (IsOperator(symbol)) {
            status = CurrentIsOperator();
        } else if (IsFunction(symbol)) {
            status = CurrentIsFunction();
        } else if (IsOpenBracket(symbol)) {
            status = CurrentIsOpenBracket();
        } else if (IsCloseBracket(symbol)) {
            status = CurrentIsCloseBracket();
        } else if (IsX(symbol)) {
            status = CurrentIsX();
        } else if (IsFactorial(symbol)) {
            status = CurrentIsFactorial();
        } else if (IsDot(symbol)) {
            status = CurrentIsDot();
        }
        return status;
    }
};

class Controller {

private:
    Model *model;
    LexemaStatus lexemaStatus;

    string _input;
    string _validInput;

public:
    QString Validate(IValidate *rule, QString input, QString button, int &status) {
        Validator *check = new Validator(rule);
        _validInput = check->Validate(input.toStdString(), button.toStdString(), status);
        return QString::fromStdString(_validInput);
    }

    bool Validate(QString input) {
        int status = true;

        if (input.isEmpty()) {
            lexemaStatus.SetDefaultStatus();
        } else {
            _input = input.toStdString();
            for (auto it : _input) {
                if (lexemaStatus.Validate(it) == false) {
                    break;
                }
            }
        }
        return status;
    }

    bool Validate(char currentSymbol) {
        return lexemaStatus.Validate(currentSymbol);
    }
};
