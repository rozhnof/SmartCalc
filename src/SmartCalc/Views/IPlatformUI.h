#ifndef IPLATFORMUI_H
#define IPLATFORMUI_H


#include "IWidgets.h"

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
