#ifndef MAINWINDOW_H
#define MAINWINDOW_H


#include <QWidget>
#include <QTabWidget>
#include <iostream>
#include "MacUI.h"
#include <unordered_map>

class MainWindow : public QWidget
{
    Q_OBJECT

public:
    QWidget *Window;

    IPlatformUI *_platform;
    QWidget *currentTab;

    QWidget *CalcTab;
    QWidget *GraphTab;
    QWidget *CreditCalcTab;
    QWidget *DepositCalcTab;

    MainWindow() {
        Window = new QWidget;
        CalcTab = new QWidget(Window);

        Window->setFixedSize(1000, 1000);
        Window->setObjectName(QString::fromUtf8("Calculator"));
    }

    void SetupPlatform(IPlatformUI *platform)
    {
        _platform = platform;
    }

    void show() {
        Window->show();
    }

    ~MainWindow() {}

public slots:
    void SetNumber() {
        cout << "EERERORR" << endl;
    }
};

#endif // MAINWINDOW_H
