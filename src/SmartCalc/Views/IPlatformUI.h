#pragma once


#include "Widgets.h"

using namespace std;



class IPlatformUI
{
public:
    IPlatformUI() {}
    virtual void SetupUI(CalcWidgets *widgets) = 0;
    virtual void SetupUI(CreditCalcWidgets *widgets) = 0;
};
