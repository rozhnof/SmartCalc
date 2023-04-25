#ifndef CREDITCALCULATORUI_H
#define CREDITCALCULATORUI_H

#include "mainwindow.h"
#include "IPlatformUI.h"

class CreditCalculatorUI : public MainWindow
{
public:
    CreditCalcWidgets *widgets;

    CreditCalculatorUI() {
        widgets = new CreditCalcWidgets;

        creditTab = new QWidget(this);
        widgets->Window = calcTab;
        currentTab = this;

        widgets->label = new QLabel(this);

        _platform->SetupUI(widgets);
    }
};


#endif // CREDITCALCULATORUI_H
