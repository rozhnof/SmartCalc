#ifndef MACUI_H
#define MACUI_H

#include "IPlatformUI.h"
#include <iostream>
#include <QWidget>


using namespace std;

class MacUI : public IPlatformUI
{

private:
    CalcWidgets *_calcWidgets;


public:

    void SetupUI(CalcWidgets *calcWidgets) override {
        _calcWidgets = calcWidgets;

        SetCalcStyle();
        SetCalcGeometry();
    }

    void SetupUI(CreditCalcWidgets *creditCalcWidgets) override {
    }

    void SetupUI(DepositCalcWidgets *depositCalcWidgets) override {
    }

    void SetupUI(GraphWidgets *graphWidgets) override {

    }


private:


    void SetCalcStyle() {
        _calcWidgets->Input->setAlignment(Qt::AlignRight | Qt::AlignCenter);

        _calcWidgets->calcWindow->setStyleSheet("QLabel#input { "
                                              "     background-color: rgb(25, 25, 25); "
                                              "     font-size: 26px;"
                                              "}"
                                              "QPushButton { "
                                              "     background-color: rgb(56, 56, 56);"
                                              "     border-style: solid;"
                                              "     border-width: 1px 1px 0px 0px;"
                                              "     border-color: rgb(34, 34, 34); }"
                                              "QPushButton:pressed { "
                                              "     background-color: rgb(89, 89, 89); "
                                              "}"
                                              "QPushButton#number, QPushButton#dot { "
                                              "     background-color: rgb(89, 89, 89);"
                                              "     border-style: solid;"
                                              "     border-width: 1px 1px 0px 0px;"
                                              "     border-color: rgb(34, 34, 34); }"
                                              "QPushButton#number:pressed, QPushButton#dot:pressed { "
                                              "     background-color: rgb(155, 155, 155); "
                                              "}"
                                              "QPushButton#operator, QPushButton#clear, QPushButton#unaryOperator, QPushButton#equal { "
                                              "     background-color: rgb(226, 153, 57);"
                                              "     border-style: solid;"
                                              "     border-width: 1px 1px 0px 0px;"
                                              "     border-color: rgb(34, 34, 34); }"
                                              "QPushButton#operator:pressed, QPushButton#clear:pressed, QPushButton#unaryOperator:pressed, QPushButton#equal:pressed { "
                                              "     background-color: rgb(191, 129, 46); "
                                              "}");
    }

    void SetCalcGeometry() {
        _calcWidgets->calcWindow->setFixedSize(420, 350);
        Layout *calcLayout = new Layout(0, 0, _calcWidgets->calcWindow->width(), _calcWidgets->calcWindow->height(), 7, 7, 0, 0);

        calcLayout->AddWidget(_calcWidgets->Input, 7, 2);
        calcLayout->AddWidget(_calcWidgets->calcButtons[ButtonX]);
        calcLayout->AddWidget(_calcWidgets->calcButtons[ButtonOpenBracket]);
        calcLayout->AddWidget(_calcWidgets->calcButtons[ButtonCloseBracket]);
        calcLayout->AddWidget(_calcWidgets->calcButtons[ButtonAC]);
        calcLayout->AddWidget(_calcWidgets->calcButtons[ButtonC]);
        calcLayout->AddWidget(_calcWidgets->calcButtons[ButtonUnaryOperator]);
        calcLayout->AddWidget(_calcWidgets->calcButtons[ButtonDiv]);

        calcLayout->AddWidget(_calcWidgets->calcButtons[ButtonMod]);
        calcLayout->AddWidget(_calcWidgets->calcButtons[ButtonPow]);
        calcLayout->AddWidget(_calcWidgets->calcButtons[ButtonFactorial]);
        calcLayout->AddWidget(_calcWidgets->calcButtons[Button7]);
        calcLayout->AddWidget(_calcWidgets->calcButtons[Button8]);
        calcLayout->AddWidget(_calcWidgets->calcButtons[Button9]);
        calcLayout->AddWidget(_calcWidgets->calcButtons[ButtonMul]);

        calcLayout->AddWidget(_calcWidgets->calcButtons[ButtonLog]);
        calcLayout->AddWidget(_calcWidgets->calcButtons[ButtonLn]);
        calcLayout->AddWidget(_calcWidgets->calcButtons[ButtonSqrt]);
        calcLayout->AddWidget(_calcWidgets->calcButtons[Button4]);
        calcLayout->AddWidget(_calcWidgets->calcButtons[Button5]);
        calcLayout->AddWidget(_calcWidgets->calcButtons[Button6]);
        calcLayout->AddWidget(_calcWidgets->calcButtons[ButtonSub]);

        calcLayout->AddWidget(_calcWidgets->calcButtons[ButtonAsin]);
        calcLayout->AddWidget(_calcWidgets->calcButtons[ButtonAcos]);
        calcLayout->AddWidget(_calcWidgets->calcButtons[ButtonAtan]);
        calcLayout->AddWidget(_calcWidgets->calcButtons[Button1]);
        calcLayout->AddWidget(_calcWidgets->calcButtons[Button2]);
        calcLayout->AddWidget(_calcWidgets->calcButtons[Button3]);
        calcLayout->AddWidget(_calcWidgets->calcButtons[ButtonSum]);

        calcLayout->AddWidget(_calcWidgets->calcButtons[ButtonSin]);
        calcLayout->AddWidget(_calcWidgets->calcButtons[ButtonCos]);
        calcLayout->AddWidget(_calcWidgets->calcButtons[ButtonTan]);
        calcLayout->AddWidget(_calcWidgets->calcButtons[Button0], 2);
        calcLayout->AddWidget(_calcWidgets->calcButtons[ButtonDot]);
        calcLayout->AddWidget(_calcWidgets->calcButtons[ButtonResult]);

        delete calcLayout;
    }
};

#endif // MACUI_H
