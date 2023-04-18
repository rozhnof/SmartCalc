#ifndef MACUI_H
#define MACUI_H

#include "IPlatformUI.h"
#include <iostream>


using namespace std;

class MacUI : public IPlatformUI
{
public:
    MacUI() {}

    void SetupCalculatorUI() override {

    }
    void SetupGraphUI() override {

    }
    void SetupCreditCalculatorUI() override {

    }
    void SetupDepositCalculatorUI() override {

    }
};

#endif // MACUI_H
