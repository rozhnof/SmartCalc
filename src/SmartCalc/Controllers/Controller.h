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


};
