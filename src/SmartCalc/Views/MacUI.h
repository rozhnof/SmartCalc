#pragma once


#include "IPlatformUI.h"
#include <iostream>
#include <QWidget>


using namespace std;

class MacUI : public IPlatformUI
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

private:

    void SetStyle(CalcWidgets *widgets) {
        widgets->inputLineEdit->setAlignment(Qt::AlignRight | Qt::AlignVCenter);
        widgets->calculatorWindow->setStyleSheet(   "QLabel#input { "
                                              "     background-color: rgb(36, 36, 39); "
                                              "     font-size: 26px;"
                                              "     border: none"
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
                                              "QPushButton#operator, QPushButton#clear, QPushButton#unaryOperator, QPushButton#equal, QPushButton#exp { "
                                              "     background-color: rgb(226, 153, 57);"
                                              "     border-style: solid;"
                                              "     border-width: 1px 1px 0px 0px;"
                                              "     border-color: rgb(34, 34, 34); }"
                                              "QPushButton#operator:pressed, QPushButton#clear:pressed, QPushButton#unaryOperator:pressed, QPushButton#equal:pressed, QPushButton#exp:pressed { "
                                              "     background-color: rgb(191, 129, 46); "
                                              "}");
    }

    void SetStyle(CreditCalcWidgets *widgets) {
        widgets->creditCalcWindow->setStyleSheet( "QMainWindow, QChartView {"
                                                  " background-color: rgb(36, 36, 39);"
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

        widgets->title[CreditSum]->setStyleSheet("color: rgb(217, 217, 217);");
        widgets->title[CreditTerm]->setStyleSheet("color: rgb(217, 217, 217);");
        widgets->title[InterestRate]->setStyleSheet("color: rgb(217, 217, 217);");

        widgets->chartView->SetBarWidth(0.75);
        widgets->chartView->SetBarColor(QColor(226, 153, 57), QColor(237, 177, 99));
        widgets->chartView->SetBorderBarColor(QColor(36, 36, 39), QColor(36, 36, 39));
        widgets->chartView->SetLabelsColor(QColor(217, 217, 217));
        widgets->chartView->SetLinePenColor(QColor(217, 217, 217));
        widgets->chartView->SetGridLineColor(QColor(217, 217, 217));
    }

    void SetGeometry(CalcWidgets *widgets) {
        Layout layout;

        widgets->calculatorWindow->setFixedSize(420, 350);
        layout.SetStartPoints(0, 0);
        layout.SetEndPoints(widgets->calculatorWindow->width(), widgets->calculatorWindow->height());
        layout.SetColumns(7);
        layout.SetRows(7);
        layout.SetLeftSpacing(0);
        layout.SetRightSpacing(0);
        layout.SetAboveSpacing(0);
        layout.SetBottomSpacing(0);
        layout.SetHorizontalSpacing(0);
        layout.SetVerticalSpacing(0);
        layout.SetAutoSize();

        layout.AddWidget(widgets->inputLineEdit, 7, 2);
        layout.AddWidget(widgets->buttonDictionary[ButtonX]);
        layout.AddWidget(widgets->buttonDictionary[ButtonOpenBracket]);
        layout.AddWidget(widgets->buttonDictionary[ButtonCloseBracket]);
        layout.AddWidget(widgets->buttonAllClear);
        layout.AddWidget(widgets->buttonClear);
        layout.AddWidget(widgets->buttonDictionary[ButtonEXP]);
        layout.AddWidget(widgets->buttonDictionary[ButtonDiv]);

        layout.AddWidget(widgets->buttonDictionary[ButtonMod]);
        layout.AddWidget(widgets->buttonDictionary[ButtonPow]);
        layout.AddWidget(widgets->buttonDictionary[ButtonFactorial]);
        layout.AddWidget(widgets->buttonDictionary[Button7]);
        layout.AddWidget(widgets->buttonDictionary[Button8]);
        layout.AddWidget(widgets->buttonDictionary[Button9]);
        layout.AddWidget(widgets->buttonDictionary[ButtonMul]);

        layout.AddWidget(widgets->buttonDictionary[ButtonLog]);
        layout.AddWidget(widgets->buttonDictionary[ButtonLn]);
        layout.AddWidget(widgets->buttonDictionary[ButtonSqrt]);
        layout.AddWidget(widgets->buttonDictionary[Button4]);
        layout.AddWidget(widgets->buttonDictionary[Button5]);
        layout.AddWidget(widgets->buttonDictionary[Button6]);
        layout.AddWidget(widgets->buttonDictionary[ButtonSub]);

        layout.AddWidget(widgets->buttonDictionary[ButtonAsin]);
        layout.AddWidget(widgets->buttonDictionary[ButtonAcos]);
        layout.AddWidget(widgets->buttonDictionary[ButtonAtan]);
        layout.AddWidget(widgets->buttonDictionary[Button1]);
        layout.AddWidget(widgets->buttonDictionary[Button2]);
        layout.AddWidget(widgets->buttonDictionary[Button3]);
        layout.AddWidget(widgets->buttonDictionary[ButtonSum]);

        layout.AddWidget(widgets->buttonDictionary[ButtonSin]);
        layout.AddWidget(widgets->buttonDictionary[ButtonCos]);
        layout.AddWidget(widgets->buttonDictionary[ButtonTan]);
        layout.AddWidget(widgets->buttonDictionary[Button0], 2);
        layout.AddWidget(widgets->buttonDictionary[ButtonDot]);
        layout.AddWidget(widgets->buttonEqual);
    }
};
