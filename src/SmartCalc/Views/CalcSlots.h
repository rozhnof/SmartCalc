#ifndef CALCSLOTS_H
#define CALCSLOTS_H

#include <QWidget>
#include "GraphUI.h"

class CalcSlots : public QWidget
{
    Q_OBJECT

public:

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
};

#endif // CALCSLOTS_H
