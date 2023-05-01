#ifndef IWIDGETS_H
#define IWIDGETS_H


#include <QVector>
#include <QPushButton>
#include <unordered_map>
#include <QLabel>
#include <QMainWindow>
#include "qcustomplot.h"


using namespace std;



class Layout
{
private:
    int _rowsCount = 0;
    int _colsCount = 0;
    int _rowsMax;
    int _colsMax;

    int _spacerX;
    int _spacerY;

    int _elemWidth;
    int _elemHeight;

    int _currentX;
    int _currentY;

    int _x0;

    int _remainingX;
    int _remainingY;

    int _remainingXcount;
    int _remainingYcount;

public:
    Layout(int x0, int y0, int xMax, int yMax, int rows, int cols, int spacerX, int spacerY) :
        _rowsMax(rows), _colsMax(cols), _spacerX(spacerX), _spacerY(spacerY), _x0(x0)
    {
        int generalWidth = (xMax - x0) - (_spacerX * (_colsMax - 1));
        int generalHeight = (yMax - y0) - (_spacerY * (_rowsMax - 1));

        _elemWidth = generalWidth / _colsMax;
        _elemHeight = generalHeight / _rowsMax;

        _remainingX = _remainingXcount = generalWidth % _colsMax;
        _remainingY = _remainingYcount = generalHeight % _rowsMax;

        _currentX = _x0;
        _currentY = y0;
    }


    void AddWidget(QWidget* widget, int width, int height) {
        int currentWidth = (_elemWidth * width) + ((width - 1) * _spacerX);
        int currentHeight = (_elemHeight * height) + ((height - 1) * _spacerY);

        if (_remainingXcount-- > 0) currentWidth += 1;
        if (_remainingYcount-- > 0) currentHeight += 1;

        widget->setGeometry(_currentX, _currentY, currentWidth, currentHeight);

        _colsCount += width;
        _currentX += currentWidth + _spacerX;

        if (_colsCount >= _colsMax) {
            _colsCount = 0;
            _rowsCount += height;

            _currentY += currentHeight + _spacerY;
            _currentX = _x0;
            _remainingXcount = _remainingX;
        }
    }
};


typedef struct CalcWidgets {
    QMainWindow *calcWindow;

    QLabel *Input;
    unordered_map<int, QPushButton*> calcButtons;
} CalcWidgets;

typedef struct GraphWidgets  {
    QWidget *graphWindow;
    QCustomPlot *graph;

    QLineEdit *Input;
    QCheckBox* drawingLine;
    unordered_map<int, QLabel*> titles;
    unordered_map<int, QDoubleSpinBox*> values;

} GraphWidgets;

typedef struct CreditCalcWidgets  {
    QWidget *creditCalcWindow;

    unordered_map<int, QLineEdit*> values;
    QVector<QLineEdit*> payments;
} CreditCalcWidgets;


typedef struct DepositCalcWidgets  {
    QWidget *depositCalcWindow;

    QLabel *label;
} DepositCalcWidgets;


enum CreditCalcObjectsEnum {
    CreditSum,
    CreditTerm,
    InterestRate,
    TotalPyament,
    Overpayment
};


enum GraphObjectsEnum {
    ScopeMin,
    ScopeMax,
    RangeMin,
    RangeMax,
    InputX,
    Points
};

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
    ButtonUnaryOperator,
    ButtonResult,

    LabelInput
};

#endif // IWIDGETS_H
