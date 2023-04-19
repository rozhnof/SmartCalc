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


struct CalculatorWidgets
{
    unordered_map<int, QPushButton*> buttons;
    QLabel *Input;
} CalculatorWidgets;


class CalculatorUI : public MainWindow
{
    Q_OBJECT

public:

    enum ButtonNames {
        Button0,
        Button1,
        Button2,
        Button3,
        Button4,
        Button5,
        Button6,
        Button7,
        Button8,
        Button9,
        ButtonX,
        ButtonDot,

        ButtonSin,
        ButtonCos,
        ButtonTan,
        ButtonAsin,
        ButtonAcos,
        ButtonAtan,
        ButtonLog,
        ButtonLn,
        ButtonSqrt,

        ButtonSum,
        ButtonSub,
        ButtonMul,
        ButtonDiv,
        ButtonMod,
        ButtonPow,
        ButtonFactorial,

        ButtonOpenBracket,
        ButtonCloseBracket,

        ButtonAC,
        ButtonGraph,
        ButtonResult
    };

    struct ButtonSettings
    {
        QString _buttonText;
        const char* _slot;

        ButtonSettings(QString buttonText, const char* slot)
            : _buttonText(buttonText),
              _slot(slot) {}
    };



    unordered_map<int, ButtonSettings*> buttonSettings;


    CalculatorUI() {
        SetupPlatform();
        SetupButtons();

        Input = new QLabel("0", Window);
        Input->setGeometry(0, 300, 400, 60);
        Input->setAlignment(Qt::AlignCenter | Qt::AlignRight);
        Input->setStyleSheet("background-color: black");

        for (int i = Button0; i <= ButtonResult; i++) {
            buttons.insert(make_pair(i, new QPushButton(buttonSettings.at(i)->_buttonText, Window)));
            buttons.at(i)->setGeometry(i/5*60, i%5*60, 60, 60);
            connect(buttons.at(i), SIGNAL(clicked()), this, buttonSettings[i]->_slot);
        }

        _platform->SetupCalculatorUI();
    }

