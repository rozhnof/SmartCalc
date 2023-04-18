#ifndef CALCWIDGETS_H
#define CALCWIDGETS_H

#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include <QDoubleSpinBox>

#include <QApplication>
#include <QLineEdit>
#include <unordered_map>
#include <iostream>


using namespace std;

class IWidgets {
public:

};

class PushButton
{
    Q_OBJECT

public:
    QPushButton *newButton;


    QPushButton *NewPushButton(QWidget *parent, string buttonText) {
        newButton = new QPushButton(parent);
        newButton->setText(QString::fromStdString(buttonText));

        return newButton;
    }
};

class CalcWidgets : public IWidgets {
public:

    QLabel *LabelInput;
    QDoubleSpinBox *InputX;
    QLineEdit *XDef;

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

        ButtonGetResult,
        ButtonDrawGraph,

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
        ButtonDot
    };

    unordered_map<int, QPushButton*> buttonsMap;
    PushButton *buttons;

    CalcWidgets(QWidget *parent) {

        buttons = new PushButton;

        LabelInput = new QLabel;
        InputX = new QDoubleSpinBox;
        XDef = new QLineEdit;

        buttonsMap.insert(make_pair(Button0 , buttons->NewPushButton(parent, "01" )));
        buttonsMap[Button0]->setGeometry(10, 10, 100, 100);


//        cSlots->connect(buttonsMap[Button0], SIGNAL(clicked()), cSlots, SLOT(SetNumber()));

//        cSlots->connect(ButtonFactorial, SIGNAL(clicked()), cSlots, SLOT(SetFactorial()));

//        cSlots->connect(ButtonSum, SIGNAL(clicked()), cSlots, SLOT(SetOperator()));
//        cSlots->connect(ButtonSub, SIGNAL(clicked()), cSlots, SLOT(SetOperator()));
//        cSlots->connect(ButtonMul, SIGNAL(clicked()), cSlots, SLOT(SetOperator()));
//        cSlots->connect(ButtonDiv, SIGNAL(clicked()), cSlots, SLOT(SetOperator()));
//        cSlots->connect(ButtonMod, SIGNAL(clicked()), cSlots, SLOT(SetOperator()));
//        cSlots->connect(ButtonPow, SIGNAL(clicked()), cSlots, SLOT(SetOperator()));

//        cSlots->connect(ButtonSin, SIGNAL(clicked()), cSlots, SLOT(SetFunction()));
//        cSlots->connect(ButtonCos, SIGNAL(clicked()), cSlots, SLOT(SetFunction()));
//        cSlots->connect(ButtonTan, SIGNAL(clicked()), cSlots, SLOT(SetFunction()));
//        cSlots->connect(ButtonAsin, SIGNAL(clicked()), cSlots, SLOT(SetFunction()));
//        cSlots->connect(ButtonAcos, SIGNAL(clicked()), cSlots, SLOT(SetFunction()));
//        cSlots->connect(ButtonAtan, SIGNAL(clicked()), cSlots, SLOT(SetFunction()));
//        cSlots->connect(ButtonLog, SIGNAL(clicked()), cSlots, SLOT(SetFunction()));
//        cSlots->connect(ButtonLn, SIGNAL(clicked()), cSlots, SLOT(SetFunction()));
//        cSlots->connect(ButtonSqrt, SIGNAL(clicked()), cSlots, SLOT(SetFunction()));

//        cSlots->connect(ButtonAC, SIGNAL(clicked()), cSlots, SLOT(ClearAll()));

//        cSlots->connect(ButtonGetResult, SIGNAL(clicked()), cSlots, SLOT(Equal()));
//        cSlots->connect(ButtonDrawGraph, SIGNAL(clicked()), cSlots, SLOT(DrawGraph()));



//        buttonsMap[ButtonGetResult]->setText(QCoreApplication::translate("MainWindow", "=", nullptr));
//        buttonsMap[ButtonDrawGraph]->setText(QCoreApplication::translate("MainWindow", "Graph", nullptr));
//        buttonsMap[ButtonCos]->setText(QCoreApplication::translate("MainWindow", "cos", nullptr));
//        buttonsMap[ButtonLog]->setText(QCoreApplication::translate("MainWindow", "log", nullptr));
//        buttonsMap[ButtonTan]->setText(QCoreApplication::translate("MainWindow", "tan", nullptr));
//        buttonsMap[Button5]->setText(QCoreApplication::translate("MainWindow", "5", nullptr));

//        ButtonAcos->setText(QCoreApplication::translate("MainWindow", "acos", nullptr));
//        Button3->setText(QCoreApplication::translate("MainWindow", "3", nullptr));
//        Button8->setText(QCoreApplication::translate("MainWindow", "8", nullptr));
//
//        ButtonPow->setText(QCoreApplication::translate("MainWindow", "^", nullptr));
//        ButtonFactorial->setText(QCoreApplication::translate("MainWindow", "!", nullptr));
//        ButtonAsin->setText(QCoreApplication::translate("MainWindow", "asin", nullptr));
//        ButtonSub->setText(QCoreApplication::translate("MainWindow", "-", nullptr));
//        ButtonLn->setText(QCoreApplication::translate("MainWindow", "ln", nullptr));
//        ButtonAC->setText(QCoreApplication::translate("MainWindow", "AC", nullptr));
//        ButtonCloseBracket->setText(QCoreApplication::translate("MainWindow", ")", nullptr));
//        ButtonMul->setText(QCoreApplication::translate("MainWindow", "*", nullptr));
//        ButtonSin->setText(QCoreApplication::translate("MainWindow", "sin", nullptr));
//        ButtonX->setText(QCoreApplication::translate("MainWindow", "x", nullptr));
//        Button2->setText(QCoreApplication::translate("MainWindow", "2", nullptr));
//        Button9->setText(QCoreApplication::translate("MainWindow", "9", nullptr));
//        Button4->setText(QCoreApplication::translate("MainWindow", "4", nullptr));
//        ButtonAtan->setText(QCoreApplication::translate("MainWindow", "atan", nullptr));
//        ButtonSqrt->setText(QCoreApplication::translate("MainWindow", "sqrt", nullptr));
//        Button7->setText(QCoreApplication::translate("MainWindow", "7", nullptr));
//        ButtonSum->setText(QCoreApplication::translate("MainWindow", "+", nullptr));
//        Button6->setText(QCoreApplication::translate("MainWindow", "6", nullptr));
//        ButtonDot->setText(QCoreApplication::translate("MainWindow", ".", nullptr));
//        Button1->setText(QCoreApplication::translate("MainWindow", "1", nullptr));
//        ButtonOpenBracket->setText(QCoreApplication::translate("MainWindow", "(", nullptr));
//        ButtonMod->setText(QCoreApplication::translate("MainWindow", "mod", nullptr));
//        ButtonDiv->setText(QCoreApplication::translate("MainWindow", "/", nullptr));
//        LabelInput->setText(QString());






//        CreditCalcOpen = new QPushButton(parent);
//        CreditCalcOpen->setText(QCoreApplication::translate("MainWindow", "Credit calc open", nullptr));
//        CreditCalcOpen->setGeometry(QRect(10, 10, 100, 60));
//        cSlots->connect(CreditCalcOpen, SIGNAL(clicked()), parent, SLOT(OpenCreditCalc()));



    }

};

#endif // CALCWIDGETS_H
