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
  CalculatorUI *calc_;
  CreditCalculatorUI *creditCalc_;
  DepositCalculatorUI *depositCalc_;
  GraphUI *graph_;

 protected:
  IPlatformUI *platform_ = nullptr;
  IPlatformUI *winUi_;
  IPlatformUI *macUi_;

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
