#pragma once

#include <QAction>
#include <QCursor>
#include <QDate>
#include <QVector>
#include <cmath>

#include "../Controllers/DepositCalcController.h"
#include "Calendar.h"
#include "IPlatformUI.h"
#include "MainWindow.h"

class DepositCalculatorUI : public MainWindow {
 private:
  DepositCalcController *controller_;
  DepositCalcWidgets *widgets_;
  QToolButton *calendarSender_;

  enum Frequencies {
    DAILY,
    WEEKLY,
    MONTHLY,
    QUARTERLY,
    SEMI_ANNUALLY,
    YEARLY,
    END_OF_TERM
  };
  enum Periods { DAYS, WEEKS, MONTHS, YEARS };

 public:
  DepositCalculatorUI();
  ~DepositCalculatorUI();

  void initWidgets();
  void connectWidgetsToSlots();

  void setGeometry();
  bool setInput();
  void setFrequencyOfPaymentsButton();
  void setPlacementPeriodButton();
  void setOutputContainer();
  void setTableContainer();
  void setTable();
  void setAddInputContainer();
  void setMainInputContainer();
  void setInputValidator();
  void setStyle();

  void setRow(QTableWidget *table, QString date, QString sum);
  void setRow(QTableWidget *table, QString date, QString type, QString sum,
              QString depositSum);
  void setFrequencyButtonActiveAction(QAction *action);
  void setPeriodButtonActiveAction(QAction *action);
  QVector<QDate> setPaymentDays(QDate startDate, QDate endDate,
                                int frequencyOfPayments);
  QDate setEndDate(QDate startDate, int periodType, int periodCount);

  void getOutput();

  void fillGeneralList();

 private slots:
  void clearTakeOffList();
  void clearTopUpList();
  void clearGeneralList();

  void showGeneralTable();
  void showTopUpTable();
  void showTakeOffTable();
  void calendarShow();

  void addTopUp();
  void addTakeOff();

  void setPeriod();
  void setFrequency();
  void setDate();

  void Calculate();
};
