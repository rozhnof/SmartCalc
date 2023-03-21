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
#include <QtWidgets/QFrame>
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
    QTabWidget *tabWidget;
    QWidget *tabWidgetPage2;
    QPushButton *pushButton_acos;
    QPushButton *pushButton_8;
    QPushButton *pushButton_sub;
    QPushButton *pushButton_7;
    QPushButton *pushButton_6;
    QPushButton *pushButton_open_bracket;
    QPushButton *pushButton_asin;
    QPushButton *pushButton_sin;
    QPushButton *pushButton_3;
    QPushButton *pushButton_0;
    QPushButton *pushButton_dot;
    QPushButton *pushButton_log;
    QPushButton *pushButton_tan;
    QPushButton *pushButton_x;
    QPushButton *pushButton_atan;
    QPushButton *pushButton_1;
    QPushButton *pushButton_mul;
    QPushButton *pushButton_2;
    QPushButton *pushButton_eq;
    QPushButton *pushButton_mod;
    QPushButton *pushButton_sum;
    QPushButton *pushButton_ln;
    QPushButton *pushButton_C;
    QPushButton *pushButton_9;
    QPushButton *pushButton_factorial;
    QPushButton *pushButton_sqrt;
    QPushButton *pushButton_4;
    QPushButton *pushButton_close_bracket;
    QPushButton *pushButton_exp;
    QPushButton *pushButton_cos;
    QPushButton *pushButton_5;
    QPushButton *pushButton_AC;
    QPushButton *pushButton_div;
    QLabel *input;
    QPushButton *pushButton_grafik;
    QLineEdit *lineEdit_5;
    QLineEdit *lineEdit_4;
    QDoubleSpinBox *doubleSpinBox;
    QDoubleSpinBox *doubleSpinBox_2;
    QDoubleSpinBox *doubleSpinBox_4;
    QLineEdit *lineEdit_3;
    QDoubleSpinBox *doubleSpinBox_3;
    QDoubleSpinBox *input_x;
    QFrame *line;
    QFrame *line_2;
    QWidget *tabWidgetPage3;
    QPushButton *pushButton_CreditResult;
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_2;
    QLineEdit *monthly_payment;
    QLineEdit *overpayment;
    QLineEdit *total_payment;
    QLineEdit *monthly_payment_A;
    QLineEdit *monthly_payment_D;
    QLineEdit *overpayment_D;
    QLineEdit *overpayment_A;
    QLineEdit *total_payment_D;
    QLineEdit *total_payment_A;
    QLineEdit *loan_amount;
    QLineEdit *credit_term;
    QLineEdit *percent;
    QDoubleSpinBox *loan_amount_input;
    QDoubleSpinBox *credit_term_input;
    QDoubleSpinBox *percent_input;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(412, 409);
        MainWindow->setMinimumSize(QSize(412, 409));
        MainWindow->setMaximumSize(QSize(412, 409));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setGeometry(QRect(-4, 0, 419, 411));
        tabWidget->setMinimumSize(QSize(410, 340));
        tabWidget->setMaximumSize(QSize(600, 600));
        tabWidget->setFocusPolicy(Qt::TabFocus);
        tabWidget->setContextMenuPolicy(Qt::DefaultContextMenu);
        tabWidget->setTabPosition(QTabWidget::North);
        tabWidget->setTabShape(QTabWidget::Rounded);
        tabWidget->setUsesScrollButtons(false);
        tabWidgetPage2 = new QWidget();
        tabWidgetPage2->setObjectName(QString::fromUtf8("tabWidgetPage2"));
        pushButton_acos = new QPushButton(tabWidgetPage2);
        pushButton_acos->setObjectName(QString::fromUtf8("pushButton_acos"));
        pushButton_acos->setGeometry(QRect(59, 278, 60, 53));
        pushButton_acos->setMinimumSize(QSize(60, 10));
        pushButton_acos->setMaximumSize(QSize(60, 100));
        QFont font;
        font.setPointSize(18);
        pushButton_acos->setFont(font);
        pushButton_acos->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color: rgb(56, 56, 56);\n"
"	border: 1px solid rgb(34, 34, 34);\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: rgba(162, 161, 166, 128);\n"
"}"));
        pushButton_8 = new QPushButton(tabWidgetPage2);
        pushButton_8->setObjectName(QString::fromUtf8("pushButton_8"));
        pushButton_8->setGeometry(QRect(236, 174, 60, 53));
        pushButton_8->setMinimumSize(QSize(60, 10));
        pushButton_8->setMaximumSize(QSize(60, 100));
        QFont font1;
        font1.setPointSize(25);
        pushButton_8->setFont(font1);
        pushButton_8->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	 background-color: rgb(89, 89, 89);\n"
"   border: 1px solid rgb(34, 34, 34);\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: rgba(255, 255, 255, 128);\n"
"}"));
        pushButton_sub = new QPushButton(tabWidgetPage2);
        pushButton_sub->setObjectName(QString::fromUtf8("pushButton_sub"));
        pushButton_sub->setGeometry(QRect(354, 226, 60, 53));
        pushButton_sub->setMinimumSize(QSize(60, 10));
        pushButton_sub->setMaximumSize(QSize(60, 100));
        pushButton_sub->setFont(font1);
        pushButton_sub->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	 background-color: rgb(226, 153, 57);\n"
"   border: 1px solid rgb(34, 34, 34);\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: rgba(255, 165, 2, 130)\n"
"}"));
        pushButton_7 = new QPushButton(tabWidgetPage2);
        pushButton_7->setObjectName(QString::fromUtf8("pushButton_7"));
        pushButton_7->setGeometry(QRect(177, 174, 60, 53));
        pushButton_7->setMinimumSize(QSize(60, 10));
        pushButton_7->setMaximumSize(QSize(60, 100));
        pushButton_7->setFont(font1);
        pushButton_7->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	 background-color: rgb(89, 89, 89);\n"
