#ifndef WINUI_H
#define WINUI_H

#include "IPlatformUI.h"
#include <iostream>
#include <QWidget>


using namespace std;

class WinUI : public IPlatformUI
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

        _calcWidgets->calcWindow->setStyleSheet(
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

    void SetCalcGeometry() {
        _calcWidgets->calcWindow->setFixedSize(420, 350);
        Layout *calcLayout = new Layout(4, 0, _calcWidgets->calcWindow->width() - 4, _calcWidgets->calcWindow->height() - 4, 7, 7, 2, 2);

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

#endif // WINUI_H
