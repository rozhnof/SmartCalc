#pragma once


#include "mainwindow.h"
#include "IPlatformUI.h"
#include "../Controllers/DepositCalcController.h"
#include <cmath>
#include "Calendar.h"
#include <QDate>
#include <QCursor>
#include <QVector>
#include <QAction>


using namespace std;

class DepositCalculatorUI : public MainWindow
{
    QToolButton *calendarSender;
public:
    DepositCalcWidgets *widgets;
    DepositCalcController *controller;



    DepositCalculatorUI() : MainWindow() {
        controller = new DepositCalcController;
        widgets = new DepositCalcWidgets;

        widgets->depositCalcWindow = this;

        CreateObjects();

        SetMainInputContainer();
        SetAddInputContainer();
        SetOutputContainer();
        SetTableContainer();
        SetInputValidator();
        SetTable();

        SetFrequencyOfPaymentsButton();
        SetPlacementPeriodButton();

        Connects();

        SetStyle();
    }

    void CreateObjects() {
        this->setFixedSize(1280, 615);

        widgets->mainInputContainer = NewWidget(this, "container");
        widgets->addInputContainer = NewWidget(this, "container");
        widgets->outputContainer = NewWidget(this, "container");
        widgets->tablesContainer = NewWidget(this, "table_container");

        widgets->box.insert(make_pair(DEPOSIT_AMOUNT, NewWidget(this, "box")));
        widgets->box.insert(make_pair(INTEREST_RATE, NewWidget(this, "box")));
        widgets->box.insert(make_pair(PLACEMENT_PERIOD, NewWidget(this, "box_left")));
        widgets->box.insert(make_pair(SUM, NewWidget(this, "box_right")));
        widgets->box.insert(make_pair(TAX_RATE, NewWidget(this, "box")));
        widgets->box.insert(make_pair(ACCURED_INTEREST, NewWidget(this, "box")));
        widgets->box.insert(make_pair(TOTAL_AMOUNT, NewWidget(this, "box")));
        widgets->box.insert(make_pair(TAX_AMOUNT, NewWidget(this, "box")));

        widgets->boxTitle.insert(make_pair(DEPOSIT_AMOUNT, NewLabel(this, "Deposit Amount", "title")));
        widgets->boxTitle.insert(make_pair(INTEREST_RATE, NewLabel(this, "Interest Rate", "title")));
        widgets->boxTitle.insert(make_pair(PLACEMENT_PERIOD, NewLabel(this, "Placement period", "title")));
        widgets->boxTitle.insert(make_pair(FREQUENCY_OF_PAYMENTS, NewLabel(this, "Frequency of Payments", "title")));
        widgets->boxTitle.insert(make_pair(DATE_OF_PLACEMENT, NewLabel(this, "Date of Placement", "title")));
        widgets->boxTitle.insert(make_pair(DATE, NewLabel(this, "Date", "title")));
        widgets->boxTitle.insert(make_pair(SUM, NewLabel(this, "Sum", "title")));
        widgets->boxTitle.insert(make_pair(TAX_RATE, NewLabel(this, "Tax Rate", "title")));
        widgets->boxTitle.insert(make_pair(ACCURED_INTEREST, NewLabel(this, "Accrued Interest", "title")));
        widgets->boxTitle.insert(make_pair(TOTAL_AMOUNT, NewLabel(this, "Total Amount", "title")));
        widgets->boxTitle.insert(make_pair(TAX_AMOUNT, NewLabel(this, "Tax Amount", "title")));

        widgets->boxData.insert(make_pair(DEPOSIT_AMOUNT, NewLineEdit(this, "", "data")));
        widgets->boxData.insert(make_pair(INTEREST_RATE, NewLineEdit(this, "", "data")));
        widgets->boxData.insert(make_pair(PLACEMENT_PERIOD, NewLineEdit(this, "", "data")));
        widgets->boxData.insert(make_pair(TAX_RATE, NewLineEdit(this, "", "data")));
        widgets->boxData.insert(make_pair(SUM, NewLineEdit(this, "", "data")));
        widgets->boxData.insert(make_pair(ACCURED_INTEREST, NewLineEdit(this, "", "data")));
        widgets->boxData.insert(make_pair(TOTAL_AMOUNT, NewLineEdit(this, "", "data")));
        widgets->boxData.insert(make_pair(TAX_AMOUNT, NewLineEdit(this, "", "data")));

        widgets->setTopUpListButton = NewPushButton(this, "Top Up List", "button");
        widgets->setTakeOffListButton = NewPushButton(this, "Take Off List", "button");
        widgets->setGeneralListButton = NewPushButton(this, "General List", "button");
        widgets->topUpButton = NewPushButton(this, "Top Up", "button_left");
        widgets->takeOffButton = NewPushButton(this, "Take Off", "button_right");
        widgets->calculateButton = NewPushButton(this, "Calculate", "button");
        widgets->dateButton = NewPushButton(this, QDate::currentDate().toString("dd-MM-yyyy"), "button_left");
        widgets->dateOfPlacementButton = NewPushButton(this, QDate::currentDate().toString("dd-MM-yyyy"), "button");
        widgets->frequencyOfPaymentsButton = NewToolButton(this, "", "button");
        widgets->placementPeriodButton = NewToolButton(this, "", "button_right");

        widgets->interestCapitalization = NewCheckBox(this, "Interest Capitalization", "check_box");

        widgets->generalTable = new QTableWidget(this);
        widgets->generalTable->setObjectName("data_table");

        widgets->topUpTable = new QTableWidget(this);
        widgets->topUpTable->setObjectName("data_table");

        widgets->takeOffTable = new QTableWidget(this);
        widgets->takeOffTable->setObjectName("data_table");

        widgets->backgroundCalendar = NewWidget(this, "calendar_background");
        widgets->calendar = new Calendar(widgets->backgroundCalendar);
        widgets->backgroundCalendar->hide();
    }

