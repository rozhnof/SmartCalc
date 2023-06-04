#pragma once

#include "../Models/Model.h"
#include <QString>
#include "Validate/Validate.h"

using namespace std;

class Controller {

private:

    Model *model;

    string _input;
    string _validInput;

public:
    QString Validate(IValidate *rule, QString input, QString button, int &status) {
        Validator *check = new Validator(rule);
        _validInput = check->Validate(input.toStdString(), button.toStdString(), status);
        return QString::fromStdString(_validInput);
    }

    QString SymbolValidate(string input, int &status) {

        char charSymbol = input.back();
        string stringSymbol = string{charSymbol};
        char lastInputSymbol = input[input.size() - 2];

        Validator *check;
        if (Validator::IsNumber(charSymbol)) {
            check = new Validator(new NumberValidate);
        } else if (Validator::IsOperator(charSymbol)) {
            check = new Validator(new OperatorValidate);
        } else if (charSymbol == '(') {
            check = new Validator(new OpenBracketValidate);
        } else if (charSymbol == ')') {
            check = new Validator(new CloseBracketValidate);
        } else if (charSymbol == '!') {
            check = new Validator(new FactorialValidate);
        } else if (charSymbol == '.') {
            check = new Validator(new OpenBracketValidate);
        } else if (charSymbol == 's' || charSymbol == 'c' || charSymbol == 'a' || charSymbol == 'l') {
            if (!(lastInputSymbol == '(' && Validator::IsOperator(lastInputSymbol) && input.empty())) {
                input.pop_back();
            }
        } else if (lastInputSymbol == 's' && charSymbol == 'i') {
            input += 'n';
        } else if (lastInputSymbol == 's' && charSymbol == 'q') {
            input += "rt";
        } else if (lastInputSymbol == 'c' && charSymbol == 'o') {
            input += 's';
        } else if (lastInputSymbol == 'a' && charSymbol == 's') {
            input += "in";
        } else if (lastInputSymbol == 'a' && charSymbol == 'c') {
            input += "os";
        } else if (lastInputSymbol == 'a' && charSymbol == 't') {
            input += "an";
        } else {
            input.pop_back();
        }
    }

};