"   border: 1px solid rgb(34, 34, 34);\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: rgba(255, 255, 255, 128);\n"
"}"));
        pushButton_6 = new QPushButton(tabWidgetPage2);
        pushButton_6->setObjectName(QString::fromUtf8("pushButton_6"));
        pushButton_6->setGeometry(QRect(295, 226, 60, 53));
        pushButton_6->setMinimumSize(QSize(60, 10));
        pushButton_6->setMaximumSize(QSize(60, 100));
        pushButton_6->setFont(font1);
        pushButton_6->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	 background-color: rgb(89, 89, 89);\n"
"   border: 1px solid rgb(34, 34, 34);\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: rgba(255, 255, 255, 128);\n"
"}"));
        pushButton_open_bracket = new QPushButton(tabWidgetPage2);
        pushButton_open_bracket->setObjectName(QString::fromUtf8("pushButton_open_bracket"));
        pushButton_open_bracket->setGeometry(QRect(59, 122, 60, 53));
        pushButton_open_bracket->setMinimumSize(QSize(60, 10));
        pushButton_open_bracket->setMaximumSize(QSize(60, 100));
        pushButton_open_bracket->setFont(font);
        pushButton_open_bracket->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color: rgb(56, 56, 56);\n"
"	border: 1px solid rgb(34, 34, 34);\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: rgba(162, 161, 166, 128);\n"
"}"));
        pushButton_asin = new QPushButton(tabWidgetPage2);
        pushButton_asin->setObjectName(QString::fromUtf8("pushButton_asin"));
        pushButton_asin->setGeometry(QRect(0, 278, 60, 53));
        pushButton_asin->setMinimumSize(QSize(60, 10));
        pushButton_asin->setMaximumSize(QSize(60, 100));
        pushButton_asin->setFont(font);
        pushButton_asin->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color: rgb(56, 56, 56);\n"
"	border: 1px solid rgb(34, 34, 34);\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: rgba(162, 161, 166, 128);\n"
"}"));
        pushButton_sin = new QPushButton(tabWidgetPage2);
        pushButton_sin->setObjectName(QString::fromUtf8("pushButton_sin"));
        pushButton_sin->setGeometry(QRect(0, 330, 60, 53));
        pushButton_sin->setMinimumSize(QSize(60, 10));
        pushButton_sin->setMaximumSize(QSize(60, 100));
        pushButton_sin->setFont(font);
        pushButton_sin->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color: rgb(56, 56, 56);\n"
"	border: 1px solid rgb(34, 34, 34);\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: rgba(162, 161, 166, 128);\n"
"}"));
        pushButton_3 = new QPushButton(tabWidgetPage2);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setGeometry(QRect(295, 278, 60, 53));
        pushButton_3->setMinimumSize(QSize(60, 10));
        pushButton_3->setMaximumSize(QSize(60, 100));
        pushButton_3->setFont(font1);
        pushButton_3->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	 background-color: rgb(89, 89, 89);\n"
"   border: 1px solid rgb(34, 34, 34);\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: rgba(255, 255, 255, 128);\n"
"}"));
        pushButton_0 = new QPushButton(tabWidgetPage2);
        pushButton_0->setObjectName(QString::fromUtf8("pushButton_0"));
        pushButton_0->setGeometry(QRect(177, 330, 119, 53));
        pushButton_0->setMinimumSize(QSize(119, 10));
        pushButton_0->setMaximumSize(QSize(119, 100));
        pushButton_0->setFont(font1);
        pushButton_0->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	 background-color: rgb(89, 89, 89);\n"
"   border: 1px solid rgb(34, 34, 34);\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: rgba(255, 255, 255, 128);\n"
"}"));
        pushButton_dot = new QPushButton(tabWidgetPage2);
        pushButton_dot->setObjectName(QString::fromUtf8("pushButton_dot"));
        pushButton_dot->setGeometry(QRect(295, 330, 60, 53));
        pushButton_dot->setMinimumSize(QSize(60, 10));
        pushButton_dot->setMaximumSize(QSize(60, 100));
        pushButton_dot->setFont(font1);
        pushButton_dot->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	 background-color: rgb(89, 89, 89);\n"
"   border: 1px solid rgb(34, 34, 34);\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: rgba(255, 255, 255, 128);\n"
"}"));
        pushButton_log = new QPushButton(tabWidgetPage2);
        pushButton_log->setObjectName(QString::fromUtf8("pushButton_log"));
        pushButton_log->setGeometry(QRect(0, 226, 60, 53));
        pushButton_log->setMinimumSize(QSize(60, 10));
        pushButton_log->setMaximumSize(QSize(60, 100));
        pushButton_log->setFont(font);
        pushButton_log->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color: rgb(56, 56, 56);\n"
"	border: 1px solid rgb(34, 34, 34);\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: rgba(162, 161, 166, 128);\n"
"}"));
        pushButton_tan = new QPushButton(tabWidgetPage2);
        pushButton_tan->setObjectName(QString::fromUtf8("pushButton_tan"));
        pushButton_tan->setGeometry(QRect(118, 330, 60, 53));
        pushButton_tan->setMinimumSize(QSize(60, 10));
        pushButton_tan->setMaximumSize(QSize(60, 100));
        pushButton_tan->setFont(font);
        pushButton_tan->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color: rgb(56, 56, 56);\n"