    class date {
        int year;
        int month;
        int day;
    };

    void SetInput() {
        double depositAmount = widgets->boxData[DEPOSIT_AMOUNT]->text().toDouble();
        double interestRate = widgets->boxData[INTEREST_RATE]->text().toDouble();
        int frequencyOfPayments = widgets->frequencyActiveAction.first;
        bool interestCapitalization = widgets->interestCapitalization->isChecked();
        double taxRate = widgets->boxData[TAX_RATE]->text().toDouble();
        double placementPeriodNumber = widgets->boxData[PLACEMENT_PERIOD]->text().toDouble();
        int placementPeriodType = widgets->periodActiveAction.first;

        QVector<QDate> frequencyOfPaymentsList;
        QDate startDate = QDate::fromString(widgets->dateOfPlacementButton->text(), "dd-MM-yyyy");
        QDate endDate;

        if (placementPeriodType == DAYS) {
            endDate = startDate.addDays(placementPeriodNumber);
        } else if (placementPeriodType == WEEKS) {
            endDate = startDate.addDays(placementPeriodNumber * 7);
        } else if (placementPeriodType == MONTHS) {
            endDate = startDate.addMonths(placementPeriodNumber);
        } else if (placementPeriodType == YEARS) {
            endDate = startDate.addYears(placementPeriodNumber);
        }

        QDate itDate = startDate;



        while (itDate < endDate) {
            if (frequencyOfPayments == DAILY) {
                itDate = itDate.addDays(1);
            } else if (frequencyOfPayments == WEEKLY) {
                 itDate = itDate.addDays(7);
            } else if (frequencyOfPayments == MONTHLY) {
                 itDate = itDate.addMonths(1);
            } else if (frequencyOfPayments == QUARTERLY) {
                 itDate = itDate.addMonths(3);
            } else if (frequencyOfPayments == SEMI_ANNUALLY) {
                 itDate = itDate.addMonths(6);
            } else if (frequencyOfPayments == YEARLY) {
                 itDate = itDate.addYears(1);
            } else if (frequencyOfPayments == END_OF_TERM) {
                 itDate = endDate;
            }
            frequencyOfPaymentsList.append(itDate);
        }

        if (frequencyOfPaymentsList.back() > endDate) {
            frequencyOfPaymentsList.pop_back();
            frequencyOfPaymentsList.push_back(endDate);
        } else if (itDate < endDate) {
            frequencyOfPaymentsList.append(endDate);
        }

//        controller->setDepositCalculatorInput(depositAmount, interestRate, frequencyOfPaymentsList, startDate, endDate, interestCapitalization, taxRate);
    }

