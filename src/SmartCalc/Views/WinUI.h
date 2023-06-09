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
        Layout layout;

        widgets->calcWindow->setFixedSize(420, 350);
        layout.SetStartPoints(0, 0);
        layout.SetEndPoints(widgets->calcWindow->width(), widgets->calcWindow->height());
        layout.SetColumns(7);
        layout.SetRows(7);
        layout.SetLeftSpacing(3);
        layout.SetRightSpacing(3);
        layout.SetAboveSpacing(2);
        layout.SetBottomSpacing(3);
        layout.SetHorizontalSpacing(2);
        layout.SetVerticalSpacing(2);
        layout.SetAutoSize();

        layout.AddWidget(widgets->Input, 7, 2);
        layout.AddWidget(widgets->calcButtons[ButtonX]);
        layout.AddWidget(widgets->calcButtons[ButtonOpenBracket]);
        layout.AddWidget(widgets->calcButtons[ButtonCloseBracket]);
        layout.AddWidget(widgets->calcButtons[ButtonAC]);
        layout.AddWidget(widgets->calcButtons[ButtonC]);
        layout.AddWidget(widgets->calcButtons[ButtonUnaryOperator]);
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
        layout.AddWidget(widgets->calcButtons[ButtonResult]);
    }
};

#endif // WINUI_H
