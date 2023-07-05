#pragma once


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

private:

    void SetStyle(CalcWidgets *widgets) {
        widgets->inputLineEdit->setAlignment(Qt::AlignRight | Qt::AlignVCenter);
        widgets->calculatorWindow->setStyleSheet(     "QWidget, QLabel#input {"
                                                "   background-color: rgb(27, 32, 50);"
                                                "   color: white;"
                                                "   font-size: 26px;"
                                                "   border: none;"
                                                "}"
                                                "QPushButton {"
                                                "   background-color: rgb(46, 49, 68);"
                                                "   color: white;"
                                                "   font-size: 14px;"
                                                "   border-radius: 5; "
                                                "}"
                                                "QPushButton:hover {"
                                                "   background-color: rgb(51, 54, 70);"
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

                                                "QPushButton#number:hover, QPushButton#dot:hover {"
                                                "    background-color: rgb(51, 54, 72);"
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
                                                "   background-color: rgb(53, 163, 211); "
                                                "}"
                                                "QPushButton#equal:pressed {"
                                                "   background-color: rgb(82, 144, 187); "
                                                "}"
                                              );
    }

    void SetStyle(CreditCalcWidgets *widgets) {
        widgets->creditCalcWindow->setStyleSheet("QMainWindow, QChartView {"
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

        widgets->title[CreditSum]->setStyleSheet("color: rgb(217, 217, 217);");
        widgets->title[CreditTerm]->setStyleSheet("color: rgb(217, 217, 217);");
        widgets->title[InterestRate]->setStyleSheet("color: rgb(217, 217, 217);");

        widgets->chartView->SetBarWidth(0.75);
        widgets->chartView->SetBarColor(QColor(105, 124, 194), QColor(132, 157, 245));
        widgets->chartView->SetBorderBarColor(QColor(27, 32, 50), QColor(27, 32, 50));
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
        layout.SetLeftSpacing(3);
        layout.SetRightSpacing(3);
        layout.SetAboveSpacing(2);
        layout.SetBottomSpacing(3);
        layout.SetHorizontalSpacing(2);
        layout.SetVerticalSpacing(2);
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
