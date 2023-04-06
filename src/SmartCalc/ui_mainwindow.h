/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.2.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QLineEdit *FunctionScope;
    QDoubleSpinBox *ScopeMin;
    QDoubleSpinBox *RangeMin;
    QLineEdit *XDef;
    QDoubleSpinBox *ScopeMax;
    QLineEdit *FunctionRange;
    QDoubleSpinBox *RangeMax;
    QDoubleSpinBox *input_x;
    QPushButton *pushButton_gra;
    QTabWidget *tabWidget;
    QWidget *Calculator;
    QPushButton *pushButton_eq;
    QPushButton *pushButton_grafik;
    QPushButton *pushButton_cos;
    QPushButton *pushButton_log;
    QPushButton *pushButton_tan;
    QPushButton *pushButton_5;
    QPushButton *pushButton_acos;
    QPushButton *pushButton_3;
    QPushButton *pushButton_8;
    QPushButton *pushButton_0;
    QPushButton *pushButton_exp;
    QPushButton *pushButton_factorial;
    QPushButton *pushButton_asin;
    QPushButton *pushButton_sub;
    QPushButton *pushButton_ln;
    QPushButton *pushButton_AC;
    QPushButton *pushButton_close_bracket;
    QPushButton *pushButton_mul;
    QPushButton *pushButton_sin;
    QPushButton *pushButton_x;
    QPushButton *pushButton_2;
    QPushButton *pushButton_9;
    QPushButton *pushButton_4;
    QPushButton *pushButton_atan;
    QPushButton *pushButton_sqrt;
    QPushButton *pushButton_7;
    QPushButton *pushButton_sum;
    QPushButton *pushButton_6;
    QPushButton *pushButton_dot;
    QPushButton *pushButton_1;
    QPushButton *pushButton_open_bracket;
    QPushButton *pushButton_mod;
    QPushButton *pushButton_div;
    QLabel *input;
    QWidget *CreditCalc;
    QWidget *DepositCalc;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1090, 773);
        MainWindow->setMinimumSize(QSize(412, 300));
        MainWindow->setMaximumSize(QSize(10000, 10000));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        FunctionScope = new QLineEdit(centralwidget);
        FunctionScope->setObjectName(QString::fromUtf8("FunctionScope"));
        FunctionScope->setGeometry(QRect(641, 73, 89, 22));
        QFont font;
        font.setPointSize(9);
        FunctionScope->setFont(font);
        FunctionScope->setLayoutDirection(Qt::LeftToRight);
        FunctionScope->setStyleSheet(QString::fromUtf8("background-color: rgb(56, 56, 56);\n"
"border: 1px solid rgb(34, 34, 34);\n"
""));
        FunctionScope->setAlignment(Qt::AlignCenter);
        FunctionScope->setReadOnly(true);
        ScopeMin = new QDoubleSpinBox(centralwidget);
        ScopeMin->setObjectName(QString::fromUtf8("ScopeMin"));
        ScopeMin->setGeometry(QRect(641, 92, 93, 22));
        ScopeMin->setFont(font);
        ScopeMin->setStyleSheet(QString::fromUtf8("background-color: rgb(56, 56, 56);\n"
"border: 1px solid rgb(34, 34, 34);\n"
""));
        ScopeMin->setAlignment(Qt::AlignCenter);
        ScopeMin->setButtonSymbols(QAbstractSpinBox::NoButtons);
        ScopeMin->setKeyboardTracking(true);
        ScopeMin->setMinimum(-1000000.000000000000000);
        ScopeMin->setMaximum(1000000.000000000000000);
        ScopeMin->setValue(-50.000000000000000);
        RangeMin = new QDoubleSpinBox(centralwidget);
        RangeMin->setObjectName(QString::fromUtf8("RangeMin"));
        RangeMin->setGeometry(QRect(729, 92, 93, 22));
        RangeMin->setFont(font);
        RangeMin->setStyleSheet(QString::fromUtf8("background-color: rgb(56, 56, 56);\n"
"border: 1px solid rgb(34, 34, 34);\n"
""));
        RangeMin->setAlignment(Qt::AlignCenter);
        RangeMin->setButtonSymbols(QAbstractSpinBox::NoButtons);
        RangeMin->setMinimum(-1000000.000000000000000);
        RangeMin->setMaximum(1000000.000000000000000);
        RangeMin->setValue(-2.000000000000000);
        XDef = new QLineEdit(centralwidget);
        XDef->setObjectName(QString::fromUtf8("XDef"));
        XDef->setGeometry(QRect(820, 73, 33, 29));
        QFont font1;
        font1.setPointSize(20);
        XDef->setFont(font1);
        XDef->setLayoutDirection(Qt::LeftToRight);
        XDef->setStyleSheet(QString::fromUtf8("background-color: rgb(56, 56, 56);\n"
"border: 1px solid rgb(34, 34, 34);\n"
""));
        XDef->setAlignment(Qt::AlignCenter);
        XDef->setReadOnly(true);
        ScopeMax = new QDoubleSpinBox(centralwidget);
        ScopeMax->setObjectName(QString::fromUtf8("ScopeMax"));
        ScopeMax->setGeometry(QRect(641, 110, 93, 22));
        ScopeMax->setFont(font);
        ScopeMax->setStyleSheet(QString::fromUtf8("background-color: rgb(56, 56, 56);\n"
"border: 1px solid rgb(34, 34, 34);\n"
""));
        ScopeMax->setAlignment(Qt::AlignCenter);
        ScopeMax->setButtonSymbols(QAbstractSpinBox::NoButtons);
        ScopeMax->setMinimum(-1000000.000000000000000);
        ScopeMax->setMaximum(1000000.000000000000000);
        ScopeMax->setValue(50.000000000000000);
        FunctionRange = new QLineEdit(centralwidget);
        FunctionRange->setObjectName(QString::fromUtf8("FunctionRange"));
        FunctionRange->setGeometry(QRect(729, 73, 93, 22));
        FunctionRange->setFont(font);
        FunctionRange->setLayoutDirection(Qt::LeftToRight);
        FunctionRange->setStyleSheet(QString::fromUtf8("background-color: rgb(56, 56, 56);\n"
"border: 1px solid rgb(34, 34, 34);\n"
""));
        FunctionRange->setAlignment(Qt::AlignCenter);
        FunctionRange->setReadOnly(true);
        RangeMax = new QDoubleSpinBox(centralwidget);
        RangeMax->setObjectName(QString::fromUtf8("RangeMax"));
        RangeMax->setGeometry(QRect(729, 111, 93, 21));
        RangeMax->setFont(font);
        RangeMax->setStyleSheet(QString::fromUtf8("background-color: rgb(56, 56, 56);\n"
"border: 1px solid rgb(34, 34, 34);\n"
""));
        RangeMax->setAlignment(Qt::AlignCenter);
        RangeMax->setButtonSymbols(QAbstractSpinBox::NoButtons);
        RangeMax->setMinimum(-1000000.000000000000000);
        RangeMax->setMaximum(1000000.000000000000000);
        RangeMax->setValue(2.000000000000000);
        input_x = new QDoubleSpinBox(centralwidget);
        input_x->setObjectName(QString::fromUtf8("input_x"));
        input_x->setGeometry(QRect(851, 73, 207, 29));
        input_x->setStyleSheet(QString::fromUtf8("background-color: rgb(56, 56, 56);\n"
"border: 1px solid rgb(34, 34, 34);\n"
""));
        input_x->setAlignment(Qt::AlignCenter);
        input_x->setButtonSymbols(QAbstractSpinBox::NoButtons);
        input_x->setMinimum(-1000000.000000000000000);
        input_x->setMaximum(1000000.000000000000000);
        input_x->setValue(0.000000000000000);
        pushButton_gra = new QPushButton(centralwidget);
        pushButton_gra->setObjectName(QString::fromUtf8("pushButton_gra"));
        pushButton_gra->setGeometry(QRect(820, 100, 237, 31));
        pushButton_gra->setMinimumSize(QSize(0, 0));
        pushButton_gra->setMaximumSize(QSize(100000, 100000));
        QFont font2;
        font2.setPointSize(15);
        pushButton_gra->setFont(font2);
        pushButton_gra->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color: rgb(56, 56, 56);\n"