    void SetOutput() {
        double accuredInterest = 0;
        double totalAmount = 0;
        double taxAmount = 0;

//        controller->getDepositCalculatorOutput(accuredInterest, totalAmount, taxAmount);

        widgets->boxData[ACCURED_INTEREST]->setText(QString::number(accuredInterest, 'f', 2));
        widgets->boxData[TOTAL_AMOUNT]->setText(QString::number(totalAmount, 'f', 2));
        widgets->boxData[TAX_AMOUNT]->setText(QString::number(taxAmount, 'f', 2));
    }

    void Connects() {
        connect(widgets->dateButton, &QPushButton::clicked, this, &DepositCalculatorUI::CalendarShow);
        connect(widgets->dateOfPlacementButton, &QPushButton::clicked, this, &DepositCalculatorUI::CalendarShow);
        connect(widgets->calendar, &QCalendarWidget::clicked, this, &DepositCalculatorUI::SetDate);
        connect(widgets->calculateButton, &QPushButton::clicked, this, &DepositCalculatorUI::Calculate);
        connect(widgets->topUpButton, &QPushButton::clicked, this, &DepositCalculatorUI::AddTopUp);
        connect(widgets->takeOffButton, &QPushButton::clicked, this, &DepositCalculatorUI::AddTakeOff);
        connect(widgets->setGeneralListButton, &QPushButton::clicked, this, &DepositCalculatorUI::ShowGeneralTable);
        connect(widgets->setTopUpListButton, &QPushButton::clicked, this, &DepositCalculatorUI::ShowTopUpTable);
        connect(widgets->setTakeOffListButton, &QPushButton::clicked, this, &DepositCalculatorUI::ShowTakeOffTable);
    }

    enum Frequencies {
        DAILY,
        WEEKLY,
        MONTHLY,
        QUARTERLY,
        SEMI_ANNUALLY,
        YEARLY,
        END_OF_TERM
    };

    enum Periods {
        DAYS,
        WEEKS,
        MONTHS,
        YEARS
    };


    void SetFrequencyOfPaymentsButton() {
        QMenu *menu = new QMenu(this);
        map<Frequencies, QString> keyAndName;

        keyAndName.insert(make_pair(DAILY, "Daily"));
        keyAndName.insert(make_pair(WEEKLY, "Weekly"));
        keyAndName.insert(make_pair(MONTHLY, "Monthly"));
        keyAndName.insert(make_pair(QUARTERLY, "Quarterly"));
        keyAndName.insert(make_pair(SEMI_ANNUALLY, "Semi-Annualy"));
        keyAndName.insert(make_pair(YEARLY, "Yearly"));
        keyAndName.insert(make_pair(END_OF_TERM, "End of Term"));

        for (auto it : keyAndName) {
            QAction *action = new QAction(this);
            action->setText(it.second);
            action->setData(it.first);
            menu->addAction(action);
            connect(action, &QAction::triggered, this, &DepositCalculatorUI::SetFrequency);
        }
        widgets->frequencyOfPaymentsButton->setMenu(menu);
        widgets->frequencyOfPaymentsButton->setPopupMode(QToolButton::InstantPopup);

        SetFrequencyButtonActiveAction(menu->actions()[MONTHLY]);
    }

    void SetPlacementPeriodButton() {
        QMenu *menu = new QMenu(this);
        map<Periods, QString> keyAndName;

        keyAndName.insert(make_pair(DAYS, "Days"));
        keyAndName.insert(make_pair(WEEKS, "Weeks"));
        keyAndName.insert(make_pair(MONTHS, "Months"));
        keyAndName.insert(make_pair(YEARS, "Years"));

        for (auto it : keyAndName) {
            QAction *action = new QAction(this);
            action->setText(it.second);
            action->setData(it.first);
            menu->addAction(action);
            connect(action, &QAction::triggered, this, &DepositCalculatorUI::SetPeriod);
        }
        widgets->placementPeriodButton->setMenu(menu);
        widgets->placementPeriodButton->setPopupMode(QToolButton::InstantPopup);

        SetPeriodButtonActiveAction(menu->actions()[MONTHS]);
    }

