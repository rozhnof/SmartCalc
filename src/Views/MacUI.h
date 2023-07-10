#pragma once


#include "IPlatformUI.h"
#include <iostream>
#include <QWidget>


class MacUI : public IPlatformUI
{
public:

    void SetupUI(CalcWidgets *widgets) override {
        setStyle(widgets);
        setGeometry(widgets);
    }

    void SetupUI(CreditCalcWidgets *widgets) override {
        setStyle(widgets);
    }

private:

    void setStyle(CalcWidgets *widgets) {
        widgets->inputLineEdit->setAlignment(Qt::AlignRight | Qt::AlignVCenter);
        widgets->inputXLineEdit->setAlignment(Qt::AlignVCenter | Qt::AlignHCenter);
        widgets->calculatorWindow->setStyleSheet(R"(
            QLineEdit#input {
                background-color: rgb(36, 36, 39);
                font-size: 26px;
                border: none;
            }
            QLineEdit#input_x {
                background-color: rgb(45, 45, 45);
                font-size: 26px;
                border-radius: 10;
            }
            QPushButton {
                background-color: rgb(56, 56, 56);
                border-style: solid;
                border-width: 1px 1px 0px 0px;
                border-color: rgb(34, 34, 34);
            }
            QPushButton:pressed {
                background-color: rgb(89, 89, 89);
            }
            QPushButton#number,
            QPushButton#dot {
                background-color: rgb(89, 89, 89);
                border-style: solid;
                border-width: 1px 1px 0px 0px;
                border-color: rgb(34, 34, 34);
            }
            QPushButton#number:pressed,
            QPushButton#dot:pressed {
                background-color: rgb(155, 155, 155);
            }
            QPushButton#operator,
            QPushButton#clear,
            QPushButton#unaryOperator,
            QPushButton#equal,
            QPushButton#exp {
                background-color: rgb(226, 153, 57);
                border-style: solid;
                border-width: 1px 1px 0px 0px;
                border-color: rgb(34, 34, 34);
            }
            QPushButton#operator:pressed,
            QPushButton#clear:pressed,
            QPushButton#unaryOperator:pressed,
            QPushButton#equal:pressed,
            QPushButton#exp:pressed {
                background-color: rgb(191, 129, 46);
            }
            QPushButton#button_input_x,
            QLineEdit#input_x {
                background-color: rgb(56, 56, 56);
                border-style: solid;
                color: white;
                border-width: 1px;
                border-color: rgb(34, 34, 34);
                border-radius: 0;
                font-size: 14px;
            }
        )");
    }

    void setStyle(CreditCalcWidgets *widgets) {
        widgets->creditCalcWindow->setStyleSheet(R"(
            QMainWindow, QChartView {
                background-color: rgb(36, 36, 39);
            }
            QPushButton {
                background-color: rgb(217, 217, 217);
                color: rgb(37, 37, 37);
                border-radius: 10;
                font: 16px;
            }
            QComboBox {
                background-color: rgba(0, 0, 0, 0);
                color: rgb(37, 37, 37);
                font: 16px;
            }
            QTextEdit {
                background-color: rgb(217, 217, 217);
                border-radius: 10;
                font: 18px;
                color: rgb(37, 37, 37);
            }
            QPushButton:pressed {
                background-color: rgb(171, 171, 171);
            }
            QComboBox::drop-down {
                width: 0px;
                height: 0px;
                border: 0px;
            }
            QComboBox QAbstractItemView {
                color: rgb(37, 37, 37);
                background-color: rgb(217, 217, 217);
                padding: 10px;
            }
            QLabel, QLineEdit {
                background-color: rgba(217, 217, 217, 0);
                font: 16px;
                color: rgb(37, 37, 37);
            }
        )");

        widgets->title[CREDIT_SUM]->setStyleSheet("color: rgb(217, 217, 217);");
        widgets->title[CREDIT_TERM]->setStyleSheet("color: rgb(217, 217, 217);");
        widgets->title[CREDIT_INTEREST_RATE]->setStyleSheet("color: rgb(217, 217, 217);");

        widgets->chartView->SetBarWidth(0.75);
        widgets->chartView->SetBarColor(QColor(226, 153, 57), QColor(237, 177, 99));
        widgets->chartView->SetBorderBarColor(QColor(36, 36, 39), QColor(36, 36, 39));
        widgets->chartView->SetLabelsColor(QColor(217, 217, 217));
        widgets->chartView->SetLinePenColor(QColor(217, 217, 217));
        widgets->chartView->SetGridLineColor(QColor(217, 217, 217));
    }

    void setGeometry(CalcWidgets *widgets) {
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
        widgets->inputXWidget->setGeometry(-160, 0, 160, widgets->inputLineEdit->height());
        layout.AddWidget(widgets->buttonDictionary[BUTTON_X]);
        layout.AddWidget(widgets->buttonDictionary[BUTTON_OPEN_BRACKET]);
        layout.AddWidget(widgets->buttonDictionary[BUTTON_CLOSE_BRACKET]);
        layout.AddWidget(widgets->buttonAllClear);
        layout.AddWidget(widgets->buttonClear);
        layout.AddWidget(widgets->buttonDictionary[BUTTON_EXP]);
        layout.AddWidget(widgets->buttonDictionary[BUTTON_DIV]);

        layout.AddWidget(widgets->buttonDictionary[BUTTON_MOD]);
        layout.AddWidget(widgets->buttonDictionary[BUTTON_POW]);
        layout.AddWidget(widgets->buttonDictionary[BUTTON_FACTORIAL]);
        layout.AddWidget(widgets->buttonDictionary[BUTTON_7]);
        layout.AddWidget(widgets->buttonDictionary[BUTTON_8]);
        layout.AddWidget(widgets->buttonDictionary[BUTTON_9]);
        layout.AddWidget(widgets->buttonDictionary[BUTTON_MUL]);

        layout.AddWidget(widgets->buttonDictionary[BUTTON_LOG]);
        layout.AddWidget(widgets->buttonDictionary[BUTTON_LN]);
        layout.AddWidget(widgets->buttonDictionary[BUTTON_SQRT]);
        layout.AddWidget(widgets->buttonDictionary[BUTTON_4]);
        layout.AddWidget(widgets->buttonDictionary[BUTTON_5]);
        layout.AddWidget(widgets->buttonDictionary[BUTTON_6]);
        layout.AddWidget(widgets->buttonDictionary[BUTTON_SUB]);

        layout.AddWidget(widgets->buttonDictionary[BUTTON_ASIN]);
        layout.AddWidget(widgets->buttonDictionary[BUTTON_ACOS]);
        layout.AddWidget(widgets->buttonDictionary[BUTTON_ATAN]);
        layout.AddWidget(widgets->buttonDictionary[BUTTON_1]);
        layout.AddWidget(widgets->buttonDictionary[BUTTON_2]);
        layout.AddWidget(widgets->buttonDictionary[BUTTON_3]);
        layout.AddWidget(widgets->buttonDictionary[BUTTON_SUM]);

        layout.AddWidget(widgets->buttonDictionary[BUTTON_SIN]);
        layout.AddWidget(widgets->buttonDictionary[BUTTON_COS]);
        layout.AddWidget(widgets->buttonDictionary[BUTTON_TAN]);
        layout.AddWidget(widgets->buttonDictionary[BUTTON_0], 2);
        layout.AddWidget(widgets->buttonDictionary[BUTTON_DOT]);
        layout.AddWidget(widgets->buttonEqual);
    }
};