"	border: 1px solid rgb(34, 34, 34);\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: rgba(162, 161, 166, 128);\n"
"}"));
        pushButton_tan->setAutoExclusive(false);
        pushButton_tan->setAutoDefault(false);
        pushButton_x = new QPushButton(tabWidgetPage2);
        pushButton_x->setObjectName(QString::fromUtf8("pushButton_x"));
        pushButton_x->setGeometry(QRect(0, 122, 60, 53));
        pushButton_x->setMinimumSize(QSize(60, 10));
        pushButton_x->setMaximumSize(QSize(60, 100));
        pushButton_x->setFont(font);
        pushButton_x->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color: rgb(56, 56, 56);\n"
"	border: 1px solid rgb(34, 34, 34);\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: rgba(162, 161, 166, 128);\n"
"}"));
        pushButton_atan = new QPushButton(tabWidgetPage2);
        pushButton_atan->setObjectName(QString::fromUtf8("pushButton_atan"));
        pushButton_atan->setGeometry(QRect(118, 278, 60, 53));
        pushButton_atan->setMinimumSize(QSize(60, 10));
        pushButton_atan->setMaximumSize(QSize(60, 100));
        pushButton_atan->setFont(font);
        pushButton_atan->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color: rgb(56, 56, 56);\n"
"	border: 1px solid rgb(34, 34, 34);\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: rgba(162, 161, 166, 128);\n"
"}"));
        pushButton_1 = new QPushButton(tabWidgetPage2);
        pushButton_1->setObjectName(QString::fromUtf8("pushButton_1"));
        pushButton_1->setGeometry(QRect(177, 278, 60, 53));
        pushButton_1->setMinimumSize(QSize(60, 10));
        pushButton_1->setMaximumSize(QSize(60, 100));
        pushButton_1->setFont(font1);
        pushButton_1->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	 background-color: rgb(89, 89, 89);\n"
"   border: 1px solid rgb(34, 34, 34);\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: rgba(255, 255, 255, 128);\n"
"}"));
        pushButton_mul = new QPushButton(tabWidgetPage2);
        pushButton_mul->setObjectName(QString::fromUtf8("pushButton_mul"));
        pushButton_mul->setGeometry(QRect(354, 174, 60, 53));
        pushButton_mul->setMinimumSize(QSize(60, 10));
        pushButton_mul->setMaximumSize(QSize(60, 100));
        pushButton_mul->setFont(font1);
        pushButton_mul->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	 background-color: rgb(226, 153, 57);\n"
"   border: 1px solid rgb(34, 34, 34);\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: rgba(255, 165, 2, 130)\n"
"}"));
        pushButton_2 = new QPushButton(tabWidgetPage2);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(236, 278, 60, 53));
        pushButton_2->setMinimumSize(QSize(60, 10));
        pushButton_2->setMaximumSize(QSize(60, 100));
        pushButton_2->setFont(font1);
        pushButton_2->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	 background-color: rgb(89, 89, 89);\n"
"   border: 1px solid rgb(34, 34, 34);\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: rgba(255, 255, 255, 128);\n"
"}"));
        pushButton_eq = new QPushButton(tabWidgetPage2);
        pushButton_eq->setObjectName(QString::fromUtf8("pushButton_eq"));
        pushButton_eq->setGeometry(QRect(354, 330, 60, 53));
        pushButton_eq->setMinimumSize(QSize(60, 10));
        pushButton_eq->setMaximumSize(QSize(60, 100));
        pushButton_eq->setFont(font1);
        pushButton_eq->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	 background-color: rgb(226, 153, 57);\n"
"   border: 1px solid rgb(34, 34, 34);\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: rgba(255, 165, 2, 130)\n"
"}"));
        pushButton_mod = new QPushButton(tabWidgetPage2);
        pushButton_mod->setObjectName(QString::fromUtf8("pushButton_mod"));
        pushButton_mod->setGeometry(QRect(0, 174, 60, 53));
        pushButton_mod->setMinimumSize(QSize(60, 10));
        pushButton_mod->setMaximumSize(QSize(60, 100));
        pushButton_mod->setFont(font);
        pushButton_mod->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color: rgb(56, 56, 56);\n"
"	border: 1px solid rgb(34, 34, 34);\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: rgba(162, 161, 166, 128);\n"
"}"));
        pushButton_sum = new QPushButton(tabWidgetPage2);
        pushButton_sum->setObjectName(QString::fromUtf8("pushButton_sum"));
        pushButton_sum->setGeometry(QRect(354, 278, 60, 53));
        pushButton_sum->setMinimumSize(QSize(60, 10));
        pushButton_sum->setMaximumSize(QSize(60, 100));
        pushButton_sum->setFont(font1);
        pushButton_sum->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	 background-color: rgb(226, 153, 57);\n"
"   border: 1px solid rgb(34, 34, 34);\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: rgba(255, 165, 2, 130)\n"
"}"));
        pushButton_ln = new QPushButton(tabWidgetPage2);
        pushButton_ln->setObjectName(QString::fromUtf8("pushButton_ln"));
        pushButton_ln->setGeometry(QRect(59, 226, 60, 53));
        pushButton_ln->setMinimumSize(QSize(60, 10));
        pushButton_ln->setMaximumSize(QSize(60, 100));
        pushButton_ln->setFont(font);
        pushButton_ln->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color: rgb(56, 56, 56);\n"
"	border: 1px solid rgb(34, 34, 34);\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: rgba(162, 161, 166, 128);\n"
"}"));
        pushButton_C = new QPushButton(tabWidgetPage2);
        pushButton_C->setObjectName(QString::fromUtf8("pushButton_C"));
        pushButton_C->setGeometry(QRect(234, 122, 121, 53));
        pushButton_C->setMinimumSize(QSize(0, 10));
        pushButton_C->setMaximumSize(QSize(1000, 10000));
        QFont font2;
        font2.setPointSize(22);
        pushButton_C->setFont(font2);
        pushButton_C->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	 background-color: rgb(226, 153, 57);\n"
