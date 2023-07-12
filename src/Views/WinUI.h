#pragma once

#include <QWidget>
#include <iostream>

#include "IPlatformUI.h"

class WinUI : public IPlatformUI {
 public:
  void SetupUI(CalcWidgets *widgets) override;

  void SetupUI(CreditCalcWidgets *widgets) override;

 private:
  void setStyle(CalcWidgets *widgets);

  void setStyle(CreditCalcWidgets *widgets);

  void setGeometry(CalcWidgets *widgets);
};
