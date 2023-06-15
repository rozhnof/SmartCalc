#ifndef MACUI_H
#define MACUI_H

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

    void SetupUI(DepositCalcWidgets *widgets) override {
        SetStyle(widgets);
    }

private:

    void SetStyle(CalcWidgets *widgets) {
        widgets->Input->setAlignment(Qt::AlignRight | Qt::AlignVCenter);
        widgets->calcWindow->setStyleSheet(   "QLabel#input { "
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

    void SetStyle(DepositCalcWidgets *widgets) {
        widgets->depositCalcWindow->setStyleSheet( "QMainWindow, QChartView {"
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

        widgets->boxTitle[CreditSum]->setStyleSheet("color: rgb(217, 217, 217);");
        widgets->boxTitle[CreditTerm]->setStyleSheet("color: rgb(217, 217, 217);");
        widgets->boxTitle[InterestRate]->setStyleSheet("color: rgb(217, 217, 217);");

        widgets->chartView->SetBarWidth(0.75);
        widgets->chartView->SetBarColor(QColor(226, 153, 57), QColor(237, 177, 99));
        widgets->chartView->SetBorderBarColor(QColor(36, 36, 39), QColor(36, 36, 39));
        widgets->chartView->SetLabelsColor(QColor(217, 217, 217));
        widgets->chartView->SetLinePenColor(QColor(217, 217, 217));
        widgets->chartView->SetGridLineColor(QColor(217, 217, 217));
    }



    void SetGeometry(CalcWidgets *widgets) {
        Layout layout;

        widgets->calcWindow->setFixedSize(420, 350);
        layout.SetStartPoints(0, 0);
        layout.SetEndPoints(widgets->calcWindow->width(), widgets->calcWindow->height());
        layout.SetColumns(7);
        layout.SetRows(7);
        layout.SetLeftSpacing(0);
        layout.SetRightSpacing(0);
        layout.SetAboveSpacing(0);
        layout.SetBottomSpacing(0);
        layout.SetHorizontalSpacing(0);
        layout.SetVerticalSpacing(0);
        layout.SetAutoSize();

        layout.AddWidget(widgets->Input, 7, 2);
        layout.AddWidget(widgets->calcButtons[ButtonX]);
        layout.AddWidget(widgets->calcButtons[ButtonOpenBracket]);
        layout.AddWidget(widgets->calcButtons[ButtonCloseBracket]);
        layout.AddWidget(widgets->allClear);
        layout.AddWidget(widgets->clear);
        layout.AddWidget(widgets->calcButtons[ButtonEXP]);
        layout.AddWidget(widgets->calcButtons[ButtonDiv]);

        layout.AddWidget(widgets->calcButtons[ButtonMod]);
        layout.AddWidget(widgets->calcButtons[ButtonPow]);
        layout.AddWidget(widgets->calcButtons[ButtonFactorial]);
        layout.AddWidget(widgets->calcButtons[Button7]);
        layout.AddWidget(widgets->calcButtons[Button8]);
        layout.AddWidget(widgets->calcButtons[Button9]);
        layout.AddWidget(widgets->calcButtons[ButtonMul]);

        layout.AddWidget(widgets->calcButtons[ButtonLog]);
        layout.AddWidget(widgets->calcButtons[ButtonLn]);
        layout.AddWidget(widgets->calcButtons[ButtonSqrt]);
        layout.AddWidget(widgets->calcButtons[Button4]);
        layout.AddWidget(widgets->calcButtons[Button5]);
        layout.AddWidget(widgets->calcButtons[Button6]);
        layout.AddWidget(widgets->calcButtons[ButtonSub]);

        layout.AddWidget(widgets->calcButtons[ButtonAsin]);
        layout.AddWidget(widgets->calcButtons[ButtonAcos]);
        layout.AddWidget(widgets->calcButtons[ButtonAtan]);
        layout.AddWidget(widgets->calcButtons[Button1]);
        layout.AddWidget(widgets->calcButtons[Button2]);
        layout.AddWidget(widgets->calcButtons[Button3]);
        layout.AddWidget(widgets->calcButtons[ButtonSum]);

        layout.AddWidget(widgets->calcButtons[ButtonSin]);
        layout.AddWidget(widgets->calcButtons[ButtonCos]);
        layout.AddWidget(widgets->calcButtons[ButtonTan]);
        layout.AddWidget(widgets->calcButtons[Button0], 2);
        layout.AddWidget(widgets->calcButtons[ButtonDot]);
        layout.AddWidget(widgets->result);
    }
};

#endif // MACUI_H
