#ifndef IPLATFORMUI_H
#define IPLATFORMUI_H

#include <QVector>
#include <QPushButton>
#include <unordered_map>
#include <QLabel>
#include <QMainWindow>

using namespace std;


class CalcGroup
{

private:
    unordered_map<int, QPushButton*> _buttonMap;

    QString _styleButton = "QPushButton {";
    QString _styleButtonPressed = "QPushButton:pressed {";
    QString _style;

public:
    QList<int> indices;



    CalcGroup(unordered_map<int, QPushButton*> &buttonMap) : _buttonMap(buttonMap) {}
    ~CalcGroup() {}

    void addButton(int index) {
        indices.push_back(index);
    }

    void StyleApply() {
        _style = _styleButton + _styleButtonPressed;
        for (int i = 0; i < indices.size(); i++) {
            _buttonMap.at(indices.at(i))->setStyleSheet(_style);
        }
    }

    void SetButtonStyle(QString styleButton) {
        _styleButton += (styleButton + "}");
    }

    void SetPressedButtonStyle(QString styleButtonPressed) {
        _styleButtonPressed += (styleButtonPressed + "}");
    }
};

typedef struct CalcWidgets {
    QWidget *Window;
    QLabel *Input;
    unordered_map<int, QPushButton*> calcButtons;
} CalcWidgets;


typedef struct CreditCalcWidgets {
    QWidget *Window;
    QLabel *label;
} CreditCalcWidgets;


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
    ButtonDot,

    ButtonX,

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
    virtual void SetupUI(CalcWidgets *widgets) = 0;
    virtual void SetSize(CalcWidgets *widgets) = 0;

//    virtual void SetupGraphUI() = 0;
    virtual void SetupUI(CreditCalcWidgets *widgets) = 0;
//    virtual void SetupDepositCalculatorUI() = 0;
};


#endif // IPLATFORMUI_H
