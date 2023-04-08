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




class IPlatformUI
{
public:
    QMainWindow *window;

    QTabWidget *MainTab;
    QWidget *Calculator;
    QWidget *CreditCalc;
    QWidget *DepositCalc;

    QLabel *LabelInput;
    QDoubleSpinBox *InputX;
    QLineEdit *XDef;

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

    QLineEdit *FunctionScope;
    QDoubleSpinBox *ScopeMin;
    QDoubleSpinBox *RangeMin;

    QLineEdit *FunctionRange;
    QDoubleSpinBox *ScopeMax;
    QDoubleSpinBox *RangeMax;

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

    IPlatformUI() {
        DefaultSettings();
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
        MainTab->setTabText(MainTab->indexOf(Calculator), QCoreApplication::translate("MainWindow", "Calculator", nullptr));
        MainTab->setTabText(MainTab->indexOf(CreditCalc), QCoreApplication::translate("MainWindow", "Credit Calculator", nullptr));
        MainTab->setTabText(MainTab->indexOf(DepositCalc), QCoreApplication::translate("MainWindow", "Deposit Calculator", nullptr));
    }
};


#endif // IPLATFORMUI_H
