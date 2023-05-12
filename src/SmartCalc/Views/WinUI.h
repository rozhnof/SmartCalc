#ifndef WINUI_H
#define WINUI_H

#include "IPlatformUI.h"
#include <iostream>
#include <QWidget>


using namespace std;

class WinUI : public IPlatformUI
{

private:


public:

    void SetupUI(CalcWidgets *widgets) override {
        SetStyle(widgets);
        SetGeometry(widgets);
    }

    void SetupUI(CreditCalcWidgets *widgets) override {
        SetStyle(widgets);
    }

    void SetupUI(DepositCalcWidgets *widgets) override {
    }

    void SetupUI(GraphWidgets *widgets) override {

    }


private:

    void SetStyle(CalcWidgets *calcWidgets) {
        calcWidgets->calcWindow->setStyleSheet(
                                                "QWidget, QLabel#input {"
                                                "   background-color: rgb(27, 32, 50);"
                                                "   color: white;"
                                                "   font-size: 26px;"
                                                "}"
                                                "QPushButton {"
                                                "   background-color: rgb(46, 49, 68);"
                                                "   color: white;"
                                                "   font-size: 14px;"
                                                "   border-radius: 5; "
                                                "}"
                                                "QPushButton:pressed {"
                                                "   background-color: rgb(55, 58, 76);"
                                                "}"
                                               "QPushButton#number, QPushButton#dot {"
                                               "    background-color: rgb(55, 58, 76);"
                                               "    color: white;"
                                               "    font-size: 18px;"
                                               "    border-radius: 5; "
                                               "}"
                                               "QPushButton#number:pressed, QPushButton#dot:pressed {"
                                               "    background-color: rgb(46, 49, 68);"
                                               "}"
                                                "QPushButton#equal {"
                                                "   background-color: rgb(104, 181, 235);"
                                                "   color: white;"
                                                "   font-size: 14px;"
                                                "   border-radius: 5; "
                                                "}"
                                                "QPushButton#equal:pressed {"
                                                "   background-color: rgb(82, 144, 187); "
                                                "}"
                                              );
    }

    void SetStyle(CreditCalcWidgets *creditCalcWidgets) {
        creditCalcWidgets->creditCalcWindow->setStyleSheet("QMainWindow, QChartView {"
                      " background-color: rgb(27, 32, 50);"
                      "}"
                      "QPushButton {"
                      " background-color: rgb(217, 217, 217);"
                      " color: rgb(37, 37, 37);"
                      " border-radius: 10;"
                      " font: 16px;"
                      "}"
                      "QComboBox {"
                      " background-color: rgba(0, 0, 0, 0);"
                      " color: rgb(37, 37, 37);"
                      " font: 16px;"
                      "}"
                      "QTextEdit {"
                      " background-color: rgb(217, 217, 217);"
                      " border-radius: 10;"
                      " font: 18px;"
                      " color: rgb(37, 37, 37);"
                      "}"
                      "QPushButton:pressed {"
                      " background-color: rgb(171, 171, 171);"
                      "}"
                      "QComboBox::drop-down {"
                      "    width: 0px; "
                      "    height: 0px; "
                      "    border: 0px; "
                      "}"
                      "QComboBox QAbstractItemView {"
                      " color: rgb(37, 37, 37);"
                      " background-color: rgb(217, 217, 217);"
                      " padding: 10px;"
                      "}"
                      "QLabel, QLineEdit { "
                      " background-color: rgba(217, 217, 217, 0);"
                      " font: 16px; "
                      " color: rgb(37, 37, 37);"
                      "}");

        creditCalcWidgets->boxTitle[CreditSum]->setStyleSheet("color: rgb(217, 217, 217);");
        creditCalcWidgets->boxTitle[CreditTerm]->setStyleSheet("color: rgb(217, 217, 217);");
        creditCalcWidgets->boxTitle[InterestRate]->setStyleSheet("color: rgb(217, 217, 217);");
    }

    void SetGeometry(CalcWidgets *calcWidgets) {
        calcWidgets->calcWindow->setFixedSize(420, 350);
        Layout *calcLayout = new Layout(4, 0, calcWidgets->calcWindow->width() - 4, calcWidgets->calcWindow->height() - 4, 7, 7, 2, 2);

        calcLayout->AddWidget(calcWidgets->Input, 7, 2);
        calcLayout->AddWidget(calcWidgets->calcButtons[ButtonX]);
        calcLayout->AddWidget(calcWidgets->calcButtons[ButtonOpenBracket]);
        calcLayout->AddWidget(calcWidgets->calcButtons[ButtonCloseBracket]);
        calcLayout->AddWidget(calcWidgets->calcButtons[ButtonAC]);
        calcLayout->AddWidget(calcWidgets->calcButtons[ButtonC]);
        calcLayout->AddWidget(calcWidgets->calcButtons[ButtonUnaryOperator]);
        calcLayout->AddWidget(calcWidgets->calcButtons[ButtonDiv]);

        calcLayout->AddWidget(calcWidgets->calcButtons[ButtonMod]);
        calcLayout->AddWidget(calcWidgets->calcButtons[ButtonPow]);
        calcLayout->AddWidget(calcWidgets->calcButtons[ButtonFactorial]);
        calcLayout->AddWidget(calcWidgets->calcButtons[Button7]);
        calcLayout->AddWidget(calcWidgets->calcButtons[Button8]);
        calcLayout->AddWidget(calcWidgets->calcButtons[Button9]);
        calcLayout->AddWidget(calcWidgets->calcButtons[ButtonMul]);

        calcLayout->AddWidget(calcWidgets->calcButtons[ButtonLog]);
        calcLayout->AddWidget(calcWidgets->calcButtons[ButtonLn]);
        calcLayout->AddWidget(calcWidgets->calcButtons[ButtonSqrt]);
        calcLayout->AddWidget(calcWidgets->calcButtons[Button4]);
        calcLayout->AddWidget(calcWidgets->calcButtons[Button5]);
        calcLayout->AddWidget(calcWidgets->calcButtons[Button6]);
        calcLayout->AddWidget(calcWidgets->calcButtons[ButtonSub]);

        calcLayout->AddWidget(calcWidgets->calcButtons[ButtonAsin]);
        calcLayout->AddWidget(calcWidgets->calcButtons[ButtonAcos]);
        calcLayout->AddWidget(calcWidgets->calcButtons[ButtonAtan]);
        calcLayout->AddWidget(calcWidgets->calcButtons[Button1]);
        calcLayout->AddWidget(calcWidgets->calcButtons[Button2]);
        calcLayout->AddWidget(calcWidgets->calcButtons[Button3]);
        calcLayout->AddWidget(calcWidgets->calcButtons[ButtonSum]);

        calcLayout->AddWidget(calcWidgets->calcButtons[ButtonSin]);
        calcLayout->AddWidget(calcWidgets->calcButtons[ButtonCos]);
        calcLayout->AddWidget(calcWidgets->calcButtons[ButtonTan]);
        calcLayout->AddWidget(calcWidgets->calcButtons[Button0], 2);
        calcLayout->AddWidget(calcWidgets->calcButtons[ButtonDot]);
        calcLayout->AddWidget(calcWidgets->calcButtons[ButtonResult]);

        delete calcLayout;
    }
};

#endif // WINUI_H
