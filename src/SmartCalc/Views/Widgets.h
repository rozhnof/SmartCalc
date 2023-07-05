#pragma once


#include <QVector>
#include <QPushButton>
#include <unordered_map>
#include <QLabel>
#include <QMainWindow>
#include "qcustomplot.h"
#include "Calendar.h"

#include "Layout.h"
#include "ChartView.h"

using namespace std;


typedef struct CalcWidgets {
    QMainWindow *calcWindow;

    QLineEdit *Input;
    QPushButton *allClear;
    QPushButton *clear;
    QPushButton *result;

    unordered_map<int, QPushButton*> calcButtons;
} CalcWidgets;

typedef struct GraphWidgets  {
    QWidget *graphWindow;
    QCustomPlot *graph;

    QLineEdit *Input;
    QCheckBox* drawingLine;

    unordered_map<int, QTextEdit*> box;
    unordered_map<int, QLabel*> title;
    unordered_map<int, QDoubleSpinBox*> data;
} GraphWidgets;

typedef struct CreditCalcWidgets  {
    QWidget *creditCalcWindow;
    ChartView* chartView;

    unordered_map<int, QTextEdit*> box;
    unordered_map<int, QLabel*> title;
    unordered_map<int, QLineEdit*> data;

    QVector<double> bodyPayments;
    QVector<double> percentPayments;

    QComboBox *monthlyPaymentList;
    QComboBox *creditTermList;
    QPushButton *annuityPaymentButton;
    QPushButton *differentiatedPaymentButton;

} CreditCalcWidgets;


typedef struct DepositCalcWidgets  {
    QWidget *depositCalcWindow;
    Calendar *calendar;
    QWidget *backgroundCalendar;

    QTableWidget *generalTable;
    QTableWidget *topUpTable;
    QTableWidget *takeOffTable;

    QWidget* mainInputContainer;
    QWidget* addInputContainer;
    QWidget* outputContainer;
    QWidget* tablesContainer;

    QPushButton *topUpButton;
    QPushButton *takeOffButton;
    QPushButton *dateButton;
    QPushButton *dateOfPlacementButton;

    QPushButton *setTopUpListButton;
    QPushButton *setTakeOffListButton;
    QPushButton *setGeneralListButton;

    QCheckBox *interestCapitalization;

    QPushButton *calculateButton;


    QToolButton *frequencyOfPaymentsButton;
    pair<int, QAction*> frequencyActiveAction;

    QToolButton *placementPeriodButton;
    pair<int, QAction*> periodActiveAction;

    multimap<QDate, double> generalList;
    multimap<QDate, double> topUpList;
    multimap<QDate, double> takeOffList;

    unordered_map<int, QWidget*> box;
    unordered_map<int, QLabel*> boxTitle;
    unordered_map<int, QLineEdit*> boxData;
    unordered_map<int, QString> operationTypes;

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
    ButtonEXP
};

enum GraphObjectsEnum {
    Input,
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
    DEPOSIT_AMOUNT,
    INTEREST_RATE,
    PLACEMENT_PERIOD,
    FREQUENCY_OF_PAYMENTS,
    DATE_OF_PLACEMENT,
    TAX_RATE,
    OPERATION_DATE,
    OPERATION_SUM,
    ACCURED_INTEREST,
    TOTAL_AMOUNT,
    TAX_AMOUNT
};
