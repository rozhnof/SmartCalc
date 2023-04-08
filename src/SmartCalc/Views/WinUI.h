#ifndef WINUI_H
#define WINUI_H

#include "BaseView.h"
#include "IPlatformUI.h"

class WinUI : public IPlatformUI
{
public:
    WinUI() {
        SetupUI();
       RetranslateUI();
    }

    void SetupUI()  {
        MainTab = new QTabWidget(window);
                MainTab->setObjectName(QString::fromUtf8("MainTab"));
                MainTab->setGeometry(QRect(10, 10, 601, 371));
                Calculator = new QWidget();
                Calculator->setObjectName(QString::fromUtf8("Calculator"));
                ButtonGetResult = new QPushButton(Calculator);
                ButtonGetResult->setObjectName(QString::fromUtf8("ButtonGetResult"));
                ButtonGetResult->setGeometry(QRect(468, 268, 60, 53));
                ButtonGetResult->setMinimumSize(QSize(60, 10));
                ButtonGetResult->setMaximumSize(QSize(60, 100));
                QFont font;
                font.setPointSize(25);
                ButtonGetResult->setFont(font);
                ButtonGetResult->setStyleSheet(QString::fromUtf8("QPushButton {\n"
        "	 background-color: rgb(152, 218, 255);\n"
        "   border: 1px solid rgb(34, 34, 34);\n"
        "color: black;\n"
        "}\n"
        "QPushButton:pressed {\n"
        "    background-color: rgb(0, 0, 0);\n"
        "}"));
                ButtonDrawGraph = new QPushButton(Calculator);
                ButtonDrawGraph->setObjectName(QString::fromUtf8("ButtonDrawGraph"));
                ButtonDrawGraph->setGeometry(QRect(350, 60, 119, 53));
                ButtonDrawGraph->setMinimumSize(QSize(0, 10));
                ButtonDrawGraph->setMaximumSize(QSize(1000, 10000));
                QFont font1;
                font1.setPointSize(22);
                ButtonDrawGraph->setFont(font1);
                ButtonDrawGraph->setStyleSheet(QString::fromUtf8("QPushButton {\n"
        "	 background-color: rgb(152, 218, 255);\n"
        "   border: 1px solid rgb(34, 34, 34);\n"
        "color: black;\n"
        "}\n"
        "QPushButton:pressed {\n"
        "    background-color: rgb(0, 0, 0);\n"
        "}"));
                ButtonCos = new QPushButton(Calculator);
                ButtonCos->setObjectName(QString::fromUtf8("ButtonCos"));
                ButtonCos->setGeometry(QRect(173, 268, 60, 53));
                ButtonCos->setMinimumSize(QSize(60, 10));
                ButtonCos->setMaximumSize(QSize(60, 100));
                QFont font2;
                font2.setPointSize(18);
                ButtonCos->setFont(font2);
                ButtonCos->setStyleSheet(QString::fromUtf8("QPushButton {\n"
        "	 background-color: rgb(152, 218, 255);\n"
        "   border: 1px solid rgb(34, 34, 34);\n"
        "color: black;\n"
        "}\n"
        "QPushButton:pressed {\n"
        "    background-color: rgb(0, 0, 0);\n"
        "}"));
                ButtonLog = new QPushButton(Calculator);
                ButtonLog->setObjectName(QString::fromUtf8("ButtonLog"));
                ButtonLog->setGeometry(QRect(114, 164, 60, 53));
                ButtonLog->setMinimumSize(QSize(60, 10));
                ButtonLog->setMaximumSize(QSize(60, 100));
                ButtonLog->setFont(font2);
                ButtonLog->setStyleSheet(QString::fromUtf8("QPushButton {\n"
        "	 background-color: rgb(152, 218, 255);\n"
        "   border: 1px solid rgb(34, 34, 34);\n"
        "color: black;\n"
        "}\n"
        "QPushButton:pressed {\n"
        "    background-color: rgb(0, 0, 0);\n"
        "}"));
                ButtonTan = new QPushButton(Calculator);
                ButtonTan->setObjectName(QString::fromUtf8("ButtonTan"));
                ButtonTan->setGeometry(QRect(232, 268, 60, 53));
                ButtonTan->setMinimumSize(QSize(60, 10));
                ButtonTan->setMaximumSize(QSize(60, 100));
                ButtonTan->setFont(font2);
                ButtonTan->setStyleSheet(QString::fromUtf8("QPushButton {\n"
        "	 background-color: rgb(152, 218, 255);\n"
        "   border: 1px solid rgb(34, 34, 34);\n"
        "color: black;\n"
        "}\n"
        "QPushButton:pressed {\n"
        "    background-color: rgb(0, 0, 0);\n"
        "}"));
                ButtonTan->setAutoExclusive(false);
                ButtonTan->setAutoDefault(false);
                Button5 = new QPushButton(Calculator);
                Button5->setObjectName(QString::fromUtf8("Button5"));
                Button5->setGeometry(QRect(350, 164, 60, 53));
                Button5->setMinimumSize(QSize(60, 10));
                Button5->setMaximumSize(QSize(60, 100));
                Button5->setFont(font);
                Button5->setStyleSheet(QString::fromUtf8("QPushButton {\n"
        "	 background-color: rgb(152, 218, 255);\n"
        "   border: 1px solid rgb(34, 34, 34);\n"
        "color: black;\n"
        "}\n"
        "QPushButton:pressed {\n"
        "    background-color: rgb(0, 0, 0);\n"
        "}"));
                ButtonAcos = new QPushButton(Calculator);
                ButtonAcos->setObjectName(QString::fromUtf8("ButtonAcos"));
                ButtonAcos->setGeometry(QRect(173, 216, 60, 53));
                ButtonAcos->setMinimumSize(QSize(60, 10));
                ButtonAcos->setMaximumSize(QSize(60, 100));
                ButtonAcos->setFont(font2);
                ButtonAcos->setStyleSheet(QString::fromUtf8("QPushButton {\n"
        "	 background-color: rgb(152, 218, 255);\n"
        "   border: 1px solid rgb(34, 34, 34);\n"
        "color: black;\n"
        "}\n"
        "QPushButton:pressed {\n"
        "    background-color: rgb(0, 0, 0);\n"
        "}"));
                Button3 = new QPushButton(Calculator);
                Button3->setObjectName(QString::fromUtf8("Button3"));
                Button3->setGeometry(QRect(409, 216, 60, 53));
                Button3->setMinimumSize(QSize(60, 10));
                Button3->setMaximumSize(QSize(60, 100));
                Button3->setFont(font);
                Button3->setStyleSheet(QString::fromUtf8("QPushButton {\n"
        "	 background-color: rgb(152, 218, 255);\n"
        "   border: 1px solid rgb(34, 34, 34);\n"
        "color: black;\n"
        "}\n"
        "QPushButton:pressed {\n"
        "    background-color: rgb(0, 0, 0);\n"
        "}"));
                Button8 = new QPushButton(Calculator);
                Button8->setObjectName(QString::fromUtf8("Button8"));
                Button8->setGeometry(QRect(350, 112, 60, 53));
                Button8->setMinimumSize(QSize(60, 10));
                Button8->setMaximumSize(QSize(60, 100));
                Button8->setFont(font);
                Button8->setStyleSheet(QString::fromUtf8("QPushButton {\n"
        "	 background-color: rgb(152, 218, 255);\n"
        "   border: 1px solid rgb(34, 34, 34);\n"
        "color: black;\n"
        "}\n"
        "QPushButton:pressed {\n"
        "    background-color: rgb(0, 0, 0);\n"
        "}"));
                Button0 = new QPushButton(Calculator);
                Button0->setObjectName(QString::fromUtf8("Button0"));
                Button0->setGeometry(QRect(291, 268, 119, 53));
                Button0->setMinimumSize(QSize(119, 10));
                Button0->setMaximumSize(QSize(119, 100));
                Button0->setFont(font);
                Button0->setStyleSheet(QString::fromUtf8("QPushButton {\n"
        "	 background-color: rgb(152, 218, 255);\n"
        "   border: 1px solid rgb(34, 34, 34);\n"
        "color: black;\n"
        "}\n"
        "QPushButton:pressed {\n"
        "    background-color: rgb(0, 0, 0);\n"
        "}"));
                ButtonPow = new QPushButton(Calculator);
                ButtonPow->setObjectName(QString::fromUtf8("ButtonPow"));
                ButtonPow->setGeometry(QRect(232, 112, 60, 53));
                ButtonPow->setMinimumSize(QSize(60, 10));
                ButtonPow->setMaximumSize(QSize(60, 100));
                ButtonPow->setFont(font2);
                ButtonPow->setStyleSheet(QString::fromUtf8("QPushButton {\n"
        "	 background-color: rgb(152, 218, 255);\n"
        "   border: 1px solid rgb(34, 34, 34);\n"
        "color: black;\n"
        "}\n"
        "QPushButton:pressed {\n"
        "    background-color: rgb(0, 0, 0);\n"
        "}"));
                ButtonFactorial = new QPushButton(Calculator);
                ButtonFactorial->setObjectName(QString::fromUtf8("ButtonFactorial"));
                ButtonFactorial->setGeometry(QRect(173, 112, 60, 53));
                ButtonFactorial->setMinimumSize(QSize(60, 10));
                ButtonFactorial->setMaximumSize(QSize(60, 100));
                ButtonFactorial->setFont(font2);
                ButtonFactorial->setStyleSheet(QString::fromUtf8("QPushButton {\n"
        "	 background-color: rgb(152, 218, 255);\n"
        "   border: 1px solid rgb(34, 34, 34);\n"
        "color: black;\n"
        "}\n"
        "QPushButton:pressed {\n"
        "    background-color: rgb(0, 0, 0);\n"
        "}"));
                ButtonAsin = new QPushButton(Calculator);
                ButtonAsin->setObjectName(QString::fromUtf8("ButtonAsin"));
                ButtonAsin->setGeometry(QRect(114, 216, 60, 53));
                ButtonAsin->setMinimumSize(QSize(60, 10));
                ButtonAsin->setMaximumSize(QSize(60, 100));
                ButtonAsin->setFont(font2);
                ButtonAsin->setStyleSheet(QString::fromUtf8("QPushButton {\n"
        "	 background-color: rgb(152, 218, 255);\n"
        "   border: 1px solid rgb(34, 34, 34);\n"
        "color: black;\n"
        "}\n"
        "QPushButton:pressed {\n"
        "    background-color: rgb(0, 0, 0);\n"
        "}"));
                ButtonSub = new QPushButton(Calculator);
                ButtonSub->setObjectName(QString::fromUtf8("ButtonSub"));
                ButtonSub->setGeometry(QRect(468, 164, 60, 53));
                ButtonSub->setMinimumSize(QSize(60, 10));
                ButtonSub->setMaximumSize(QSize(60, 100));
                ButtonSub->setFont(font);
                ButtonSub->setStyleSheet(QString::fromUtf8("QPushButton {\n"
        "	 background-color: rgb(152, 218, 255);\n"
        "   border: 1px solid rgb(34, 34, 34);\n"
        "color: black;\n"
        "}\n"
        "QPushButton:pressed {\n"
        "    background-color: rgb(0, 0, 0);\n"
        "}"));
                ButtonLn = new QPushButton(Calculator);
                ButtonLn->setObjectName(QString::fromUtf8("ButtonLn"));
                ButtonLn->setGeometry(QRect(173, 164, 60, 53));
                ButtonLn->setMinimumSize(QSize(60, 10));
                ButtonLn->setMaximumSize(QSize(60, 100));
                ButtonLn->setFont(font2);
                ButtonLn->setStyleSheet(QString::fromUtf8("QPushButton {\n"
        "	 background-color: rgb(152, 218, 255);\n"
        "   border: 1px solid rgb(34, 34, 34);\n"
        "color: black;\n"
        "}\n"
        "QPushButton:pressed {\n"
        "    background-color: rgb(0, 0, 0);\n"
        "}"));
                ButtonAC = new QPushButton(Calculator);
                ButtonAC->setObjectName(QString::fromUtf8("ButtonAC"));
                ButtonAC->setGeometry(QRect(291, 60, 60, 53));
                ButtonAC->setMinimumSize(QSize(60, 10));
                ButtonAC->setMaximumSize(QSize(60, 100));
                ButtonAC->setFont(font1);
                ButtonAC->setStyleSheet(QString::fromUtf8("QPushButton {\n"
        "	 background-color: rgb(152, 218, 255);\n"
        "   border: 1px solid rgb(34, 34, 34);\n"
        "color: black;\n"
        "}\n"
        "QPushButton:pressed {\n"
        "    background-color: rgb(0, 0, 0);\n"
        "}"));
                ButtonCloseBracket = new QPushButton(Calculator);
                ButtonCloseBracket->setObjectName(QString::fromUtf8("ButtonCloseBracket"));
                ButtonCloseBracket->setGeometry(QRect(232, 60, 60, 53));
                ButtonCloseBracket->setMinimumSize(QSize(60, 10));
                ButtonCloseBracket->setMaximumSize(QSize(60, 100));
                ButtonCloseBracket->setFont(font2);
                ButtonCloseBracket->setStyleSheet(QString::fromUtf8("QPushButton {\n"
        "	 background-color: rgb(152, 218, 255);\n"
        "   border: 1px solid rgb(34, 34, 34);\n"
        "color: black;\n"
        "}\n"
        "QPushButton:pressed {\n"
        "    background-color: rgb(0, 0, 0);\n"
        "}"));
                ButtonMul = new QPushButton(Calculator);
                ButtonMul->setObjectName(QString::fromUtf8("ButtonMul"));
                ButtonMul->setGeometry(QRect(468, 112, 60, 53));
                ButtonMul->setMinimumSize(QSize(60, 10));
                ButtonMul->setMaximumSize(QSize(60, 100));
                ButtonMul->setFont(font);
                ButtonMul->setStyleSheet(QString::fromUtf8("QPushButton {\n"
        "	 background-color: rgb(152, 218, 255);\n"
        "   border: 1px solid rgb(34, 34, 34);\n"
        "color: black;\n"
        "}\n"
        "QPushButton:pressed {\n"
        "    background-color: rgb(0, 0, 0);\n"
        "}"));
                ButtonSin = new QPushButton(Calculator);
                ButtonSin->setObjectName(QString::fromUtf8("ButtonSin"));
                ButtonSin->setGeometry(QRect(114, 268, 60, 53));
                ButtonSin->setMinimumSize(QSize(60, 10));
                ButtonSin->setMaximumSize(QSize(60, 100));
                ButtonSin->setFont(font2);
                ButtonSin->setStyleSheet(QString::fromUtf8("QPushButton {\n"
        "	 background-color: rgb(152, 218, 255);\n"
        "   border: 1px solid rgb(34, 34, 34);\n"
        "color: black;\n"
        "}\n"
        "QPushButton:pressed {\n"
        "    background-color: rgb(0, 0, 0);\n"
        "}"));
                ButtonX = new QPushButton(Calculator);
                ButtonX->setObjectName(QString::fromUtf8("ButtonX"));
                ButtonX->setGeometry(QRect(114, 60, 60, 53));
                ButtonX->setMinimumSize(QSize(60, 10));
                ButtonX->setMaximumSize(QSize(60, 100));
                ButtonX->setFont(font2);
                ButtonX->setStyleSheet(QString::fromUtf8("QPushButton {\n"
        "	 background-color: rgb(152, 218, 255);\n"
        "   border: 1px solid rgb(34, 34, 34);\n"
        "color: black;\n"
        "}\n"
        "QPushButton:pressed {\n"
        "    background-color: rgb(0, 0, 0);\n"
        "}"));
                Button2 = new QPushButton(Calculator);
                Button2->setObjectName(QString::fromUtf8("Button2"));
                Button2->setGeometry(QRect(350, 216, 60, 53));
                Button2->setMinimumSize(QSize(60, 10));
                Button2->setMaximumSize(QSize(60, 100));
                Button2->setFont(font);
                Button2->setStyleSheet(QString::fromUtf8("QPushButton {\n"
        "	 background-color: rgb(152, 218, 255);\n"
        "   border: 1px solid rgb(34, 34, 34);\n"
        "color: black;\n"
        "}\n"
        "QPushButton:pressed {\n"
        "    background-color: rgb(0, 0, 0);\n"
        "}"));
                Button9 = new QPushButton(Calculator);
                Button9->setObjectName(QString::fromUtf8("Button9"));
                Button9->setGeometry(QRect(409, 112, 60, 53));
                Button9->setMinimumSize(QSize(60, 10));
                Button9->setMaximumSize(QSize(60, 100));
                Button9->setFont(font);
                Button9->setStyleSheet(QString::fromUtf8("QPushButton {\n"
        "	 background-color: rgb(152, 218, 255);\n"
        "   border: 1px solid rgb(34, 34, 34);\n"
        "color: black;\n"
        "}\n"
        "QPushButton:pressed {\n"
        "    background-color: rgb(0, 0, 0);\n"
        "}"));
                Button4 = new QPushButton(Calculator);
                Button4->setObjectName(QString::fromUtf8("Button4"));
                Button4->setGeometry(QRect(291, 164, 60, 53));
                Button4->setMinimumSize(QSize(60, 10));
                Button4->setMaximumSize(QSize(60, 100));
                Button4->setFont(font);
                Button4->setStyleSheet(QString::fromUtf8("QPushButton {\n"
        "	 background-color: rgb(152, 218, 255);\n"
        "   border: 1px solid rgb(34, 34, 34);\n"
        "color: black;\n"
        "}\n"
        "QPushButton:pressed {\n"
        "    background-color: rgb(0, 0, 0);\n"
        "}"));
                ButtonAtan = new QPushButton(Calculator);
                ButtonAtan->setObjectName(QString::fromUtf8("ButtonAtan"));
                ButtonAtan->setGeometry(QRect(232, 216, 60, 53));
                ButtonAtan->setMinimumSize(QSize(60, 10));
                ButtonAtan->setMaximumSize(QSize(60, 100));
                ButtonAtan->setFont(font2);
                ButtonAtan->setStyleSheet(QString::fromUtf8("QPushButton {\n"
        "	 background-color: rgb(152, 218, 255);\n"
        "   border: 1px solid rgb(34, 34, 34);\n"
        "color: black;\n"
        "}\n"
        "QPushButton:pressed {\n"
        "    background-color: rgb(0, 0, 0);\n"
        "}"));
                ButtonSqrt = new QPushButton(Calculator);
                ButtonSqrt->setObjectName(QString::fromUtf8("ButtonSqrt"));
                ButtonSqrt->setGeometry(QRect(232, 164, 60, 53));
                ButtonSqrt->setMinimumSize(QSize(60, 10));
                ButtonSqrt->setMaximumSize(QSize(60, 100));
                ButtonSqrt->setFont(font2);
                ButtonSqrt->setStyleSheet(QString::fromUtf8("QPushButton {\n"
        "	 background-color: rgb(152, 218, 255);\n"
        "   border: 1px solid rgb(34, 34, 34);\n"
        "color: black;\n"
        "}\n"
        "QPushButton:pressed {\n"
        "    background-color: rgb(0, 0, 0);\n"
        "}"));
                Button7 = new QPushButton(Calculator);
                Button7->setObjectName(QString::fromUtf8("Button7"));
                Button7->setGeometry(QRect(291, 112, 60, 53));
                Button7->setMinimumSize(QSize(60, 10));
                Button7->setMaximumSize(QSize(60, 100));
                Button7->setFont(font);
                Button7->setStyleSheet(QString::fromUtf8("QPushButton {\n"
        "	 background-color: rgb(152, 218, 255);\n"
        "   border: 1px solid rgb(34, 34, 34);\n"
        "color: black;\n"
        "}\n"
        "QPushButton:pressed {\n"
        "    background-color: rgb(0, 0, 0);\n"
        "}"));
                ButtonSum = new QPushButton(Calculator);
                ButtonSum->setObjectName(QString::fromUtf8("ButtonSum"));
                ButtonSum->setGeometry(QRect(468, 216, 60, 53));
                ButtonSum->setMinimumSize(QSize(60, 10));
                ButtonSum->setMaximumSize(QSize(60, 100));
                ButtonSum->setFont(font);
                ButtonSum->setStyleSheet(QString::fromUtf8("QPushButton {\n"
        "	 background-color: rgb(152, 218, 255);\n"
        "   border: 1px solid rgb(34, 34, 34);\n"
        "color: black;\n"
        "}\n"
        "QPushButton:pressed {\n"
        "    background-color: rgb(0, 0, 0);\n"
        "}"));
                Button6 = new QPushButton(Calculator);
                Button6->setObjectName(QString::fromUtf8("Button6"));
                Button6->setGeometry(QRect(409, 164, 60, 53));
                Button6->setMinimumSize(QSize(60, 10));
                Button6->setMaximumSize(QSize(60, 100));
                Button6->setFont(font);
                Button6->setStyleSheet(QString::fromUtf8("QPushButton {\n"
        "	 background-color: rgb(152, 218, 255);\n"
        "   border: 1px solid rgb(34, 34, 34);\n"
        "color: black;\n"
        "}\n"
        "QPushButton:pressed {\n"
        "    background-color: rgb(0, 0, 0);\n"
        "}"));
                ButtonDot = new QPushButton(Calculator);
                ButtonDot->setObjectName(QString::fromUtf8("ButtonDot"));
                ButtonDot->setGeometry(QRect(409, 268, 60, 53));
                ButtonDot->setMinimumSize(QSize(60, 10));
                ButtonDot->setMaximumSize(QSize(60, 100));
                ButtonDot->setFont(font);
                ButtonDot->setStyleSheet(QString::fromUtf8("QPushButton {\n"
        "	 background-color: rgb(152, 218, 255);\n"
        "   border: 1px solid rgb(34, 34, 34);\n"
        "color: black;\n"
        "}\n"
        "QPushButton:pressed {\n"
        "    background-color: rgb(0, 0, 0);\n"
        "}"));
                Button1 = new QPushButton(Calculator);
                Button1->setObjectName(QString::fromUtf8("Button1"));
                Button1->setGeometry(QRect(291, 216, 60, 53));
                Button1->setMinimumSize(QSize(60, 10));
                Button1->setMaximumSize(QSize(60, 100));
                Button1->setFont(font);
                Button1->setStyleSheet(QString::fromUtf8("QPushButton {\n"
        "	 background-color: rgb(152, 218, 255);\n"
        "   border: 1px solid rgb(34, 34, 34);\n"
        "color: black;\n"
        "}\n"
        "QPushButton:pressed {\n"
        "    background-color: rgb(0, 0, 0);\n"
        "}"));
                ButtonOpenBracket = new QPushButton(Calculator);
                ButtonOpenBracket->setObjectName(QString::fromUtf8("ButtonOpenBracket"));
                ButtonOpenBracket->setGeometry(QRect(173, 60, 60, 53));
                ButtonOpenBracket->setMinimumSize(QSize(60, 10));
                ButtonOpenBracket->setMaximumSize(QSize(60, 100));
                ButtonOpenBracket->setFont(font2);
                ButtonOpenBracket->setStyleSheet(QString::fromUtf8("QPushButton {\n"
        "	 background-color: rgb(152, 218, 255);\n"
        "   border: 1px solid rgb(34, 34, 34);\n"
        "color: black;\n"
        "}\n"
        "QPushButton:pressed {\n"
        "    background-color: rgb(0, 0, 0);\n"
        "}"));
                ButtonMod = new QPushButton(Calculator);
                ButtonMod->setObjectName(QString::fromUtf8("ButtonMod"));
                ButtonMod->setGeometry(QRect(114, 112, 60, 53));
                ButtonMod->setMinimumSize(QSize(60, 10));
                ButtonMod->setMaximumSize(QSize(60, 100));
                ButtonMod->setFont(font2);
                ButtonMod->setStyleSheet(QString::fromUtf8("QPushButton {\n"
        "	 background-color: rgb(152, 218, 255);\n"
        "   border: 1px solid rgb(34, 34, 34);\n"
        "color: black;\n"
        "}\n"
        "QPushButton:pressed {\n"
        "    background-color: rgb(0, 0, 0);\n"
        "}"));
                ButtonDiv = new QPushButton(Calculator);
                ButtonDiv->setObjectName(QString::fromUtf8("ButtonDiv"));
                ButtonDiv->setGeometry(QRect(468, 60, 60, 53));
                ButtonDiv->setMinimumSize(QSize(60, 10));
                ButtonDiv->setMaximumSize(QSize(60, 100));
                ButtonDiv->setFont(font);
                ButtonDiv->setStyleSheet(QString::fromUtf8("QPushButton {\n"
        "	 background-color: rgb(152, 218, 255);\n"
        "   border: 1px solid rgb(34, 34, 34);\n"
        "color: black;\n"
        "}\n"
        "QPushButton:pressed {\n"
        "    background-color: rgb(0, 0, 0);\n"
        "}"));
                LabelInput = new QLabel(Calculator);
                LabelInput->setObjectName(QString::fromUtf8("LabelInput"));
                LabelInput->setGeometry(QRect(120, 0, 412, 62));
                QFont font3;
                font3.setPointSize(25);
                font3.setBold(true);
                LabelInput->setFont(font3);
                LabelInput->setStyleSheet(QString::fromUtf8("background-color:white;"));
                MainTab->addTab(Calculator, QString());
                CreditCalc = new QWidget();
                CreditCalc->setObjectName(QString::fromUtf8("CreditCalc"));
                MainTab->addTab(CreditCalc, QString());
                DepositCalc = new QWidget();
                DepositCalc->setObjectName(QString::fromUtf8("DepositCalc"));
                MainTab->addTab(DepositCalc, QString());

                RetranslateUI();

                MainTab->setCurrentIndex(0);

                QMetaObject::connectSlotsByName(window);
    }
};

#endif // WINUI_H