    void SetOutputContainer() {
        widgets->outputContainer->setGeometry(10, widgets->mainInputContainer->y() + widgets->mainInputContainer->height() + 10, 320, 250);

        Layout layout;
        layout.SetStartPoints(widgets->outputContainer->x(), widgets->outputContainer->y());
        layout.SetEndPoints(widgets->outputContainer->x() + widgets->outputContainer->width(), widgets->outputContainer->y() + widgets->outputContainer->height());
        layout.SetRows(3);
        layout.SetColumns(1);
        layout.SetLeftSpacing(10);
        layout.SetRightSpacing(10);
        layout.SetAboveSpacing(35);
        layout.SetBottomSpacing(10);
        layout.SetHorizontalSpacing(2);
        layout.SetVerticalSpacing(35);
        layout.SetAutoSize();

        layout.AddWidget(widgets->box[ACCURED_INTEREST]);
        layout.AddWidget(widgets->box[TOTAL_AMOUNT]);
        layout.AddWidget(widgets->box[TAX_AMOUNT]);

        layout.SetTitle(widgets->box[ACCURED_INTEREST], widgets->boxTitle[ACCURED_INTEREST], Layout::CenterH, Layout::Above, 16, 0, -10);
        layout.SetTitle(widgets->box[TOTAL_AMOUNT], widgets->boxTitle[TOTAL_AMOUNT], Layout::CenterH, Layout::Above, 16, 0, -10);
        layout.SetTitle(widgets->box[TAX_AMOUNT], widgets->boxTitle[TAX_AMOUNT], Layout::CenterH, Layout::Above, 16, 0, -10);

        layout.SetField(widgets->box[ACCURED_INTEREST], widgets->boxData[ACCURED_INTEREST], Layout::Left, 5);
        layout.SetField(widgets->box[TOTAL_AMOUNT], widgets->boxData[TOTAL_AMOUNT], Layout::Left, 5);
        layout.SetField(widgets->box[TAX_AMOUNT], widgets->boxData[TAX_AMOUNT], Layout::Left, 5);
    }

    void SetTableContainer() {
        Layout layout;

        int x0 = widgets->mainInputContainer->x() + widgets->mainInputContainer->width() + 20;
        int y0 = widgets->addInputContainer->y() + widgets->addInputContainer->height() + 26 + 45 + 20;

        int xMax = this->width() - 10;
        int yMax = this->height() - 10;

        layout.SetStartPoints(x0, y0);
        layout.SetEndPoints(xMax, yMax);
        layout.SetRows(1);
        layout.SetColumns(1);
        layout.SetAutoSize();

        layout.AddWidget(widgets->tablesContainer);
        widgets->generalTable->setGeometry(widgets->tablesContainer->x(), widgets->tablesContainer->y(), widgets->tablesContainer->width(), widgets->tablesContainer->height());
        widgets->topUpTable->setGeometry(widgets->tablesContainer->x(), widgets->tablesContainer->y(), widgets->tablesContainer->width(), widgets->tablesContainer->height());
        widgets->takeOffTable->setGeometry(widgets->tablesContainer->x(), widgets->tablesContainer->y(), widgets->tablesContainer->width(), widgets->tablesContainer->height());
    }

