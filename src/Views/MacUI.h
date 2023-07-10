#pragma once


#include "IPlatformUI.h"
#include <iostream>
#include <QWidget>


class MacUI : public IPlatformUI
{
public:

    void SetupUI(CalcWidgets *widgets) override;

    void SetupUI(CreditCalcWidgets *widgets) override;

private:

    void setStyle(CalcWidgets *widgets);

    void setStyle(CreditCalcWidgets *widgets);

    void setGeometry(CalcWidgets *widgets);
};
