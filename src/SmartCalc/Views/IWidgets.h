#ifndef IWIDGETS_H
#define IWIDGETS_H

#include <QVector>
#include <QPushButton>
#include <unordered_map>
#include <QLabel>
#include <QMainWindow>
#include "qcustomplot.h"

#include "Layout.h"
#include "ChartView.h"

using namespace std;


typedef struct CalcWidgets {
    QMainWindow *calcWindow;

    QLineEdit *Input;
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
    ChartView* chartView;

    unordered_map<int, QTextEdit*> box;
    unordered_map<int, QLabel*> boxTitle;
    unordered_map<int, QLineEdit*> boxText;

    QVector<double> bodyPayments;
    QVector<double> percentPayments;

} CreditCalcWidgets;


typedef struct DepositCalcWidgets  {
    QWidget *depositCalcWindow;
    ChartView* chartView;

    unordered_map<int, QTextEdit*> box;
    unordered_map<int, QLabel*> boxTitle;
    unordered_map<int, QLineEdit*> boxText;

    QVector<double> bodyPayments;
    QVector<double> percentPayments;
} DepositCalcWidgets;


enum CalcObjectsEnum {
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

    ButtonC,
    ButtonAC,
    ButtonUnaryOperator,
    ButtonEXP,
    ButtonResult,
};

enum GraphObjectsEnum {
    ScopeMin,
    ScopeMax,
    RangeMin,
    RangeMax,
    InputX,
    Points
};

enum CreditCalcObjectsEnum {
    CreditSum,
    CreditTerm,
    InterestRate,
    TotalPayment,
    Overpayment,
    MonthlyPayment
};

enum DepositCalcObjectsEnum {
    DepositSum,
    DepositTerm,
    DepositInterestRate,
    DepositTotalPayment,
    DepositOverpayment,
    DepositMonthlyPayment
};






#endif // IWIDGETS_H
