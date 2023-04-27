#ifndef CALCULATOR_H
#define CALCULATOR_H

#include "CalculatorUI.h"
#include "CreditCalculatorUI.h"
#include "DepositCalculatorUI.h"
#include "GraphUI.h"

#include <QObject>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtGui/QAction>
#include "MacUI.h"
#include "WinUI.h"


class Calculator : public QObject
{

    Q_OBJECT

private:

    class MainWindow *_currentTab;

    CalculatorUI *_calc;
    CreditCalculatorUI *_creditCalc;
    DepositCalculatorUI *_depositCalc;
    GraphUI *_graph;


    IPlatformUI *_platform;
    IPlatformUI *_winUi;
    IPlatformUI *_macUi;

    QMenuBar *menuBar;
    QMenu *menuMode;
    QAction *actionCalc;
    QAction *actionGraph;
    QAction *actionCreditCalc;
    QAction *actionDepositCalc;
    QAction *switchMode;

public:

    Calculator() {
        _calc = new CalculatorUI;
        _creditCalc = new CreditCalculatorUI;
        _depositCalc = new DepositCalculatorUI;
        _graph = new GraphUI;

        _winUi = new WinUI;
        _macUi = new MacUI;

        SetupPlatform();

        _calc->_platform = &_platform;
        _creditCalc->_platform = &_platform;
        _depositCalc->_platform = &_platform;
        _graph->_platform = &_platform;

        _currentTab = _calc;

         AddMenu();

        connect(actionCalc, &QAction::triggered, this, &Calculator::SwitchToCalc);
        connect(actionGraph, &QAction::triggered, this, &Calculator::SwithToGraph);
        connect(actionCreditCalc, &QAction::triggered, this, &Calculator::SwitchToCreditCalc);
        connect(actionDepositCalc, &QAction::triggered, this, &Calculator::SwitchToDepositCalc);
        connect(switchMode, &QAction::triggered, this, &Calculator::SwitchMode);


    }

    void AddMenu() {
        menuBar = new QMenuBar(nullptr);
        menuMode = new QMenu(menuBar);

        actionCalc = new QAction;
        actionGraph = new QAction;
        actionCreditCalc = new QAction;
        actionDepositCalc = new QAction;
        switchMode = new QAction;

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
    }

    void SetupPlatform()
    {
#ifdef __APPLE__
        _platform = _macUi;
#else
        _platform = _winUi;
#endif
    }

    void show() {
        _currentTab->SetupUI();
        _currentTab->show();
    }



private:

    void SwitchTo(class MainWindow *newTab) {
        _currentTab->hide();
        _currentTab = newTab;
        show();
    }


private slots:

    void SwitchToCalc() {
        SwitchTo(_calc);
    }

    void SwitchToCreditCalc() {
        SwitchTo(_creditCalc);
    }

    void SwitchToDepositCalc() {
        SwitchTo(_depositCalc);
    }

    void SwithToGraph() {
        SwitchTo(_graph);
    }

    void SwitchMode() {
        if (_platform == _macUi) {
            _platform = _winUi;
        } else {
            _platform = _macUi;
        }
        show();
    }

};


#endif // CALCULATOR_H
