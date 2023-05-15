#ifndef CALCULATORCONTROLLER_H
#define CALCULATORCONTROLLER_H

#include "Controller.h"
#include "../Models/CalculatorModel.h"

using namespace std;

class CalculatorController : public Controller {

private:

    CalculatorModel *model;

    string _input;
    string _validInput;

public:

    CalculatorController() {
        model = new CalculatorModel;
    }



    QString GetResult(double x) {
        model->SetInput(_validInput);
        return QString::number(model->Calculate(x));
    }
};


#endif // CALCULATORCONTROLLER_H
