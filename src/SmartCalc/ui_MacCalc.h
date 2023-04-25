/********************************************************************************
** Form generated from reading UI file 'MacCalc.ui'
**
** Created by: Qt User Interface Compiler version 6.2.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MACCALC_H
#define UI_MACCALC_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionCalculator;
    QAction *actionCredit_Calculator;
    QAction *actionDeposit_Calculator;
    QAction *actionGraph;
    QWidget *MainWidget;
    QTabWidget *MainTab;
    QWidget *Calculator;
    QWidget *widget;
    QLabel *LabelInput;
    QPushButton *ButtonMod;
    QPushButton *ButtonPow;
    QPushButton *Button7;
    QPushButton *Button8;
    QPushButton *Button9;
    QPushButton *ButtonMul;
    QPushButton *ButtonLog;
    QPushButton *ButtonLn;
    QPushButton *ButtonSqrt;
    QPushButton *Button4;
    QPushButton *Button5;
    QPushButton *Button6;
    QPushButton *ButtonSub;
    QPushButton *ButtonAsin;
    QPushButton *ButtonAcos;
    QPushButton *ButtonAtan;
    QPushButton *Button1;
    QPushButton *Button2;
    QPushButton *Button3;
    QPushButton *ButtonSum;
    QPushButton *ButtonSin;
    QPushButton *ButtonCos;
    QPushButton *ButtonTan;
    QPushButton *Button0;
    QPushButton *ButtonDot;
    QPushButton *ButtonGetResult;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *ButtonX;
    QPushButton *ButtonOpenBracket;
    QPushButton *ButtonCloseBracket;
    QPushButton *ButtonAC;
    QPushButton *ButtonDrawGraph;
    QPushButton *ButtonDiv;
    QWidget *Graph;
    QDoubleSpinBox *RangeMax;
    QLineEdit *FunctionScope;
    QDoubleSpinBox *input_x;
    QLineEdit *StepXDef;
    QDoubleSpinBox *ScopeMax;
    QDoubleSpinBox *StepX;
    QDoubleSpinBox *ScopeMin;
    QLineEdit *FunctionRange;
    QDoubleSpinBox *RangeMin;
    QLineEdit *XDef;
    QGraphicsView *graphicsView;
    QWidget *CreditCalc;
    QWidget *DepositCalc;
    QPushButton *ButtonFactorial;
    QMenuBar *menuBar;
    QMenu *menuCalculator;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1120, 858);
        MainWindow->setMinimumSize(QSize(412, 300));
        MainWindow->setMaximumSize(QSize(10000, 10000));
        actionCalculator = new QAction(MainWindow);
        actionCalculator->setObjectName(QString::fromUtf8("actionCalculator"));
        actionCredit_Calculator = new QAction(MainWindow);
        actionCredit_Calculator->setObjectName(QString::fromUtf8("actionCredit_Calculator"));
        actionDeposit_Calculator = new QAction(MainWindow);
        actionDeposit_Calculator->setObjectName(QString::fromUtf8("actionDeposit_Calculator"));
        actionGraph = new QAction(MainWindow);
        actionGraph->setObjectName(QString::fromUtf8("actionGraph"));
        MainWidget = new QWidget(MainWindow);
        MainWidget->setObjectName(QString::fromUtf8("MainWidget"));
        MainTab = new QTabWidget(MainWidget);
        MainTab->setObjectName(QString::fromUtf8("MainTab"));
        MainTab->setGeometry(QRect(90, 40, 991, 811));
        Calculator = new QWidget();
        Calculator->setObjectName(QString::fromUtf8("Calculator"));
        widget = new QWidget(Calculator);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(130, 140, 741, 501));
        widget->setStyleSheet(QString::fromUtf8("background-color:black;\n"
""));
        LabelInput = new QLabel(widget);
        LabelInput->setObjectName(QString::fromUtf8("LabelInput"));
        LabelInput->setGeometry(QRect(40, 0, 16, 29));
        QFont font;
        font.setPointSize(25);
        font.setBold(true);
        LabelInput->setFont(font);
        LabelInput->setStyleSheet(QString::fromUtf8("background-color:black;"));
        ButtonMod = new QPushButton(widget);
        ButtonMod->setObjectName(QString::fromUtf8("ButtonMod"));
        ButtonMod->setGeometry(QRect(40, 167, 60, 24));
        ButtonMod->setMinimumSize(QSize(60, 10));
        ButtonMod->setMaximumSize(QSize(60, 100));
        QFont font1;
        font1.setPointSize(18);
        ButtonMod->setFont(font1);
        ButtonMod->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color: rgb(56, 56, 56);\n"
"	border: 1px solid rgb(34, 34, 34);\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: rgba(162, 161, 166, 128);\n"
"}"));
        ButtonPow = new QPushButton(widget);
        ButtonPow->setObjectName(QString::fromUtf8("ButtonPow"));
        ButtonPow->setGeometry(QRect(240, 167, 60, 24));
        ButtonPow->setMinimumSize(QSize(60, 10));
        ButtonPow->setMaximumSize(QSize(60, 100));
        ButtonPow->setFont(font1);
        ButtonPow->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color: rgb(56, 56, 56);\n"
"	border: 1px solid rgb(34, 34, 34);\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: rgba(162, 161, 166, 128);\n"
"}"));
        Button7 = new QPushButton(widget);
        Button7->setObjectName(QString::fromUtf8("Button7"));
        Button7->setGeometry(QRect(340, 167, 60, 84));
        Button7->setMinimumSize(QSize(60, 10));
        Button7->setMaximumSize(QSize(60, 100));
        QFont font2;
        font2.setPointSize(25);
        Button7->setFont(font2);
        Button7->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	 background-color: rgb(89, 89, 89);\n"
"   border: 1px solid rgb(34, 34, 34);\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: rgba(255, 255, 255, 128);\n"
"}"));
        Button8 = new QPushButton(widget);
        Button8->setObjectName(QString::fromUtf8("Button8"));
        Button8->setGeometry(QRect(440, 167, 60, 32));
        Button8->setMinimumSize(QSize(60, 10));
        Button8->setMaximumSize(QSize(60, 100));
        Button8->setFont(font2);
        Button8->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	 background-color: rgb(89, 89, 89);\n"
"   border: 1px solid rgb(34, 34, 34);\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: rgba(255, 255, 255, 128);\n"
"}"));
        Button9 = new QPushButton(widget);
        Button9->setObjectName(QString::fromUtf8("Button9"));
        Button9->setGeometry(QRect(540, 167, 60, 32));
        Button9->setMinimumSize(QSize(60, 10));
        Button9->setMaximumSize(QSize(60, 100));
        Button9->setFont(font2);
        Button9->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	 background-color: rgb(89, 89, 89);\n"
"   border: 1px solid rgb(34, 34, 34);\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: rgba(255, 255, 255, 128);\n"
"}"));
        ButtonMul = new QPushButton(widget);
        ButtonMul->setObjectName(QString::fromUtf8("ButtonMul"));
        ButtonMul->setGeometry(QRect(640, 167, 60, 32));
        ButtonMul->setMinimumSize(QSize(60, 10));
        ButtonMul->setMaximumSize(QSize(60, 100));
        ButtonMul->setFont(font2);
        ButtonMul->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	 background-color: rgb(226, 153, 57);\n"
"   border: 1px solid rgb(34, 34, 34);\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: rgba(255, 165, 2, 130)\n"
"}"));
        ButtonLog = new QPushButton(widget);
        ButtonLog->setObjectName(QString::fromUtf8("ButtonLog"));
        ButtonLog->setGeometry(QRect(40, 251, 60, 24));
        ButtonLog->setMinimumSize(QSize(60, 10));
        ButtonLog->setMaximumSize(QSize(60, 100));
        ButtonLog->setFont(font1);
        ButtonLog->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color: rgb(56, 56, 56);\n"
"	border: 1px solid rgb(34, 34, 34);\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: rgba(162, 161, 166, 128);\n"
"}"));
        ButtonLn = new QPushButton(widget);
        ButtonLn->setObjectName(QString::fromUtf8("ButtonLn"));
        ButtonLn->setGeometry(QRect(140, 251, 60, 24));
        ButtonLn->setMinimumSize(QSize(60, 10));
        ButtonLn->setMaximumSize(QSize(60, 100));
        ButtonLn->setFont(font1);
        ButtonLn->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color: rgb(56, 56, 56);\n"
"	border: 1px solid rgb(34, 34, 34);\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: rgba(162, 161, 166, 128);\n"
"}"));
        ButtonSqrt = new QPushButton(widget);
        ButtonSqrt->setObjectName(QString::fromUtf8("ButtonSqrt"));
        ButtonSqrt->setGeometry(QRect(240, 251, 60, 24));
        ButtonSqrt->setMinimumSize(QSize(60, 10));
        ButtonSqrt->setMaximumSize(QSize(60, 100));
        ButtonSqrt->setFont(font1);
        ButtonSqrt->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color: rgb(56, 56, 56);\n"
"	border: 1px solid rgb(34, 34, 34);\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: rgba(162, 161, 166, 128);\n"
"}"));
        Button4 = new QPushButton(widget);
        Button4->setObjectName(QString::fromUtf8("Button4"));
        Button4->setGeometry(QRect(340, 251, 60, 32));
        Button4->setMinimumSize(QSize(60, 10));
        Button4->setMaximumSize(QSize(60, 100));
        Button4->setFont(font2);
        Button4->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	 background-color: rgb(89, 89, 89);\n"
"   border: 1px solid rgb(34, 34, 34);\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: rgba(255, 255, 255, 128);\n"
"}"));
        Button5 = new QPushButton(widget);
        Button5->setObjectName(QString::fromUtf8("Button5"));
        Button5->setGeometry(QRect(440, 251, 60, 32));
        Button5->setMinimumSize(QSize(60, 10));
        Button5->setMaximumSize(QSize(60, 100));
        Button5->setFont(font2);
        Button5->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	 background-color: rgb(89, 89, 89);\n"
"   border: 1px solid rgb(34, 34, 34);\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: rgba(255, 255, 255, 128);\n"
"}"));
        Button6 = new QPushButton(widget);
        Button6->setObjectName(QString::fromUtf8("Button6"));
        Button6->setGeometry(QRect(540, 251, 60, 32));
        Button6->setMinimumSize(QSize(60, 10));
        Button6->setMaximumSize(QSize(60, 100));
        Button6->setFont(font2);
        Button6->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	 background-color: rgb(89, 89, 89);\n"
"   border: 1px solid rgb(34, 34, 34);\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: rgba(255, 255, 255, 128);\n"
"}"));
        ButtonSub = new QPushButton(widget);
        ButtonSub->setObjectName(QString::fromUtf8("ButtonSub"));
        ButtonSub->setGeometry(QRect(640, 251, 60, 32));
        ButtonSub->setMinimumSize(QSize(60, 10));
        ButtonSub->setMaximumSize(QSize(60, 100));
        ButtonSub->setFont(font2);
        ButtonSub->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	 background-color: rgb(226, 153, 57);\n"
"   border: 1px solid rgb(34, 34, 34);\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: rgba(255, 165, 2, 130)\n"
"}"));
        ButtonAsin = new QPushButton(widget);
        ButtonAsin->setObjectName(QString::fromUtf8("ButtonAsin"));
        ButtonAsin->setGeometry(QRect(40, 334, 60, 24));
        ButtonAsin->setMinimumSize(QSize(60, 10));
        ButtonAsin->setMaximumSize(QSize(60, 100));
        ButtonAsin->setFont(font1);
        ButtonAsin->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color: rgb(56, 56, 56);\n"
"	border: 1px solid rgb(34, 34, 34);\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: rgba(162, 161, 166, 128);\n"
"}"));
        ButtonAcos = new QPushButton(widget);
        ButtonAcos->setObjectName(QString::fromUtf8("ButtonAcos"));
        ButtonAcos->setGeometry(QRect(140, 334, 60, 24));
        ButtonAcos->setMinimumSize(QSize(60, 10));
        ButtonAcos->setMaximumSize(QSize(60, 100));
        ButtonAcos->setFont(font1);
        ButtonAcos->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color: rgb(56, 56, 56);\n"
"	border: 1px solid rgb(34, 34, 34);\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: rgba(162, 161, 166, 128);\n"
"}"));
        ButtonAtan = new QPushButton(widget);
        ButtonAtan->setObjectName(QString::fromUtf8("ButtonAtan"));
        ButtonAtan->setGeometry(QRect(240, 334, 60, 24));
        ButtonAtan->setMinimumSize(QSize(60, 10));
        ButtonAtan->setMaximumSize(QSize(60, 100));
        ButtonAtan->setFont(font1);
        ButtonAtan->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color: rgb(56, 56, 56);\n"
"	border: 1px solid rgb(34, 34, 34);\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: rgba(162, 161, 166, 128);\n"
"}"));
        Button1 = new QPushButton(widget);
        Button1->setObjectName(QString::fromUtf8("Button1"));
        Button1->setGeometry(QRect(340, 334, 60, 32));
        Button1->setMinimumSize(QSize(60, 10));
        Button1->setMaximumSize(QSize(60, 100));
        Button1->setFont(font2);
        Button1->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	 background-color: rgb(89, 89, 89);\n"
"   border: 1px solid rgb(34, 34, 34);\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: rgba(255, 255, 255, 128);\n"
"}"));
        Button2 = new QPushButton(widget);
        Button2->setObjectName(QString::fromUtf8("Button2"));
        Button2->setGeometry(QRect(440, 334, 60, 32));
        Button2->setMinimumSize(QSize(60, 10));
        Button2->setMaximumSize(QSize(60, 100));
        Button2->setFont(font2);
        Button2->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	 background-color: rgb(89, 89, 89);\n"
"   border: 1px solid rgb(34, 34, 34);\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: rgba(255, 255, 255, 128);\n"
"}"));
        Button3 = new QPushButton(widget);
        Button3->setObjectName(QString::fromUtf8("Button3"));
        Button3->setGeometry(QRect(540, 334, 60, 32));
        Button3->setMinimumSize(QSize(60, 10));
        Button3->setMaximumSize(QSize(60, 100));
        Button3->setFont(font2);
        Button3->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	 background-color: rgb(89, 89, 89);\n"
"   border: 1px solid rgb(34, 34, 34);\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: rgba(255, 255, 255, 128);\n"
"}"));
        ButtonSum = new QPushButton(widget);
        ButtonSum->setObjectName(QString::fromUtf8("ButtonSum"));
        ButtonSum->setGeometry(QRect(640, 334, 60, 32));
        ButtonSum->setMinimumSize(QSize(60, 10));
        ButtonSum->setMaximumSize(QSize(60, 100));
        ButtonSum->setFont(font2);
        ButtonSum->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	 background-color: rgb(226, 153, 57);\n"
"   border: 1px solid rgb(34, 34, 34);\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: rgba(255, 165, 2, 130)\n"
"}"));
        ButtonSin = new QPushButton(widget);
        ButtonSin->setObjectName(QString::fromUtf8("ButtonSin"));
        ButtonSin->setGeometry(QRect(40, 418, 60, 24));
        ButtonSin->setMinimumSize(QSize(60, 10));
        ButtonSin->setMaximumSize(QSize(60, 100));
        ButtonSin->setFont(font1);
        ButtonSin->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color: rgb(56, 56, 56);\n"
"	border: 1px solid rgb(34, 34, 34);\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: rgba(162, 161, 166, 128);\n"
"}"));
        ButtonCos = new QPushButton(widget);
        ButtonCos->setObjectName(QString::fromUtf8("ButtonCos"));
        ButtonCos->setGeometry(QRect(140, 418, 60, 24));
        ButtonCos->setMinimumSize(QSize(60, 10));
        ButtonCos->setMaximumSize(QSize(60, 100));
        ButtonCos->setFont(font1);
        ButtonCos->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color: rgb(56, 56, 56);\n"
"	border: 1px solid rgb(34, 34, 34);\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: rgba(162, 161, 166, 128);\n"
"}"));
        ButtonTan = new QPushButton(widget);
        ButtonTan->setObjectName(QString::fromUtf8("ButtonTan"));
        ButtonTan->setGeometry(QRect(240, 418, 60, 24));
        ButtonTan->setMinimumSize(QSize(60, 10));
        ButtonTan->setMaximumSize(QSize(60, 100));
        ButtonTan->setFont(font1);
        ButtonTan->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color: rgb(56, 56, 56);\n"
"	border: 1px solid rgb(34, 34, 34);\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: rgba(162, 161, 166, 128);\n"
"}"));
        ButtonTan->setAutoExclusive(false);
        ButtonTan->setAutoDefault(false);
        Button0 = new QPushButton(widget);
        Button0->setObjectName(QString::fromUtf8("Button0"));
        Button0->setGeometry(QRect(340, 418, 119, 32));
        Button0->setMinimumSize(QSize(119, 10));
        Button0->setMaximumSize(QSize(119, 100));
        Button0->setFont(font2);
        Button0->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	 background-color: rgb(89, 89, 89);\n"
"   border: 1px solid rgb(34, 34, 34);\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: rgba(255, 255, 255, 128);\n"
"}"));
        ButtonDot = new QPushButton(widget);
        ButtonDot->setObjectName(QString::fromUtf8("ButtonDot"));
        ButtonDot->setGeometry(QRect(540, 418, 60, 32));
        ButtonDot->setMinimumSize(QSize(60, 10));
        ButtonDot->setMaximumSize(QSize(60, 100));
        ButtonDot->setFont(font2);
        ButtonDot->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	 background-color: rgb(89, 89, 89);\n"
"   border: 1px solid rgb(34, 34, 34);\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: rgba(255, 255, 255, 128);\n"
"}"));
        ButtonGetResult = new QPushButton(widget);
        ButtonGetResult->setObjectName(QString::fromUtf8("ButtonGetResult"));
        ButtonGetResult->setGeometry(QRect(640, 418, 60, 83));
        ButtonGetResult->setMinimumSize(QSize(60, 10));
        ButtonGetResult->setMaximumSize(QSize(60, 100));
        ButtonGetResult->setFont(font2);
        ButtonGetResult->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	 background-color: rgb(226, 153, 57);\n"
"   border: 1px solid rgb(34, 34, 34);\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: rgba(255, 165, 2, 130)\n"
"}"));
        layoutWidget = new QWidget(widget);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(0, 84, 741, 34));
        horizontalLayout = new QHBoxLayout(layoutWidget);
#ifndef Q_OS_MAC
        horizontalLayout->setSpacing(-1);
#endif
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 1, 0, 0);
        ButtonX = new QPushButton(layoutWidget);
        ButtonX->setObjectName(QString::fromUtf8("ButtonX"));
        ButtonX->setMinimumSize(QSize(60, 10));
        ButtonX->setMaximumSize(QSize(60, 100));
        ButtonX->setFont(font1);
        ButtonX->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color: rgb(56, 56, 56);\n"
"	border: 1px solid rgb(34, 34, 34);\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: rgba(162, 161, 166, 128);\n"
"}"));

        horizontalLayout->addWidget(ButtonX);

        ButtonOpenBracket = new QPushButton(layoutWidget);
        ButtonOpenBracket->setObjectName(QString::fromUtf8("ButtonOpenBracket"));
        ButtonOpenBracket->setMinimumSize(QSize(60, 10));
        ButtonOpenBracket->setMaximumSize(QSize(60, 100));
        QFont font3;
        font3.setPointSize(7);
        ButtonOpenBracket->setFont(font3);
        ButtonOpenBracket->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color: rgb(56, 56, 56);\n"
"	border: 1px solid rgb(34, 34, 34);\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: rgba(162, 161, 166, 128);\n"
"}"));

        horizontalLayout->addWidget(ButtonOpenBracket);

        ButtonCloseBracket = new QPushButton(layoutWidget);
        ButtonCloseBracket->setObjectName(QString::fromUtf8("ButtonCloseBracket"));
        ButtonCloseBracket->setMinimumSize(QSize(60, 10));
        ButtonCloseBracket->setMaximumSize(QSize(60, 100));
        QFont font4;
        font4.setPointSize(8);
        ButtonCloseBracket->setFont(font4);
        ButtonCloseBracket->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color: rgb(56, 56, 56);\n"
"	border: 1px solid rgb(34, 34, 34);\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: rgba(162, 161, 166, 128);\n"
"}"));

        horizontalLayout->addWidget(ButtonCloseBracket);

        ButtonAC = new QPushButton(layoutWidget);
        ButtonAC->setObjectName(QString::fromUtf8("ButtonAC"));
        ButtonAC->setMinimumSize(QSize(60, 10));
        ButtonAC->setMaximumSize(QSize(60, 100));
        QFont font5;
        font5.setPointSize(22);
        ButtonAC->setFont(font5);
        ButtonAC->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	 background-color: rgb(226, 153, 57);\n"
"   border: 1px solid rgb(34, 34, 34);\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: rgba(255, 165, 2, 130)\n"
"}"));

        horizontalLayout->addWidget(ButtonAC);

        ButtonDrawGraph = new QPushButton(layoutWidget);
        ButtonDrawGraph->setObjectName(QString::fromUtf8("ButtonDrawGraph"));
        ButtonDrawGraph->setMinimumSize(QSize(0, 10));
        ButtonDrawGraph->setMaximumSize(QSize(1000, 10000));
        ButtonDrawGraph->setFont(font5);
        ButtonDrawGraph->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	 background-color: rgb(226, 153, 57);\n"
"   border: 1px solid rgb(34, 34, 34);\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: rgba(255, 165, 2, 130)\n"
"}"));

        horizontalLayout->addWidget(ButtonDrawGraph);

        ButtonDiv = new QPushButton(layoutWidget);
        ButtonDiv->setObjectName(QString::fromUtf8("ButtonDiv"));
        ButtonDiv->setMinimumSize(QSize(60, 10));
        ButtonDiv->setMaximumSize(QSize(60, 100));
        ButtonDiv->setFont(font2);
        ButtonDiv->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	 background-color: rgb(226, 153, 57);\n"
"   border: 1px solid rgb(34, 34, 34);\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: rgba(255, 165, 2, 130)\n"
"}"));

        horizontalLayout->addWidget(ButtonDiv);

        MainTab->addTab(Calculator, QString());
        Graph = new QWidget();
        Graph->setObjectName(QString::fromUtf8("Graph"));
        RangeMax = new QDoubleSpinBox(Graph);
        RangeMax->setObjectName(QString::fromUtf8("RangeMax"));
        RangeMax->setGeometry(QRect(200, 580, 66, 18));
        QFont font6;
        font6.setPointSize(9);
        RangeMax->setFont(font6);
        RangeMax->setStyleSheet(QString::fromUtf8("background-color: white;\n"
"color: black;\n"
"border: 1px solid rgb(0, 32, 255);\n"
""));
        RangeMax->setAlignment(Qt::AlignCenter);
        RangeMax->setButtonSymbols(QAbstractSpinBox::NoButtons);
        RangeMax->setMinimum(-1000000.000000000000000);
        RangeMax->setMaximum(1000000.000000000000000);
        RangeMax->setValue(2.000000000000000);
        FunctionScope = new QLineEdit(Graph);
        FunctionScope->setObjectName(QString::fromUtf8("FunctionScope"));
        FunctionScope->setGeometry(QRect(72, 540, 91, 18));
        FunctionScope->setFont(font6);
        FunctionScope->setLayoutDirection(Qt::LeftToRight);
        FunctionScope->setStyleSheet(QString::fromUtf8("background-color: white;\n"
"color: black;\n"
"border: 1px solid rgb(0, 32, 255);\n"
""));
        FunctionScope->setAlignment(Qt::AlignCenter);
        FunctionScope->setReadOnly(true);
        input_x = new QDoubleSpinBox(Graph);
        input_x->setObjectName(QString::fromUtf8("input_x"));
        input_x->setGeometry(QRect(640, 570, 151, 20));
        input_x->setStyleSheet(QString::fromUtf8("background-color: white;\n"
"color: black;\n"
"border: 1px solid rgb(0, 32, 255);\n"
""));
        input_x->setWrapping(false);
        input_x->setAlignment(Qt::AlignCenter);
        input_x->setButtonSymbols(QAbstractSpinBox::NoButtons);
        input_x->setMinimum(-1000000.000000000000000);
        input_x->setMaximum(1000000.000000000000000);
        input_x->setSingleStep(0.010000000000000);
        input_x->setStepType(QAbstractSpinBox::DefaultStepType);
        input_x->setValue(0.000000000000000);
        StepXDef = new QLineEdit(Graph);
        StepXDef->setObjectName(QString::fromUtf8("StepXDef"));
        StepXDef->setGeometry(QRect(510, 540, 87, 27));
        QFont font7;
        font7.setPointSize(20);
        StepXDef->setFont(font7);
        StepXDef->setLayoutDirection(Qt::LeftToRight);
        StepXDef->setStyleSheet(QString::fromUtf8("background-color: white;\n"
"color: black;\n"
"border: 1px solid rgb(0, 32, 255);\n"
""));
        StepXDef->setAlignment(Qt::AlignCenter);
        StepXDef->setReadOnly(true);
        ScopeMax = new QDoubleSpinBox(Graph);
        ScopeMax->setObjectName(QString::fromUtf8("ScopeMax"));
        ScopeMax->setGeometry(QRect(80, 580, 66, 18));
        ScopeMax->setFont(font6);
        ScopeMax->setStyleSheet(QString::fromUtf8("background-color: white;\n"
"color: black;\n"
"border: 1px solid rgb(0, 32, 255);\n"
""));
        ScopeMax->setAlignment(Qt::AlignCenter);
        ScopeMax->setButtonSymbols(QAbstractSpinBox::NoButtons);
        ScopeMax->setMinimum(-1000000.000000000000000);
        ScopeMax->setMaximum(1000000.000000000000000);
        ScopeMax->setValue(50.000000000000000);
        StepX = new QDoubleSpinBox(Graph);
        StepX->setObjectName(QString::fromUtf8("StepX"));
        StepX->setGeometry(QRect(480, 570, 151, 20));
        StepX->setStyleSheet(QString::fromUtf8("background-color: white;\n"
"color: black;\n"
"border: 1px solid rgb(0, 32, 255);\n"
""));
        StepX->setWrapping(false);
        StepX->setAlignment(Qt::AlignCenter);
        StepX->setButtonSymbols(QAbstractSpinBox::NoButtons);
        StepX->setMinimum(-1000000.000000000000000);
        StepX->setMaximum(1000000.000000000000000);
        StepX->setSingleStep(0.010000000000000);
        StepX->setStepType(QAbstractSpinBox::DefaultStepType);
        StepX->setValue(0.000000000000000);
        ScopeMin = new QDoubleSpinBox(Graph);
        ScopeMin->setObjectName(QString::fromUtf8("ScopeMin"));
        ScopeMin->setGeometry(QRect(80, 560, 66, 18));
        ScopeMin->setFont(font6);
        ScopeMin->setStyleSheet(QString::fromUtf8("background-color: white;\n"
"color: black;\n"
"border: 1px solid rgb(0, 32, 255);\n"
""));
        ScopeMin->setAlignment(Qt::AlignCenter);
        ScopeMin->setButtonSymbols(QAbstractSpinBox::NoButtons);
        ScopeMin->setKeyboardTracking(true);
        ScopeMin->setMinimum(-1000000.000000000000000);
        ScopeMin->setMaximum(1000000.000000000000000);
        ScopeMin->setValue(-50.000000000000000);
        FunctionRange = new QLineEdit(Graph);
        FunctionRange->setObjectName(QString::fromUtf8("FunctionRange"));
        FunctionRange->setGeometry(QRect(190, 540, 91, 18));
        FunctionRange->setFont(font6);
        FunctionRange->setLayoutDirection(Qt::LeftToRight);
        FunctionRange->setStyleSheet(QString::fromUtf8("background-color: white;\n"
"color: black;\n"
"border: 1px solid rgb(0, 32, 255);\n"
""));
        FunctionRange->setAlignment(Qt::AlignCenter);
        FunctionRange->setReadOnly(true);
        RangeMin = new QDoubleSpinBox(Graph);
        RangeMin->setObjectName(QString::fromUtf8("RangeMin"));
        RangeMin->setGeometry(QRect(200, 560, 66, 18));
        RangeMin->setFont(font6);
        RangeMin->setStyleSheet(QString::fromUtf8("background-color: white;\n"
"color: black;\n"
"border: 1px solid rgb(0, 32, 255);\n"
""));
        RangeMin->setAlignment(Qt::AlignCenter);
        RangeMin->setButtonSymbols(QAbstractSpinBox::NoButtons);
        RangeMin->setMinimum(-1000000.000000000000000);
        RangeMin->setMaximum(1000000.000000000000000);
        RangeMin->setValue(-2.000000000000000);
        XDef = new QLineEdit(Graph);
        XDef->setObjectName(QString::fromUtf8("XDef"));
        XDef->setGeometry(QRect(670, 540, 87, 27));
        XDef->setFont(font7);
        XDef->setLayoutDirection(Qt::LeftToRight);
        XDef->setStyleSheet(QString::fromUtf8("background-color: white;\n"
"color: black;\n"
"border: 1px solid rgb(0, 32, 255);\n"
""));
        XDef->setAlignment(Qt::AlignCenter);
        XDef->setReadOnly(true);
        graphicsView = new QGraphicsView(Graph);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));
        graphicsView->setGeometry(QRect(-10, -30, 871, 661));
        graphicsView->setMinimumSize(QSize(776, 482));
        graphicsView->setStyleSheet(QString::fromUtf8("background-color:white;\n"
""));
        MainTab->addTab(Graph, QString());
        graphicsView->raise();
        RangeMax->raise();
        FunctionScope->raise();
        input_x->raise();
        StepXDef->raise();
        ScopeMax->raise();
        StepX->raise();
        ScopeMin->raise();
        FunctionRange->raise();
        RangeMin->raise();
        XDef->raise();
        CreditCalc = new QWidget();
        CreditCalc->setObjectName(QString::fromUtf8("CreditCalc"));
        MainTab->addTab(CreditCalc, QString());
        DepositCalc = new QWidget();
        DepositCalc->setObjectName(QString::fromUtf8("DepositCalc"));
        MainTab->addTab(DepositCalc, QString());
        ButtonFactorial = new QPushButton(MainWidget);
        ButtonFactorial->setObjectName(QString::fromUtf8("ButtonFactorial"));
        ButtonFactorial->setGeometry(QRect(20, 110, 60, 84));
        ButtonFactorial->setMinimumSize(QSize(60, 10));
        ButtonFactorial->setMaximumSize(QSize(60, 100));
        ButtonFactorial->setFont(font1);
        ButtonFactorial->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color: rgb(56, 56, 56);\n"
"	border: 1px solid rgb(34, 34, 34);\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: rgba(162, 161, 166, 128);\n"
"}"));
        MainWindow->setCentralWidget(MainWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1120, 24));
        menuCalculator = new QMenu(menuBar);
        menuCalculator->setObjectName(QString::fromUtf8("menuCalculator"));
        MainWindow->setMenuBar(menuBar);

        menuBar->addAction(menuCalculator->menuAction());
        menuCalculator->addAction(actionCalculator);
        menuCalculator->addAction(actionCredit_Calculator);
        menuCalculator->addAction(actionDeposit_Calculator);
        menuCalculator->addAction(actionGraph);

        retranslateUi(MainWindow);

        MainTab->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        actionCalculator->setText(QCoreApplication::translate("MainWindow", "Calculator", nullptr));
        actionCredit_Calculator->setText(QCoreApplication::translate("MainWindow", "Credit Calculator", nullptr));
        actionDeposit_Calculator->setText(QCoreApplication::translate("MainWindow", "Deposit Calculator", nullptr));
        actionGraph->setText(QCoreApplication::translate("MainWindow", "Graph", nullptr));
        LabelInput->setText(QString());
        ButtonMod->setText(QCoreApplication::translate("MainWindow", "mod", nullptr));
        ButtonPow->setText(QCoreApplication::translate("MainWindow", "pow", nullptr));
        Button7->setText(QCoreApplication::translate("MainWindow", "seven", nullptr));
        Button8->setText(QCoreApplication::translate("MainWindow", "eight", nullptr));
        Button9->setText(QCoreApplication::translate("MainWindow", "nine", nullptr));
        ButtonMul->setText(QCoreApplication::translate("MainWindow", "mul", nullptr));
        ButtonLog->setText(QCoreApplication::translate("MainWindow", "log", nullptr));
        ButtonLn->setText(QCoreApplication::translate("MainWindow", "ln", nullptr));
        ButtonSqrt->setText(QCoreApplication::translate("MainWindow", "sqrt", nullptr));
        Button4->setText(QCoreApplication::translate("MainWindow", "four", nullptr));
        Button5->setText(QCoreApplication::translate("MainWindow", "five", nullptr));
        Button6->setText(QCoreApplication::translate("MainWindow", "six", nullptr));
        ButtonSub->setText(QCoreApplication::translate("MainWindow", "sub", nullptr));
        ButtonAsin->setText(QCoreApplication::translate("MainWindow", "asin", nullptr));
        ButtonAcos->setText(QCoreApplication::translate("MainWindow", "acos", nullptr));
        ButtonAtan->setText(QCoreApplication::translate("MainWindow", "atan", nullptr));
        Button1->setText(QCoreApplication::translate("MainWindow", "one", nullptr));
        Button2->setText(QCoreApplication::translate("MainWindow", "two", nullptr));
        Button3->setText(QCoreApplication::translate("MainWindow", "three", nullptr));
        ButtonSum->setText(QCoreApplication::translate("MainWindow", "sum", nullptr));
        ButtonSin->setText(QCoreApplication::translate("MainWindow", "sin", nullptr));
        ButtonCos->setText(QCoreApplication::translate("MainWindow", "cos", nullptr));
        ButtonTan->setText(QCoreApplication::translate("MainWindow", "tan", nullptr));
        Button0->setText(QCoreApplication::translate("MainWindow", "zero", nullptr));
        ButtonDot->setText(QCoreApplication::translate("MainWindow", "dot", nullptr));
        ButtonGetResult->setText(QCoreApplication::translate("MainWindow", "equal", nullptr));
        ButtonX->setText(QCoreApplication::translate("MainWindow", "x", nullptr));
        ButtonOpenBracket->setText(QCoreApplication::translate("MainWindow", "openBracket", nullptr));
        ButtonCloseBracket->setText(QCoreApplication::translate("MainWindow", "closeBracket", nullptr));
        ButtonAC->setText(QCoreApplication::translate("MainWindow", "AC", nullptr));
        ButtonDrawGraph->setText(QCoreApplication::translate("MainWindow", "Graph", nullptr));
        ButtonDiv->setText(QCoreApplication::translate("MainWindow", "div", nullptr));
        MainTab->setTabText(MainTab->indexOf(Calculator), QCoreApplication::translate("MainWindow", "Calculator", nullptr));
        FunctionScope->setText(QCoreApplication::translate("MainWindow", " Function scope", nullptr));
        StepXDef->setText(QCoreApplication::translate("MainWindow", "step", nullptr));
        FunctionRange->setText(QCoreApplication::translate("MainWindow", "Function range ", nullptr));
        XDef->setText(QCoreApplication::translate("MainWindow", "X", nullptr));
        MainTab->setTabText(MainTab->indexOf(Graph), QCoreApplication::translate("MainWindow", "\320\241\321\202\321\200\320\260\320\275\320\270\321\206\320\260", nullptr));
        MainTab->setTabText(MainTab->indexOf(CreditCalc), QCoreApplication::translate("MainWindow", "Credit Calculator", nullptr));
        MainTab->setTabText(MainTab->indexOf(DepositCalc), QCoreApplication::translate("MainWindow", "Deposit Calculator", nullptr));
        ButtonFactorial->setText(QCoreApplication::translate("MainWindow", "factorial", nullptr));
        menuCalculator->setTitle(QCoreApplication::translate("MainWindow", "Mode", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MACCALC_H
