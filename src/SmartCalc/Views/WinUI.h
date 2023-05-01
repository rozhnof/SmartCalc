#ifndef WINUI_H
#define WINUI_H

#include "IPlatformUI.h"
#include <iostream>


using namespace std;




class WinUI : public IPlatformUI
{

private:
    CalcGroup *digitButtons;
    CalcGroup *functionButtons;
    CalcGroup *operatorButtons;

    CalcGroup *buttonList;

    CalcWidgets **widgets;

public:

    void SetupUI(CalcWidgets *o_widgets) override {
        widgets = &o_widgets;

        CreateButtonGroups();
        SetStyleSheet();
        SetSize();
    }

    void SetupUI(CreditCalcWidgets *o_widgets) override {
//        o_widgets->label->setText("ЭТО КРЕДИТНЫЙ КАЛЬКУЛЯТОР НА винде");
    }

    void SetupUI(DepositCalcWidgets *o_widgets) override {
        o_widgets->label->setText("ЭТО ДЕПОЗИТНЫЙ КАЛЬКУЛЯТОР НА винде");
    }

    void SetupUI(GraphWidgets *o_widgets) override {

    }

private:

    void SetStyleSheet() {

        (*widgets)->Input->setAlignment(Qt::AlignRight | Qt::AlignCenter);
        (*widgets)->Input->setStyleSheet("background-color: rgb(25, 25, 25)");

        digitButtons->SetButtonStyle("background-color: rgb(120, 120, 120);"
                                     "border-style: solid;"
                                     "border-width: 1px 1px 0px 0px;"
                                     "border-color: rgb(34, 34, 34);");
        digitButtons->SetPressedButtonStyle("background-color: rgba(255, 255, 255, 128);");
        digitButtons->StyleApply();

        functionButtons->SetButtonStyle("background-color: rgb(200, 200, 200);"
                                     "border-style: solid;"
                                     "border-width: 1px 1px 0px 0px;"
                                     "border-color: rgb(34, 34, 34);");
        functionButtons->SetPressedButtonStyle("background-color: rgba(162, 161, 166, 128);");
        functionButtons->StyleApply();

        operatorButtons->SetButtonStyle("background-color: rgb(123, 234, 54);"
                                     "border-style: solid;"
                                     "border-width: 1px 1px 0px 0px;"
                                     "border-color: rgb(34, 34, 34);");
        operatorButtons->SetPressedButtonStyle("background-color: rgba(255, 165, 2, 130)");
        operatorButtons->StyleApply();
    }

    void SetSize() {
        (*widgets)->calcWindow->setFixedSize(420, 360);

        int windowWidth = (*widgets)->calcWindow->width();
        int windowHeight = (*widgets)->calcWindow->height();

        int horizontalButtons = 7;
        int verticalButtons = 6;

        int width = windowWidth / horizontalButtons + 1;
        int height = windowHeight / verticalButtons + 1;

        QFont font = (*widgets)->Input->font();
        int size_text = (width + height ) / 4;
        font.setPointSize(size_text);
        (*widgets)->Input->setFont(font);

        QFont fontButtons;
        fontButtons.setPointSize(size_text / 2);

        int x = 0;
        int y = 0;
        (*widgets)->Input->setGeometry(x, y, windowWidth, height);

        y += height;
        for (int buttonCounter = 0; buttonCounter < 33; buttonCounter++) {

            int coef = 1;
            if (buttonList->indices.at(buttonCounter) == ButtonUnaryOperator || buttonList->indices.at(buttonCounter) == Button0) {
                coef = 2;
            }

            (*widgets)->calcButtons.at(buttonList->indices.at(buttonCounter))->setGeometry(x, y, width * coef, height);
            (*widgets)->calcButtons.at(buttonList->indices.at(buttonCounter))->setFont(fontButtons);
            x += width * coef;

            if (x > windowWidth) {
                x = 0;
                y += height;
            }
        }
    }

    void CreateButtonGroups() {
        digitButtons = new CalcGroup((*widgets)->calcButtons);
        for (int i = Button0; i <= ButtonDot; i++) {
            digitButtons->addButton(i);
        }

        functionButtons = new CalcGroup((*widgets)->calcButtons);
        functionButtons->indices = { ButtonX, ButtonMod, ButtonFactorial, ButtonPow, ButtonOpenBracket, ButtonOpenBracket, ButtonCloseBracket };
        for (int i = ButtonSin; i <= ButtonSqrt; i++) {
            functionButtons->addButton(i);
        }

        operatorButtons = new CalcGroup((*widgets)->calcButtons);
        operatorButtons->indices = { ButtonSum, ButtonSub, ButtonMul, ButtonDiv, ButtonAC, ButtonUnaryOperator, ButtonResult };

        buttonList = new CalcGroup((*widgets)->calcButtons);
        buttonList->indices = { ButtonX, ButtonOpenBracket, ButtonCloseBracket, ButtonAC, ButtonUnaryOperator, ButtonDiv,
                                ButtonMod, ButtonFactorial, ButtonPow, Button7, Button8, Button9, ButtonMul,
                                ButtonLog, ButtonLn, ButtonSqrt, Button4, Button5, Button6, ButtonSub,
                                ButtonAsin, ButtonAcos, ButtonAtan, Button1, Button2, Button3, ButtonSum,
                                ButtonSin, ButtonCos, ButtonTan, Button0, ButtonDot, ButtonResult };
    }



};

#endif // WINUI_H