    void SetupButtons() {
       buttonSettings.insert(make_pair(Button0, new ButtonSettings("0", SLOT(SetNumber()))));
       buttonSettings.insert(make_pair(Button1, new ButtonSettings("1", SLOT(SetNumber()))));
       buttonSettings.insert(make_pair(Button2, new ButtonSettings("2", SLOT(SetNumber()))));
       buttonSettings.insert(make_pair(Button3, new ButtonSettings("3", SLOT(SetNumber()))));
       buttonSettings.insert(make_pair(Button4, new ButtonSettings("4", SLOT(SetNumber()))));
       buttonSettings.insert(make_pair(Button5, new ButtonSettings("5", SLOT(SetNumber()))));
       buttonSettings.insert(make_pair(Button6, new ButtonSettings("6", SLOT(SetNumber()))));
       buttonSettings.insert(make_pair(Button7, new ButtonSettings("7", SLOT(SetNumber()))));
       buttonSettings.insert(make_pair(Button8, new ButtonSettings("8", SLOT(SetNumber()))));
       buttonSettings.insert(make_pair(Button9, new ButtonSettings("9", SLOT(SetNumber()))));

       buttonSettings.insert(make_pair(ButtonSin, new ButtonSettings("sin", SLOT(SetFunction()))));
       buttonSettings.insert(make_pair(ButtonCos, new ButtonSettings("cos", SLOT(SetFunction()))));
       buttonSettings.insert(make_pair(ButtonTan, new ButtonSettings("tan", SLOT(SetFunction()))));
       buttonSettings.insert(make_pair(ButtonAsin, new ButtonSettings("asin", SLOT(SetFunction()))));
       buttonSettings.insert(make_pair(ButtonAcos, new ButtonSettings("acos", SLOT(SetFunction()))));
       buttonSettings.insert(make_pair(ButtonAtan, new ButtonSettings("atan", SLOT(SetFunction()))));
       buttonSettings.insert(make_pair(ButtonLog, new ButtonSettings("log", SLOT(SetFunction()))));
       buttonSettings.insert(make_pair(ButtonSqrt, new ButtonSettings("sqrt", SLOT(SetFunction()))));
       buttonSettings.insert(make_pair(ButtonLn, new ButtonSettings("ln", SLOT(SetFunction()))));

       buttonSettings.insert(make_pair(ButtonSum, new ButtonSettings("+", SLOT(SetOperator()))));
       buttonSettings.insert(make_pair(ButtonSub, new ButtonSettings("-", SLOT(SetOperator()))));
       buttonSettings.insert(make_pair(ButtonMul, new ButtonSettings("*", SLOT(SetOperator()))));
       buttonSettings.insert(make_pair(ButtonDiv, new ButtonSettings("/", SLOT(SetOperator()))));
       buttonSettings.insert(make_pair(ButtonMod, new ButtonSettings("mod", SLOT(SetOperator()))));
       buttonSettings.insert(make_pair(ButtonPow, new ButtonSettings("^", SLOT(SetOperator()))));

       buttonSettings.insert(make_pair(ButtonFactorial, new ButtonSettings("!", SLOT(SetFactorial()))));

       buttonSettings.insert(make_pair(ButtonOpenBracket, new ButtonSettings("(", SLOT(SetOpenBracket()))));
       buttonSettings.insert(make_pair(ButtonCloseBracket, new ButtonSettings(")", SLOT(SetCloseBracket()))));

       buttonSettings.insert(make_pair(ButtonDot, new ButtonSettings(".", SLOT(SetDot()))));
       buttonSettings.insert(make_pair(ButtonX, new ButtonSettings("x", SLOT(SetX()))));
       buttonSettings.insert(make_pair(ButtonAC, new ButtonSettings("AC", SLOT(Clear()))));
       buttonSettings.insert(make_pair(ButtonResult, new ButtonSettings("=", SLOT(GetResult()))));
       buttonSettings.insert(make_pair(ButtonGraph, new ButtonSettings("graph", SLOT(DrawGraph()))));
    }

public slots:
    void SetNumber() {
        int status = 1;
        Input->setText(controller->Validate(new NumberValidate, Input->text(), static_cast<QPushButton*>(sender())->text(), status));
    }

    void SetFunction() {
        int status = 1;
        Input->setText(controller->Validate(new FunctionValidate, Input->text(), static_cast<QPushButton*>(sender())->text(), status));
    }

    void SetOperator() {
        int status = 1;
        Input->setText(controller->Validate(new OperatorValidate, Input->text(), static_cast<QPushButton*>(sender())->text(), status));
    }

    void SetFactorial() {
        int status = 1;
        Input->setText(controller->Validate(new FactorialValidate, Input->text(), static_cast<QPushButton*>(sender())->text(), status));
    }

    void SetDot() {
        int status = 1;
        Input->setText(controller->Validate(new DotValidate, Input->text(), static_cast<QPushButton*>(sender())->text(), status));
    }

    void SetX() {
        int status = 1;
        Input->setText(controller->Validate(new xValidate, Input->text(), static_cast<QPushButton*>(sender())->text(), status));
    }

    void SetOpenBracket() {
        int status = 1;
        Input->setText(controller->Validate(new OpenBracketValidate, Input->text(), static_cast<QPushButton*>(sender())->text(), status));
    }

    void SetCloseBracket() {
        int status = 1;
        Input->setText(controller->Validate(new CloseBracketValidate, Input->text(), static_cast<QPushButton*>(sender())->text(), status));
    }

    void Clear() {
        Input->setText("");
    }

    void GetResult() {
        int status = 1;
        controller->Validate(new ResultValidate, Input->text(), static_cast<QPushButton*>(sender())->text(), status);
        if (status) {
            Input->setText(controller->GetResult());
        }
    }

    void DrawGraph() {

    }
};

#endif // CALCULATORUI_H
