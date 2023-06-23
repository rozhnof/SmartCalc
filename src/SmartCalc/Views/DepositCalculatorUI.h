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
        SetPlacementPeriodButton();
    }

    enum OperationTypes {
        REPLENISHMENT,
        WITHDRAWAL
    };

    void SetOperationTypes() {
        widgets->operationTypes.insert(make_pair(REPLENISHMENT, "REPLENISHMENT"));
        widgets->operationTypes.insert(make_pair(REPLENISHMENT, "WITHDRAWAL"));
    }

    void CreateObjects() {
        this->setFixedSize(1280, 615);

        widgets->mainInputContainer = NewWidget(this, "container");
        widgets->addInputContainer = NewWidget(this, "container");
        widgets->outputContainer = NewWidget(this, "container");

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

        widgets->setTopUpList = NewPushButton(this, "Top Up List", "button");
        widgets->setTakeOffList = NewPushButton(this, "Take Off List", "button");
        widgets->setGeneralList = NewPushButton(this, "General List", "button");
        widgets->topUp = NewPushButton(this, "Top Up", "button_left");
        widgets->takeOff = NewPushButton(this, "Take Off", "button_right");
        widgets->calculate = NewPushButton(this, "Calculate", "button");
        widgets->dateButton = NewPushButton(this, QDate::currentDate().toString("dd-MM-yyyy"), "button_left");
        widgets->dateOfPlacement = NewPushButton(this, QDate::currentDate().toString("dd-MM-yyyy"), "button");
        widgets->frequencyOfPayments = NewPushButton(this, "", "button");
        widgets->placementPeriod = NewPushButton(this, "Month", "button_right");

        widgets->interestCapitalization = NewCheckBox(this, "Interest Capitalization", "check_box");
        widgets->tableWidget = new QTableWidget(this);
        widgets->tableWidget->setObjectName("data_table");

        widgets->backgroundCalendar = NewWidget(this, "calendar_background");
        widgets->calendar = new Calendar(widgets->backgroundCalendar);
        widgets->backgroundCalendar->hide();
    }

    void SetInput() {
        double depositAmount = widgets->boxData[DEPOSIT_AMOUNT]->text().toDouble();
        double interestRate = widgets->boxData[INTEREST_RATE]->text().toDouble();
        double placementPeriod = widgets->boxData[PLACEMENT_PERIOD]->text().toDouble();
        int frequencyOfPayments = widgets->frequencyOfPayments->menu()->activeAction()->data().toInt();
        bool interestCapitalization = widgets->interestCapitalization->isChecked();

        std::cout << interestCapitalization << std::endl;

        QVector<QDate> frequencyOfPaymentsList;
        QDate startDate = QDate::fromString(widgets->dateOfPlacement->text(), "dd-MM-yyyy");
        QDate endDate = startDate.addDays(placementPeriod);
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
        controller->setDepositCalculatorInput(depositAmount, interestRate, placementPeriod, frequencyOfPaymentsList, startDate, interestCapitalization);
    }

    void SetOutput() {
        double accuredInterest = 0;
        double totalAmount = 0;
        double taxAmount = 0;

        controller->getDepositCalculatorOutput(accuredInterest, totalAmount, taxAmount);

        widgets->boxData[ACCURED_INTEREST]->setText(QString::number(accuredInterest, 'f', 2));
        widgets->boxData[TOTAL_AMOUNT]->setText(QString::number(totalAmount, 'f', 2));
        widgets->boxData[TAX_AMOUNT]->setText(QString::number(taxAmount, 'f', 2));
    }

    void Connects() {
        connect(widgets->dateButton, &QPushButton::clicked, this, &DepositCalculatorUI::CalendarShow);
        connect(widgets->dateOfPlacement, &QPushButton::clicked, this, &DepositCalculatorUI::CalendarShow);
        connect(widgets->calendar, &QCalendarWidget::clicked, this, &DepositCalculatorUI::SetDate);
        connect(widgets->calculate, &QPushButton::clicked, this, &DepositCalculatorUI::Calculate);
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
        QMenu *frequencyMenu = new QMenu(widgets->frequencyOfPayments);

        unordered_map<Frequencies, QString> freqMap;
        freqMap.insert({DAILY, "Daily"});
        freqMap.insert({WEEKLY, "Weekly"});
        freqMap.insert({MONTHLY, "Monthly"});
        freqMap.insert({QUARTERLY, "Quarterly"});
        freqMap.insert({SEMI_ANNUALLY, "Semi-Annually"});
        freqMap.insert({YEARLY, "Yearly"});
        freqMap.insert({END_OF_TERM, "End of Term"});

        for (auto it : freqMap) {
            QAction *action = new QAction(it.second, frequencyMenu);
            action->setData(it.first);
            frequencyMenu->addAction(action);
            connect(action, &QAction::triggered, this, &DepositCalculatorUI::SetFrequency);
        }

        widgets->frequencyOfPayments->setMenu(frequencyMenu);
        SetFrequencyButtonAction(frequencyMenu->actions()[MONTHLY]);
    }

    void SetPlacementPeriodButton() {
        widgets->periodMenu = new QMenu(widgets->placementPeriod);

        widgets->periodActions.insert(std::make_pair(DAILY, new QAction("Days", widgets->periodMenu)));
        widgets->periodActions.insert(std::make_pair(WEEKLY, new QAction("Weeks", widgets->periodMenu)));
        widgets->periodActions.insert(std::make_pair(MONTHLY, new QAction("Months", widgets->periodMenu)));
        widgets->periodActions.insert(std::make_pair(YEARS, new QAction("Years", widgets->periodMenu)));

        for (auto it : widgets->periodActions) {
            widgets->periodMenu->addAction(it.second);
            connect(it.second, &QAction::triggered, this, &DepositCalculatorUI::SetPeriod);
        }
        widgets->placementPeriod->setMenu(widgets->periodMenu);

        SetPeriodButtonAction(widgets->periodActions[MONTHS]);
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
        layout.SetHorizontalSpacing(2);
        layout.SetVerticalSpacing(35);
        layout.SetAutoSize();

        layout.AddWidget(widgets->box[DEPOSIT_AMOUNT]);
        layout.AddWidget(widgets->box[INTEREST_RATE]);
        layout.ChangeColumns(2);
        layout.AddWidget(widgets->box[PLACEMENT_PERIOD]);
        layout.AddWidget(widgets->placementPeriod);
        layout.ChangeColumns(1);
        layout.AddWidget(widgets->frequencyOfPayments);

        layout.SetTitle(widgets->box[DEPOSIT_AMOUNT], widgets->boxTitle[DEPOSIT_AMOUNT], Layout::CenterH, Layout::Above, 16, 0, -10);
        layout.SetTitle(widgets->box[INTEREST_RATE], widgets->boxTitle[INTEREST_RATE], Layout::CenterH, Layout::Above, 16, 0, -10);
        layout.SetTitle(widgets->box[PLACEMENT_PERIOD], widgets->boxTitle[PLACEMENT_PERIOD], Layout::Left, Layout::Above, 16, widgets->box[PLACEMENT_PERIOD]->width()/2 + 10, -10);
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

    void SetFrequencyButtonAction(QAction *action) {
        widgets->frequencyOfPayments->menu()->setActiveAction(action);
        widgets->frequencyOfPayments->setText(action->text());
    }

    void SetPeriodButtonAction(QAction *action) {
        widgets->periodMenu->setActiveAction(action);
        widgets->placementPeriod->setText(action->text());
    }

private slots:

    void Calculate() {
        SetInput();
        controller->DepositCalculate();
        SetOutput();
    }

    void SetPeriod() {
        SetPeriodButtonAction(static_cast<QAction*>(sender()));
    }

    void SetFrequency() {
        SetFrequencyButtonAction(static_cast<QAction*>(sender()));
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



#endif // DEPOSITCALCULATORUI_H
