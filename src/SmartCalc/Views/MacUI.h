#ifndef MACUI_H
#define MACUI_H

#include "IPlatformUI.h"
#include <iostream>

class MacUI : public IPlatformUI
{

public:

    void SetSize(CalcWidgets *widgets, QWidget *Window) override  {
        int countHorizontalButtons = 7;
        int countVerticalButtons = 6;

        int width = Window->width() / countHorizontalButtons, height = Window->height() / countVerticalButtons;
        int x, y;

        int edgeWidth = Window->width() % countHorizontalButtons + width;
        int edgeHeight = Window->height() % countVerticalButtons + height;

        QFont font = widgets->Input->font();
        font.setPointSize((width + height ) / 4);
        widgets->Input->setFont(font);

        widgets->Input->setGeometry(x = 0, y = 0, Window->width(), height);

        widgets->buttons.at(ButtonX)->setGeometry(x = 0, y+=height, width, height);
        widgets->buttons.at(ButtonOpenBracket)->setGeometry(x+=widgets->buttons.at(ButtonX)->width(), y, width, height);
        widgets->buttons.at(ButtonCloseBracket)->setGeometry(x+=widgets->buttons.at(ButtonOpenBracket)->width(), y, width, height);
        widgets->buttons.at(ButtonAC)->setGeometry(x+=widgets->buttons.at(ButtonCloseBracket)->width(), y, width, height);
        widgets->buttons.at(ButtonGraph)->setGeometry(x+=widgets->buttons.at(ButtonAC)->width(), y, width * 2, height);
        widgets->buttons.at(ButtonDiv)->setGeometry(x+=widgets->buttons.at(ButtonGraph)->width(), y, edgeWidth, height);

        widgets->buttons.at(ButtonMod)->setGeometry(x = 0, y+=height, width, height);
        widgets->buttons.at(ButtonFactorial)->setGeometry(x+=widgets->buttons.at(ButtonMod)->width(), y, width, height);
        widgets->buttons.at(ButtonPow)->setGeometry(x+=widgets->buttons.at(ButtonFactorial)->width(), y, width, height);
        widgets->buttons.at(Button7)->setGeometry(x+=widgets->buttons.at(ButtonPow)->width(), y, width, height);
        widgets->buttons.at(Button8)->setGeometry(x+=widgets->buttons.at(Button7)->width(), y, width, height);
        widgets->buttons.at(Button9)->setGeometry(x+=widgets->buttons.at(Button8)->width(), y, width, height);
        widgets->buttons.at(ButtonMul)->setGeometry(x+=widgets->buttons.at(Button9)->width(), y, edgeWidth, height);

        widgets->buttons.at(ButtonLog)->setGeometry(x = 0, y+=height, width, height);
        widgets->buttons.at(ButtonLn)->setGeometry(x+=widgets->buttons.at(ButtonLog)->width(), y, width, height);
        widgets->buttons.at(ButtonSqrt)->setGeometry(x+=widgets->buttons.at(ButtonLn)->width(), y, width, height);
        widgets->buttons.at(Button4)->setGeometry(x+=widgets->buttons.at(ButtonSqrt)->width(), y, width, height);
        widgets->buttons.at(Button5)->setGeometry(x+=widgets->buttons.at(Button4)->width(), y, width, height);
        widgets->buttons.at(Button6)->setGeometry(x+=widgets->buttons.at(Button5)->width(), y, width, height);
        widgets->buttons.at(ButtonSub)->setGeometry(x+=widgets->buttons.at(Button6)->width(), y, edgeWidth, height);

        widgets->buttons.at(ButtonAsin)->setGeometry(x = 0, y+=height, width, height);
        widgets->buttons.at(ButtonAcos)->setGeometry(x+=widgets->buttons.at(ButtonAsin)->width(), y, width, height);
        widgets->buttons.at(ButtonAtan)->setGeometry(x+=widgets->buttons.at(ButtonAcos)->width(), y, width, height);
        widgets->buttons.at(Button1)->setGeometry(x+=widgets->buttons.at(ButtonAtan)->width(), y, width, height);
        widgets->buttons.at(Button2)->setGeometry(x+=widgets->buttons.at(Button1)->width(), y, width, height);
        widgets->buttons.at(Button3)->setGeometry(x+=widgets->buttons.at(Button2)->width(), y, width, height);
        widgets->buttons.at(ButtonSum)->setGeometry(x+=widgets->buttons.at(Button3)->width(), y, edgeWidth, height);

        widgets->buttons.at(ButtonSin)->setGeometry(x = 0, y+=height, width, edgeHeight);
        widgets->buttons.at(ButtonCos)->setGeometry(x+=widgets->buttons.at(ButtonSin)->width(), y, width, edgeHeight);
        widgets->buttons.at(ButtonTan)->setGeometry(x+=widgets->buttons.at(ButtonCos)->width(), y, width, edgeHeight);
        widgets->buttons.at(Button0)->setGeometry(x+=widgets->buttons.at(ButtonTan)->width(), y, width * 2, edgeHeight);
        widgets->buttons.at(ButtonDot)->setGeometry(x+=widgets->buttons.at(Button0)->width(), y, width, edgeHeight);
        widgets->buttons.at(ButtonResult)->setGeometry(x+=widgets->buttons.at(ButtonDot)->width(), y, edgeWidth, edgeHeight);
    }

    MacUI() {}

    void SetupCalculatorUI(CalcWidgets *widgets, QWidget *Window) override {
        widgets->Input->setAlignment(Qt::AlignCenter | Qt::AlignRight);
        widgets->Input->setStyleSheet("background-color: black");

        SetSize(widgets, Window);

        Window->setStyleSheet("QPushButton {"
                                  "background-color: rgb(226, 153, 57);"
                                  "border-width: 1px;"
                                  "border-color: rgb(34, 34, 34);"
                                  "font: bold 20px; }"
                              "QPushButton:pressed {"
                                "background-color: rgba(255, 165, 2, 130);"
                              "}");



    }
    void SetupGraphUI() override {
        cout << "BEBRA" << endl;
    }
    void SetupCreditCalculatorUI() override {
        cout << "BEBRA" << endl;
    }
    void SetupDepositCalculatorUI() override {
        cout << "BEBRA" << endl;
    }

private slots:

};

#endif // MACUI_H
