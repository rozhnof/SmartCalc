#ifndef MAINWINDOW_H
#define MAINWINDOW_H


#include <QWidget>
#include <QTabWidget>
#include <iostream>
#include "MacUI.h"
#include <unordered_map>
#include "Controllers/Controller.h"
#include <QResizeEvent>
#include <QDebug>
#include <QMainWindow>

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

        Window->resize(800, 600);
        Window->setObjectName(QString::fromUtf8("Calculator"));


    }

    ~MainWindow() {}

    void SetupPlatform()
    {
        _platform = new MacUI;
    }

    void show() {
        Window->show();
    }

    void resizeEvent(QResizeEvent *e);
};

#endif // MAINWINDOW_H