    void SetTable() {
       widgets->generalTable->setColumnCount(4);
       QStringList headerLabelsGeneralTable;
       headerLabelsGeneralTable << "Date" << "Operation Type" << "Operation Sum" << "Deposit Sum";
       widgets->generalTable->setHorizontalHeaderLabels(headerLabelsGeneralTable);
       widgets->generalTable->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
       widgets->generalTable->setEditTriggers(QAbstractItemView::NoEditTriggers);

       widgets->takeOffTable->setColumnCount(2);
       QStringList headerLabelsTakeOff;
       headerLabelsTakeOff << "Date" << "Sum";
       widgets->takeOffTable->setHorizontalHeaderLabels(headerLabelsTakeOff);
       widgets->takeOffTable->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
       widgets->takeOffTable->setEditTriggers(QAbstractItemView::NoEditTriggers);

       widgets->topUpTable->setColumnCount(2);
       QStringList headerLabelsTopUpTable;
       headerLabelsTopUpTable << "Date" << "Sum";
       widgets->topUpTable->setHorizontalHeaderLabels(headerLabelsTopUpTable);
       widgets->topUpTable->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
       widgets->topUpTable->setEditTriggers(QAbstractItemView::NoEditTriggers);
    }


    void SetAddInputContainer() {
        widgets->addInputContainer->setGeometry(widgets->mainInputContainer->x() + widgets->mainInputContainer->width() + 10, 10, 930, 170);
        Layout layout;

        layout.SetStartPoints(widgets->addInputContainer->x(), widgets->addInputContainer->y());
        layout.SetEndPoints(widgets->addInputContainer->x() + widgets->addInputContainer->width(), widgets->addInputContainer->y() + widgets->addInputContainer->height());
        layout.SetRows(2);
        layout.SetColumns(3);
        layout.SetLeftSpacing(10);
        layout.SetRightSpacing(10);
        layout.SetAboveSpacing(35);
        layout.SetBottomSpacing(10);
        layout.SetVerticalSpacing(35);
        layout.SetHorizontalSpacing(10);
        layout.SetAutoSize();

        layout.AddWidget(widgets->dateOfPlacementButton);
        layout.SetHorizontalSpacing(2);
        layout.AddWidget(widgets->dateButton, 0.5);
        layout.SetHorizontalSpacing(10);
        layout.AddWidget(widgets->box[SUM], 0.5);
        layout.AddWidget(widgets->interestCapitalization);
        layout.NextRow();
        layout.AddWidget(widgets->box[TAX_RATE]);
        layout.SetHorizontalSpacing(2);
        layout.AddWidget(widgets->topUpButton, 0.5);
        layout.SetHorizontalSpacing(10);
        layout.AddWidget(widgets->takeOffButton, 0.5);
        layout.AddWidget(widgets->calculateButton);
        layout.NextRow();
        layout.AddWidget(widgets->setTopUpListButton);
        layout.AddWidget(widgets->setTakeOffListButton);
        layout.AddWidget(widgets->setGeneralListButton);

        layout.SetTitle(widgets->dateOfPlacementButton, widgets->boxTitle[DATE_OF_PLACEMENT], Layout::CenterH, Layout::Above, 16, 0, -10);
        layout.SetTitle(widgets->box[SUM], widgets->boxTitle[SUM], Layout::CenterH, Layout::Above, 16, 0, -10);
        layout.SetTitle(widgets->box[TAX_RATE], widgets->boxTitle[TAX_RATE], Layout::CenterH, Layout::Above, 16, 0, -10);
        layout.SetTitle(widgets->dateButton, widgets->boxTitle[DATE], Layout::CenterH, Layout::Above, 16, 0, -10);

        layout.SetField(widgets->box[TAX_RATE], widgets->boxData[TAX_RATE], Layout::CenterH, 0);
        layout.SetField(widgets->box[SUM], widgets->boxData[SUM], Layout::CenterH, 0);
    }

