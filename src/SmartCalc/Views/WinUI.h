#ifndef WINUI_H
#define WINUI_H

#include "IPlatformUI.h"
#include <iostream>
#include <QWidget>


using namespace std;

class WinUI : public IPlatformUI
{

private:

    CalcWidgets **widgets;

public:

    void SetupUI(CalcWidgets *o_widgets) override {
        widgets = &o_widgets;

        SetStyle();
        SetGeometry();
    }

    void SetupUI(CreditCalcWidgets *o_widgets) override {
    }

    void SetupUI(DepositCalcWidgets *o_widgets) override {
    }

    void SetupUI(GraphWidgets *o_widgets) override {
    }


private:

    void SetStyle() {

        (*widgets)->calcWindow->setStyleSheet(
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

    void SetGeometry() {
        (*widgets)->calcWindow->setFixedSize(420, 350);
        Layout *calcLayout = new Layout(4, 0, (*widgets)->calcWindow->width() - 4, (*widgets)->calcWindow->height() - 4, 7, 7, 2, 2);

        calcLayout->AddWidget((*widgets)->Input, 7, 2);
        calcLayout->AddWidget((*widgets)->calcButtons[ButtonX]);
        calcLayout->AddWidget((*widgets)->calcButtons[ButtonOpenBracket]);
        calcLayout->AddWidget((*widgets)->calcButtons[ButtonCloseBracket]);
        calcLayout->AddWidget((*widgets)->calcButtons[ButtonAC]);
        calcLayout->AddWidget((*widgets)->calcButtons[ButtonC]);
        calcLayout->AddWidget((*widgets)->calcButtons[ButtonUnaryOperator]);
        calcLayout->AddWidget((*widgets)->calcButtons[ButtonDiv]);

        calcLayout->AddWidget((*widgets)->calcButtons[ButtonMod]);
        calcLayout->AddWidget((*widgets)->calcButtons[ButtonPow]);
        calcLayout->AddWidget((*widgets)->calcButtons[ButtonFactorial]);
        calcLayout->AddWidget((*widgets)->calcButtons[Button7]);
        calcLayout->AddWidget((*widgets)->calcButtons[Button8]);
        calcLayout->AddWidget((*widgets)->calcButtons[Button9]);
        calcLayout->AddWidget((*widgets)->calcButtons[ButtonMul]);

        calcLayout->AddWidget((*widgets)->calcButtons[ButtonLog]);
        calcLayout->AddWidget((*widgets)->calcButtons[ButtonLn]);
        calcLayout->AddWidget((*widgets)->calcButtons[ButtonSqrt]);
        calcLayout->AddWidget((*widgets)->calcButtons[Button4]);
        calcLayout->AddWidget((*widgets)->calcButtons[Button5]);
        calcLayout->AddWidget((*widgets)->calcButtons[Button6]);
        calcLayout->AddWidget((*widgets)->calcButtons[ButtonSub]);

        calcLayout->AddWidget((*widgets)->calcButtons[ButtonAsin]);
        calcLayout->AddWidget((*widgets)->calcButtons[ButtonAcos]);
        calcLayout->AddWidget((*widgets)->calcButtons[ButtonAtan]);
        calcLayout->AddWidget((*widgets)->calcButtons[Button1]);
        calcLayout->AddWidget((*widgets)->calcButtons[Button2]);
        calcLayout->AddWidget((*widgets)->calcButtons[Button3]);
        calcLayout->AddWidget((*widgets)->calcButtons[ButtonSum]);

        calcLayout->AddWidget((*widgets)->calcButtons[ButtonSin]);
        calcLayout->AddWidget((*widgets)->calcButtons[ButtonCos]);
        calcLayout->AddWidget((*widgets)->calcButtons[ButtonTan]);
        calcLayout->AddWidget((*widgets)->calcButtons[Button0], 2);
        calcLayout->AddWidget((*widgets)->calcButtons[ButtonDot]);
        calcLayout->AddWidget((*widgets)->calcButtons[ButtonResult]);

        delete calcLayout;
    }
};

#endif // WINUI_H
