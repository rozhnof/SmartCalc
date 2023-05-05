#ifndef IPLATFORMUI_H
#define IPLATFORMUI_H


#include "IWidgets.h"

using namespace std;








class IPlatformUI
{
public:
    IPlatformUI() {}
    virtual void SetupUI(CalcWidgets *widgets) = 0;
    virtual void SetupUI(GraphWidgets *widgets) = 0;
    virtual void SetupUI(CreditCalcWidgets *widgets) = 0;
    virtual void SetupUI(DepositCalcWidgets *widgets) = 0;
};


#endif // IPLATFORMUI_H
