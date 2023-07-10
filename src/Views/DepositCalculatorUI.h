#pragma once


#include "MainWindow.h"
#include "IPlatformUI.h"
#include "../Controllers/DepositCalcController.h"
#include <cmath>
#include "Calendar.h"
#include <QDate>
#include <QCursor>
#include <QVector>
#include <QAction>


class DepositCalculatorUI : public MainWindow
{
private:
    DepositCalcController *_controller;
    DepositCalcWidgets *_widgets;
    QToolButton *_calendarSender;

public:
    DepositCalculatorUI();

    ~DepositCalculatorUI();

    void initWidgets();

    void setGeometry();

    bool setInput();

    enum Periods {
        DAYS,
        WEEKS,
        MONTHS,
        YEARS
    };

    QVector<QDate> setPaymentDays(QDate startDate, QDate endDate, int frequencyOfPayments);

    QDate setEndDate(QDate startDate, int periodType, int periodCount);



    void getOutput();

    void connectWidgetsToSlots();

    enum Frequencies {
        DAILY,
        WEEKLY,
        MONTHLY,
        QUARTERLY,
        SEMI_ANNUALLY,
        YEARLY,
        END_OF_TERM
    };

    void setFrequencyOfPaymentsButton();

    void setPlacementPeriodButton();

    void setOutputContainer();

    void setTableContainer();

    void setTable();


    void setAddInputContainer();

    void setMainInputContainer();

    void setInputValidator();

    void setRow(QTableWidget *table, QString date, QString sum);

    void setRow(QTableWidget *table, QString date, QString type, QString sum, QString depositSum);

    void setFrequencyButtonActiveAction(QAction *action);

    void setPeriodButtonActiveAction(QAction *action);

    void fillGeneralList();

    void setStyle();

private slots:

    void clearTakeOffList();

    void clearTopUpList();

    void clearGeneralList();

    void showGeneralTable();

    void showTopUpTable();

    void showTakeOffTable();

    void addTopUp();

    void addTakeOff();


    void Calculate();

    void setPeriod();

    void setFrequency();

    void calendarShow();

    void setDate();
};
