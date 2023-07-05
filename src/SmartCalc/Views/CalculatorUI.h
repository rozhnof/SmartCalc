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
        widgets->calculatorWindow = this;

        CreateObjects();
        Connects();
    }

    ~CalculatorUI() {
        delete controller;
        delete widgets;
    }

    void SetupUI() override {
        ResetSettings();
        (*_platform)->SetupUI(widgets);
    }

private:

    void CreateObjects() {
       widgets->inputLineEdit = NewLineEdit(this, "0", "input");
       widgets->buttonAllClear = NewPushButton(this, "AC", "clear");
       widgets->buttonClear = NewPushButton(this, "C", "clear");
       widgets->buttonEqual = NewPushButton(this, "=", "equal");

       widgets->buttonDictionary.insert(make_pair(Button0, NewPushButton(this, "0", "number")));
       widgets->buttonDictionary.insert(make_pair(Button1, NewPushButton(this, "1", "number")));
       widgets->buttonDictionary.insert(make_pair(Button2, NewPushButton(this, "2", "number")));
       widgets->buttonDictionary.insert(make_pair(Button3, NewPushButton(this, "3", "number")));
       widgets->buttonDictionary.insert(make_pair(Button4, NewPushButton(this, "4", "number")));
       widgets->buttonDictionary.insert(make_pair(Button5, NewPushButton(this, "5", "number")));
       widgets->buttonDictionary.insert(make_pair(Button6, NewPushButton(this, "6", "number")));
       widgets->buttonDictionary.insert(make_pair(Button7, NewPushButton(this, "7", "number")));
       widgets->buttonDictionary.insert(make_pair(Button8, NewPushButton(this, "8", "number")));
       widgets->buttonDictionary.insert(make_pair(Button9, NewPushButton(this, "9", "number")));

       widgets->buttonDictionary.insert(make_pair(ButtonSin, NewPushButton(this, "sin", "function")));
       widgets->buttonDictionary.insert(make_pair(ButtonCos, NewPushButton(this, "cos", "function")));
       widgets->buttonDictionary.insert(make_pair(ButtonTan, NewPushButton(this, "tan", "function")));
       widgets->buttonDictionary.insert(make_pair(ButtonAsin, NewPushButton(this, "asin", "function")));
       widgets->buttonDictionary.insert(make_pair(ButtonAcos, NewPushButton(this, "acos", "function")));
       widgets->buttonDictionary.insert(make_pair(ButtonAtan, NewPushButton(this, "atan", "function")));
       widgets->buttonDictionary.insert(make_pair(ButtonLog, NewPushButton(this, "log", "function")));
       widgets->buttonDictionary.insert(make_pair(ButtonSqrt, NewPushButton(this, "sqrt", "function")));
       widgets->buttonDictionary.insert(make_pair(ButtonLn, NewPushButton(this, "ln", "function")));

       widgets->buttonDictionary.insert(make_pair(ButtonSum, NewPushButton(this, "+", "operator")));
       widgets->buttonDictionary.insert(make_pair(ButtonSub, NewPushButton(this, "-", "operator")));
       widgets->buttonDictionary.insert(make_pair(ButtonMul, NewPushButton(this, "*", "operator")));
       widgets->buttonDictionary.insert(make_pair(ButtonDiv, NewPushButton(this, "/", "operator")));
       widgets->buttonDictionary.insert(make_pair(ButtonMod, NewPushButton(this, "%", "mod")));
       widgets->buttonDictionary.insert(make_pair(ButtonPow, NewPushButton(this, "^", "pow")));

       widgets->buttonDictionary.insert(make_pair(ButtonX, NewPushButton(this, "x", "x")));
       widgets->buttonDictionary.insert(make_pair(ButtonDot, NewPushButton(this, ".", "dot")));
       widgets->buttonDictionary.insert(make_pair(ButtonEXP, NewPushButton(this, "e", "exp")));

       widgets->buttonDictionary.insert(make_pair(ButtonFactorial, NewPushButton(this, "!", "factorial")));
       widgets->buttonDictionary.insert(make_pair(ButtonOpenBracket, NewPushButton(this, "(", "bracket")));
       widgets->buttonDictionary.insert(make_pair(ButtonCloseBracket, NewPushButton(this, ")", "bracket")));
    }

    void Connects() {
        for (auto it : widgets->buttonDictionary) {
            connect(it.second, &QPushButton::clicked, this, &CalculatorUI::SetSymbol);
        }

        connect(widgets->buttonClear, &QPushButton::clicked, this, &CalculatorUI::Clear);
        connect(widgets->buttonAllClear, &QPushButton::clicked, this, &CalculatorUI::ClearAll);
        connect(widgets->buttonEqual, &QPushButton::clicked, this, &CalculatorUI::Result);
        connect(widgets->inputLineEdit, &QLineEdit::returnPressed, this, &CalculatorUI::Result);
    }

    void ResetSettings() {
        widgets->inputLineEdit->hide();
        for (auto it : widgets->buttonDictionary) {
            it.second->hide();
        }
    }

private slots:

    void SetSymbol() {
        widgets->inputLineEdit->setText(widgets->inputLineEdit->text() + static_cast<QPushButton*>(sender())->text());
    }

    void Clear() {
        if (!widgets->inputLineEdit->text().isEmpty()) {
            QString input = widgets->inputLineEdit->text();
            input.chop(1);
            widgets->inputLineEdit->setText(input);
        }
    }

    void ClearAll() {
        widgets->inputLineEdit->setText("");
    }

    void Result() {
        QString input = widgets->inputLineEdit->text();
        double x = 0;

        if (controller->Validate(input)) {
            widgets->inputLineEdit->setText(QString::number(controller->GetResult(input, x), 'g', 8));
        }
    }
};
