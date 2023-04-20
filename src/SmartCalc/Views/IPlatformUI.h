#ifndef IPLATFORMUI_H
#define IPLATFORMUI_H

#include <QVector>
#include <QPushButton>
#include <unordered_map>
#include <QLabel>

using namespace std;

typedef struct CalcWidgets
{
    unordered_map<int, QPushButton*> buttons;
    QLabel *Input;
} CalcWidgets;

enum CalcButtons {
    Button0,
    Button1,
    Button2,
    Button3,
    Button4,
    Button5,
    Button6,
    Button7,
    Button8,
    Button9,
    ButtonX,
    ButtonDot,

    ButtonSin,
    ButtonCos,
    ButtonTan,
    ButtonAsin,
    ButtonAcos,
    ButtonAtan,
    ButtonLog,
    ButtonLn,
    ButtonSqrt,

    ButtonSum,
    ButtonSub,
    ButtonMul,
    ButtonDiv,
    ButtonMod,
    ButtonPow,
    ButtonFactorial,

    ButtonOpenBracket,
    ButtonCloseBracket,

    ButtonAC,
    ButtonGraph,
    ButtonResult
};

using namespace std;

class IPlatformUI
{
public:
    IPlatformUI() {}
    virtual void SetupCalculatorUI(CalcWidgets *widgets, QWidget *Window) = 0;
    virtual void SetSize(CalcWidgets *widgets, QWidget *Window) = 0;

    virtual void SetupGraphUI() = 0;
    virtual void SetupCreditCalculatorUI() = 0;
    virtual void SetupDepositCalculatorUI() = 0;
};


#endif // IPLATFORMUI_H
