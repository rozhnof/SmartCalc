#pragma once


#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QPushButton>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QWidget>
#include "mainwindow.h"
#include <QVector>
#include <QResizeEvent>
#include <QDebug>
#include "../Controllers/CalculatorController.h"


class CalculatorUI : public MainWindow
{
    Q_OBJECT

public:
    CalculatorController *controller;
    CalcWidgets *widgets;

    CalculatorUI() : MainWindow() {
        controller = new CalculatorController;
        widgets = new CalcWidgets;
        widgets->calcWindow = this;

        CreateObjects();
        Connects();
    }

    void SetupUI() override {
        ResetSettings();
        (*_platform)->SetupUI(widgets);
    }

private:

    void CreateObjects() {
       widgets->Input = NewLineEdit(this, "0", "input");
       widgets->allClear = NewPushButton(this, "AC", "clear");
       widgets->clear = NewPushButton(this, "C", "clear");
       widgets->result = NewPushButton(this, "=", "equal");

       widgets->calcButtons.insert(make_pair(Button0, NewPushButton(this, "0", "number")));
       widgets->calcButtons.insert(make_pair(Button1, NewPushButton(this, "1", "number")));
       widgets->calcButtons.insert(make_pair(Button2, NewPushButton(this, "2", "number")));
       widgets->calcButtons.insert(make_pair(Button3, NewPushButton(this, "3", "number")));
       widgets->calcButtons.insert(make_pair(Button4, NewPushButton(this, "4", "number")));
       widgets->calcButtons.insert(make_pair(Button5, NewPushButton(this, "5", "number")));
       widgets->calcButtons.insert(make_pair(Button6, NewPushButton(this, "6", "number")));
       widgets->calcButtons.insert(make_pair(Button7, NewPushButton(this, "7", "number")));
       widgets->calcButtons.insert(make_pair(Button8, NewPushButton(this, "8", "number")));
       widgets->calcButtons.insert(make_pair(Button9, NewPushButton(this, "9", "number")));

       widgets->calcButtons.insert(make_pair(ButtonSin, NewPushButton(this, "sin", "function")));
       widgets->calcButtons.insert(make_pair(ButtonCos, NewPushButton(this, "cos", "function")));
       widgets->calcButtons.insert(make_pair(ButtonTan, NewPushButton(this, "tan", "function")));
       widgets->calcButtons.insert(make_pair(ButtonAsin, NewPushButton(this, "asin", "function")));
       widgets->calcButtons.insert(make_pair(ButtonAcos, NewPushButton(this, "acos", "function")));
       widgets->calcButtons.insert(make_pair(ButtonAtan, NewPushButton(this, "atan", "function")));
       widgets->calcButtons.insert(make_pair(ButtonLog, NewPushButton(this, "log", "function")));
       widgets->calcButtons.insert(make_pair(ButtonSqrt, NewPushButton(this, "sqrt", "function")));
       widgets->calcButtons.insert(make_pair(ButtonLn, NewPushButton(this, "ln", "function")));

       widgets->calcButtons.insert(make_pair(ButtonSum, NewPushButton(this, "+", "operator")));
       widgets->calcButtons.insert(make_pair(ButtonSub, NewPushButton(this, "-", "operator")));
       widgets->calcButtons.insert(make_pair(ButtonMul, NewPushButton(this, "*", "operator")));
       widgets->calcButtons.insert(make_pair(ButtonDiv, NewPushButton(this, "/", "operator")));
       widgets->calcButtons.insert(make_pair(ButtonMod, NewPushButton(this, "%", "mod")));
       widgets->calcButtons.insert(make_pair(ButtonPow, NewPushButton(this, "^", "pow")));

       widgets->calcButtons.insert(make_pair(ButtonX, NewPushButton(this, "x", "x")));
       widgets->calcButtons.insert(make_pair(ButtonDot, NewPushButton(this, ".", "dot")));
       widgets->calcButtons.insert(make_pair(ButtonEXP, NewPushButton(this, "EXP", "exp")));

       widgets->calcButtons.insert(make_pair(ButtonFactorial, NewPushButton(this, "!", "factorial")));
       widgets->calcButtons.insert(make_pair(ButtonOpenBracket, NewPushButton(this, "(", "bracket")));
       widgets->calcButtons.insert(make_pair(ButtonCloseBracket, NewPushButton(this, ")", "bracket")));
    }

    void Connects() {
        for (auto it : widgets->calcButtons) {
            connect(it.second, &QPushButton::clicked, this, &CalculatorUI::SetSymbol);
        }

        connect(widgets->clear, &QPushButton::clicked, this, &CalculatorUI::Clear);
        connect(widgets->allClear, &QPushButton::clicked, this, &CalculatorUI::ClearAll);
        connect(widgets->result, &QPushButton::clicked, this, &CalculatorUI::Result);
        connect(widgets->Input, &QLineEdit::returnPressed, this, &CalculatorUI::Result);
    }

    void ResetSettings() {
        widgets->Input->hide();
        for (auto it : widgets->calcButtons) {
            it.second->hide();
        }
    }

private slots:

    void SetSymbol() {
        widgets->Input->setText(widgets->Input->text() + static_cast<QPushButton*>(sender())->text());
    }

    void Clear() {
        if (!widgets->Input->text().isEmpty()) {
            QString input = widgets->Input->text();
            input.chop(1);
            widgets->Input->setText(input);
        }
    }

    void ClearAll() {
        widgets->Input->setText("");
    }

    void Result() {
        QString input = widgets->Input->text();
        double x = 0;

        if (controller->Validate(input)) {
            widgets->Input->setText(QString::number(controller->GetResult(input, x), 'g', 8));
        }
    }
};
