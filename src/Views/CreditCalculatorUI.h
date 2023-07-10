#pragma once

#include "MainWindow.h"
#include "IPlatformUI.h"
#include "../Controllers/CreditCalcController.h"
#include <cmath>


class CreditCalculatorUI : public MainWindow
{
private:
    CreditCalcController *_controller;
    CreditCalcWidgets *_widgets;

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