"   border: 1px solid rgb(34, 34, 34);\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: rgba(255, 165, 2, 130)\n"
"}"));
        pushButton_9 = new QPushButton(tabWidgetPage2);
        pushButton_9->setObjectName(QString::fromUtf8("pushButton_9"));
        pushButton_9->setGeometry(QRect(295, 174, 60, 53));
        pushButton_9->setMinimumSize(QSize(60, 10));
        pushButton_9->setMaximumSize(QSize(60, 100));
        pushButton_9->setFont(font1);
        pushButton_9->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	 background-color: rgb(89, 89, 89);\n"
"   border: 1px solid rgb(34, 34, 34);\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: rgba(255, 255, 255, 128);\n"
"}"));
        pushButton_factorial = new QPushButton(tabWidgetPage2);
        pushButton_factorial->setObjectName(QString::fromUtf8("pushButton_factorial"));
        pushButton_factorial->setGeometry(QRect(59, 174, 60, 53));
        pushButton_factorial->setMinimumSize(QSize(60, 10));
        pushButton_factorial->setMaximumSize(QSize(60, 100));
        pushButton_factorial->setFont(font);
        pushButton_factorial->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color: rgb(56, 56, 56);\n"
"	border: 1px solid rgb(34, 34, 34);\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: rgba(162, 161, 166, 128);\n"
"}"));
        pushButton_sqrt = new QPushButton(tabWidgetPage2);
        pushButton_sqrt->setObjectName(QString::fromUtf8("pushButton_sqrt"));
        pushButton_sqrt->setGeometry(QRect(118, 226, 60, 53));
        pushButton_sqrt->setMinimumSize(QSize(60, 10));
        pushButton_sqrt->setMaximumSize(QSize(60, 100));
        pushButton_sqrt->setFont(font);
        pushButton_sqrt->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color: rgb(56, 56, 56);\n"
"	border: 1px solid rgb(34, 34, 34);\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: rgba(162, 161, 166, 128);\n"
"}"));
        pushButton_4 = new QPushButton(tabWidgetPage2);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        pushButton_4->setGeometry(QRect(177, 226, 60, 53));
        pushButton_4->setMinimumSize(QSize(60, 10));
        pushButton_4->setMaximumSize(QSize(60, 100));
        pushButton_4->setFont(font1);
        pushButton_4->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	 background-color: rgb(89, 89, 89);\n"
"   border: 1px solid rgb(34, 34, 34);\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: rgba(255, 255, 255, 128);\n"
"}"));
        pushButton_close_bracket = new QPushButton(tabWidgetPage2);
        pushButton_close_bracket->setObjectName(QString::fromUtf8("pushButton_close_bracket"));
        pushButton_close_bracket->setGeometry(QRect(118, 122, 60, 53));
        pushButton_close_bracket->setMinimumSize(QSize(60, 10));
        pushButton_close_bracket->setMaximumSize(QSize(60, 100));
        pushButton_close_bracket->setFont(font);
        pushButton_close_bracket->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color: rgb(56, 56, 56);\n"
"	border: 1px solid rgb(34, 34, 34);\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: rgba(162, 161, 166, 128);\n"
"}"));
        pushButton_exp = new QPushButton(tabWidgetPage2);
        pushButton_exp->setObjectName(QString::fromUtf8("pushButton_exp"));
        pushButton_exp->setGeometry(QRect(118, 174, 60, 53));
        pushButton_exp->setMinimumSize(QSize(60, 10));
        pushButton_exp->setMaximumSize(QSize(60, 100));
        pushButton_exp->setFont(font);
        pushButton_exp->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color: rgb(56, 56, 56);\n"
"	border: 1px solid rgb(34, 34, 34);\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: rgba(162, 161, 166, 128);\n"
"}"));
        pushButton_cos = new QPushButton(tabWidgetPage2);
        pushButton_cos->setObjectName(QString::fromUtf8("pushButton_cos"));
        pushButton_cos->setGeometry(QRect(59, 330, 60, 53));
        pushButton_cos->setMinimumSize(QSize(60, 10));
        pushButton_cos->setMaximumSize(QSize(60, 100));
        pushButton_cos->setFont(font);
        pushButton_cos->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color: rgb(56, 56, 56);\n"
"	border: 1px solid rgb(34, 34, 34);\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: rgba(162, 161, 166, 128);\n"
"}"));
        pushButton_5 = new QPushButton(tabWidgetPage2);
        pushButton_5->setObjectName(QString::fromUtf8("pushButton_5"));
        pushButton_5->setGeometry(QRect(236, 226, 60, 53));
        pushButton_5->setMinimumSize(QSize(60, 10));
        pushButton_5->setMaximumSize(QSize(60, 100));
        pushButton_5->setFont(font1);
        pushButton_5->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	 background-color: rgb(89, 89, 89);\n"
"   border: 1px solid rgb(34, 34, 34);\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: rgba(255, 255, 255, 128);\n"
"}"));
        pushButton_AC = new QPushButton(tabWidgetPage2);
        pushButton_AC->setObjectName(QString::fromUtf8("pushButton_AC"));
        pushButton_AC->setGeometry(QRect(177, 122, 60, 53));
        pushButton_AC->setMinimumSize(QSize(60, 10));
        pushButton_AC->setMaximumSize(QSize(60, 100));
        pushButton_AC->setFont(font2);
        pushButton_AC->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	 background-color: rgb(226, 153, 57);\n"
"   border: 1px solid rgb(34, 34, 34);\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: rgba(255, 165, 2, 130)\n"
"}"));
        pushButton_div = new QPushButton(tabWidgetPage2);
        pushButton_div->setObjectName(QString::fromUtf8("pushButton_div"));
        pushButton_div->setGeometry(QRect(354, 122, 60, 53));
        pushButton_div->setMinimumSize(QSize(60, 10));
        pushButton_div->setMaximumSize(QSize(60, 100));
        pushButton_div->setFont(font1);
        pushButton_div->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	 background-color: rgb(226, 153, 57);\n"
