/********************************************************************************
** Form generated from reading UI file 'WinCalc.ui'
**
** Created by: Qt User Interface Compiler version 6.2.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WINCALC_H
#define UI_WINCALC_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionCalculator;
    QWidget *MainWidget;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QLineEdit *lineEdit;
    QDoubleSpinBox *doubleSpinBox_3;
    QLineEdit *lineEdit_3;
    QLineEdit *lineEdit_2;
    QDoubleSpinBox *doubleSpinBox_5;
    QDoubleSpinBox *doubleSpinBox;
    QDoubleSpinBox *doubleSpinBox_2;
    QDoubleSpinBox *doubleSpinBox_4;
    QLineEdit *lineEdit_4;
    QDoubleSpinBox *doubleSpinBox_6;
    QLineEdit *lineEdit_5;
    QMenuBar *menuBar;
    QMenu *menuMode;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(658, 422);
        MainWindow->setMinimumSize(QSize(412, 300));
        MainWindow->setMaximumSize(QSize(10000, 10000));
        actionCalculator = new QAction(MainWindow);
        actionCalculator->setObjectName(QString::fromUtf8("actionCalculator"));
        MainWidget = new QWidget(MainWindow);
        MainWidget->setObjectName(QString::fromUtf8("MainWidget"));
        gridLayoutWidget = new QWidget(MainWidget);
        gridLayoutWidget->setObjectName(QString::fromUtf8("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(40, 30, 541, 81));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        lineEdit = new QLineEdit(gridLayoutWidget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));

        gridLayout->addWidget(lineEdit, 0, 0, 1, 1);

        doubleSpinBox_3 = new QDoubleSpinBox(gridLayoutWidget);
        doubleSpinBox_3->setObjectName(QString::fromUtf8("doubleSpinBox_3"));

        gridLayout->addWidget(doubleSpinBox_3, 1, 1, 1, 1);

        lineEdit_3 = new QLineEdit(gridLayoutWidget);
        lineEdit_3->setObjectName(QString::fromUtf8("lineEdit_3"));

        gridLayout->addWidget(lineEdit_3, 0, 2, 1, 1);

        lineEdit_2 = new QLineEdit(gridLayoutWidget);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));

        gridLayout->addWidget(lineEdit_2, 0, 1, 1, 1);

        doubleSpinBox_5 = new QDoubleSpinBox(gridLayoutWidget);
        doubleSpinBox_5->setObjectName(QString::fromUtf8("doubleSpinBox_5"));

        gridLayout->addWidget(doubleSpinBox_5, 1, 2, 1, 1);

        doubleSpinBox = new QDoubleSpinBox(gridLayoutWidget);
        doubleSpinBox->setObjectName(QString::fromUtf8("doubleSpinBox"));

        gridLayout->addWidget(doubleSpinBox, 1, 0, 1, 1);

        doubleSpinBox_2 = new QDoubleSpinBox(gridLayoutWidget);
        doubleSpinBox_2->setObjectName(QString::fromUtf8("doubleSpinBox_2"));

        gridLayout->addWidget(doubleSpinBox_2, 2, 0, 1, 1);

        doubleSpinBox_4 = new QDoubleSpinBox(gridLayoutWidget);
        doubleSpinBox_4->setObjectName(QString::fromUtf8("doubleSpinBox_4"));

        gridLayout->addWidget(doubleSpinBox_4, 2, 1, 1, 1);

        lineEdit_4 = new QLineEdit(gridLayoutWidget);
        lineEdit_4->setObjectName(QString::fromUtf8("lineEdit_4"));

        gridLayout->addWidget(lineEdit_4, 0, 3, 1, 1);

        doubleSpinBox_6 = new QDoubleSpinBox(gridLayoutWidget);
        doubleSpinBox_6->setObjectName(QString::fromUtf8("doubleSpinBox_6"));

        gridLayout->addWidget(doubleSpinBox_6, 1, 3, 1, 1);

        lineEdit_5 = new QLineEdit(gridLayoutWidget);
        lineEdit_5->setObjectName(QString::fromUtf8("lineEdit_5"));

        gridLayout->addWidget(lineEdit_5, 2, 2, 1, 2);

        MainWindow->setCentralWidget(MainWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 658, 24));
        menuMode = new QMenu(menuBar);
        menuMode->setObjectName(QString::fromUtf8("menuMode"));
        MainWindow->setMenuBar(menuBar);

        menuBar->addAction(menuMode->menuAction());
        menuMode->addAction(actionCalculator);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        actionCalculator->setText(QCoreApplication::translate("MainWindow", "Calculator", nullptr));
        menuMode->setTitle(QCoreApplication::translate("MainWindow", "Mode", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WINCALC_H
