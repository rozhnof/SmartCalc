#include "View.h"

View::View()
    : calc_(new CalculatorUI),
      creditCalc_(new CreditCalculatorUI),
      depositCalc_(new DepositCalculatorUI),
      graph_(new GraphUI),
      winUi_(new WinUI),
      macUi_(new MacUI) {
  _currentTab = calc_;
  platform_ = winUi_;

  calc_->setWindowTitle("Calculator");
  creditCalc_->setWindowTitle("Credit Calculator");
  depositCalc_->setWindowTitle("Deposit Calculator");
  graph_->setWindowTitle("Graph");

  calc_->setObjectName("calculator_window");
  creditCalc_->setObjectName("credit_calculator_window");
  depositCalc_->setObjectName("deposit_calculator_window");
  graph_->setObjectName("graph_window");

  calc_->platform_ = &platform_;
  creditCalc_->platform_ = &platform_;
  depositCalc_->platform_ = &platform_;
  graph_->platform_ = &platform_;

  AddMenu();
}

View::~View() {
  delete calc_;
  delete creditCalc_;
  delete depositCalc_;
  delete graph_;
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

void View::switchToCalc() { switchTo(calc_); }

void View::switchToCreditCalc() { switchTo(creditCalc_); }

void View::switchToDepositCalc() { switchTo(depositCalc_); }

void View::switchToGraph() { switchTo(graph_); }

void View::switchMode() {
  if (platform_ == macUi_) {
    if (winUi_ == nullptr) {
      winUi_ = new WinUI;
    }
    platform_ = winUi_;
  } else {
    if (macUi_ == nullptr) {
      macUi_ = new MacUI;
    }
    platform_ = macUi_;
  }
  show();
}
