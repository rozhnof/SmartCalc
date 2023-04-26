#ifndef DEPOSITCALCULATORUI_H
#define DEPOSITCALCULATORUI_H

#include "mainwindow.h"
#include "IPlatformUI.h"


class DepositCalculatorUI : public MainWindow
{
public:
    DepositCalcWidgets *widgets;

    DepositCalculatorUI() : MainWindow() {
        widgets = new DepositCalcWidgets;

        window = new QWidget(this);
        widgets->Window = window;

        widgets->label = new QLabel(this);
        widgets->label->setGeometry(0, 0, 400, 400);
    }

    void SetupUI() override {
        (*_platform)->SetupUI(widgets);
    }
};



#endif // DEPOSITCALCULATORUI_H
