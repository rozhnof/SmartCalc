#pragma once

#include "../Models/Model.h"
#include "Validate/Validate.h"

using namespace std;

class Controller {

private:
    string _input_text;
    string _button_text;
    string _result_text;

    double _x;

    Model *model;


public:

    Controller() {
        model = new Model;
    }

    QString Validate(IValidate *rule, QString input, QString button, int &status) {
        Validator *check = new Validator(rule);

        _input_text = input.toStdString();
        _button_text = button.toStdString();
        _result_text = check->Validate(_input_text, _button_text, status);

        return QString::fromStdString(_result_text);
    }

    QString GetResult() {
        model->SetInput(_result_text);
        return QString::number(model->Calculate(_x));
    }


};
