#ifndef CALCULATOR_H
#define CALCULATOR_H

#include "CalculatorUI.h"
#include "CreditCalculatorUI.h"

class Calculator
{
    CalculatorUI *calc;
    CreditCalculatorUI *creditCalc;

    QWidget *currentTab;

public:
    Calculator() {
         calc = new CalculatorUI;
         creditCalc = new CreditCalculatorUI;

         currentTab = calc;
    }

    void show() {

    }
};


#endif // CALCULATOR_H
