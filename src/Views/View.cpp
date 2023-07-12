#include "View.h"

View::View()
    : _calc(new CalculatorUI),
      _creditCalc(new CreditCalculatorUI),
      _depositCalc(new DepositCalculatorUI),
      _graph(new GraphUI),
      _winUi(new WinUI),
      _macUi(new MacUI) {
  _currentTab = _calc;
  _platform = _winUi;

  _calc->setWindowTitle("Calculator");
  _creditCalc->setWindowTitle("Credit Calculator");
  _depositCalc->setWindowTitle("Deposit Calculator");
  _graph->setWindowTitle("Graph");

  _calc->setObjectName("calculator_window");
  _creditCalc->setObjectName("credit_calculator_window");
  _depositCalc->setObjectName("deposit_calculator_window");
  _graph->setObjectName("graph_window");

  _calc->_platform = &_platform;
  _creditCalc->_platform = &_platform;
  _depositCalc->_platform = &_platform;
  _graph->_platform = &_platform;

  AddMenu();
}

View::~View() {
  delete _calc;
  delete _creditCalc;
  delete _depositCalc;
  delete _graph;
}

void View::show() {
  _currentTab->SetupUI();
  _currentTab->show();
}

void View::AddMenu() {
  QMenuBar *menuBar = new QMenuBar(_currentTab);
  QMenu *menuMode = new QMenu(menuBar);
  QAction *actionCalc = new QAction(menuMode);
  QAction *actionGraph = new QAction(menuMode);
  QAction *actionCreditCalc = new QAction(menuMode);
  QAction *actionDepositCalc = new QAction(menuMode);
  QAction *switchMode = new QAction(menuMode);

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

  _currentTab->setMenuBar(menuBar);

  connect(actionCalc, &QAction::triggered, this, &View::switchToCalc);
  connect(actionGraph, &QAction::triggered, this, &View::switchToGraph);
  connect(actionCreditCalc, &QAction::triggered, this,
          &View::switchToCreditCalc);
  connect(actionDepositCalc, &QAction::triggered, this,
          &View::switchToDepositCalc);
  connect(switchMode, &QAction::triggered, this, &View::switchMode);
}

void View::switchTo(MainWindow *newTab) {
  _currentTab->hide();
  _currentTab = newTab;
  show();
}

void View::switchToCalc() { switchTo(_calc); }

void View::switchToCreditCalc() { switchTo(_creditCalc); }

void View::switchToDepositCalc() { switchTo(_depositCalc); }

void View::switchToGraph() { switchTo(_graph); }

void View::switchMode() {
  if (_platform == _macUi) {
    if (_winUi == nullptr) {
      _winUi = new WinUI;
    }
    _platform = _winUi;
  } else {
    if (_macUi == nullptr) {
      _macUi = new MacUI;
    }
    _platform = _macUi;
  }
  show();
}
