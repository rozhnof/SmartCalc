#pragma once

#include <cmath>

#include "../Controllers/CreditCalcController.h"
#include "IPlatformUI.h"
#include "MainWindow.h"

class CreditCalculatorUI : public MainWindow {
 private:
  CreditCalcController *controller_;
  CreditCalcWidgets *widgets_;

 public:
  CreditCalculatorUI();
  ~CreditCalculatorUI();

  void SetupUI() override;

 private:
  void initWidgets();
  void connectWidgetsToSlots();

  void setGeometry();
  void setOptions();
  void setInputValidator();
  bool setInput();

  void getOutput();

  void Calculate(Service::CreditPaymentsType type);

 private slots:
  void AnnuityPayment();
  void DifferentiatedPayment();

  void DrawChartBars();
};
