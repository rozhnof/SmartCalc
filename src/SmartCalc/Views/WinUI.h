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
        widgets->Input->setAlignment(Qt::AlignRight | Qt::AlignVCenter);
        widgets->calcWindow->setStyleSheet(     "QWidget, QLabel#input {"
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

    void SetStyle(DepositCalcWidgets *widgets) {
        QString styleSheet = R"(
            QWidget#deposit_calculator_window {
                background-color: rgb(27, 32, 50);
            }
            QWidget#container {
                background-color: rgb(46, 49, 68);
                border: none;
                border-radius: 10;
            }
            QWidget#box {
                background-color: rgb(217, 217, 217);
                border: none;
                border-radius: 10;
            }
            QWidget#title {
                background-color: rgba(0, 0, 0, 0);
                color: rgb(217, 217, 217);
            }
            QWidget#data {
                background-color: rgba(0, 0, 0, 0);
                color: rgb(37, 37, 37);
                font-size: 16px;
            }
            QPushButton#button {
                background-color: rgb(217, 217, 217);
                border-radius: 10;
                color: rgb(37, 37, 37);
                font-size: 16px;
            }
            QPushButton#button_left {
                background-color: rgb(217, 217, 217);
                border-top-left-radius: 10;
                border-bottom-left-radius: 10;
                color: rgb(37, 37, 37);
                font-size: 16px;
            }
            QPushButton#button_right {
                background-color: rgb(217, 217, 217);
                border-top-right-radius: 10;
                border-bottom-right-radius: 10;
                color: rgb(37, 37, 37);
                font-size: 16px;
            }
            QWidget#box_right {
                background-color: rgb(217, 217, 217);
                border-top-right-radius: 10;
                border-bottom-right-radius: 10;
            }
            QPushButton#button:hover, QPushButton#button_left:hover, QPushButton#button_right:hover {
                background-color: rgb(194, 194, 194);
            }
            QPushButton#button:pressed, QPushButton#button_left:hover, QPushButton#button_right:hover {
                background-color: rgb(171, 171, 171);
            }
            QCheckBox {
                background-color: rgba(0, 0, 0, 0);
                font-size: 16px;
            }
            QCheckBox::indicator {
                background-color: rgba(27, 32, 50, 1);
                border: 1px solid rgba(217, 217, 217, 1);
                border-radius: 5;
                width: 18px;
                height: 18px;
            }
            QCheckBox::indicator:checked {
                background-color: rgba(217, 217, 217, 1);
            }
            QTableView#data_table::item:hover {
                background-color: rgba(46, 49, 68, 1);
                padding-left: 2;
            }
            QTableView#data_table {
                background-color: rgb(27, 32, 50);
                border: none;
                border-radius: 10;
                gridline-color: rgba(46, 49, 68, 1);
            }
            QTableView#data_table::item:selected {
                background-color: rgba(37, 41, 59, 1);
            }
            QTableView#data_table QHeaderView::section {
                background-color: rgba(27, 32, 50, 1);
                border: 1px solid rgba(46, 49, 68, 1);
                font-weight: bold;
            }
            QTableView#data_table QHeaderView::section:checked {
                background-color: rgba(46, 49, 68, 1);
            }
            QTableView#data_table QHeaderView::section:pressed, QTableView#data_table QTableCornerButton:pressed {
                background-color: rgba(37, 41, 59, 1);
            }
            QTableView#data_table QHeaderView::section:hover {
                background-color: rgba(46, 49, 68, 1);
            }
            QTableView#data_table QTableCornerButton {
                background-color: rgba(46, 49, 68, 1);
                border: 1px solid rgb(46, 49, 68);
            }
            QWidget#calendar_background {
                background-color: rgba(245, 246, 250, 1);
            }
        )";
        widgets->depositCalcWindow->setStyleSheet(styleSheet);

        for (auto it : widgets->boxData) {
            it.second->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
        }

        widgets->boxData[ACCURED_INTEREST]->setReadOnly(true);
        widgets->boxData[TOTAL_AMOUNT]->setReadOnly(true);
        widgets->boxData[TAX_AMOUNT]->setReadOnly(true);
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

#endif // WINUI_H
