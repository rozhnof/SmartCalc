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

    unordered_map<int, QWidget*> calcObjects;
    unordered_map<int, ButtonSettings*> buttonSetup;

    CalculatorUI() {
        SetupPlatform();
        SetupButtons();

        calcObjects.insert(make_pair(CalcObjectsEnum::MainWindow, Window));
        calcObjects.insert(make_pair(CalcObjectsEnum::LabelInput, new QLabel(calcObjects.at(CalcObjectsEnum::MainWindow))));

        for (int i = CalcObjectsEnum::Button0; i <= CalcObjectsEnum::ButtonResult; i++) {
            calcObjects.insert(make_pair(i, new QPushButton(buttonSetup.at(i)->_buttonText, Window)));
            connect(calcObjects.at(i), SIGNAL(clicked()), this, buttonSetup[i]->_slot);
        }



        _platform->SetupCalculatorUI(calcObjects);
    }

    void SetupButtons() {
       buttonSetup.insert(make_pair(CalcObjectsEnum::Button0, new ButtonSettings("0", SLOT(SetNumber()))));
       buttonSetup.insert(make_pair(CalcObjectsEnum::Button1, new ButtonSettings("1", SLOT(SetNumber()))));
       buttonSetup.insert(make_pair(CalcObjectsEnum::Button2, new ButtonSettings("2", SLOT(SetNumber()))));
       buttonSetup.insert(make_pair(CalcObjectsEnum::Button3, new ButtonSettings("3", SLOT(SetNumber()))));
       buttonSetup.insert(make_pair(CalcObjectsEnum::Button4, new ButtonSettings("4", SLOT(SetNumber()))));
       buttonSetup.insert(make_pair(CalcObjectsEnum::Button5, new ButtonSettings("5", SLOT(SetNumber()))));
       buttonSetup.insert(make_pair(CalcObjectsEnum::Button6, new ButtonSettings("6", SLOT(SetNumber()))));
       buttonSetup.insert(make_pair(CalcObjectsEnum::Button7, new ButtonSettings("7", SLOT(SetNumber()))));
       buttonSetup.insert(make_pair(CalcObjectsEnum::Button8, new ButtonSettings("8", SLOT(SetNumber()))));
       buttonSetup.insert(make_pair(CalcObjectsEnum::Button9, new ButtonSettings("9", SLOT(SetNumber()))));

       buttonSetup.insert(make_pair(CalcObjectsEnum::ButtonSin, new ButtonSettings("sin", SLOT(SetFunction()))));
       buttonSetup.insert(make_pair(CalcObjectsEnum::ButtonCos, new ButtonSettings("cos", SLOT(SetFunction()))));
       buttonSetup.insert(make_pair(CalcObjectsEnum::ButtonTan, new ButtonSettings("tan", SLOT(SetFunction()))));
       buttonSetup.insert(make_pair(CalcObjectsEnum::ButtonAsin, new ButtonSettings("asin", SLOT(SetFunction()))));
       buttonSetup.insert(make_pair(CalcObjectsEnum::ButtonAcos, new ButtonSettings("acos", SLOT(SetFunction()))));
       buttonSetup.insert(make_pair(CalcObjectsEnum::ButtonAtan, new ButtonSettings("atan", SLOT(SetFunction()))));
       buttonSetup.insert(make_pair(CalcObjectsEnum::ButtonLog, new ButtonSettings("log", SLOT(SetFunction()))));
       buttonSetup.insert(make_pair(CalcObjectsEnum::ButtonSqrt, new ButtonSettings("sqrt", SLOT(SetFunction()))));
       buttonSetup.insert(make_pair(CalcObjectsEnum::ButtonLn, new ButtonSettings("ln", SLOT(SetFunction()))));

       buttonSetup.insert(make_pair(CalcObjectsEnum::ButtonSum, new ButtonSettings("+", SLOT(SetOperator()))));
       buttonSetup.insert(make_pair(CalcObjectsEnum::ButtonSub, new ButtonSettings("-", SLOT(SetOperator()))));
       buttonSetup.insert(make_pair(CalcObjectsEnum::ButtonMul, new ButtonSettings("*", SLOT(SetOperator()))));
       buttonSetup.insert(make_pair(CalcObjectsEnum::ButtonDiv, new ButtonSettings("/", SLOT(SetOperator()))));
       buttonSetup.insert(make_pair(CalcObjectsEnum::ButtonMod, new ButtonSettings("mod", SLOT(SetOperator()))));
       buttonSetup.insert(make_pair(CalcObjectsEnum::ButtonPow, new ButtonSettings("^", SLOT(SetOperator()))));

       buttonSetup.insert(make_pair(CalcObjectsEnum::ButtonFactorial, new ButtonSettings("!", SLOT(SetFactorial()))));

       buttonSetup.insert(make_pair(CalcObjectsEnum::ButtonOpenBracket, new ButtonSettings("(", SLOT(SetOpenBracket()))));
       buttonSetup.insert(make_pair(CalcObjectsEnum::ButtonCloseBracket, new ButtonSettings(")", SLOT(SetCloseBracket()))));

       buttonSetup.insert(make_pair(CalcObjectsEnum::ButtonDot, new ButtonSettings(".", SLOT(SetDot()))));
       buttonSetup.insert(make_pair(CalcObjectsEnum::ButtonX, new ButtonSettings("x", SLOT(SetX()))));
       buttonSetup.insert(make_pair(CalcObjectsEnum::ButtonAC, new ButtonSettings("AC", SLOT(Clear()))));
       buttonSetup.insert(make_pair(CalcObjectsEnum::ButtonResult, new ButtonSettings("=", SLOT(GetResult()))));
       buttonSetup.insert(make_pair(CalcObjectsEnum::ButtonGraph, new ButtonSettings("graph", SLOT(DrawGraph()))));
    }

    void resizeEvent(QResizeEvent *e)
    {
        _platform->SetSize(calcObjects);
        QWidget::resizeEvent(e);
    }



