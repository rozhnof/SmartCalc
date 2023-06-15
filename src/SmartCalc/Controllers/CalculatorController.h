#ifndef CALCULATORCONTROLLER_H
#define CALCULATORCONTROLLER_H

#include "Controller.h"
#include "../Models/CalculatorModel.h"

using namespace std;

class CalculatorController : public Controller {

private:

public:

    CalculatorController() {}

    double GetResult(QString input, double x) {
        CalculatorModel model;
        model.SetInput(input.toStdString());
        return model.Calculate(x);
    }
};


#endif // CALCULATORCONTROLLER_H
