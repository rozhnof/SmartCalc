#ifndef DEPOSITCALCULATORUI_H
#define DEPOSITCALCULATORUI_H

#include "mainwindow.h"
#include "IPlatformUI.h"


class DepositCalculatorUI : public MainWindow
{
public:
    DepositCalcWidgets *widgets;

    DepositCalculatorUI() : MainWindow() {
        this->setWindowTitle("Deposit Calculator");

        widgets = new DepositCalcWidgets;

        widgets->depositCalcWindow = this;

        widgets->label = new QLabel(this);
        widgets->label->setGeometry(0, 0, 400, 400);
    }

    void SetupUI() override {
        (*_platform)->SetupUI(widgets);
    }
};



#endif // DEPOSITCALCULATORUI_H
