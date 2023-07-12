#pragma once

#include <QObject>
#include <QtGui/QAction>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>

#include "CalculatorUI.h"
#include "CreditCalculatorUI.h"
#include "DepositCalculatorUI.h"
#include "GraphUI.h"
#include "MacUI.h"
#include "WinUI.h"

class View : public QObject {
 private:
  class MainWindow *_currentTab;

  CalculatorUI *_calc;
  CreditCalculatorUI *_creditCalc;
  DepositCalculatorUI *_depositCalc;
  GraphUI *_graph;

 protected:
  IPlatformUI *_platform = nullptr;
  IPlatformUI *_winUi;
  IPlatformUI *_macUi;

 public:
  View();

  ~View();

  void show();

 private:
  void AddMenu();

  void switchTo(class MainWindow *newTab);

  void switchToCalc();

  void switchToCreditCalc();

  void switchToDepositCalc();

  void switchToGraph();

  void switchMode();
};