    void SetMainInputContainer() {
        widgets->mainInputContainer->setGeometry(10, 10, 320, 335);

        Layout layout;
        layout.SetStartPoints(widgets->mainInputContainer->x(), widgets->mainInputContainer->y());
        layout.SetEndPoints(widgets->mainInputContainer->x() + widgets->mainInputContainer->width(), widgets->mainInputContainer->y() + widgets->mainInputContainer->height());
        layout.SetRows(4);
        layout.SetColumns(1);
        layout.SetLeftSpacing(10);
        layout.SetRightSpacing(10);
        layout.SetAboveSpacing(35);
        layout.SetBottomSpacing(10);
        layout.SetHorizontalSpacing(2);
        layout.SetVerticalSpacing(35);
        layout.SetAutoSize();

        layout.AddWidget(widgets->box[DEPOSIT_AMOUNT]);
        layout.AddWidget(widgets->box[INTEREST_RATE]);
        layout.ChangeColumns(2);
        layout.AddWidget(widgets->box[PLACEMENT_PERIOD]);
        layout.AddWidget(widgets->placementPeriodButton);
        layout.ChangeColumns(1);
        layout.AddWidget(widgets->frequencyOfPaymentsButton);

        layout.SetTitle(widgets->box[DEPOSIT_AMOUNT], widgets->boxTitle[DEPOSIT_AMOUNT], Layout::CenterH, Layout::Above, 16, 0, -10);
        layout.SetTitle(widgets->box[INTEREST_RATE], widgets->boxTitle[INTEREST_RATE], Layout::CenterH, Layout::Above, 16, 0, -10);
        layout.SetTitle(widgets->box[PLACEMENT_PERIOD], widgets->boxTitle[PLACEMENT_PERIOD], Layout::Left, Layout::Above, 16, widgets->box[PLACEMENT_PERIOD]->width()/2 + 10, -10);
        layout.SetTitle(widgets->frequencyOfPaymentsButton, widgets->boxTitle[FREQUENCY_OF_PAYMENTS], Layout::CenterH, Layout::Above, 16, 0, -10);

        layout.SetField(widgets->box[DEPOSIT_AMOUNT], widgets->boxData[DEPOSIT_AMOUNT], Layout::Left, 5);
        layout.SetField(widgets->box[INTEREST_RATE], widgets->boxData[INTEREST_RATE], Layout::Left, 5);
        layout.SetField(widgets->box[PLACEMENT_PERIOD], widgets->boxData[PLACEMENT_PERIOD], Layout::Left, 5);
    }

    void SetInputValidator() {
        widgets->boxData[DEPOSIT_AMOUNT]->setValidator(new QRegularExpressionValidator(QRegularExpression("[0-9]{1,10}([.][0-9]{1,2})?"), this));
        widgets->boxData[INTEREST_RATE]->setValidator(new QRegularExpressionValidator(QRegularExpression("[0-9]{1,3}([.][0-9]{1,2})?"), this));
        widgets->boxData[TAX_RATE]->setValidator(new QRegularExpressionValidator(QRegularExpression("[0-9]{1,2}([.][0-9]{1,2})?"), this));
        widgets->boxData[SUM]->setValidator(new QRegularExpressionValidator(QRegularExpression("[0-9]{1,10}([.][0-9]{1,2})?"), this));
        widgets->boxData[PLACEMENT_PERIOD]->setValidator(new QRegularExpressionValidator(QRegularExpression("[0-9]{1,2}"), this));
    }

    void SetRow(QTableWidget *table, QString date, QString sum) {
        int currentRow = table->rowCount();
        table->setRowCount(currentRow + 1);

        table->setItem(currentRow, 0, new QTableWidgetItem(date));
        table->setItem(currentRow, 1, new QTableWidgetItem(sum));
    }

    void SetRow(QTableWidget *table, QString date, QString type, QString sum, QString depositSum) {
        int currentRow = table->rowCount();
        table->setRowCount(currentRow + 1);

        table->setItem(currentRow, 0, new QTableWidgetItem(date));
        table->setItem(currentRow, 1, new QTableWidgetItem(type));
        table->setItem(currentRow, 2, new QTableWidgetItem(sum));
        table->setItem(currentRow, 3, new QTableWidgetItem(depositSum));
    }

    void SetFrequencyButtonActiveAction(QAction *action) {
        widgets->frequencyActiveAction.first = action->data().toInt();
        widgets->frequencyActiveAction.second = action;

        widgets->frequencyOfPaymentsButton->setText(action->text());
    }

    void SetPeriodButtonActiveAction(QAction *action) {
        widgets->periodActiveAction.first = action->data().toInt();
        widgets->periodActiveAction.second = action;

        widgets->placementPeriodButton->setText(action->text());
    }