"   border: 1px solid rgb(34, 34, 34);\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: rgba(255, 165, 2, 130)\n"
"}"));
        input = new QLabel(tabWidgetPage2);
        input->setObjectName(QString::fromUtf8("input"));
        input->setGeometry(QRect(0, 0, 411, 61));
        QFont font3;
        font3.setPointSize(25);
        font3.setBold(true);
        input->setFont(font3);
        input->setStyleSheet(QString::fromUtf8(""));
        pushButton_grafik = new QPushButton(tabWidgetPage2);
        pushButton_grafik->setObjectName(QString::fromUtf8("pushButton_grafik"));
        pushButton_grafik->setGeometry(QRect(177, 92, 237, 31));
        pushButton_grafik->setMinimumSize(QSize(0, 0));
        pushButton_grafik->setMaximumSize(QSize(100000, 100000));
        QFont font4;
        font4.setPointSize(15);
        pushButton_grafik->setFont(font4);
        pushButton_grafik->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color: rgb(56, 56, 56);\n"
"	border: 1px solid rgb(34, 34, 34);\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: rgba(162, 161, 166, 128);\n"
"}"));
        lineEdit_5 = new QLineEdit(tabWidgetPage2);
        lineEdit_5->setObjectName(QString::fromUtf8("lineEdit_5"));
        lineEdit_5->setGeometry(QRect(177, 65, 33, 29));
        QFont font5;
        font5.setPointSize(20);
        lineEdit_5->setFont(font5);
        lineEdit_5->setLayoutDirection(Qt::LeftToRight);
        lineEdit_5->setStyleSheet(QString::fromUtf8("background-color: rgb(56, 56, 56);\n"
"border: 1px solid rgb(34, 34, 34);\n"
""));
        lineEdit_5->setAlignment(Qt::AlignCenter);
        lineEdit_5->setReadOnly(true);
        lineEdit_4 = new QLineEdit(tabWidgetPage2);
        lineEdit_4->setObjectName(QString::fromUtf8("lineEdit_4"));
        lineEdit_4->setGeometry(QRect(-2, 65, 89, 22));
        QFont font6;
        font6.setPointSize(9);
        lineEdit_4->setFont(font6);
        lineEdit_4->setLayoutDirection(Qt::LeftToRight);
        lineEdit_4->setStyleSheet(QString::fromUtf8("background-color: rgb(56, 56, 56);\n"
"border: 1px solid rgb(34, 34, 34);\n"
""));
        lineEdit_4->setAlignment(Qt::AlignCenter);
        lineEdit_4->setReadOnly(true);
        doubleSpinBox = new QDoubleSpinBox(tabWidgetPage2);
        doubleSpinBox->setObjectName(QString::fromUtf8("doubleSpinBox"));
        doubleSpinBox->setGeometry(QRect(-2, 84, 93, 22));
        doubleSpinBox->setFont(font6);
        doubleSpinBox->setStyleSheet(QString::fromUtf8("background-color: rgb(56, 56, 56);\n"
"border: 1px solid rgb(34, 34, 34);\n"
""));
        doubleSpinBox->setAlignment(Qt::AlignCenter);
        doubleSpinBox->setButtonSymbols(QAbstractSpinBox::NoButtons);
        doubleSpinBox->setKeyboardTracking(true);
        doubleSpinBox->setMinimum(-1000000.000000000000000);
        doubleSpinBox->setMaximum(1000000.000000000000000);
        doubleSpinBox->setValue(-50.000000000000000);
        doubleSpinBox_2 = new QDoubleSpinBox(tabWidgetPage2);
        doubleSpinBox_2->setObjectName(QString::fromUtf8("doubleSpinBox_2"));
        doubleSpinBox_2->setGeometry(QRect(-2, 102, 93, 22));
        doubleSpinBox_2->setFont(font6);
        doubleSpinBox_2->setStyleSheet(QString::fromUtf8("background-color: rgb(56, 56, 56);\n"
"border: 1px solid rgb(34, 34, 34);\n"
""));
        doubleSpinBox_2->setAlignment(Qt::AlignCenter);
        doubleSpinBox_2->setButtonSymbols(QAbstractSpinBox::NoButtons);
        doubleSpinBox_2->setMinimum(-1000000.000000000000000);
        doubleSpinBox_2->setMaximum(1000000.000000000000000);
        doubleSpinBox_2->setValue(50.000000000000000);
        doubleSpinBox_4 = new QDoubleSpinBox(tabWidgetPage2);
        doubleSpinBox_4->setObjectName(QString::fromUtf8("doubleSpinBox_4"));
        doubleSpinBox_4->setGeometry(QRect(86, 103, 93, 21));
        doubleSpinBox_4->setFont(font6);
        doubleSpinBox_4->setStyleSheet(QString::fromUtf8("background-color: rgb(56, 56, 56);\n"
"border: 1px solid rgb(34, 34, 34);\n"
""));
        doubleSpinBox_4->setAlignment(Qt::AlignCenter);
        doubleSpinBox_4->setButtonSymbols(QAbstractSpinBox::NoButtons);
        doubleSpinBox_4->setMinimum(-1000000.000000000000000);
        doubleSpinBox_4->setMaximum(1000000.000000000000000);
        doubleSpinBox_4->setValue(2.000000000000000);
        lineEdit_3 = new QLineEdit(tabWidgetPage2);
        lineEdit_3->setObjectName(QString::fromUtf8("lineEdit_3"));
        lineEdit_3->setGeometry(QRect(86, 65, 93, 22));
        lineEdit_3->setFont(font6);
        lineEdit_3->setLayoutDirection(Qt::LeftToRight);
        lineEdit_3->setStyleSheet(QString::fromUtf8("background-color: rgb(56, 56, 56);\n"
"border: 1px solid rgb(34, 34, 34);\n"
""));
        lineEdit_3->setAlignment(Qt::AlignCenter);
        lineEdit_3->setReadOnly(true);
        doubleSpinBox_3 = new QDoubleSpinBox(tabWidgetPage2);
        doubleSpinBox_3->setObjectName(QString::fromUtf8("doubleSpinBox_3"));
        doubleSpinBox_3->setGeometry(QRect(86, 84, 93, 22));
        doubleSpinBox_3->setFont(font6);
        doubleSpinBox_3->setStyleSheet(QString::fromUtf8("background-color: rgb(56, 56, 56);\n"
"border: 1px solid rgb(34, 34, 34);\n"
""));
        doubleSpinBox_3->setAlignment(Qt::AlignCenter);
        doubleSpinBox_3->setButtonSymbols(QAbstractSpinBox::NoButtons);
        doubleSpinBox_3->setMinimum(-1000000.000000000000000);
        doubleSpinBox_3->setMaximum(1000000.000000000000000);
        doubleSpinBox_3->setValue(-2.000000000000000);
        input_x = new QDoubleSpinBox(tabWidgetPage2);
        input_x->setObjectName(QString::fromUtf8("input_x"));
        input_x->setGeometry(QRect(208, 65, 207, 29));
        input_x->setStyleSheet(QString::fromUtf8("background-color: rgb(56, 56, 56);\n"
"border: 1px solid rgb(34, 34, 34);\n"
""));
        input_x->setAlignment(Qt::AlignCenter);
        input_x->setButtonSymbols(QAbstractSpinBox::NoButtons);
        input_x->setMinimum(-1000000.000000000000000);
        input_x->setMaximum(1000000.000000000000000);
        input_x->setValue(0.000000000000000);
        line = new QFrame(tabWidgetPage2);
        line->setObjectName(QString::fromUtf8("line"));
        line->setGeometry(QRect(-3, 57, 461, 21));
        line->setStyleSheet(QString::fromUtf8("background-color : rgb(53, 54, 55);"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);
        line_2 = new QFrame(tabWidgetPage2);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setGeometry(QRect(-10, 78, 461, 91));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);
        tabWidget->addTab(tabWidgetPage2, QString());
        line->raise();
        line_2->raise();
        pushButton_acos->raise();
        pushButton_8->raise();
        pushButton_sub->raise();
        pushButton_7->raise();
        pushButton_6->raise();
        pushButton_asin->raise();
        pushButton_sin->raise();
        pushButton_3->raise();
        pushButton_0->raise();
        pushButton_dot->raise();
        pushButton_log->raise();
        pushButton_tan->raise();
        pushButton_atan->raise();
        pushButton_1->raise();
        pushButton_mul->raise();
        pushButton_2->raise();
        pushButton_eq->raise();
        pushButton_mod->raise();
        pushButton_sum->raise();
        pushButton_ln->raise();
        pushButton_C->raise();
        pushButton_9->raise();
        pushButton_factorial->raise();
        pushButton_sqrt->raise();
        pushButton_4->raise();
        pushButton_exp->raise();
        pushButton_cos->raise();
        pushButton_5->raise();
        pushButton_div->raise();
        input->raise();
        doubleSpinBox_2->raise();
        doubleSpinBox_4->raise();
        doubleSpinBox->raise();
        doubleSpinBox_3->raise();
        lineEdit_4->raise();
        lineEdit_3->raise();
        lineEdit_5->raise();
        input_x->raise();
        pushButton_close_bracket->raise();
        pushButton_x->raise();
        pushButton_AC->raise();
        pushButton_open_bracket->raise();
        pushButton_grafik->raise();
        tabWidgetPage3 = new QWidget();
        tabWidgetPage3->setObjectName(QString::fromUtf8("tabWidgetPage3"));
        pushButton_CreditResult = new QPushButton(tabWidgetPage3);
        pushButton_CreditResult->setObjectName(QString::fromUtf8("pushButton_CreditResult"));
        pushButton_CreditResult->setGeometry(QRect(0, 300, 411, 81));
        pushButton_CreditResult->setMinimumSize(QSize(119, 10));
        pushButton_CreditResult->setMaximumSize(QSize(100000, 100000));
        pushButton_CreditResult->setFont(font5);
        pushButton_CreditResult->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	 background-color: rgb(89, 89, 89);\n"
