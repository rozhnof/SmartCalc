#pragma once

#include <QDebug>
#include <QPushButton>
#include <QResizeEvent>
#include <QVector>
#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QWidget>

#include "../Controllers/CalculatorController.h"
#include "MainWindow.h"

class CalculatorUI : public MainWindow {
  Q_OBJECT

 private:
  CalculatorController *controller_;
  CalcWidgets *widgets_;

 public:
  CalculatorUI();
  ~CalculatorUI();

  void SetupUI() override;

 private:
  void initInputXWidget();
  void initWidgets();
  void connectWidgetsToSlots();

  void resetWidgets();

 private slots:
  void setLexema();

  void clearButton();
  void equalButton();
  void clearAllButton();

  void showInputX();
  void hideInputX();

  void CalculateWithX();
  void Calculate(QString input, double x);
};
