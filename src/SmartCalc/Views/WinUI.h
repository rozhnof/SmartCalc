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
        SetStyle(widgets);
    }

private:

    void SetStyle(CalcWidgets *widgets) {
        widgets->calcWindow->setStyleSheet(     "QWidget, QLabel#input {"
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

        widgets->boxTitle[CreditSum]->setStyleSheet("color: rgb(217, 217, 217);");
        widgets->boxTitle[CreditTerm]->setStyleSheet("color: rgb(217, 217, 217);");
        widgets->boxTitle[InterestRate]->setStyleSheet("color: rgb(217, 217, 217);");

        widgets->chartView->SetBarWidth(0.75);
        widgets->chartView->SetBarColor(QColor(105, 124, 194), QColor(132, 157, 245));
        widgets->chartView->SetBorderBarColor(QColor(27, 32, 50), QColor(27, 32, 50));
        widgets->chartView->SetLabelsColor(QColor(217, 217, 217));
        widgets->chartView->SetLinePenColor(QColor(217, 217, 217));
        widgets->chartView->SetGridLineColor(QColor(217, 217, 217));
    }

    void SetStyle(DepositCalcWidgets *widgets) {
        widgets->depositCalcWindow->setStyleSheet("QMainWindow, QChartView {"
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

        widgets->boxTitle[CreditSum]->setStyleSheet("color: rgb(217, 217, 217);");
        widgets->boxTitle[CreditTerm]->setStyleSheet("color: rgb(217, 217, 217);");
        widgets->boxTitle[InterestRate]->setStyleSheet("color: rgb(217, 217, 217);");

        widgets->chartView->SetBarWidth(0.75);
        widgets->chartView->SetBarColor(QColor(105, 124, 194), QColor(132, 157, 245));
        widgets->chartView->SetBorderBarColor(QColor(27, 32, 50), QColor(27, 32, 50));
        widgets->chartView->SetLabelsColor(QColor(217, 217, 217));
        widgets->chartView->SetLinePenColor(QColor(217, 217, 217));
        widgets->chartView->SetGridLineColor(QColor(217, 217, 217));
    }

    void SetGeometry(CalcWidgets *widgets) {
        widgets->calcWindow->setFixedSize(420, 350);
        Layout *calcLayout = new Layout(4, 0, widgets->calcWindow->width() - 4, widgets->calcWindow->height() - 4, 7, 7, 2, 2);

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

#endif // WINUI_H
