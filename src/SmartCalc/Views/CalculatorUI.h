#ifndef CALCULATORUI_H
#define CALCULATORUI_H

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





class CalculatorUI : public MainWindow
{
    Q_OBJECT

public:
    CalcWidgets *widgets;

    CalculatorUI() : MainWindow() {
        widgets = new CalcWidgets;
        window = new QWidget(this);

        widgets->mainWindow = this;
        widgets->Window = window;

        this->setCentralWidget(window);
        this->setWindowTitle("Calculator");

        SetupButtons();

        widgets->Input = new QLabel(window);
    }

    void SetupUI() override {
        (*_platform)->SetupUI(widgets);
    }

    QPushButton *CreateButton(QString text, const char* member) {
        QPushButton *newButton = new QPushButton(text, window);
        connect(newButton, SIGNAL(clicked()), this, member);
        return newButton;
    }

    void SetupButtons() {
       widgets->calcButtons.insert(make_pair(Button0, CreateButton("0", SLOT(SetNumber()))));
       widgets->calcButtons.insert(make_pair(Button1, CreateButton("1", SLOT(SetNumber()))));
       widgets->calcButtons.insert(make_pair(Button2, CreateButton("2", SLOT(SetNumber()))));
       widgets->calcButtons.insert(make_pair(Button3, CreateButton("3", SLOT(SetNumber()))));
       widgets->calcButtons.insert(make_pair(Button4, CreateButton("4", SLOT(SetNumber()))));
       widgets->calcButtons.insert(make_pair(Button5, CreateButton("5", SLOT(SetNumber()))));
       widgets->calcButtons.insert(make_pair(Button6, CreateButton("6", SLOT(SetNumber()))));
       widgets->calcButtons.insert(make_pair(Button7, CreateButton("7", SLOT(SetNumber()))));
       widgets->calcButtons.insert(make_pair(Button8, CreateButton("8", SLOT(SetNumber()))));
       widgets->calcButtons.insert(make_pair(Button9, CreateButton("9", SLOT(SetNumber()))));

       widgets->calcButtons.insert(make_pair(ButtonSin, CreateButton("sin", SLOT(SetFunction()))));
       widgets->calcButtons.insert(make_pair(ButtonCos, CreateButton("cos", SLOT(SetFunction()))));
       widgets->calcButtons.insert(make_pair(ButtonTan, CreateButton("tan", SLOT(SetFunction()))));
       widgets->calcButtons.insert(make_pair(ButtonAsin, CreateButton("asin", SLOT(SetFunction()))));
       widgets->calcButtons.insert(make_pair(ButtonAcos, CreateButton("acos", SLOT(SetFunction()))));
       widgets->calcButtons.insert(make_pair(ButtonAtan, CreateButton("atan", SLOT(SetFunction()))));
       widgets->calcButtons.insert(make_pair(ButtonLog, CreateButton("log", SLOT(SetFunction()))));
       widgets->calcButtons.insert(make_pair(ButtonSqrt, CreateButton("sqrt", SLOT(SetFunction()))));
       widgets->calcButtons.insert(make_pair(ButtonLn, CreateButton("ln", SLOT(SetFunction()))));

       widgets->calcButtons.insert(make_pair(ButtonSum, CreateButton("+", SLOT(SetOperator()))));
       widgets->calcButtons.insert(make_pair(ButtonSub, CreateButton("-", SLOT(SetOperator()))));
       widgets->calcButtons.insert(make_pair(ButtonMul, CreateButton("*", SLOT(SetOperator()))));
       widgets->calcButtons.insert(make_pair(ButtonDiv, CreateButton("/", SLOT(SetOperator()))));
       widgets->calcButtons.insert(make_pair(ButtonMod, CreateButton("mod", SLOT(SetOperator()))));
       widgets->calcButtons.insert(make_pair(ButtonPow, CreateButton("^", SLOT(SetOperator()))));

       widgets->calcButtons.insert(make_pair(ButtonFactorial, CreateButton("!", SLOT(SetFactorial()))));

       widgets->calcButtons.insert(make_pair(ButtonOpenBracket, CreateButton("(", SLOT(SetOpenBracket()))));
       widgets->calcButtons.insert(make_pair(ButtonCloseBracket, CreateButton(")", SLOT(SetCloseBracket()))));

       widgets->calcButtons.insert(make_pair(ButtonDot, CreateButton(".", SLOT(SetDot()))));
       widgets->calcButtons.insert(make_pair(ButtonX, CreateButton("x", SLOT(SetX()))));
       widgets->calcButtons.insert(make_pair(ButtonAC, CreateButton("AC", SLOT(Clear()))));
       widgets->calcButtons.insert(make_pair(ButtonResult, CreateButton("=", SLOT(GetResult()))));
       widgets->calcButtons.insert(make_pair(ButtonUnaryOperator, CreateButton("+/-", SLOT(DrawGraph()))));
    }

private slots:


    void SetNumber() {
        int status = 1;
        widgets->Input->setText(controller->Validate(new NumberValidate, widgets->Input->text(), static_cast<QPushButton*>(sender())->text(), status));
    }

    void SetFunction() {
        int status = 1;
        widgets->Input->setText(controller->Validate(new FunctionValidate, widgets->Input->text(), static_cast<QPushButton*>(sender())->text(), status));
    }

    void SetOperator() {
        int status = 1;
        widgets->Input->setText(controller->Validate(new OperatorValidate, widgets->Input->text(), static_cast<QPushButton*>(sender())->text(), status));
    }

    void SetFactorial() {
        int status = 1;
        widgets->Input->setText(controller->Validate(new FactorialValidate, widgets->Input->text(), static_cast<QPushButton*>(sender())->text(), status));
    }

    void SetDot() {
        int status = 1;
        widgets->Input->setText(controller->Validate(new DotValidate, widgets->Input->text(), static_cast<QPushButton*>(sender())->text(), status));
    }

    void SetX() {
        int status = 1;
        widgets->Input->setText(controller->Validate(new xValidate, widgets->Input->text(), static_cast<QPushButton*>(sender())->text(), status));
    }

    void SetOpenBracket() {
        int status = 1;
        widgets->Input->setText(controller->Validate(new OpenBracketValidate, widgets->Input->text(), static_cast<QPushButton*>(sender())->text(), status));
    }

    void SetCloseBracket() {
        int status = 1;
        widgets->Input->setText(controller->Validate(new CloseBracketValidate, widgets->Input->text(), static_cast<QPushButton*>(sender())->text(), status));
    }

    void Clear() {
        widgets->Input->setText("");
    }

    void GetResult() {
        int status = 1;
        controller->Validate(new ResultValidate, widgets->Input->text(), static_cast<QPushButton*>(sender())->text(), status);
        if (status) {
            widgets->Input->setText(controller->GetResult());
        }
    }

    void DrawGraph() {

    }
};

#endif // CALCULATORUI_H
