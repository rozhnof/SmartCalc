#ifndef CREDITCALCULATORUI_H
#define CREDITCALCULATORUI_H

#include "mainwindow.h"
#include "IPlatformUI.h"

class CreditCalculatorUI : public MainWindow
{
public:
    CreditCalcWidgets *widgets;

    CreditCalculatorUI() : MainWindow() {
        this->setWindowTitle("Credit Calculator");

        widgets = new CreditCalcWidgets;
        widgets->creditCalcWindow = this;
    }

    void SetupUI() override {
        (*_platform)->SetupUI(widgets);
    }
};


#endif // CREDITCALCULATORUI_H
