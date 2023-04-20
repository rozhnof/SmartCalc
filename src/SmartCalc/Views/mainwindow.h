#ifndef MAINWINDOW_H
#define MAINWINDOW_H


#include <QWidget>
#include <QTabWidget>
#include <iostream>
#include "MacUI.h"
#include <unordered_map>
#include "Controllers/Controller.h"
#include <QMainWindow>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    QWidget *Window = this;

    IPlatformUI *_platform;
    QWidget *currentTab;

    QWidget *CalcTab;
    QWidget *GraphTab;
    QWidget *CreditCalcTab;
    QWidget *DepositCalcTab;

    Controller *controller;

    MainWindow(QWidget *parent = nullptr) : QMainWindow(parent) {
        controller = new Controller;

        this->resize(800, 600);
        this->setObjectName(QString::fromUtf8("Calculator"));
    }

    ~MainWindow() {}

    void SetupPlatform()
    {
        _platform = new MacUI;
    }
};

#endif // MAINWINDOW_H