"	border: 1px solid rgb(34, 34, 34);\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: rgba(162, 161, 166, 128);\n"
"}"));
        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setGeometry(QRect(150, 210, 651, 411));
        Calculator = new QWidget();
        Calculator->setObjectName(QString::fromUtf8("Calculator"));
        pushButton_eq = new QPushButton(Calculator);
        pushButton_eq->setObjectName(QString::fromUtf8("pushButton_eq"));
        pushButton_eq->setGeometry(QRect(468, 268, 60, 53));
        pushButton_eq->setMinimumSize(QSize(60, 10));
        pushButton_eq->setMaximumSize(QSize(60, 100));
        QFont font3;
        font3.setPointSize(25);
        pushButton_eq->setFont(font3);
        pushButton_eq->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	 background-color: rgb(226, 153, 57);\n"
"   border: 1px solid rgb(34, 34, 34);\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: rgba(255, 165, 2, 130)\n"
"}"));
        pushButton_grafik = new QPushButton(Calculator);
        pushButton_grafik->setObjectName(QString::fromUtf8("pushButton_grafik"));
        pushButton_grafik->setGeometry(QRect(350, 60, 119, 53));
        pushButton_grafik->setMinimumSize(QSize(0, 10));
        pushButton_grafik->setMaximumSize(QSize(1000, 10000));
        QFont font4;
        font4.setPointSize(22);
        pushButton_grafik->setFont(font4);
        pushButton_grafik->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	 background-color: rgb(226, 153, 57);\n"