"   border: 1px solid rgb(34, 34, 34);\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: rgba(255, 255, 255, 128);\n"
"}"));
        lineEdit = new QLineEdit(tabWidgetPage3);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(0, 100, 191, 31));
        lineEdit->setMinimumSize(QSize(141, 21));
        QFont font7;
        font7.setPointSize(16);
        lineEdit->setFont(font7);
        lineEdit->setAlignment(Qt::AlignCenter);
        lineEdit->setReadOnly(true);
        lineEdit_2 = new QLineEdit(tabWidgetPage3);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(213, 100, 201, 31));
        lineEdit_2->setMinimumSize(QSize(141, 21));
        QFont font8;
        font8.setPointSize(16);
        font8.setBold(false);
        lineEdit_2->setFont(font8);
        lineEdit_2->setAlignment(Qt::AlignCenter);
        lineEdit_2->setReadOnly(true);
        monthly_payment = new QLineEdit(tabWidgetPage3);
        monthly_payment->setObjectName(QString::fromUtf8("monthly_payment"));
        monthly_payment->setGeometry(QRect(60, 140, 291, 21));
        monthly_payment->setMinimumSize(QSize(141, 21));
        monthly_payment->setAlignment(Qt::AlignCenter);
        monthly_payment->setReadOnly(true);
        overpayment = new QLineEdit(tabWidgetPage3);
        overpayment->setObjectName(QString::fromUtf8("overpayment"));
        overpayment->setGeometry(QRect(60, 190, 291, 21));
        overpayment->setMinimumSize(QSize(141, 21));
        overpayment->setAlignment(Qt::AlignCenter);
        overpayment->setReadOnly(true);
        total_payment = new QLineEdit(tabWidgetPage3);
        total_payment->setObjectName(QString::fromUtf8("total_payment"));
        total_payment->setGeometry(QRect(60, 240, 291, 21));
        total_payment->setMinimumSize(QSize(141, 21));
        total_payment->setAlignment(Qt::AlignCenter);
        total_payment->setReadOnly(true);
        monthly_payment_A = new QLineEdit(tabWidgetPage3);
        monthly_payment_A->setObjectName(QString::fromUtf8("monthly_payment_A"));
        monthly_payment_A->setGeometry(QRect(0, 160, 200, 21));
        monthly_payment_A->setMinimumSize(QSize(141, 21));
        monthly_payment_A->setAlignment(Qt::AlignCenter);
        monthly_payment_A->setReadOnly(true);
        monthly_payment_D = new QLineEdit(tabWidgetPage3);
        monthly_payment_D->setObjectName(QString::fromUtf8("monthly_payment_D"));
        monthly_payment_D->setGeometry(QRect(213, 160, 201, 21));
        monthly_payment_D->setMinimumSize(QSize(141, 21));
        monthly_payment_D->setAlignment(Qt::AlignCenter);
        monthly_payment_D->setReadOnly(true);
        overpayment_D = new QLineEdit(tabWidgetPage3);
        overpayment_D->setObjectName(QString::fromUtf8("overpayment_D"));
        overpayment_D->setGeometry(QRect(213, 210, 201, 21));
        overpayment_D->setMinimumSize(QSize(141, 21));
        overpayment_D->setAlignment(Qt::AlignCenter);
        overpayment_D->setReadOnly(true);
        overpayment_A = new QLineEdit(tabWidgetPage3);
        overpayment_A->setObjectName(QString::fromUtf8("overpayment_A"));
        overpayment_A->setGeometry(QRect(0, 210, 200, 21));
        overpayment_A->setMinimumSize(QSize(141, 21));
        overpayment_A->setAlignment(Qt::AlignCenter);
        overpayment_A->setReadOnly(true);
        total_payment_D = new QLineEdit(tabWidgetPage3);
        total_payment_D->setObjectName(QString::fromUtf8("total_payment_D"));
        total_payment_D->setGeometry(QRect(213, 260, 201, 21));
        total_payment_D->setMinimumSize(QSize(141, 21));
        total_payment_D->setAlignment(Qt::AlignCenter);
        total_payment_D->setReadOnly(true);
        total_payment_A = new QLineEdit(tabWidgetPage3);
        total_payment_A->setObjectName(QString::fromUtf8("total_payment_A"));
        total_payment_A->setGeometry(QRect(0, 260, 200, 21));
        total_payment_A->setMinimumSize(QSize(141, 21));
        total_payment_A->setAlignment(Qt::AlignCenter);
        total_payment_A->setReadOnly(true);
        loan_amount = new QLineEdit(tabWidgetPage3);
        loan_amount->setObjectName(QString::fromUtf8("loan_amount"));
        loan_amount->setGeometry(QRect(0, 0, 139, 31));
        loan_amount->setMinimumSize(QSize(0, 0));
        loan_amount->setAlignment(Qt::AlignCenter);
        loan_amount->setReadOnly(true);
        credit_term = new QLineEdit(tabWidgetPage3);
        credit_term->setObjectName(QString::fromUtf8("credit_term"));
        credit_term->setGeometry(QRect(139, 0, 139, 31));
        credit_term->setMinimumSize(QSize(0, 0));
        credit_term->setAlignment(Qt::AlignCenter);
        credit_term->setReadOnly(true);
        percent = new QLineEdit(tabWidgetPage3);
        percent->setObjectName(QString::fromUtf8("percent"));
        percent->setGeometry(QRect(278, 0, 139, 31));
        percent->setMinimumSize(QSize(0, 0));
        percent->setAlignment(Qt::AlignCenter);
        percent->setReadOnly(true);
        loan_amount_input = new QDoubleSpinBox(tabWidgetPage3);
        loan_amount_input->setObjectName(QString::fromUtf8("loan_amount_input"));
        loan_amount_input->setGeometry(QRect(-1, 30, 155, 51));
        loan_amount_input->setAlignment(Qt::AlignCenter);
        loan_amount_input->setMaximum(1000000000000.000000000000000);
        loan_amount_input->setValue(1000000.000000000000000);
        credit_term_input = new QDoubleSpinBox(tabWidgetPage3);
        credit_term_input->setObjectName(QString::fromUtf8("credit_term_input"));
        credit_term_input->setGeometry(QRect(138, 30, 155, 51));
        credit_term_input->setAlignment(Qt::AlignCenter);
        credit_term_input->setMaximum(100000.000000000000000);
        credit_term_input->setValue(120.000000000000000);
        percent_input = new QDoubleSpinBox(tabWidgetPage3);
        percent_input->setObjectName(QString::fromUtf8("percent_input"));
        percent_input->setGeometry(QRect(277, 30, 152, 51));
        percent_input->setAlignment(Qt::AlignCenter);
        percent_input->setMaximum(100.000000000000000);
        percent_input->setValue(10.000000000000000);
        tabWidget->addTab(tabWidgetPage3, QString());
        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
