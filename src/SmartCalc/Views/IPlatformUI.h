#ifndef IPLATFORMUI_H
#define IPLATFORMUI_H

#include <QWidget>
#include <QMainWindow>
#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QWidget>
#include "CalcSlots.h"



class IPlatformUI
{
public:
    QMainWindow *window;

    QTabWidget *MainTab;
    QWidget *Calculator;
    QWidget *CreditCalc;
    QWidget *DepositCalc;

    QLabel *LabelInput;

    QPushButton *Button0;
    QPushButton *Button1;
    QPushButton *Button2;
    QPushButton *Button3;
    QPushButton *Button4;
    QPushButton *Button5;
    QPushButton *Button6;
    QPushButton *Button7;
    QPushButton *Button8;
    QPushButton *Button9;
    QPushButton *ButtonX;


    QPushButton *ButtonGetResult;
    QPushButton *ButtonDrawGraph;

    QPushButton *ButtonSin;
    QPushButton *ButtonCos;
    QPushButton *ButtonTan;
    QPushButton *ButtonAsin;
    QPushButton *ButtonAcos;
    QPushButton *ButtonAtan;
    QPushButton *ButtonLog;
    QPushButton *ButtonLn;
    QPushButton *ButtonSqrt;

    QPushButton *ButtonSum;
    QPushButton *ButtonSub;
    QPushButton *ButtonMul;
    QPushButton *ButtonDiv;
    QPushButton *ButtonMod;
    QPushButton *ButtonPow;
    QPushButton *ButtonFactorial;
    QPushButton *ButtonOpenBracket;
    QPushButton *ButtonCloseBracket;
    QPushButton *ButtonAC;
    QPushButton *ButtonDot;

    QPushButton *SwitchMode;
    CalcSlots *cSlots;
    Graph *graph;

    IPlatformUI() {
        DefaultSettings();
        cSlots = new CalcSlots;
        graph = new Graph;
    }

    void show() {
        window->show();
    }

    void DefaultSettings() {
        window = new QMainWindow;
        window->setFixedSize(1000, 1000);
        window->setObjectName(QString::fromUtf8("window"));
    }