"   border: 1px solid rgb(34, 34, 34);\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: rgba(255, 165, 2, 130)\n"
"}"));
        pushButton_cos = new QPushButton(Calculator);
        pushButton_cos->setObjectName(QString::fromUtf8("pushButton_cos"));
        pushButton_cos->setGeometry(QRect(173, 268, 60, 53));
        pushButton_cos->setMinimumSize(QSize(60, 10));
        pushButton_cos->setMaximumSize(QSize(60, 100));
        QFont font5;
        font5.setPointSize(18);
        pushButton_cos->setFont(font5);
        pushButton_cos->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color: rgb(56, 56, 56);\n"
"	border: 1px solid rgb(34, 34, 34);\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: rgba(162, 161, 166, 128);\n"
"}"));
        pushButton_log = new QPushButton(Calculator);
        pushButton_log->setObjectName(QString::fromUtf8("pushButton_log"));
        pushButton_log->setGeometry(QRect(114, 164, 60, 53));
        pushButton_log->setMinimumSize(QSize(60, 10));
        pushButton_log->setMaximumSize(QSize(60, 100));
        pushButton_log->setFont(font5);
        pushButton_log->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color: rgb(56, 56, 56);\n"
"	border: 1px solid rgb(34, 34, 34);\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: rgba(162, 161, 166, 128);\n"
"}"));
        pushButton_tan = new QPushButton(Calculator);
        pushButton_tan->setObjectName(QString::fromUtf8("pushButton_tan"));
        pushButton_tan->setGeometry(QRect(232, 268, 60, 53));
        pushButton_tan->setMinimumSize(QSize(60, 10));
        pushButton_tan->setMaximumSize(QSize(60, 100));
        pushButton_tan->setFont(font5);
        pushButton_tan->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color: rgb(56, 56, 56);\n"
"	border: 1px solid rgb(34, 34, 34);\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: rgba(162, 161, 166, 128);\n"
"}"));
        pushButton_tan->setAutoExclusive(false);
        pushButton_tan->setAutoDefault(false);
        pushButton_5 = new QPushButton(Calculator);
        pushButton_5->setObjectName(QString::fromUtf8("pushButton_5"));
        pushButton_5->setGeometry(QRect(350, 164, 60, 53));
        pushButton_5->setMinimumSize(QSize(60, 10));
        pushButton_5->setMaximumSize(QSize(60, 100));
        pushButton_5->setFont(font3);
        pushButton_5->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	 background-color: rgb(89, 89, 89);\n"
