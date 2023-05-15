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
        widgets->Input->setAlignment(Qt::AlignRight | Qt::AlignCenter);
        widgets->calcWindow->setStyleSheet(   "QLabel#input { "
                                              "     background-color: rgb(36, 36, 39); "
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
        widgets->calcWindow->setFixedSize(420, 350);
        Layout *calcLayout = new Layout(0, 0, widgets->calcWindow->width(), widgets->calcWindow->height(), 7, 7, 0, 0);

        calcLayout->AddWidget(widgets->Input, 7, 2);
        calcLayout->AddWidget(widgets->calcButtons[ButtonX]);
        calcLayout->AddWidget(widgets->calcButtons[ButtonOpenBracket]);
        calcLayout->AddWidget(widgets->calcButtons[ButtonCloseBracket]);
        calcLayout->AddWidget(widgets->calcButtons[ButtonAC]);
        calcLayout->AddWidget(widgets->calcButtons[ButtonC]);
        calcLayout->AddWidget(widgets->calcButtons[ButtonUnaryOperator]);
        calcLayout->AddWidget(widgets->calcButtons[ButtonDiv]);

        calcLayout->AddWidget(widgets->calcButtons[ButtonMod]);
        calcLayout->AddWidget(widgets->calcButtons[ButtonPow]);
        calcLayout->AddWidget(widgets->calcButtons[ButtonFactorial]);
        calcLayout->AddWidget(widgets->calcButtons[Button7]);
        calcLayout->AddWidget(widgets->calcButtons[Button8]);
        calcLayout->AddWidget(widgets->calcButtons[Button9]);
        calcLayout->AddWidget(widgets->calcButtons[ButtonMul]);

        calcLayout->AddWidget(widgets->calcButtons[ButtonLog]);
        calcLayout->AddWidget(widgets->calcButtons[ButtonLn]);
        calcLayout->AddWidget(widgets->calcButtons[ButtonSqrt]);
        calcLayout->AddWidget(widgets->calcButtons[Button4]);
        calcLayout->AddWidget(widgets->calcButtons[Button5]);
        calcLayout->AddWidget(widgets->calcButtons[Button6]);
        calcLayout->AddWidget(widgets->calcButtons[ButtonSub]);

        calcLayout->AddWidget(widgets->calcButtons[ButtonAsin]);
        calcLayout->AddWidget(widgets->calcButtons[ButtonAcos]);
        calcLayout->AddWidget(widgets->calcButtons[ButtonAtan]);
        calcLayout->AddWidget(widgets->calcButtons[Button1]);
        calcLayout->AddWidget(widgets->calcButtons[Button2]);
        calcLayout->AddWidget(widgets->calcButtons[Button3]);
        calcLayout->AddWidget(widgets->calcButtons[ButtonSum]);

        calcLayout->AddWidget(widgets->calcButtons[ButtonSin]);
        calcLayout->AddWidget(widgets->calcButtons[ButtonCos]);
        calcLayout->AddWidget(widgets->calcButtons[ButtonTan]);
        calcLayout->AddWidget(widgets->calcButtons[Button0], 2);
        calcLayout->AddWidget(widgets->calcButtons[ButtonDot]);
        calcLayout->AddWidget(widgets->calcButtons[ButtonResult]);

        delete calcLayout;
    }
};

#endif // MACUI_H
