#ifndef IPLATFORMUI_H
#define IPLATFORMUI_H

#include <QVector>
#include <QPushButton>
#include <unordered_map>
#include <QLabel>

using namespace std;

enum CalcObjectsEnum {
    MainWindow,

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
    ButtonResult,

    LabelInput
};

using namespace std;

class IPlatformUI
{
public:
    IPlatformUI() {}
    virtual void SetupCalculatorUI(unordered_map<int, QWidget*> calcObjects) = 0;
    virtual void SetSize(unordered_map<int, QWidget*> calcObjects) = 0;

    virtual void SetupGraphUI() = 0;
    virtual void SetupCreditCalculatorUI() = 0;
    virtual void SetupDepositCalculatorUI() = 0;
};


#endif // IPLATFORMUI_H