"   border: 1px solid rgb(34, 34, 34);\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: rgba(255, 255, 255, 128);\n"
"}"));
        pushButton_acos = new QPushButton(Calculator);
        pushButton_acos->setObjectName(QString::fromUtf8("pushButton_acos"));
        pushButton_acos->setGeometry(QRect(173, 216, 60, 53));
        pushButton_acos->setMinimumSize(QSize(60, 10));
        pushButton_acos->setMaximumSize(QSize(60, 100));
        pushButton_acos->setFont(font5);
        pushButton_acos->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color: rgb(56, 56, 56);\n"
"	border: 1px solid rgb(34, 34, 34);\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: rgba(162, 161, 166, 128);\n"
"}"));
        pushButton_3 = new QPushButton(Calculator);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setGeometry(QRect(409, 216, 60, 53));
        pushButton_3->setMinimumSize(QSize(60, 10));
        pushButton_3->setMaximumSize(QSize(60, 100));
        pushButton_3->setFont(font3);
        pushButton_3->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	 background-color: rgb(89, 89, 89);\n"
"   border: 1px solid rgb(34, 34, 34);\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: rgba(255, 255, 255, 128);\n"
"}"));
        pushButton_8 = new QPushButton(Calculator);
        pushButton_8->setObjectName(QString::fromUtf8("pushButton_8"));
        pushButton_8->setGeometry(QRect(350, 112, 60, 53));
        pushButton_8->setMinimumSize(QSize(60, 10));
        pushButton_8->setMaximumSize(QSize(60, 100));
        pushButton_8->setFont(font3);
        pushButton_8->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	 background-color: rgb(89, 89, 89);\n"
"   border: 1px solid rgb(34, 34, 34);\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: rgba(255, 255, 255, 128);\n"
"}"));
        pushButton_0 = new QPushButton(Calculator);
        pushButton_0->setObjectName(QString::fromUtf8("pushButton_0"));
        pushButton_0->setGeometry(QRect(291, 268, 119, 53));
        pushButton_0->setMinimumSize(QSize(119, 10));
        pushButton_0->setMaximumSize(QSize(119, 100));
        pushButton_0->setFont(font3);
        pushButton_0->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	 background-color: rgb(89, 89, 89);\n"
"   border: 1px solid rgb(34, 34, 34);\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: rgba(255, 255, 255, 128);\n"
"}"));
        pushButton_exp = new QPushButton(Calculator);
        pushButton_exp->setObjectName(QString::fromUtf8("pushButton_exp"));
        pushButton_exp->setGeometry(QRect(232, 112, 60, 53));
        pushButton_exp->setMinimumSize(QSize(60, 10));
        pushButton_exp->setMaximumSize(QSize(60, 100));
        pushButton_exp->setFont(font5);
        pushButton_exp->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color: rgb(56, 56, 56);\n"
"	border: 1px solid rgb(34, 34, 34);\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: rgba(162, 161, 166, 128);\n"
"}"));
        pushButton_factorial = new QPushButton(Calculator);
        pushButton_factorial->setObjectName(QString::fromUtf8("pushButton_factorial"));
        pushButton_factorial->setGeometry(QRect(173, 112, 60, 53));
        pushButton_factorial->setMinimumSize(QSize(60, 10));
        pushButton_factorial->setMaximumSize(QSize(60, 100));
        pushButton_factorial->setFont(font5);
        pushButton_factorial->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color: rgb(56, 56, 56);\n"
"	border: 1px solid rgb(34, 34, 34);\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: rgba(162, 161, 166, 128);\n"
"}"));
        pushButton_asin = new QPushButton(Calculator);
        pushButton_asin->setObjectName(QString::fromUtf8("pushButton_asin"));
        pushButton_asin->setGeometry(QRect(114, 216, 60, 53));
        pushButton_asin->setMinimumSize(QSize(60, 10));
        pushButton_asin->setMaximumSize(QSize(60, 100));
        pushButton_asin->setFont(font5);
        pushButton_asin->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color: rgb(56, 56, 56);\n"
