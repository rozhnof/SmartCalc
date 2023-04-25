#ifndef MAINWINDOW_H
#define MAINWINDOW_H


#include <QWidget>
#include <QTabWidget>
#include <iostream>
#include "MacUI.h"
#include "WinUI.h"
#include <unordered_map>
#include "Controllers/Controller.h"
#include <QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtGui/QAction>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    IPlatformUI *_winUi;
    IPlatformUI *_macUi;
    IPlatformUI *_platform;
    Controller *controller;



    QMenuBar *menuBar;
    QMenu *menuMode;
    QAction *actionCalc;
    QAction *actionGraph;
    QAction *actionCreditCalc;
    QAction *actionDepositCalc;
    QAction *switchMode;


    MainWindow(QWidget *parent = nullptr) : QMainWindow(parent) {
        controller = new Controller;

        this->resize(840, 720);

        AddMenu();

        _winUi = new WinUI;
        _macUi = new MacUI;

        SetupPlatform();
    }

    void AddMenu() {
        menuBar = new QMenuBar(this);
        menuMode = new QMenu(menuBar);

        actionCalc = new QAction(this);
        actionGraph = new QAction(this);
        actionCreditCalc = new QAction(this);
        actionDepositCalc = new QAction(this);
        switchMode = new QAction(this);

        menuMode->setTitle("Mode");
        menuBar->addAction(menuMode->menuAction());

        menuMode->addAction(actionCalc);
        menuMode->addAction(actionGraph);
        menuMode->addAction(actionCreditCalc);
        menuMode->addAction(actionDepositCalc);
        menuMode->addAction(switchMode);

        actionCalc->setText("Calculator");
        actionGraph->setText("Graph");
        actionCreditCalc->setText("Credit Calculator");
        actionDepositCalc->setText("Deposit Calculator");
        switchMode->setText("Switch Mode");

        connect(actionCalc, SIGNAL(triggered()), this, SLOT(SwitchToCalc()));
        connect(actionGraph, SIGNAL(triggered()), this, SLOT(SwitchToGraph()));
        connect(actionCreditCalc, SIGNAL(triggered()), this, SLOT(SwitchToCreditCalc()));
        connect(actionDepositCalc, SIGNAL(triggered()), this, SLOT(SwitchToDepositCalc()));
        connect(switchMode, SIGNAL(triggered()), this, SLOT(SwitchMode()));
    }

    ~MainWindow() {}


    void SetupPlatform()
    {
#ifdef __APPLE__
        _platform = _macUi;
#else
        _platform = _winUi;
#endif
    }
};

#endif // MAINWINDOW_H
