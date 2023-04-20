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

    struct ButtonSettings
    {
        QString _buttonText;
        const char* _slot;

        ButtonSettings(QString buttonText, const char* slot)
            : _buttonText(buttonText),
              _slot(slot) {}
    };

    unordered_map<int, ButtonSettings*> dctButtonSettings;
    CalcWidgets *widgets;

    CalculatorUI() {
        SetupPlatform();
        SetupButtons();

        widgets = new CalcWidgets;
        widgets->Input = new QLabel(Window);


        for (int i = CalcButtons::Button0; i <= CalcButtons::ButtonResult; i++) {
            widgets->buttons.insert(make_pair(i, new QPushButton(dctButtonSettings.at(i)->_buttonText, Window)));
            connect(widgets->buttons.at(i), SIGNAL(clicked()), this, dctButtonSettings[i]->_slot);
        }


        _platform->SetupCalculatorUI(widgets, Window);
    }

    void SetupButtons() {
       dctButtonSettings.insert(make_pair(CalcButtons::Button0, new ButtonSettings("0", SLOT(SetNumber()))));
       dctButtonSettings.insert(make_pair(CalcButtons::Button1, new ButtonSettings("1", SLOT(SetNumber()))));
       dctButtonSettings.insert(make_pair(CalcButtons::Button2, new ButtonSettings("2", SLOT(SetNumber()))));
       dctButtonSettings.insert(make_pair(CalcButtons::Button3, new ButtonSettings("3", SLOT(SetNumber()))));
       dctButtonSettings.insert(make_pair(CalcButtons::Button4, new ButtonSettings("4", SLOT(SetNumber()))));
       dctButtonSettings.insert(make_pair(CalcButtons::Button5, new ButtonSettings("5", SLOT(SetNumber()))));
       dctButtonSettings.insert(make_pair(CalcButtons::Button6, new ButtonSettings("6", SLOT(SetNumber()))));
       dctButtonSettings.insert(make_pair(CalcButtons::Button7, new ButtonSettings("7", SLOT(SetNumber()))));
       dctButtonSettings.insert(make_pair(CalcButtons::Button8, new ButtonSettings("8", SLOT(SetNumber()))));
       dctButtonSettings.insert(make_pair(CalcButtons::Button9, new ButtonSettings("9", SLOT(SetNumber()))));

       dctButtonSettings.insert(make_pair(CalcButtons::ButtonSin, new ButtonSettings("sin", SLOT(SetFunction()))));
       dctButtonSettings.insert(make_pair(CalcButtons::ButtonCos, new ButtonSettings("cos", SLOT(SetFunction()))));
       dctButtonSettings.insert(make_pair(CalcButtons::ButtonTan, new ButtonSettings("tan", SLOT(SetFunction()))));
       dctButtonSettings.insert(make_pair(CalcButtons::ButtonAsin, new ButtonSettings("asin", SLOT(SetFunction()))));
       dctButtonSettings.insert(make_pair(CalcButtons::ButtonAcos, new ButtonSettings("acos", SLOT(SetFunction()))));
       dctButtonSettings.insert(make_pair(CalcButtons::ButtonAtan, new ButtonSettings("atan", SLOT(SetFunction()))));
       dctButtonSettings.insert(make_pair(CalcButtons::ButtonLog, new ButtonSettings("log", SLOT(SetFunction()))));
       dctButtonSettings.insert(make_pair(CalcButtons::ButtonSqrt, new ButtonSettings("sqrt", SLOT(SetFunction()))));
       dctButtonSettings.insert(make_pair(CalcButtons::ButtonLn, new ButtonSettings("ln", SLOT(SetFunction()))));

       dctButtonSettings.insert(make_pair(CalcButtons::ButtonSum, new ButtonSettings("+", SLOT(SetOperator()))));
       dctButtonSettings.insert(make_pair(CalcButtons::ButtonSub, new ButtonSettings("-", SLOT(SetOperator()))));
       dctButtonSettings.insert(make_pair(CalcButtons::ButtonMul, new ButtonSettings("*", SLOT(SetOperator()))));
       dctButtonSettings.insert(make_pair(CalcButtons::ButtonDiv, new ButtonSettings("/", SLOT(SetOperator()))));
       dctButtonSettings.insert(make_pair(CalcButtons::ButtonMod, new ButtonSettings("mod", SLOT(SetOperator()))));
       dctButtonSettings.insert(make_pair(CalcButtons::ButtonPow, new ButtonSettings("^", SLOT(SetOperator()))));

       dctButtonSettings.insert(make_pair(CalcButtons::ButtonFactorial, new ButtonSettings("!", SLOT(SetFactorial()))));

       dctButtonSettings.insert(make_pair(CalcButtons::ButtonOpenBracket, new ButtonSettings("(", SLOT(SetOpenBracket()))));
       dctButtonSettings.insert(make_pair(CalcButtons::ButtonCloseBracket, new ButtonSettings(")", SLOT(SetCloseBracket()))));

       dctButtonSettings.insert(make_pair(CalcButtons::ButtonDot, new ButtonSettings(".", SLOT(SetDot()))));
       dctButtonSettings.insert(make_pair(CalcButtons::ButtonX, new ButtonSettings("x", SLOT(SetX()))));
       dctButtonSettings.insert(make_pair(CalcButtons::ButtonAC, new ButtonSettings("AC", SLOT(Clear()))));
       dctButtonSettings.insert(make_pair(CalcButtons::ButtonResult, new ButtonSettings("=", SLOT(GetResult()))));
       dctButtonSettings.insert(make_pair(CalcButtons::ButtonGraph, new ButtonSettings("graph", SLOT(DrawGraph()))));
    }

    void resizeEvent(QResizeEvent *e)
    {
        _platform->SetSize(widgets, Window);
        QWidget::resizeEvent(e);
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