"	border: 1px solid rgb(34, 34, 34);\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: rgba(162, 161, 166, 128);\n"
"}"));
        pushButton_sub = new QPushButton(Calculator);
        pushButton_sub->setObjectName(QString::fromUtf8("pushButton_sub"));
        pushButton_sub->setGeometry(QRect(468, 164, 60, 53));
        pushButton_sub->setMinimumSize(QSize(60, 10));
        pushButton_sub->setMaximumSize(QSize(60, 100));
        pushButton_sub->setFont(font3);
        pushButton_sub->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	 background-color: rgb(226, 153, 57);\n"
"   border: 1px solid rgb(34, 34, 34);\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: rgba(255, 165, 2, 130)\n"
"}"));
        pushButton_ln = new QPushButton(Calculator);
        pushButton_ln->setObjectName(QString::fromUtf8("pushButton_ln"));
        pushButton_ln->setGeometry(QRect(173, 164, 60, 53));
        pushButton_ln->setMinimumSize(QSize(60, 10));
        pushButton_ln->setMaximumSize(QSize(60, 100));
        pushButton_ln->setFont(font5);
        pushButton_ln->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color: rgb(56, 56, 56);\n"
"	border: 1px solid rgb(34, 34, 34);\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: rgba(162, 161, 166, 128);\n"
"}"));
        pushButton_AC = new QPushButton(Calculator);
        pushButton_AC->setObjectName(QString::fromUtf8("pushButton_AC"));
        pushButton_AC->setGeometry(QRect(291, 60, 60, 53));
        pushButton_AC->setMinimumSize(QSize(60, 10));
        pushButton_AC->setMaximumSize(QSize(60, 100));
        pushButton_AC->setFont(font4);
        pushButton_AC->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	 background-color: rgb(226, 153, 57);\n"
"   border: 1px solid rgb(34, 34, 34);\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: rgba(255, 165, 2, 130)\n"
"}"));
        pushButton_close_bracket = new QPushButton(Calculator);
        pushButton_close_bracket->setObjectName(QString::fromUtf8("pushButton_close_bracket"));
        pushButton_close_bracket->setGeometry(QRect(232, 60, 60, 53));
        pushButton_close_bracket->setMinimumSize(QSize(60, 10));
        pushButton_close_bracket->setMaximumSize(QSize(60, 100));
        pushButton_close_bracket->setFont(font5);
        pushButton_close_bracket->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color: rgb(56, 56, 56);\n"
"	border: 1px solid rgb(34, 34, 34);\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: rgba(162, 161, 166, 128);\n"
"}"));
        pushButton_mul = new QPushButton(Calculator);
        pushButton_mul->setObjectName(QString::fromUtf8("pushButton_mul"));
        pushButton_mul->setGeometry(QRect(468, 112, 60, 53));
        pushButton_mul->setMinimumSize(QSize(60, 10));
        pushButton_mul->setMaximumSize(QSize(60, 100));
        pushButton_mul->setFont(font3);
        pushButton_mul->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	 background-color: rgb(226, 153, 57);\n"
"   border: 1px solid rgb(34, 34, 34);\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: rgba(255, 165, 2, 130)\n"
"}"));
        pushButton_sin = new QPushButton(Calculator);
        pushButton_sin->setObjectName(QString::fromUtf8("pushButton_sin"));
        pushButton_sin->setGeometry(QRect(114, 268, 60, 53));
        pushButton_sin->setMinimumSize(QSize(60, 10));
        pushButton_sin->setMaximumSize(QSize(60, 100));
        pushButton_sin->setFont(font5);
        pushButton_sin->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color: rgb(56, 56, 56);\n"
"	border: 1px solid rgb(34, 34, 34);\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: rgba(162, 161, 166, 128);\n"
"}"));
        pushButton_x = new QPushButton(Calculator);
        pushButton_x->setObjectName(QString::fromUtf8("pushButton_x"));
        pushButton_x->setGeometry(QRect(114, 60, 60, 53));
        pushButton_x->setMinimumSize(QSize(60, 10));
        pushButton_x->setMaximumSize(QSize(60, 100));
        pushButton_x->setFont(font5);
        pushButton_x->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color: rgb(56, 56, 56);\n"
