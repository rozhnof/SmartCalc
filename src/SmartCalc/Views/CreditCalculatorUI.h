#ifndef CREDITCALCULATORUI_H
#define CREDITCALCULATORUI_H

#include "mainwindow.h"
#include "IPlatformUI.h"

class CreditCalculatorUI : public MainWindow
{
public:
    CreditCalcWidgets *widgets;

    CreditCalculatorUI() : MainWindow() {
        widgets = new CreditCalcWidgets;

        window = new QWidget(this);
        widgets->Window = window;
    }

    void SetupUI() override {
        (*_platform)->SetupUI(widgets);
    }
};


#endif // CREDITCALCULATORUI_H