    void FillGeneralList() {
//        widgets->generalTable->setRowCount(0);
//        QVector<std::tuple<QDate, QString, double, double>> generalList = controller->getGeneralList();

//        for (const auto& tuple : generalList) {
//             QString date = std::get<0>(tuple).toString("dd-MM-yyyy");
//             QString type = std::get<1>(tuple);
//             QString operationSum = QString::number(std::get<2>(tuple));
//             QString depositSum = QString::number(std::get<3>(tuple));

//             SetRow(widgets->generalTable, date, type, operationSum, depositSum);
//        }
    }

    void SetStyle() {
        QString styleSheet = R"(
            QWidget#deposit_calculator_window, QWidget#table_container{
                background-color: rgb(27, 32, 50);
            }
            QWidget#container {
                background-color: rgb(46, 49, 68);
                border: none;
                border-radius: 10;
            }
            QWidget#box {
                background-color: rgb(217, 217, 217);
                border: none;
                border-radius: 10;
            }
            QWidget#title {
                background-color: rgba(0, 0, 0, 0);
                color: rgb(217, 217, 217);
            }
            QWidget#data {
                background-color: rgba(0, 0, 0, 0);
                color: rgb(37, 37, 37);
                font-size: 16px;
            }
            QPushButton#button, QToolButton#button {
                background-color: rgb(217, 217, 217);
                border-radius: 10;
                color: rgb(37, 37, 37);
                font-size: 16px;
            }
            QPushButton#button_left {
                background-color: rgb(217, 217, 217);
                border-top-left-radius: 10;
                border-bottom-left-radius: 10;
                color: rgb(37, 37, 37);
                font-size: 16px;
            }
            QPushButton#button_right, QToolButton#button_right {
                background-color: rgb(217, 217, 217);
                border-top-right-radius: 10;
                border-bottom-right-radius: 10;
                color: rgb(37, 37, 37);
                font-size: 16px;
            }
            QWidget#box_right {
                background-color: rgb(217, 217, 217);
                border-top-right-radius: 10;
                border-bottom-right-radius: 10;
            }
            QWidget#box_left {
                background-color: rgb(217, 217, 217);
                border-top-left-radius: 10;
                border-bottom-left-radius: 10;
            }
            QPushButton#button:hover, QPushButton#button_left:hover, QPushButton#button_right:hover, QToolButton#button:hover, QToolButton#button_right:hover {
                background-color: rgb(194, 194, 194);
            }
            QPushButton#button:pressed, QPushButton#button_left:pressed, QPushButton#button_right:pressed, QToolButton#button:pressed, QToolButton#button_right:pressed {
                background-color: rgb(171, 171, 171);
            }
            QCheckBox {
                background-color: rgba(0, 0, 0, 0);
                font-size: 16px;
            }
            QCheckBox::indicator {
                background-color: rgba(27, 32, 50, 1);
                border: 1px solid rgba(217, 217, 217, 1);
                border-radius: 5;
                width: 18px;
                height: 18px;
            }
            QCheckBox::indicator:checked {
                background-color: rgba(217, 217, 217, 1);
            }
            QTableView#data_table::item:hover {
                background-color: rgba(46, 49, 68, 1);
                padding-left: 2;
            }
            QTableView#data_table {
                background-color: rgb(27, 32, 50);
                border: none;
                border-radius: 10;
                gridline-color: rgba(46, 49, 68, 1);
            }
            QTableView#data_table::item:selected {
                background-color: rgba(37, 41, 59, 1);
            }
            QTableView#data_table QHeaderView::section {
                background-color: rgba(27, 32, 50, 1);
                border: 1px solid rgba(46, 49, 68, 1);
                font-weight: bold;
            }
            QTableView#data_table QHeaderView::section:checked {
                background-color: rgba(46, 49, 68, 1);
            }
            QTableView#data_table QHeaderView::section:pressed, QTableView#data_table QTableCornerButton:pressed {
                background-color: rgba(37, 41, 59, 1);
            }
            QTableView#data_table QHeaderView::section:hover {
                background-color: rgba(46, 49, 68, 1);
            }
            QTableView#data_table QTableCornerButton {
                background-color: rgba(46, 49, 68, 1);
                border: 1px solid rgb(46, 49, 68);
            }
            QWidget#calendar_background {
                background-color: rgba(245, 246, 250, 1);
            }
            QToolButton#button::menu-indicator, QToolButton#button_right::menu-indicator {
                width: 0px;
            }
            QToolButton#button QMenu, QToolButton#button_right QMenu {
                background-color: rgb(255, 255, 255);
                color: rgb(72, 75, 79);
            }
            QToolButton#button QMenu::item:selected, QToolButton#button_right QMenu::item:selected {
                background-color: rgb(230,230,230);
                border: 1px rgb(230,230,230);
                border-radius: 5;
            }
        )";
        widgets->depositCalcWindow->setStyleSheet(styleSheet);

        for (auto it : widgets->boxData) {
            it.second->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
        }

        widgets->boxData[ACCURED_INTEREST]->setReadOnly(true);
        widgets->boxData[TOTAL_AMOUNT]->setReadOnly(true);
        widgets->boxData[TAX_AMOUNT]->setReadOnly(true);
    }

