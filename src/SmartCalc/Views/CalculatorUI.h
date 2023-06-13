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
#include "../Controllers/CalculatorController.h"




class CalculatorUI : public MainWindow
{
    Q_OBJECT

public:
    CalculatorController *controller;
    CalcWidgets *widgets;

    CalculatorUI() : MainWindow() {
        this->setWindowTitle("Calculator");

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
       widgets->Input = NewLabel(this, "0", "input");
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
       widgets->calcButtons.insert(make_pair(ButtonUnaryOperator, NewPushButton(this, "+/-", "unaryOperator")));

       widgets->calcButtons.insert(make_pair(ButtonC, NewPushButton(this, "C", "clear")));
       widgets->calcButtons.insert(make_pair(ButtonAC, NewPushButton(this, "AC", "clear")));
       widgets->calcButtons.insert(make_pair(ButtonResult, NewPushButton(this, "=", "equal")));
    }

    void Connects() {
        connect(widgets->calcButtons[Button0], &QPushButton::clicked, this, &CalculatorUI::SetNumber);
        connect(widgets->calcButtons[Button1], &QPushButton::clicked, this, &CalculatorUI::SetNumber);
        connect(widgets->calcButtons[Button2], &QPushButton::clicked, this, &CalculatorUI::SetNumber);
        connect(widgets->calcButtons[Button3], &QPushButton::clicked, this, &CalculatorUI::SetNumber);
        connect(widgets->calcButtons[Button4], &QPushButton::clicked, this, &CalculatorUI::SetNumber);
        connect(widgets->calcButtons[Button5], &QPushButton::clicked, this, &CalculatorUI::SetNumber);
        connect(widgets->calcButtons[Button6], &QPushButton::clicked, this, &CalculatorUI::SetNumber);
        connect(widgets->calcButtons[Button7], &QPushButton::clicked, this, &CalculatorUI::SetNumber);
        connect(widgets->calcButtons[Button8], &QPushButton::clicked, this, &CalculatorUI::SetNumber);
        connect(widgets->calcButtons[Button9], &QPushButton::clicked, this, &CalculatorUI::SetNumber);

        connect(widgets->calcButtons[ButtonSin], &QPushButton::clicked, this, &CalculatorUI::SetFunction);
        connect(widgets->calcButtons[ButtonCos], &QPushButton::clicked, this, &CalculatorUI::SetFunction);
        connect(widgets->calcButtons[ButtonTan], &QPushButton::clicked, this, &CalculatorUI::SetFunction);
        connect(widgets->calcButtons[ButtonAsin], &QPushButton::clicked, this, &CalculatorUI::SetFunction);
        connect(widgets->calcButtons[ButtonAcos], &QPushButton::clicked, this, &CalculatorUI::SetFunction);
        connect(widgets->calcButtons[ButtonAtan], &QPushButton::clicked, this, &CalculatorUI::SetFunction);
        connect(widgets->calcButtons[ButtonLog], &QPushButton::clicked, this, &CalculatorUI::SetFunction);
        connect(widgets->calcButtons[ButtonSqrt], &QPushButton::clicked, this, &CalculatorUI::SetFunction);
        connect(widgets->calcButtons[ButtonLn], &QPushButton::clicked, this, &CalculatorUI::SetFunction);

        connect(widgets->calcButtons[ButtonSum], &QPushButton::clicked, this, &CalculatorUI::SetOperator);
        connect(widgets->calcButtons[ButtonSub], &QPushButton::clicked, this, &CalculatorUI::SetOperator);
        connect(widgets->calcButtons[ButtonMul], &QPushButton::clicked, this, &CalculatorUI::SetOperator);
        connect(widgets->calcButtons[ButtonDiv], &QPushButton::clicked, this, &CalculatorUI::SetOperator);
        connect(widgets->calcButtons[ButtonMod], &QPushButton::clicked, this, &CalculatorUI::SetOperator);
        connect(widgets->calcButtons[ButtonPow], &QPushButton::clicked, this, &CalculatorUI::SetOperator);

        connect(widgets->calcButtons[ButtonX], &QPushButton::clicked, this, &CalculatorUI::SetX);
        connect(widgets->calcButtons[ButtonDot], &QPushButton::clicked, this, &CalculatorUI::SetDot);
        connect(widgets->calcButtons[ButtonEXP], &QPushButton::clicked, this, &CalculatorUI::SetExp);

        connect(widgets->calcButtons[ButtonFactorial], &QPushButton::clicked, this, &CalculatorUI::SetFactorial);
        connect(widgets->calcButtons[ButtonOpenBracket], &QPushButton::clicked, this, &CalculatorUI::SetOpenBracket);
        connect(widgets->calcButtons[ButtonCloseBracket], &QPushButton::clicked, this, &CalculatorUI::SetCloseBracket);
        connect(widgets->calcButtons[ButtonUnaryOperator], &QPushButton::clicked, this, &CalculatorUI::SetUnaryOperator);

        connect(widgets->calcButtons[ButtonC], &QPushButton::clicked, this, &CalculatorUI::Clear);
        connect(widgets->calcButtons[ButtonAC], &QPushButton::clicked, this, &CalculatorUI::ClearAll);
        connect(widgets->calcButtons[ButtonResult], &QPushButton::clicked, this, &CalculatorUI::Result);
    }

    void ResetSettings() {
        widgets->Input->setGeometry(0, 0, 0, 0);
        for (int i = Button0; i <= ButtonResult; i++) {
            widgets->calcButtons.at(i)->setGeometry(0, 0, 0, 0);
        }
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

    void SetUnaryOperator() {
        int status = 1;
        widgets->Input->setText(controller->Validate(new UnaryOperatorValidate, widgets->Input->text(), static_cast<QPushButton*>(sender())->text(), status));
    }

    void SetExp() {
        int status = 1;
        widgets->Input->setText(controller->Validate(new CloseBracketValidate, widgets->Input->text(), static_cast<QPushButton*>(sender())->text(), status));
    }

    void Clear() {
        widgets->Input->setText("");
    }

    void ClearAll() {
        widgets->Input->setText("");
    }

    void Result() {
        int status = controller->ResultValidate(widgets->Input->text());

        if (status) cout << "OK" << endl;
        else cout << "ERROR" << endl;
    }

    void DrawGraph() {

    }
};

#endif // CALCULATORUI_H
