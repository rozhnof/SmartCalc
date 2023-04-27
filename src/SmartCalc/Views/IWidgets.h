#ifndef IWIDGETS_H
#define IWIDGETS_H


#include <QVector>
#include <QPushButton>
#include <unordered_map>
#include <QLabel>
#include <QMainWindow>
#include "qcustomplot.h"


using namespace std;


typedef struct CalcWidgets {
    QMainWindow *calcWindow;

    QLabel *Input;
    unordered_map<int, QPushButton*> calcButtons;
} CalcWidgets;

typedef struct GraphWidgets  {
    QWidget *graphWindow;
    QCustomPlot *graph;

    unordered_map<int, QLineEdit*> titles;
    unordered_map<int, QDoubleSpinBox*> values;

} GraphWidgets;

typedef struct CreditCalcWidgets  {
    QWidget *creditCalcWindow;

    QLineEdit *creditSum;
    QLineEdit *creditTerm;
    QLineEdit *interestRate;

    QLineEdit *totalPyament;
    QLineEdit *overpayment;

    QVector<QLineEdit*> payments;
} CreditCalcWidgets;


typedef struct DepositCalcWidgets  {
    QWidget *depositCalcWindow;

    QLabel *label;
} DepositCalcWidgets;



enum GraphObjectsEnum {
    LineInput,
    LineScope,
    LineRange,
    LineX,
    LineStepX,

    ScopeMin,
    ScopeMax,
    RangeMin,
    RangeMax,
    X,
    StepX
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