"	border: 1px solid rgb(34, 34, 34);\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: rgba(162, 161, 166, 128);\n"
"}"));
        pushButton_2 = new QPushButton(Calculator);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(350, 216, 60, 53));
        pushButton_2->setMinimumSize(QSize(60, 10));
        pushButton_2->setMaximumSize(QSize(60, 100));
        pushButton_2->setFont(font3);
        pushButton_2->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	 background-color: rgb(89, 89, 89);\n"
"   border: 1px solid rgb(34, 34, 34);\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: rgba(255, 255, 255, 128);\n"
"}"));
        pushButton_9 = new QPushButton(Calculator);
        pushButton_9->setObjectName(QString::fromUtf8("pushButton_9"));
        pushButton_9->setGeometry(QRect(409, 112, 60, 53));
        pushButton_9->setMinimumSize(QSize(60, 10));
        pushButton_9->setMaximumSize(QSize(60, 100));
        pushButton_9->setFont(font3);
        pushButton_9->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	 background-color: rgb(89, 89, 89);\n"
"   border: 1px solid rgb(34, 34, 34);\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: rgba(255, 255, 255, 128);\n"
"}"));
        pushButton_4 = new QPushButton(Calculator);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        pushButton_4->setGeometry(QRect(291, 164, 60, 53));
        pushButton_4->setMinimumSize(QSize(60, 10));
        pushButton_4->setMaximumSize(QSize(60, 100));
        pushButton_4->setFont(font3);
        pushButton_4->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	 background-color: rgb(89, 89, 89);\n"
"   border: 1px solid rgb(34, 34, 34);\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: rgba(255, 255, 255, 128);\n"
"}"));
        pushButton_atan = new QPushButton(Calculator);
        pushButton_atan->setObjectName(QString::fromUtf8("pushButton_atan"));
        pushButton_atan->setGeometry(QRect(232, 216, 60, 53));
        pushButton_atan->setMinimumSize(QSize(60, 10));
        pushButton_atan->setMaximumSize(QSize(60, 100));
        pushButton_atan->setFont(font5);
        pushButton_atan->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color: rgb(56, 56, 56);\n"
"	border: 1px solid rgb(34, 34, 34);\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: rgba(162, 161, 166, 128);\n"
"}"));
        pushButton_sqrt = new QPushButton(Calculator);
        pushButton_sqrt->setObjectName(QString::fromUtf8("pushButton_sqrt"));
        pushButton_sqrt->setGeometry(QRect(232, 164, 60, 53));
        pushButton_sqrt->setMinimumSize(QSize(60, 10));
        pushButton_sqrt->setMaximumSize(QSize(60, 100));
        pushButton_sqrt->setFont(font5);
        pushButton_sqrt->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color: rgb(56, 56, 56);\n"
"	border: 1px solid rgb(34, 34, 34);\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: rgba(162, 161, 166, 128);\n"
"}"));
        pushButton_7 = new QPushButton(Calculator);
        pushButton_7->setObjectName(QString::fromUtf8("pushButton_7"));
        pushButton_7->setGeometry(QRect(291, 112, 60, 53));
        pushButton_7->setMinimumSize(QSize(60, 10));
        pushButton_7->setMaximumSize(QSize(60, 100));
        pushButton_7->setFont(font3);
        pushButton_7->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	 background-color: rgb(89, 89, 89);\n"
"   border: 1px solid rgb(34, 34, 34);\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: rgba(255, 255, 255, 128);\n"
"}"));
        pushButton_sum = new QPushButton(Calculator);
        pushButton_sum->setObjectName(QString::fromUtf8("pushButton_sum"));
        pushButton_sum->setGeometry(QRect(468, 216, 60, 53));
        pushButton_sum->setMinimumSize(QSize(60, 10));
        pushButton_sum->setMaximumSize(QSize(60, 100));
        pushButton_sum->setFont(font3);
        pushButton_sum->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	 background-color: rgb(226, 153, 57);\n"
