#ifndef IPLATFORMUI_H
#define IPLATFORMUI_H

#include <QVector>
#include <QPushButton>


class IPlatformUI
{
public:
    IPlatformUI() {}
    virtual void SetupCalculatorUI() = 0;
    virtual void SetupGraphUI() = 0;
    virtual void SetupCreditCalculatorUI() = 0;
    virtual void SetupDepositCalculatorUI() = 0;
};


#endif // IPLATFORMUI_H
