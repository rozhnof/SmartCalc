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
