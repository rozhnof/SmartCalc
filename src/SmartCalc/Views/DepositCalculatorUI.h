#ifndef DEPOSITCALCULATORUI_H
#define DEPOSITCALCULATORUI_H

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
        Connects();
        SetTableData();
        SetFrequencyOfPaymentsButton();
    }

    void CreateObjects() {
        this->setFixedSize(1280, 615);

        widgets->mainInputContainer = NewWidget(this, "container");
        widgets->addInputContainer = NewWidget(this, "container");
        widgets->outputContainer = NewWidget(this, "container");

        widgets->box.insert(make_pair(DEPOSIT_AMOUNT, NewWidget(this, "box")));
        widgets->box.insert(make_pair(INTEREST_RATE, NewWidget(this, "box")));
        widgets->box.insert(make_pair(PLACEMENT_PERIOD, NewWidget(this, "box")));
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

        widgets->setTopUpList = NewPushButton(this, "Top Up List", "button");
        widgets->setTakeOffList = NewPushButton(this, "Take Off List", "button");
        widgets->setGeneralList = NewPushButton(this, "General List", "button");
        widgets->topUp = NewPushButton(this, "Top Up", "button_left");
        widgets->takeOff = NewPushButton(this, "Take Off", "button_right");
        widgets->calculate = NewPushButton(this, "Calculate", "button");
        widgets->dateButton = NewPushButton(this, QDate::currentDate().toString("dd-MM-yyyy"), "button_left");
        widgets->dateOfPlacement = NewPushButton(this, QDate::currentDate().toString("dd-MM-yyyy"), "button");
        widgets->frequencyOfPayments = NewPushButton(this, "", "button");

        widgets->interestCapitalization = NewCheckBox(this, "Interest Capitalization", "check_box");
        widgets->tableWidget = new QTableWidget(this);
        widgets->tableWidget->setObjectName("data_table");

        widgets->backgroundCalendar = NewWidget(this, "calendar_background");
        widgets->calendar = new Calendar(widgets->backgroundCalendar);
        widgets->backgroundCalendar->hide();
    }

    void Connects() {
        connect(widgets->dateButton, &QPushButton::clicked, this, &DepositCalculatorUI::CalendarShow);
        connect(widgets->dateOfPlacement, &QPushButton::clicked, this, &DepositCalculatorUI::CalendarShow);
        connect(widgets->calendar, &QCalendarWidget::clicked, this, &DepositCalculatorUI::SetDate);

    }

    enum Frequencies {
        DAILY,
        WEEKLY,
        MONTHLY,
        QUARTERLY,
        SEMI_ANNUALLY,
        AT_MATURITY,
        END_OF_TERM
    };

    void SetFrequencyOfPaymentsButton() {
        widgets->frequenciesMenu = new QMenu(widgets->frequencyOfPayments);
        unordered_map<Frequencies, QString> frequencies;

        frequencies.insert(std::make_pair(DAILY, "Daily"));
        frequencies.insert(std::make_pair(WEEKLY, "Weekly"));
        frequencies.insert(std::make_pair(MONTHLY, "Monthly"));
        frequencies.insert(std::make_pair(QUARTERLY, "Quarterly"));
        frequencies.insert(std::make_pair(SEMI_ANNUALLY, "Semi-Annually"));
        frequencies.insert(std::make_pair(AT_MATURITY, "At Maturity"));
        frequencies.insert(std::make_pair(END_OF_TERM, "End of Term"));

        for (auto it : frequencies) {
            QAction* action = new QAction(it.second);
            widgets->frequenciesMenu->addAction(action);
            connect(action, &QAction::triggered, this, &DepositCalculatorUI::SetCurrentFrequency);
        }

//        widgets->frequenciesMenu->setActiveAction(frequencies[MONTHLY]);
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
        layout.SetRows(2);
        layout.SetColumns(3);
        layout.SetVerticalSpacing(20);
        layout.SetHorizontalSpacing(10);
        layout.SetDefaultElementSize(300, 45);

        layout.ChangeColumns(1);
        layout.SetDefaultElementSize(925, 335);

        layout.AddWidget(widgets->tableWidget);
    }

    void SetTable() {
       widgets->tableWidget->setColumnCount(4);

       QStringList headerLabels;
       headerLabels << "Date" << "Operation Type" << "Operation Sum" << "Deposit Sum";
       widgets->tableWidget->setHorizontalHeaderLabels(headerLabels);
       widgets->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
       widgets->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    }

    void SetTableData() {
        for (int i = 0; i < 100; i++) {
            widgets->tableWidget->insertRow(i);

            widgets->tableWidget->setItem(i, 0, new QTableWidgetItem("2023-06-19"));
            widgets->tableWidget->setItem(i, 1, new QTableWidgetItem("Deposit"));
            widgets->tableWidget->setItem(i, 2, new QTableWidgetItem("1000"));
            widgets->tableWidget->setItem(i, 3, new QTableWidgetItem("50000"));
        }
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

        layout.AddWidget(widgets->dateOfPlacement);
        layout.SetHorizontalSpacing(2);
        layout.AddWidget(widgets->dateButton, 0.5);
        layout.SetHorizontalSpacing(10);
        layout.AddWidget(widgets->box[SUM], 0.5);
        layout.AddWidget(widgets->interestCapitalization);
        layout.NextRow();
        layout.AddWidget(widgets->box[TAX_RATE]);
        layout.SetHorizontalSpacing(2);
        layout.AddWidget(widgets->topUp, 0.5);
        layout.SetHorizontalSpacing(10);
        layout.AddWidget(widgets->takeOff, 0.5);
        layout.AddWidget(widgets->calculate);
        layout.NextRow();
        layout.AddWidget(widgets->setTopUpList);
        layout.AddWidget(widgets->setTakeOffList);
        layout.AddWidget(widgets->setGeneralList);

        layout.SetTitle(widgets->dateOfPlacement, widgets->boxTitle[DATE_OF_PLACEMENT], Layout::CenterH, Layout::Above, 16, 0, -10);
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
        layout.SetVerticalSpacing(35);
        layout.SetAutoSize();

        layout.AddWidget(widgets->box[DEPOSIT_AMOUNT]);
        layout.AddWidget(widgets->box[INTEREST_RATE]);
        layout.AddWidget(widgets->box[PLACEMENT_PERIOD]);
        layout.AddWidget(widgets->frequencyOfPayments);

        layout.SetTitle(widgets->box[DEPOSIT_AMOUNT], widgets->boxTitle[DEPOSIT_AMOUNT], Layout::CenterH, Layout::Above, 16, 0, -10);
        layout.SetTitle(widgets->box[INTEREST_RATE], widgets->boxTitle[INTEREST_RATE], Layout::CenterH, Layout::Above, 16, 0, -10);
        layout.SetTitle(widgets->box[PLACEMENT_PERIOD], widgets->boxTitle[PLACEMENT_PERIOD], Layout::CenterH, Layout::Above, 16, 0, -10);
        layout.SetTitle(widgets->frequencyOfPayments, widgets->boxTitle[FREQUENCY_OF_PAYMENTS], Layout::CenterH, Layout::Above, 16, 0, -10);

        layout.SetField(widgets->box[DEPOSIT_AMOUNT], widgets->boxData[DEPOSIT_AMOUNT], Layout::Left, 5);
        layout.SetField(widgets->box[INTEREST_RATE], widgets->boxData[INTEREST_RATE], Layout::Left, 5);
        layout.SetField(widgets->box[PLACEMENT_PERIOD], widgets->boxData[PLACEMENT_PERIOD], Layout::Left, 5);
    }

    void SetInputValidator() {
        widgets->boxData[DEPOSIT_AMOUNT]->setValidator(new QRegularExpressionValidator(QRegularExpression("[0-9]{1,10}([.][0-9]{1,2})?"), this));
        widgets->boxData[INTEREST_RATE]->setValidator(new QRegularExpressionValidator(QRegularExpression("[0-9]{1,3}([.][0-9]{1,2})?"), this));
        widgets->boxData[TAX_RATE]->setValidator(new QRegularExpressionValidator(QRegularExpression("[0-9]{1,3}([.][0-9]{1,2})?"), this));
        widgets->boxData[SUM]->setValidator(new QRegularExpressionValidator(QRegularExpression("[0-9]{1,10}([.][0-9]{1,2})?"), this));
        widgets->boxData[PLACEMENT_PERIOD]->setValidator(new QRegularExpressionValidator(QRegularExpression("[0-9]{1,7}"), this));
    }


    void SetupUI() override {
        (*_platform)->SetupUI(widgets);
    }

private slots:
    void SetCurrentFrequency() {
        widgets->frequencyOfPayments->setText(static_cast<QAction*>(sender())->text());
    }

    void CalendarShow() {
        calendarSender = static_cast<QToolButton*>(sender());
        QPoint windowPos = mapFromGlobal(QCursor::pos());
        widgets->backgroundCalendar->setGeometry(windowPos.x(), windowPos.y(), 300, 300);
        widgets->calendar->setGeometry(10, 10, widgets->backgroundCalendar->width() - 15, widgets->backgroundCalendar->height() - 20);
        widgets->backgroundCalendar->show();
    }

    void SetDate() {
        widgets->backgroundCalendar->hide();
        QDate selectedDate(widgets->calendar->selectedDate());
        calendarSender->setText(selectedDate.toString("dd-MM-yyyy"));
    }
};



#endif // DEPOSITCALCULATORUI_H
