#ifndef MAINWINDOW_H
#define MAINWINDOW_H


#include <QWidget>
#include <QTabWidget>
#include <iostream>
#include "MacUI.h"
#include <unordered_map>
#include "Controllers/Controller.h"

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

    Controller *controller;

    MainWindow() {
        Window = new QWidget;
        CalcTab = new QWidget(Window);
        controller = new Controller;

        Window->setFixedSize(1000, 1000);
        Window->setObjectName(QString::fromUtf8("Calculator"));
    }

    void SetupPlatform()
    {
        _platform = new MacUI;
    }

    void show() {
        Window->show();
    }

    ~MainWindow() {}


};

#endif // MAINWINDOW_H