private slots:

    void SetNumber() {
        int status = 1;
        static_cast<QLabel*>(calcObjects.at(CalcObjectsEnum::LabelInput))->setText(controller->Validate(new NumberValidate, static_cast<QLabel*>(calcObjects.at(CalcObjectsEnum::LabelInput))->text(), static_cast<QPushButton*>(sender())->text(), status));
    }

    void SetFunction() {
        int status = 1;
        static_cast<QLabel*>(calcObjects.at(CalcObjectsEnum::LabelInput))->setText(controller->Validate(new FunctionValidate, static_cast<QLabel*>(calcObjects.at(CalcObjectsEnum::LabelInput))->text(), static_cast<QPushButton*>(sender())->text(), status));
    }

    void SetOperator() {
        int status = 1;
        static_cast<QLabel*>(calcObjects.at(CalcObjectsEnum::LabelInput))->setText(controller->Validate(new OperatorValidate, static_cast<QLabel*>(calcObjects.at(CalcObjectsEnum::LabelInput))->text(), static_cast<QPushButton*>(sender())->text(), status));
    }

    void SetFactorial() {
        int status = 1;
        static_cast<QLabel*>(calcObjects.at(CalcObjectsEnum::LabelInput))->setText(controller->Validate(new FactorialValidate, static_cast<QLabel*>(calcObjects.at(CalcObjectsEnum::LabelInput))->text(), static_cast<QPushButton*>(sender())->text(), status));
    }

    void SetDot() {
        int status = 1;
        static_cast<QLabel*>(calcObjects.at(CalcObjectsEnum::LabelInput))->setText(controller->Validate(new DotValidate, static_cast<QLabel*>(calcObjects.at(CalcObjectsEnum::LabelInput))->text(), static_cast<QPushButton*>(sender())->text(), status));
    }

    void SetX() {
        int status = 1;
        static_cast<QLabel*>(calcObjects.at(CalcObjectsEnum::LabelInput))->setText(controller->Validate(new xValidate, static_cast<QLabel*>(calcObjects.at(CalcObjectsEnum::LabelInput))->text(), static_cast<QPushButton*>(sender())->text(), status));
    }

    void SetOpenBracket() {
        int status = 1;
        static_cast<QLabel*>(calcObjects.at(CalcObjectsEnum::LabelInput))->setText(controller->Validate(new OpenBracketValidate, static_cast<QLabel*>(calcObjects.at(CalcObjectsEnum::LabelInput))->text(), static_cast<QPushButton*>(sender())->text(), status));
    }

    void SetCloseBracket() {
        int status = 1;
        static_cast<QLabel*>(calcObjects.at(CalcObjectsEnum::LabelInput))->setText(controller->Validate(new CloseBracketValidate, static_cast<QLabel*>(calcObjects.at(CalcObjectsEnum::LabelInput))->text(), static_cast<QPushButton*>(sender())->text(), status));
    }

    void Clear() {
        static_cast<QLabel*>(calcObjects.at(CalcObjectsEnum::LabelInput))->setText("");
    }

    void GetResult() {
        int status = 1;
        controller->Validate(new ResultValidate, static_cast<QLabel*>(calcObjects.at(CalcObjectsEnum::LabelInput))->text(), static_cast<QPushButton*>(sender())->text(), status);
        if (status) {
            static_cast<QLabel*>(calcObjects.at(CalcObjectsEnum::LabelInput))->setText(controller->GetResult());
        }
    }

    void DrawGraph() {

    }
};

#endif // CALCULATORUI_H