#if QT_CONFIG(tooltip)
        tabWidget->setToolTip(QCoreApplication::translate("MainWindow", "<html><head/><body><p><br/></p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        pushButton_acos->setText(QCoreApplication::translate("MainWindow", "acos", nullptr));
        pushButton_8->setText(QCoreApplication::translate("MainWindow", "8", nullptr));
        pushButton_sub->setText(QCoreApplication::translate("MainWindow", "-", nullptr));
        pushButton_7->setText(QCoreApplication::translate("MainWindow", "7", nullptr));
        pushButton_6->setText(QCoreApplication::translate("MainWindow", "6", nullptr));
        pushButton_open_bracket->setText(QCoreApplication::translate("MainWindow", "(", nullptr));
        pushButton_asin->setText(QCoreApplication::translate("MainWindow", "asin", nullptr));
        pushButton_sin->setText(QCoreApplication::translate("MainWindow", "sin", nullptr));
        pushButton_3->setText(QCoreApplication::translate("MainWindow", "3", nullptr));
        pushButton_0->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        pushButton_dot->setText(QCoreApplication::translate("MainWindow", ".", nullptr));
        pushButton_log->setText(QCoreApplication::translate("MainWindow", "log", nullptr));
        pushButton_tan->setText(QCoreApplication::translate("MainWindow", "tan", nullptr));
        pushButton_x->setText(QCoreApplication::translate("MainWindow", "x", nullptr));
        pushButton_atan->setText(QCoreApplication::translate("MainWindow", "atan", nullptr));
        pushButton_1->setText(QCoreApplication::translate("MainWindow", "1", nullptr));
        pushButton_mul->setText(QCoreApplication::translate("MainWindow", "*", nullptr));
        pushButton_2->setText(QCoreApplication::translate("MainWindow", "2", nullptr));
        pushButton_eq->setText(QCoreApplication::translate("MainWindow", "=", nullptr));
        pushButton_mod->setText(QCoreApplication::translate("MainWindow", "mod", nullptr));
        pushButton_sum->setText(QCoreApplication::translate("MainWindow", "+", nullptr));
        pushButton_ln->setText(QCoreApplication::translate("MainWindow", "ln", nullptr));
        pushButton_C->setText(QCoreApplication::translate("MainWindow", "C", nullptr));
        pushButton_9->setText(QCoreApplication::translate("MainWindow", "9", nullptr));
        pushButton_factorial->setText(QCoreApplication::translate("MainWindow", "!", nullptr));
        pushButton_sqrt->setText(QCoreApplication::translate("MainWindow", "sqrt", nullptr));
        pushButton_4->setText(QCoreApplication::translate("MainWindow", "4", nullptr));
        pushButton_close_bracket->setText(QCoreApplication::translate("MainWindow", ")", nullptr));
        pushButton_exp->setText(QCoreApplication::translate("MainWindow", "^", nullptr));
        pushButton_cos->setText(QCoreApplication::translate("MainWindow", "cos", nullptr));
        pushButton_5->setText(QCoreApplication::translate("MainWindow", "5", nullptr));
        pushButton_AC->setText(QCoreApplication::translate("MainWindow", "AC", nullptr));
        pushButton_div->setText(QCoreApplication::translate("MainWindow", "/", nullptr));
        input->setText(QString());
        pushButton_grafik->setText(QCoreApplication::translate("MainWindow", "Graph", nullptr));
        lineEdit_5->setText(QCoreApplication::translate("MainWindow", "X", nullptr));
        lineEdit_4->setText(QCoreApplication::translate("MainWindow", " Function scope", nullptr));
        lineEdit_3->setText(QCoreApplication::translate("MainWindow", "Function range ", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tabWidgetPage2), QString());
        pushButton_CreditResult->setText(QCoreApplication::translate("MainWindow", "\320\240\320\220\320\241\320\241\320\247\320\230\320\242\320\220\320\242\320\254", nullptr));
        lineEdit->setText(QCoreApplication::translate("MainWindow", "\320\220\320\275\320\275\321\203\320\270\321\202\320\265\321\202\320\275\321\213\320\271", nullptr));
        lineEdit_2->setText(QCoreApplication::translate("MainWindow", "\320\224\320\270\321\204\321\204\320\265\321\200\320\265\320\275\321\206\320\270\321\200\320\276\320\262\320\260\320\275\320\275\321\213\320\271", nullptr));
        monthly_payment->setText(QCoreApplication::translate("MainWindow", "E\320\266\320\265\320\274\320\265\321\201\321\217\321\207\320\275\321\213\320\271 \320\277\320\273\320\260\321\202\320\265\320\266", nullptr));
        overpayment->setText(QCoreApplication::translate("MainWindow", "\320\237\320\265\321\200\320\265\320\277\320\273\320\260\321\202\320\260 \320\277\320\276 \320\272\321\200\320\265\320\264\320\270\321\202\321\203", nullptr));
        total_payment->setText(QCoreApplication::translate("MainWindow", "\320\236\320\261\321\211\320\260\321\217 \320\262\321\213\320\277\320\273\320\260\321\202\320\260", nullptr));
        monthly_payment_A->setText(QString());
        monthly_payment_D->setText(QString());
        overpayment_D->setText(QString());
        overpayment_A->setText(QString());
        total_payment_D->setText(QString());
        total_payment_A->setText(QString());
        loan_amount->setText(QCoreApplication::translate("MainWindow", "C\321\203\320\274\320\274\320\260 \320\272\321\200\320\265\320\264\320\270\321\202\320\260", nullptr));
        credit_term->setText(QCoreApplication::translate("MainWindow", "C\321\200\320\276\320\272 \320\272\321\200\320\265\320\264\320\270\321\202\320\260", nullptr));
        percent->setText(QCoreApplication::translate("MainWindow", "\320\237\321\200\320\276\321\206\320\265\320\275\321\202\320\275\320\260\321\217 \321\201\321\202\320\260\320\262\320\272\320\260", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tabWidgetPage3), QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
