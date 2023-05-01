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
        this->setFixedSize(1200, 800);
    }

    QLineEdit *CreateWidget(int index) {
        QLineEdit *newWidget = new QLineEdit(this);
        SetStyle(newWidget);
        return newWidget;
    }

    void SetStyle(QLineEdit *widget) {
        widget->setStyleSheet("background-color:black;");
    }


    void SetupUI() override {
        (*_platform)->SetupUI(widgets);
    }
};


#endif // CREDITCALCULATORUI_H
