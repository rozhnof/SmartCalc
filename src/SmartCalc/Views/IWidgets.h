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
    QMainWindow *mainWindow;
    QWidget *Window;

    QCustomPlot *_graph;
    QLineEdit *Input;

    QDoubleSpinBox *rangeMin;
    QDoubleSpinBox *scopeMax;
    QLineEdit *rangeText;

    QDoubleSpinBox *scopeMin;
    QDoubleSpinBox *rangeMax;
    QLineEdit *scopeText;

    QLineEdit *xText;
    QDoubleSpinBox *xInput;
    QLineEdit *xStepText;
    QDoubleSpinBox *xStep;
} GraphWidgets;

typedef struct CreditCalcWidgets  {
    QMainWindow *mainWindow;
    QWidget *Window;

    QLineEdit *creditSum;
    QLineEdit *creditTerm;
    QLineEdit *interestRate;

    QLineEdit *totalPyament;
    QLineEdit *overpayment;

    QVector<QLineEdit*> payments;
} CreditCalcWidgets;


typedef struct DepositCalcWidgets  {
    QMainWindow *mainWindow;
    QWidget *Window;

    QLabel *label;
} DepositCalcWidgets;





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
