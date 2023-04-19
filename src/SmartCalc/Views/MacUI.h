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
        cout << "BEBRA" << endl;
    }
    void SetupGraphUI() override {
        cout << "BEBRA" << endl;
    }
    void SetupCreditCalculatorUI() override {
        cout << "BEBRA" << endl;
    }
    void SetupDepositCalculatorUI() override {
        cout << "BEBRA" << endl;
    }
};

#endif // MACUI_H
