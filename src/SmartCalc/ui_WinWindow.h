/********************************************************************************
** Form generated from reading UI file 'WinWindow.ui'
**
** Created by: Qt User Interface Compiler version 6.2.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WINWINDOW_H
#define UI_WINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_WinWindow
{
public:
    QWidget *centralwidget;
    QPushButton *pushButton_open_bracket;
    QPushButton *pushButton_tan;
    QPushButton *pushButton_0;
    QPushButton *pushButton_AC;
    QPushButton *pushButton_grafik;
    QPushButton *pushButton_eq;
    QPushButton *pushButton_dot;
    QPushButton *pushButton_acos;
    QPushButton *pushButton_atan;
    QPushButton *pushButton_div;
    QPushButton *pushButton_cos;
    QPushButton *pushButton_1;
    QPushButton *pushButton_mul;
    QPushButton *pushButton_4;
    QPushButton *pushButton_close_bracket;
    QPushButton *pushButton_exp;
    QPushButton *pushButton_6;
    QPushButton *pushButton_log;
    QPushButton *pushButton_3;
    QPushButton *pushButton_sin;
    QPushButton *pushButton_5;
    QPushButton *pushButton_7;
    QPushButton *pushButton_2;
    QPushButton *pushButton_9;
    QPushButton *pushButton_x;
    QPushButton *pushButton_ln;
    QPushButton *pushButton_factorial;
    QPushButton *pushButton_sqrt;
    QPushButton *pushButton_sub;
    QPushButton *pushButton_mod;
    QPushButton *pushButton_sum;
    QPushButton *pushButton_8;
    QPushButton *pushButton_asin;
    QLabel *input;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *WinWindow)
    {
        if (WinWindow->objectName().isEmpty())
            WinWindow->setObjectName(QString::fromUtf8("WinWindow"));
        WinWindow->resize(800, 600);
        centralwidget = new QWidget(WinWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        pushButton_open_bracket = new QPushButton(centralwidget);
        pushButton_open_bracket->setObjectName(QString::fromUtf8("pushButton_open_bracket"));
        pushButton_open_bracket->setGeometry(QRect(233, 140, 60, 53));
        pushButton_open_bracket->setMinimumSize(QSize(60, 10));
        pushButton_open_bracket->setMaximumSize(QSize(60, 100));
        QFont font;
        font.setPointSize(18);
        pushButton_open_bracket->setFont(font);
        pushButton_open_bracket->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color: rgb(0, 255, 226);\n"
"	border: 1px solid rgb(34, 34, 34);\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: rgb(183, 238, 255);\n"
"}"));
        pushButton_tan = new QPushButton(centralwidget);
        pushButton_tan->setObjectName(QString::fromUtf8("pushButton_tan"));
        pushButton_tan->setGeometry(QRect(292, 348, 60, 53));
        pushButton_tan->setMinimumSize(QSize(60, 10));
        pushButton_tan->setMaximumSize(QSize(60, 100));
        pushButton_tan->setFont(font);
        pushButton_tan->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color: rgb(0, 255, 226);\n"
"	border: 1px solid rgb(34, 34, 34);\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: rgb(183, 238, 255);\n"
"}"));
        pushButton_tan->setAutoExclusive(false);
        pushButton_tan->setAutoDefault(false);
        pushButton_0 = new QPushButton(centralwidget);
        pushButton_0->setObjectName(QString::fromUtf8("pushButton_0"));
        pushButton_0->setGeometry(QRect(351, 348, 119, 53));
        pushButton_0->setMinimumSize(QSize(119, 10));
        pushButton_0->setMaximumSize(QSize(119, 100));
        QFont font1;
        font1.setPointSize(25);
        pushButton_0->setFont(font1);
        pushButton_0->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color: rgb(0, 255, 226);\n"
"	border: 1px solid rgb(34, 34, 34);\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: rgb(183, 238, 255);\n"
"}"));
        pushButton_AC = new QPushButton(centralwidget);
        pushButton_AC->setObjectName(QString::fromUtf8("pushButton_AC"));
        pushButton_AC->setGeometry(QRect(351, 140, 60, 53));
        pushButton_AC->setMinimumSize(QSize(60, 10));
        pushButton_AC->setMaximumSize(QSize(60, 100));
        QFont font2;
        font2.setPointSize(22);
        pushButton_AC->setFont(font2);
        pushButton_AC->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color: rgb(0, 255, 226);\n"
"	border: 1px solid rgb(34, 34, 34);\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: rgb(183, 238, 255);\n"
"}"));
        pushButton_grafik = new QPushButton(centralwidget);
        pushButton_grafik->setObjectName(QString::fromUtf8("pushButton_grafik"));
        pushButton_grafik->setGeometry(QRect(410, 140, 119, 53));
        pushButton_grafik->setMinimumSize(QSize(0, 10));
        pushButton_grafik->setMaximumSize(QSize(1000, 10000));
        pushButton_grafik->setFont(font2);
        pushButton_grafik->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color: rgb(0, 255, 226);\n"
"	border: 1px solid rgb(34, 34, 34);\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: rgb(183, 238, 255);\n"
"}"));
        pushButton_eq = new QPushButton(centralwidget);
        pushButton_eq->setObjectName(QString::fromUtf8("pushButton_eq"));
        pushButton_eq->setGeometry(QRect(528, 348, 60, 53));
        pushButton_eq->setMinimumSize(QSize(60, 10));
        pushButton_eq->setMaximumSize(QSize(60, 100));
        pushButton_eq->setFont(font1);
        pushButton_eq->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color: rgb(0, 255, 226);\n"
"	border: 1px solid rgb(34, 34, 34);\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: rgb(183, 238, 255);\n"
"}"));
        pushButton_dot = new QPushButton(centralwidget);
        pushButton_dot->setObjectName(QString::fromUtf8("pushButton_dot"));
        pushButton_dot->setGeometry(QRect(469, 348, 60, 53));
        pushButton_dot->setMinimumSize(QSize(60, 10));
        pushButton_dot->setMaximumSize(QSize(60, 100));
        pushButton_dot->setFont(font1);
        pushButton_dot->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color: rgb(0, 255, 226);\n"
"	border: 1px solid rgb(34, 34, 34);\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: rgb(183, 238, 255);\n"
"}"));
        pushButton_acos = new QPushButton(centralwidget);
        pushButton_acos->setObjectName(QString::fromUtf8("pushButton_acos"));
        pushButton_acos->setGeometry(QRect(233, 296, 60, 53));
        pushButton_acos->setMinimumSize(QSize(60, 10));
        pushButton_acos->setMaximumSize(QSize(60, 100));
        pushButton_acos->setFont(font);
        pushButton_acos->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color: rgb(0, 255, 226);\n"
"	border: 1px solid rgb(34, 34, 34);\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: rgb(183, 238, 255);\n"
"}"));
        pushButton_atan = new QPushButton(centralwidget);
        pushButton_atan->setObjectName(QString::fromUtf8("pushButton_atan"));
        pushButton_atan->setGeometry(QRect(292, 296, 60, 53));
        pushButton_atan->setMinimumSize(QSize(60, 10));
        pushButton_atan->setMaximumSize(QSize(60, 100));
        pushButton_atan->setFont(font);
        pushButton_atan->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color: rgb(0, 255, 226);\n"
"	border: 1px solid rgb(34, 34, 34);\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: rgb(183, 238, 255);\n"
"}"));
        pushButton_div = new QPushButton(centralwidget);
        pushButton_div->setObjectName(QString::fromUtf8("pushButton_div"));
        pushButton_div->setGeometry(QRect(528, 140, 60, 53));
        pushButton_div->setMinimumSize(QSize(60, 10));
        pushButton_div->setMaximumSize(QSize(60, 100));
        pushButton_div->setFont(font1);
        pushButton_div->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color: rgb(0, 255, 226);\n"
"	border: 1px solid rgb(34, 34, 34);\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: rgb(183, 238, 255);\n"
"}"));
        pushButton_cos = new QPushButton(centralwidget);
        pushButton_cos->setObjectName(QString::fromUtf8("pushButton_cos"));
        pushButton_cos->setGeometry(QRect(233, 348, 60, 53));
        pushButton_cos->setMinimumSize(QSize(60, 10));
        pushButton_cos->setMaximumSize(QSize(60, 100));
        pushButton_cos->setFont(font);
        pushButton_cos->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color: rgb(0, 255, 226);\n"
"	border: 1px solid rgb(34, 34, 34);\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: rgb(183, 238, 255);\n"
"}"));
        pushButton_1 = new QPushButton(centralwidget);
        pushButton_1->setObjectName(QString::fromUtf8("pushButton_1"));
        pushButton_1->setGeometry(QRect(351, 296, 60, 53));
        pushButton_1->setMinimumSize(QSize(60, 10));
        pushButton_1->setMaximumSize(QSize(60, 100));
        pushButton_1->setFont(font1);
        pushButton_1->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color: rgb(0, 255, 226);\n"
"	border: 1px solid rgb(34, 34, 34);\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: rgb(183, 238, 255);\n"
"}"));
        pushButton_mul = new QPushButton(centralwidget);
        pushButton_mul->setObjectName(QString::fromUtf8("pushButton_mul"));
        pushButton_mul->setGeometry(QRect(528, 192, 60, 53));
        pushButton_mul->setMinimumSize(QSize(60, 10));
        pushButton_mul->setMaximumSize(QSize(60, 100));
        pushButton_mul->setFont(font1);
        pushButton_mul->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color: rgb(0, 255, 226);\n"
"	border: 1px solid rgb(34, 34, 34);\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: rgb(183, 238, 255);\n"
"}"));
        pushButton_4 = new QPushButton(centralwidget);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        pushButton_4->setGeometry(QRect(351, 244, 60, 53));
        pushButton_4->setMinimumSize(QSize(60, 10));
        pushButton_4->setMaximumSize(QSize(60, 100));
        pushButton_4->setFont(font1);
        pushButton_4->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color: rgb(0, 255, 226);\n"
"	border: 1px solid rgb(34, 34, 34);\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: rgb(183, 238, 255);\n"
"}"));
        pushButton_close_bracket = new QPushButton(centralwidget);
        pushButton_close_bracket->setObjectName(QString::fromUtf8("pushButton_close_bracket"));
        pushButton_close_bracket->setGeometry(QRect(292, 140, 60, 53));
        pushButton_close_bracket->setMinimumSize(QSize(60, 10));
        pushButton_close_bracket->setMaximumSize(QSize(60, 100));
        pushButton_close_bracket->setFont(font);
        pushButton_close_bracket->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color: rgb(0, 255, 226);\n"
"	border: 1px solid rgb(34, 34, 34);\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: rgb(183, 238, 255);\n"
"}"));
        pushButton_exp = new QPushButton(centralwidget);
        pushButton_exp->setObjectName(QString::fromUtf8("pushButton_exp"));
        pushButton_exp->setGeometry(QRect(292, 192, 60, 53));
        pushButton_exp->setMinimumSize(QSize(60, 10));
        pushButton_exp->setMaximumSize(QSize(60, 100));
        pushButton_exp->setFont(font);
        pushButton_exp->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color: rgb(0, 255, 226);\n"
"	border: 1px solid rgb(34, 34, 34);\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: rgb(183, 238, 255);\n"
"}"));
        pushButton_6 = new QPushButton(centralwidget);
        pushButton_6->setObjectName(QString::fromUtf8("pushButton_6"));
        pushButton_6->setGeometry(QRect(469, 244, 60, 53));
        pushButton_6->setMinimumSize(QSize(60, 10));
        pushButton_6->setMaximumSize(QSize(60, 100));
        pushButton_6->setFont(font1);
        pushButton_6->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color: rgb(0, 255, 226);\n"
"	border: 1px solid rgb(34, 34, 34);\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: rgb(183, 238, 255);\n"
"}"));
        pushButton_log = new QPushButton(centralwidget);
        pushButton_log->setObjectName(QString::fromUtf8("pushButton_log"));
        pushButton_log->setGeometry(QRect(174, 244, 60, 53));
        pushButton_log->setMinimumSize(QSize(60, 10));
        pushButton_log->setMaximumSize(QSize(60, 100));
        pushButton_log->setFont(font);
        pushButton_log->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color: rgb(0, 255, 226);\n"
"	border: 1px solid rgb(34, 34, 34);\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: rgb(183, 238, 255);\n"
"}"));
        pushButton_3 = new QPushButton(centralwidget);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setGeometry(QRect(469, 296, 60, 53));
        pushButton_3->setMinimumSize(QSize(60, 10));
        pushButton_3->setMaximumSize(QSize(60, 100));
        pushButton_3->setFont(font1);
        pushButton_3->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color: rgb(0, 255, 226);\n"
"	border: 1px solid rgb(34, 34, 34);\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: rgb(183, 238, 255);\n"
"}"));
        pushButton_sin = new QPushButton(centralwidget);
        pushButton_sin->setObjectName(QString::fromUtf8("pushButton_sin"));
        pushButton_sin->setGeometry(QRect(174, 348, 60, 53));
        pushButton_sin->setMinimumSize(QSize(60, 10));
        pushButton_sin->setMaximumSize(QSize(60, 100));
        pushButton_sin->setFont(font);
        pushButton_sin->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color: rgb(0, 255, 226);\n"
"	border: 1px solid rgb(34, 34, 34);\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: rgb(183, 238, 255);\n"
"}"));
        pushButton_5 = new QPushButton(centralwidget);
        pushButton_5->setObjectName(QString::fromUtf8("pushButton_5"));
        pushButton_5->setGeometry(QRect(410, 244, 60, 53));
        pushButton_5->setMinimumSize(QSize(60, 10));
        pushButton_5->setMaximumSize(QSize(60, 100));
        pushButton_5->setFont(font1);
        pushButton_5->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color: rgb(0, 255, 226);\n"
"	border: 1px solid rgb(34, 34, 34);\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: rgb(183, 238, 255);\n"
"}"));
        pushButton_7 = new QPushButton(centralwidget);
        pushButton_7->setObjectName(QString::fromUtf8("pushButton_7"));
        pushButton_7->setGeometry(QRect(351, 192, 60, 53));
        pushButton_7->setMinimumSize(QSize(60, 10));
        pushButton_7->setMaximumSize(QSize(60, 100));
        pushButton_7->setFont(font1);
        pushButton_7->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color: rgb(0, 255, 226);\n"
"	border: 1px solid rgb(34, 34, 34);\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: rgb(183, 238, 255);\n"
"}"));
        pushButton_2 = new QPushButton(centralwidget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(410, 296, 60, 53));
        pushButton_2->setMinimumSize(QSize(60, 10));
        pushButton_2->setMaximumSize(QSize(60, 100));
        pushButton_2->setFont(font1);
        pushButton_2->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color: rgb(0, 255, 226);\n"
"	border: 1px solid rgb(34, 34, 34);\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: rgb(183, 238, 255);\n"
"}"));
        pushButton_9 = new QPushButton(centralwidget);
        pushButton_9->setObjectName(QString::fromUtf8("pushButton_9"));
        pushButton_9->setGeometry(QRect(469, 192, 60, 53));
        pushButton_9->setMinimumSize(QSize(60, 10));
        pushButton_9->setMaximumSize(QSize(60, 100));
        pushButton_9->setFont(font1);
        pushButton_9->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color: rgb(0, 255, 226);\n"
"	border: 1px solid rgb(34, 34, 34);\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: rgb(183, 238, 255);\n"
"}"));
        pushButton_x = new QPushButton(centralwidget);
        pushButton_x->setObjectName(QString::fromUtf8("pushButton_x"));
        pushButton_x->setGeometry(QRect(174, 140, 60, 53));
        pushButton_x->setMinimumSize(QSize(60, 10));
        pushButton_x->setMaximumSize(QSize(60, 100));
        pushButton_x->setFont(font);
        pushButton_x->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color: rgb(0, 255, 226);\n"
"	border: 1px solid rgb(34, 34, 34);\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: rgb(183, 238, 255);\n"
"}"));
        pushButton_ln = new QPushButton(centralwidget);
        pushButton_ln->setObjectName(QString::fromUtf8("pushButton_ln"));
        pushButton_ln->setGeometry(QRect(233, 244, 60, 53));
        pushButton_ln->setMinimumSize(QSize(60, 10));
        pushButton_ln->setMaximumSize(QSize(60, 100));
        pushButton_ln->setFont(font);
        pushButton_ln->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color: rgb(0, 255, 226);\n"
"	border: 1px solid rgb(34, 34, 34);\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: rgb(183, 238, 255);\n"
"}"));
        pushButton_factorial = new QPushButton(centralwidget);
        pushButton_factorial->setObjectName(QString::fromUtf8("pushButton_factorial"));
        pushButton_factorial->setGeometry(QRect(233, 192, 60, 53));
        pushButton_factorial->setMinimumSize(QSize(60, 10));
        pushButton_factorial->setMaximumSize(QSize(60, 100));
        pushButton_factorial->setFont(font);
        pushButton_factorial->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color: rgb(0, 255, 226);\n"
"	border: 1px solid rgb(34, 34, 34);\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: rgb(183, 238, 255);\n"
"}"));
        pushButton_sqrt = new QPushButton(centralwidget);
        pushButton_sqrt->setObjectName(QString::fromUtf8("pushButton_sqrt"));
        pushButton_sqrt->setGeometry(QRect(292, 244, 60, 53));
        pushButton_sqrt->setMinimumSize(QSize(60, 10));
        pushButton_sqrt->setMaximumSize(QSize(60, 100));
        pushButton_sqrt->setFont(font);
        pushButton_sqrt->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color: rgb(0, 255, 226);\n"
"	border: 1px solid rgb(34, 34, 34);\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: rgb(183, 238, 255);\n"
"}"));
        pushButton_sub = new QPushButton(centralwidget);
        pushButton_sub->setObjectName(QString::fromUtf8("pushButton_sub"));
        pushButton_sub->setGeometry(QRect(528, 244, 60, 53));
        pushButton_sub->setMinimumSize(QSize(60, 10));
        pushButton_sub->setMaximumSize(QSize(60, 100));
        pushButton_sub->setFont(font1);
        pushButton_sub->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color: rgb(0, 255, 226);\n"
"	border: 1px solid rgb(34, 34, 34);\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: rgb(183, 238, 255);\n"
"}"));
        pushButton_mod = new QPushButton(centralwidget);
        pushButton_mod->setObjectName(QString::fromUtf8("pushButton_mod"));
        pushButton_mod->setGeometry(QRect(174, 192, 60, 53));
        pushButton_mod->setMinimumSize(QSize(60, 10));
        pushButton_mod->setMaximumSize(QSize(60, 100));
        pushButton_mod->setFont(font);
        pushButton_mod->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color: rgb(0, 255, 226);\n"
"	border: 1px solid rgb(34, 34, 34);\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: rgb(183, 238, 255);\n"
"}"));
        pushButton_sum = new QPushButton(centralwidget);
        pushButton_sum->setObjectName(QString::fromUtf8("pushButton_sum"));
        pushButton_sum->setGeometry(QRect(528, 296, 60, 53));
        pushButton_sum->setMinimumSize(QSize(60, 10));
        pushButton_sum->setMaximumSize(QSize(60, 100));
        pushButton_sum->setFont(font1);
        pushButton_sum->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color: rgb(0, 255, 226);\n"
"	border: 1px solid rgb(34, 34, 34);\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: rgb(183, 238, 255);\n"
"}"));
        pushButton_8 = new QPushButton(centralwidget);
        pushButton_8->setObjectName(QString::fromUtf8("pushButton_8"));
        pushButton_8->setGeometry(QRect(410, 192, 60, 53));
        pushButton_8->setMinimumSize(QSize(60, 10));
        pushButton_8->setMaximumSize(QSize(60, 100));
        pushButton_8->setFont(font1);
        pushButton_8->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color: rgb(0, 255, 226);\n"
"	border: 1px solid rgb(34, 34, 34);\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: rgb(183, 238, 255);\n"
"}"));
        pushButton_asin = new QPushButton(centralwidget);
        pushButton_asin->setObjectName(QString::fromUtf8("pushButton_asin"));
        pushButton_asin->setGeometry(QRect(174, 296, 60, 53));
        pushButton_asin->setMinimumSize(QSize(60, 10));
        pushButton_asin->setMaximumSize(QSize(60, 100));
        pushButton_asin->setFont(font);
        pushButton_asin->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color: rgb(0, 255, 226);\n"
"	border: 1px solid rgb(34, 34, 34);\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: rgb(183, 238, 255);\n"
"}"));
        input = new QLabel(centralwidget);
        input->setObjectName(QString::fromUtf8("input"));
        input->setGeometry(QRect(180, 70, 412, 62));
        QFont font3;
        font3.setPointSize(25);
        font3.setBold(true);
        input->setFont(font3);
        input->setStyleSheet(QString::fromUtf8(""));
        WinWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(WinWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 24));
        WinWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(WinWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        WinWindow->setStatusBar(statusbar);

        retranslateUi(WinWindow);

        QMetaObject::connectSlotsByName(WinWindow);
    } // setupUi

    void retranslateUi(QMainWindow *WinWindow)
    {
        WinWindow->setWindowTitle(QCoreApplication::translate("WinWindow", "MainWindow", nullptr));
        pushButton_open_bracket->setText(QCoreApplication::translate("WinWindow", "(", nullptr));
        pushButton_tan->setText(QCoreApplication::translate("WinWindow", "tan", nullptr));
        pushButton_0->setText(QCoreApplication::translate("WinWindow", "0", nullptr));
        pushButton_AC->setText(QCoreApplication::translate("WinWindow", "AC", nullptr));
        pushButton_grafik->setText(QCoreApplication::translate("WinWindow", "Graph", nullptr));
        pushButton_eq->setText(QCoreApplication::translate("WinWindow", "=", nullptr));
        pushButton_dot->setText(QCoreApplication::translate("WinWindow", ".", nullptr));
        pushButton_acos->setText(QCoreApplication::translate("WinWindow", "acos", nullptr));
        pushButton_atan->setText(QCoreApplication::translate("WinWindow", "atan", nullptr));
        pushButton_div->setText(QCoreApplication::translate("WinWindow", "/", nullptr));
        pushButton_cos->setText(QCoreApplication::translate("WinWindow", "cos", nullptr));
        pushButton_1->setText(QCoreApplication::translate("WinWindow", "1", nullptr));
        pushButton_mul->setText(QCoreApplication::translate("WinWindow", "*", nullptr));
        pushButton_4->setText(QCoreApplication::translate("WinWindow", "4", nullptr));
        pushButton_close_bracket->setText(QCoreApplication::translate("WinWindow", ")", nullptr));
        pushButton_exp->setText(QCoreApplication::translate("WinWindow", "^", nullptr));
        pushButton_6->setText(QCoreApplication::translate("WinWindow", "6", nullptr));
        pushButton_log->setText(QCoreApplication::translate("WinWindow", "log", nullptr));
        pushButton_3->setText(QCoreApplication::translate("WinWindow", "3", nullptr));
        pushButton_sin->setText(QCoreApplication::translate("WinWindow", "sin", nullptr));
        pushButton_5->setText(QCoreApplication::translate("WinWindow", "5", nullptr));
        pushButton_7->setText(QCoreApplication::translate("WinWindow", "7", nullptr));
        pushButton_2->setText(QCoreApplication::translate("WinWindow", "2", nullptr));
        pushButton_9->setText(QCoreApplication::translate("WinWindow", "9", nullptr));
        pushButton_x->setText(QCoreApplication::translate("WinWindow", "x", nullptr));
        pushButton_ln->setText(QCoreApplication::translate("WinWindow", "ln", nullptr));
        pushButton_factorial->setText(QCoreApplication::translate("WinWindow", "!", nullptr));
        pushButton_sqrt->setText(QCoreApplication::translate("WinWindow", "sqrt", nullptr));
        pushButton_sub->setText(QCoreApplication::translate("WinWindow", "-", nullptr));
        pushButton_mod->setText(QCoreApplication::translate("WinWindow", "mod", nullptr));
        pushButton_sum->setText(QCoreApplication::translate("WinWindow", "+", nullptr));
        pushButton_8->setText(QCoreApplication::translate("WinWindow", "8", nullptr));
        pushButton_asin->setText(QCoreApplication::translate("WinWindow", "asin", nullptr));
        input->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class WinWindow: public Ui_WinWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WINWINDOW_H
