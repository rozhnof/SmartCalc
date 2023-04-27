#ifndef CALCULATORCONTROLLER_H
#define CALCULATORCONTROLLER_H

#include "Controller.h"

using namespace std;

class CalculatorController {

private:

    Model *model;

    string _input;
    string _validInput;

public:

    CalculatorController() {
        model = new Model;
    }

    QString Validate(IValidate *rule, QString input, QString button, int &status) {
        Validator *check = new Validator(rule);
        _validInput = check->Validate(input.toStdString(), button.toStdString(), status);
        return QString::fromStdString(_validInput);
    }

    QString GetResult(double x) {
        model->SetInput(_validInput);
        return QString::number(model->Calculate(x));
    }
};


#endif // CALCULATORCONTROLLER_H
