#ifndef CALCSLOTS_H
#define CALCSLOTS_H

#include <QWidget>
#include "Graph.h"

class CalcSlots : public QWidget
{
    Q_OBJECT

public:

    CalcSlots() {}
    ~CalcSlots() {}


private slots:
    void SetNumber();
    void SetOperator();
    void SetFactorial();
    void SetDot();
    void SetOpenBracket();
    void SetCloseBracket();
    void SetX();
    void SetFunction();
    void ClearAll();
    void Equal();
    void DrawGraph();
    void SwitchToWin();
};

#endif // CALCSLOTS_H
