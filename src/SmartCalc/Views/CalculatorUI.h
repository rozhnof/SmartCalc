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

    ButtonGetResult,

    ButtonDrawGraph
};


class CalculatorUI : public MainWindow
{
public:
    unordered_map<int, QString> buttonText;
    unordered_map<int, QPushButton*> buttonNames;



    CalculatorUI(IPlatformUI *platform) {
        SetupPlatform(platform);

        for (int i = Button0; i <= Button9; i++) {
            buttonNames.insert(make_pair(i, new QPushButton(QString::number(i), Window)));
            connect(buttonNames[i], SIGNAL(clicked()), this, SLOT(SetNumber()));
        }

        buttonNames.insert(make_pair(ButtonSin, new QPushButton("Sin", Window)));
        connect(buttonNames[ButtonSin], SIGNAL(clicked()), this, SLOT(SetNumber()));


        _platform->SetupCalculatorUI();
    }

    void setupButtons() {
        buttonText.insert(make_pair(Button0, "0"));
        buttonText.insert(make_pair(Button1, "1"));
        buttonText.insert(make_pair(Button2, "2"));
        buttonText.insert(make_pair(Button3, "3"));
        buttonText.insert(make_pair(Button4, "4"));
        buttonText.insert(make_pair(Button5, "5"));
        buttonText.insert(make_pair(Button6, "6"));
        buttonText.insert(make_pair(Button7, "7"));
        buttonText.insert(make_pair(Button8, "8"));
        buttonText.insert(make_pair(Button9, "9"));

        buttonText.insert(make_pair(ButtonSin, "0"));
        buttonText.insert(make_pair(ButtonCos, "0"));
        buttonText.insert(make_pair(ButtonTan, "0"));
        buttonText.insert(make_pair(ButtonAsin, "0"));
        buttonText.insert(make_pair(ButtonAcos, "0"));
        buttonText.insert(make_pair(ButtonAtan, "0"));

        buttonText.insert(make_pair(ButtonSum, "0"));
        buttonText.insert(make_pair(ButtonSub, "0"));
        buttonText.insert(make_pair(ButtonMul, "0"));
        buttonText.insert(make_pair(ButtonDiv, "0"));

    }
};

#endif // CALCULATORUI_H
