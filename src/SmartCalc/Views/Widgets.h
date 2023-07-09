#pragma once


#include <QVector>
#include <QPushButton>
#include <unordered_map>
#include <QLabel>
#include <QMainWindow>
#include "qcustomplot.h"
#include "Calendar.h"
#include "ChartView.h"

using namespace std;


typedef struct CalcWidgets {
    QMainWindow *calculatorWindow;
    QWidget *inputXWidget;

    QLineEdit *inputLineEdit;
    QLineEdit *inputXLineEdit;

    QPushButton *buttonAllClear;
    QPushButton *buttonClear;
    QPushButton *buttonEqual;

    QPropertyAnimation *animation;

    unordered_map<int, QPushButton*> buttonDictionary;
} CalcWidgets;

typedef struct GraphWidgets  {
    QWidget *graphWindow;
    QCustomPlot *graph;

    QLineEdit *inputLineEdit;
    QCheckBox* checkBoxLineDrawing;

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

    QVector<double> bodyPaymentCollection;
    QVector<double> percentPaymentCollection;

    QComboBox *monthlyPaymentList;
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

    QPushButton *buttonClearGeneralTable;
    QPushButton *buttonClearTopUpTable;
    QPushButton *buttonClearTakeOffTable;

    unordered_map<int, QWidget*> box;
    unordered_map<int, QLabel*> boxTitle;
    unordered_map<int, QLineEdit*> boxData;
    unordered_map<int, QString> operationTypes;

} DepositCalcWidgets;


enum CalcWidgetsEnum {
    BUTTON_0,
    BUTTON_1,
    BUTTON_2,
    BUTTON_3,
    BUTTON_4,
    BUTTON_5,
    BUTTON_6,
    BUTTON_7,
    BUTTON_8,
    BUTTON_9,
    BUTTON_DOT,

    BUTTON_X,

    BUTTON_SIN,
    BUTTON_COS,
    BUTTON_TAN,
    BUTTON_ASIN,
    BUTTON_ACOS,
    BUTTON_ATAN,
    BUTTON_LOG,
    BUTTON_LN,
    BUTTON_SQRT,

    BUTTON_SUM,
    BUTTON_SUB,
    BUTTON_MUL,
    BUTTON_DIV,
    BUTTON_MOD,
    BUTTON_POW,
    BUTTON_FACTORIAL,

    BUTTON_OPEN_BRACKET,
    BUTTON_CLOSE_BRACKET,
    BUTTON_EXP
};

enum GraphWidgetsEnum {
    INPUT,
    SCOPE_MIN,
    SCOPE_MAX,
    RANGE_MIN,
    RANGE_MAX,
    INPUT_X,
    POINTS
};

enum CreditCalcWidgetsEnum {
    CREDIT_SUM,
    CREDIT_TERM,
    CREDIT_INTEREST_RATE,
    CREDIT_TOTAL_PAYMENT,
    CREDIT_OVERPAYMENT,
    CREDIT_MONTHLY_PAYMENT
};

enum DepositCalcWidgetsEnum {
    DEPOSIT_AMOUNT,
    DEPOSIT_INTEREST_RATE,
    DEPOSIT_PLACEMENT_PERIOD,
    DEPOSIT_FREQUENCY_OF_PAYMENTS,
    DEPOSIT_DATE_OF_PLACEMENT,
    DEPOSIT_TAX_RATE,
    DEPOSIT_OPERATION_DATE,
    DEPOSIT_OPERATION_SUM,
    DEPOSIT_ACCURED_INTEREST,
    DEPOSIT_TOTAL_AMOUNT,
    DEPOSIT_TAX_AMOUNT
};
