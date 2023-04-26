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

        widgets->label = new QLabel(this);
        widgets->label->setGeometry(0, 0, 400, 400);
    }

    void SetupUI() override {
        (*_platform)->SetupUI(widgets);
    }
};


#endif // CREDITCALCULATORUI_H