"   border: 1px solid rgb(34, 34, 34);\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: rgba(255, 165, 2, 130)\n"
"}"));
        pushButton_6 = new QPushButton(Calculator);
        pushButton_6->setObjectName(QString::fromUtf8("pushButton_6"));
        pushButton_6->setGeometry(QRect(409, 164, 60, 53));
        pushButton_6->setMinimumSize(QSize(60, 10));
        pushButton_6->setMaximumSize(QSize(60, 100));
        pushButton_6->setFont(font3);
        pushButton_6->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	 background-color: rgb(89, 89, 89);\n"
"   border: 1px solid rgb(34, 34, 34);\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: rgba(255, 255, 255, 128);\n"
"}"));
        pushButton_dot = new QPushButton(Calculator);
        pushButton_dot->setObjectName(QString::fromUtf8("pushButton_dot"));
        pushButton_dot->setGeometry(QRect(409, 268, 60, 53));
        pushButton_dot->setMinimumSize(QSize(60, 10));
        pushButton_dot->setMaximumSize(QSize(60, 100));
        pushButton_dot->setFont(font3);
        pushButton_dot->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	 background-color: rgb(89, 89, 89);\n"
"   border: 1px solid rgb(34, 34, 34);\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: rgba(255, 255, 255, 128);\n"
"}"));
        pushButton_1 = new QPushButton(Calculator);
        pushButton_1->setObjectName(QString::fromUtf8("pushButton_1"));
        pushButton_1->setGeometry(QRect(291, 216, 60, 53));
        pushButton_1->setMinimumSize(QSize(60, 10));
        pushButton_1->setMaximumSize(QSize(60, 100));
        pushButton_1->setFont(font3);
        pushButton_1->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	 background-color: rgb(89, 89, 89);\n"
"   border: 1px solid rgb(34, 34, 34);\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: rgba(255, 255, 255, 128);\n"
"}"));
        pushButton_open_bracket = new QPushButton(Calculator);
        pushButton_open_bracket->setObjectName(QString::fromUtf8("pushButton_open_bracket"));
        pushButton_open_bracket->setGeometry(QRect(173, 60, 60, 53));
        pushButton_open_bracket->setMinimumSize(QSize(60, 10));
        pushButton_open_bracket->setMaximumSize(QSize(60, 100));
        pushButton_open_bracket->setFont(font5);
        pushButton_open_bracket->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color: rgb(56, 56, 56);\n"
"	border: 1px solid rgb(34, 34, 34);\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: rgba(162, 161, 166, 128);\n"
"}"));
        pushButton_mod = new QPushButton(Calculator);
        pushButton_mod->setObjectName(QString::fromUtf8("pushButton_mod"));
        pushButton_mod->setGeometry(QRect(114, 112, 60, 53));
        pushButton_mod->setMinimumSize(QSize(60, 10));
        pushButton_mod->setMaximumSize(QSize(60, 100));
        pushButton_mod->setFont(font5);
        pushButton_mod->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color: rgb(56, 56, 56);\n"
"	border: 1px solid rgb(34, 34, 34);\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: rgba(162, 161, 166, 128);\n"
"}"));
        pushButton_div = new QPushButton(Calculator);
        pushButton_div->setObjectName(QString::fromUtf8("pushButton_div"));
        pushButton_div->setGeometry(QRect(468, 60, 60, 53));
        pushButton_div->setMinimumSize(QSize(60, 10));
        pushButton_div->setMaximumSize(QSize(60, 100));
        pushButton_div->setFont(font3);
        pushButton_div->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	 background-color: rgb(226, 153, 57);\n"