private slots:

    void ShowGeneralTable() {
        widgets->takeOffTable->hide();
        widgets->topUpTable->hide();
        widgets->generalTable->show();
    }

    void ShowTopUpTable() {
        widgets->generalTable->hide();
        widgets->takeOffTable->hide();
        widgets->topUpTable->show();
    }

    void ShowTakeOffTable() {
        widgets->generalTable->hide();
        widgets->topUpTable->hide();
        widgets->takeOffTable->show();
    }

    void AddTopUp() {
        if (widgets->topUpList.size() < 50) {
            QDate date = QDate::fromString(widgets->dateButton->text(), "dd-MM-yyyy");
            double sum = widgets->boxData[SUM]->text().toDouble();

            widgets->topUpList.insert(make_pair(date, sum));
            widgets->topUpTable->setRowCount(0);

            for (auto it : widgets->topUpList) {
                SetRow(widgets->topUpTable, it.first.toString("dd-MM-yyyy"), QString::number(it.second, 'f', 2));
            }
        }
        ShowTopUpTable();
    }

    void AddTakeOff() {
        if (widgets->takeOffList.size() < 50) {
            QDate date = QDate::fromString(widgets->dateButton->text(), "dd-MM-yyyy");
            double sum = widgets->boxData[SUM]->text().toDouble();

            widgets->takeOffList.insert(make_pair(date, sum));
            widgets->takeOffTable->setRowCount(0);

            for (auto it : widgets->takeOffList) {
                SetRow(widgets->takeOffTable, it.first.toString("dd-MM-yyyy"), QString::number(it.second, 'f', 2));
            }
        }
        ShowTakeOffTable();
    }


    void Calculate() {
        DepositCalculatorInput input;
        SetInput();

        if (controller->Validate(input)) {
            controller->setInput(input);
            SetOutput();
            FillGeneralList();
            ShowGeneralTable();
        }
    }

    void SetPeriod() {
        SetPeriodButtonActiveAction(static_cast<QAction*>(sender()));
    }

    void SetFrequency() {
        SetFrequencyButtonActiveAction(static_cast<QAction*>(sender()));
    }

    void CalendarShow() {
        calendarSender = static_cast<QToolButton*>(sender());

        int calendarWidth = 300;
        int calendarHeight = 300;

        int calendarY = calendarSender->y() + calendarSender->height() + 10;
        int calendarX = calendarSender->x() + calendarSender->width() / 2 - calendarWidth / 2;

        widgets->backgroundCalendar->setGeometry(calendarX, calendarY, calendarWidth, calendarHeight);
        widgets->calendar->setGeometry(10, 10, widgets->backgroundCalendar->width() - 15, widgets->backgroundCalendar->height() - 20);
        widgets->backgroundCalendar->show();
    }

    void SetDate() {
        widgets->backgroundCalendar->hide();
        QDate selectedDate(widgets->calendar->selectedDate());
        calendarSender->setText(selectedDate.toString("dd-MM-yyyy"));
    }
};