    void RetranslateUI() {
        cSlots->connect(ButtonCloseBracket, SIGNAL(clicked()), cSlots, SLOT(SetCloseBracket()));
        cSlots->connect(ButtonOpenBracket, SIGNAL(clicked()), cSlots, SLOT(SetOpenBracket()));

        cSlots->connect(Button0, SIGNAL(clicked()), cSlots, SLOT(SetNumber()));
        cSlots->connect(Button1, SIGNAL(clicked()), cSlots, SLOT(SetNumber()));
        cSlots->connect(Button2, SIGNAL(clicked()), cSlots, SLOT(SetNumber()));
        cSlots->connect(Button3, SIGNAL(clicked()), cSlots, SLOT(SetNumber()));
        cSlots->connect(Button4, SIGNAL(clicked()), cSlots, SLOT(SetNumber()));
        cSlots->connect(Button5, SIGNAL(clicked()), cSlots, SLOT(SetNumber()));
        cSlots->connect(Button6, SIGNAL(clicked()), cSlots, SLOT(SetNumber()));
        cSlots->connect(Button7, SIGNAL(clicked()), cSlots, SLOT(SetNumber()));
        cSlots->connect(Button8, SIGNAL(clicked()), cSlots, SLOT(SetNumber()));
        cSlots->connect(Button9, SIGNAL(clicked()), cSlots, SLOT(SetNumber()));
        cSlots->connect(ButtonX, SIGNAL(clicked()), cSlots, SLOT(SetX()));

        cSlots->connect(ButtonDot, SIGNAL(clicked()), cSlots, SLOT(SetDot()));

        cSlots->connect(ButtonFactorial, SIGNAL(clicked()), cSlots, SLOT(SetFactorial()));

        cSlots->connect(ButtonSum, SIGNAL(clicked()), cSlots, SLOT(SetOperator()));
        cSlots->connect(ButtonSub, SIGNAL(clicked()), cSlots, SLOT(SetOperator()));
        cSlots->connect(ButtonMul, SIGNAL(clicked()), cSlots, SLOT(SetOperator()));
        cSlots->connect(ButtonDiv, SIGNAL(clicked()), cSlots, SLOT(SetOperator()));
        cSlots->connect(ButtonMod, SIGNAL(clicked()), cSlots, SLOT(SetOperator()));
        cSlots->connect(ButtonPow, SIGNAL(clicked()), cSlots, SLOT(SetOperator()));

        cSlots->connect(ButtonSin, SIGNAL(clicked()), cSlots, SLOT(SetFunction()));
        cSlots->connect(ButtonCos, SIGNAL(clicked()), cSlots, SLOT(SetFunction()));
        cSlots->connect(ButtonTan, SIGNAL(clicked()), cSlots, SLOT(SetFunction()));
        cSlots->connect(ButtonAsin, SIGNAL(clicked()), cSlots, SLOT(SetFunction()));
        cSlots->connect(ButtonAcos, SIGNAL(clicked()), cSlots, SLOT(SetFunction()));
        cSlots->connect(ButtonAtan, SIGNAL(clicked()), cSlots, SLOT(SetFunction()));
        cSlots->connect(ButtonLog, SIGNAL(clicked()), cSlots, SLOT(SetFunction()));
        cSlots->connect(ButtonLn, SIGNAL(clicked()), cSlots, SLOT(SetFunction()));
        cSlots->connect(ButtonSqrt, SIGNAL(clicked()), cSlots, SLOT(SetFunction()));

        cSlots->connect(ButtonAC, SIGNAL(clicked()), cSlots, SLOT(ClearAll()));

        cSlots->connect(ButtonGetResult, SIGNAL(clicked()), cSlots, SLOT(Equal()));
        cSlots->connect(ButtonDrawGraph, SIGNAL(clicked()), cSlots, SLOT(DrawGraph()));

        cSlots->connect(SwitchMode, SIGNAL(clicked()), cSlots, SLOT(SwitchToWin()));
        cSlots->connect(ButtonDrawGraph, SIGNAL(clicked()), graph, SLOT(Show()));


        ButtonGetResult->setText(QCoreApplication::translate("MainWindow", "=", nullptr));
        ButtonDrawGraph->setText(QCoreApplication::translate("MainWindow", "Graph", nullptr));
        ButtonCos->setText(QCoreApplication::translate("MainWindow", "cos", nullptr));
        ButtonLog->setText(QCoreApplication::translate("MainWindow", "log", nullptr));
        ButtonTan->setText(QCoreApplication::translate("MainWindow", "tan", nullptr));
        Button5->setText(QCoreApplication::translate("MainWindow", "5", nullptr));
        ButtonAcos->setText(QCoreApplication::translate("MainWindow", "acos", nullptr));
        Button3->setText(QCoreApplication::translate("MainWindow", "3", nullptr));
        Button8->setText(QCoreApplication::translate("MainWindow", "8", nullptr));
        Button0->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        ButtonPow->setText(QCoreApplication::translate("MainWindow", "^", nullptr));
        ButtonFactorial->setText(QCoreApplication::translate("MainWindow", "!", nullptr));
        ButtonAsin->setText(QCoreApplication::translate("MainWindow", "asin", nullptr));
        ButtonSub->setText(QCoreApplication::translate("MainWindow", "-", nullptr));
        ButtonLn->setText(QCoreApplication::translate("MainWindow", "ln", nullptr));
        ButtonAC->setText(QCoreApplication::translate("MainWindow", "AC", nullptr));
        ButtonCloseBracket->setText(QCoreApplication::translate("MainWindow", ")", nullptr));
        ButtonMul->setText(QCoreApplication::translate("MainWindow", "*", nullptr));
        ButtonSin->setText(QCoreApplication::translate("MainWindow", "sin", nullptr));
        ButtonX->setText(QCoreApplication::translate("MainWindow", "x", nullptr));
        Button2->setText(QCoreApplication::translate("MainWindow", "2", nullptr));
        Button9->setText(QCoreApplication::translate("MainWindow", "9", nullptr));
        Button4->setText(QCoreApplication::translate("MainWindow", "4", nullptr));
        ButtonAtan->setText(QCoreApplication::translate("MainWindow", "atan", nullptr));
        ButtonSqrt->setText(QCoreApplication::translate("MainWindow", "sqrt", nullptr));
        Button7->setText(QCoreApplication::translate("MainWindow", "7", nullptr));
        ButtonSum->setText(QCoreApplication::translate("MainWindow", "+", nullptr));
        Button6->setText(QCoreApplication::translate("MainWindow", "6", nullptr));
        ButtonDot->setText(QCoreApplication::translate("MainWindow", ".", nullptr));
        Button1->setText(QCoreApplication::translate("MainWindow", "1", nullptr));
        ButtonOpenBracket->setText(QCoreApplication::translate("MainWindow", "(", nullptr));
        ButtonMod->setText(QCoreApplication::translate("MainWindow", "mod", nullptr));
        ButtonDiv->setText(QCoreApplication::translate("MainWindow", "/", nullptr));
        LabelInput->setText(QString());
        SwitchMode->setText(QCoreApplication::translate("MainWindow", "Mac", nullptr));
        MainTab->setTabText(MainTab->indexOf(Calculator), QCoreApplication::translate("MainWindow", "Calculator", nullptr));
        MainTab->setTabText(MainTab->indexOf(CreditCalc), QCoreApplication::translate("MainWindow", "Credit Calculator", nullptr));
        MainTab->setTabText(MainTab->indexOf(DepositCalc), QCoreApplication::translate("MainWindow", "Deposit Calculator", nullptr));
    }
};


#endif // IPLATFORMUI_H