"   border: 1px solid rgb(34, 34, 34);\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: rgba(255, 165, 2, 130)\n"
"}"));
        input = new QLabel(Calculator);
        input->setObjectName(QString::fromUtf8("input"));
        input->setGeometry(QRect(120, 0, 412, 62));
        QFont font6;
        font6.setPointSize(25);
        font6.setBold(true);
        input->setFont(font6);
        input->setStyleSheet(QString::fromUtf8("background-color:black;"));
        tabWidget->addTab(Calculator, QString());
        CreditCalc = new QWidget();
        CreditCalc->setObjectName(QString::fromUtf8("CreditCalc"));
        tabWidget->addTab(CreditCalc, QString());
        DepositCalc = new QWidget();
        DepositCalc->setObjectName(QString::fromUtf8("DepositCalc"));
        tabWidget->addTab(DepositCalc, QString());
        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        FunctionScope->setText(QCoreApplication::translate("MainWindow", " Function scope", nullptr));
        XDef->setText(QCoreApplication::translate("MainWindow", "X", nullptr));
        FunctionRange->setText(QCoreApplication::translate("MainWindow", "Function range ", nullptr));
        pushButton_gra->setText(QCoreApplication::translate("MainWindow", "Graph", nullptr));
        pushButton_eq->setText(QCoreApplication::translate("MainWindow", "=", nullptr));
        pushButton_grafik->setText(QCoreApplication::translate("MainWindow", "Graph", nullptr));
        pushButton_cos->setText(QCoreApplication::translate("MainWindow", "cos", nullptr));
        pushButton_log->setText(QCoreApplication::translate("MainWindow", "log", nullptr));
        pushButton_tan->setText(QCoreApplication::translate("MainWindow", "tan", nullptr));
        pushButton_5->setText(QCoreApplication::translate("MainWindow", "5", nullptr));
        pushButton_acos->setText(QCoreApplication::translate("MainWindow", "acos", nullptr));
        pushButton_3->setText(QCoreApplication::translate("MainWindow", "3", nullptr));
        pushButton_8->setText(QCoreApplication::translate("MainWindow", "8", nullptr));
        pushButton_0->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        pushButton_exp->setText(QCoreApplication::translate("MainWindow", "^", nullptr));
        pushButton_factorial->setText(QCoreApplication::translate("MainWindow", "!", nullptr));
        pushButton_asin->setText(QCoreApplication::translate("MainWindow", "asin", nullptr));
        pushButton_sub->setText(QCoreApplication::translate("MainWindow", "-", nullptr));
        pushButton_ln->setText(QCoreApplication::translate("MainWindow", "ln", nullptr));
        pushButton_AC->setText(QCoreApplication::translate("MainWindow", "AC", nullptr));
        pushButton_close_bracket->setText(QCoreApplication::translate("MainWindow", ")", nullptr));
        pushButton_mul->setText(QCoreApplication::translate("MainWindow", "*", nullptr));
        pushButton_sin->setText(QCoreApplication::translate("MainWindow", "sin", nullptr));
        pushButton_x->setText(QCoreApplication::translate("MainWindow", "x", nullptr));
        pushButton_2->setText(QCoreApplication::translate("MainWindow", "2", nullptr));
        pushButton_9->setText(QCoreApplication::translate("MainWindow", "9", nullptr));
        pushButton_4->setText(QCoreApplication::translate("MainWindow", "4", nullptr));
        pushButton_atan->setText(QCoreApplication::translate("MainWindow", "atan", nullptr));
        pushButton_sqrt->setText(QCoreApplication::translate("MainWindow", "sqrt", nullptr));
        pushButton_7->setText(QCoreApplication::translate("MainWindow", "7", nullptr));
        pushButton_sum->setText(QCoreApplication::translate("MainWindow", "+", nullptr));
        pushButton_6->setText(QCoreApplication::translate("MainWindow", "6", nullptr));
        pushButton_dot->setText(QCoreApplication::translate("MainWindow", ".", nullptr));
        pushButton_1->setText(QCoreApplication::translate("MainWindow", "1", nullptr));
        pushButton_open_bracket->setText(QCoreApplication::translate("MainWindow", "(", nullptr));
        pushButton_mod->setText(QCoreApplication::translate("MainWindow", "mod", nullptr));
        pushButton_div->setText(QCoreApplication::translate("MainWindow", "/", nullptr));
        input->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(Calculator), QCoreApplication::translate("MainWindow", "Calculator", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(CreditCalc), QCoreApplication::translate("MainWindow", "Credit Calculator", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(DepositCalc), QCoreApplication::translate("MainWindow", "Deposit Calculator", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
