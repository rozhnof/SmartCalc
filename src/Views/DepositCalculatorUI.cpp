#include "DepositCalculatorUI.h"



DepositCalculatorUI::DepositCalculatorUI() : MainWindow(), _controller(new DepositCalcController), _widgets(new DepositCalcWidgets) {
    _widgets->depositCalcWindow = this;

    initWidgets();
    setGeometry();
    setInputValidator();

    setTable();
    setFrequencyOfPaymentsButton();
    setPlacementPeriodButton();

    connectWidgetsToSlots();
    setStyle();
}

DepositCalculatorUI::~DepositCalculatorUI() {
    delete _controller;
    delete _widgets;
}

void DepositCalculatorUI::initWidgets() {
    this->setFixedSize(1280, 615);

    _widgets->mainInputContainer = NewWidget(this, "container");
    _widgets->addInputContainer = NewWidget(this, "container");
    _widgets->outputContainer = NewWidget(this, "container");
    _widgets->tablesContainer = NewWidget(this, "table_container");

    _widgets->box.insert(std::make_pair(DEPOSIT_AMOUNT, NewWidget(this, "box")));
    _widgets->box.insert(std::make_pair(DEPOSIT_INTEREST_RATE, NewWidget(this, "box")));
    _widgets->box.insert(std::make_pair(DEPOSIT_PLACEMENT_PERIOD, NewWidget(this, "box_left")));
    _widgets->box.insert(std::make_pair(DEPOSIT_OPERATION_SUM, NewWidget(this, "box_right")));
    _widgets->box.insert(std::make_pair(DEPOSIT_TAX_RATE, NewWidget(this, "box")));
    _widgets->box.insert(std::make_pair(DEPOSIT_ACCURED_INTEREST, NewWidget(this, "box")));
    _widgets->box.insert(std::make_pair(DEPOSIT_TOTAL_AMOUNT, NewWidget(this, "box")));
    _widgets->box.insert(std::make_pair(DEPOSIT_TAX_AMOUNT, NewWidget(this, "box")));

    _widgets->boxTitle.insert(std::make_pair(DEPOSIT_AMOUNT, NewLabel(this, "Deposit Amount", "title")));
    _widgets->boxTitle.insert(std::make_pair(DEPOSIT_INTEREST_RATE, NewLabel(this, "Interest Rate", "title")));
    _widgets->boxTitle.insert(std::make_pair(DEPOSIT_PLACEMENT_PERIOD, NewLabel(this, "Placement period", "title")));
    _widgets->boxTitle.insert(std::make_pair(DEPOSIT_FREQUENCY_OF_PAYMENTS, NewLabel(this, "Frequency of Payments", "title")));
    _widgets->boxTitle.insert(std::make_pair(DEPOSIT_DATE_OF_PLACEMENT, NewLabel(this, "Date of Placement", "title")));
    _widgets->boxTitle.insert(std::make_pair(DEPOSIT_OPERATION_DATE, NewLabel(this, "Date", "title")));
    _widgets->boxTitle.insert(std::make_pair(DEPOSIT_OPERATION_SUM, NewLabel(this, "Sum", "title")));
    _widgets->boxTitle.insert(std::make_pair(DEPOSIT_TAX_RATE, NewLabel(this, "Tax Rate", "title")));
    _widgets->boxTitle.insert(std::make_pair(DEPOSIT_ACCURED_INTEREST, NewLabel(this, "Accrued Interest", "title")));
    _widgets->boxTitle.insert(std::make_pair(DEPOSIT_TOTAL_AMOUNT, NewLabel(this, "Total Amount", "title")));
    _widgets->boxTitle.insert(std::make_pair(DEPOSIT_TAX_AMOUNT, NewLabel(this, "Tax Amount", "title")));

    _widgets->boxData.insert(std::make_pair(DEPOSIT_AMOUNT, NewLineEdit(this, "10000", "data")));
    _widgets->boxData.insert(std::make_pair(DEPOSIT_INTEREST_RATE, NewLineEdit(this, "10", "data")));
    _widgets->boxData.insert(std::make_pair(DEPOSIT_PLACEMENT_PERIOD, NewLineEdit(this, "10", "data")));
    _widgets->boxData.insert(std::make_pair(DEPOSIT_TAX_RATE, NewLineEdit(this, "", "data")));
    _widgets->boxData.insert(std::make_pair(DEPOSIT_OPERATION_SUM, NewLineEdit(this, "", "data")));
    _widgets->boxData.insert(std::make_pair(DEPOSIT_ACCURED_INTEREST, NewLineEdit(this, "", "data")));
    _widgets->boxData.insert(std::make_pair(DEPOSIT_TOTAL_AMOUNT, NewLineEdit(this, "", "data")));
    _widgets->boxData.insert(std::make_pair(DEPOSIT_TAX_AMOUNT, NewLineEdit(this, "", "data")));

    _widgets->calculateButton = NewPushButton(this, "Calculate", "button");
    _widgets->dateOfPlacementButton = NewPushButton(this, QDate::currentDate().toString("dd-MM-yyyy"), "button");
    _widgets->frequencyOfPaymentsButton = NewToolButton(this, "", "button");

    _widgets->setTopUpListButton = NewPushButton(this, "Top Up List", "button_left");
    _widgets->setTakeOffListButton = NewPushButton(this, "Take Off List", "button_left");
    _widgets->setGeneralListButton = NewPushButton(this, "General List", "button_left");
    _widgets->topUpButton = NewPushButton(this, "Top Up", "button_left");
    _widgets->dateButton = NewPushButton(this, QDate::currentDate().toString("dd-MM-yyyy"), "button_left");

    _widgets->takeOffButton = NewPushButton(this, "Take Off", "button_right");
    _widgets->placementPeriodButton = NewToolButton(this, "", "button_right");
    _widgets->buttonClearGeneralTable = NewPushButton(this, "Clear", "button_right");
    _widgets->buttonClearTakeOffTable = NewPushButton(this, "Clear", "button_right");
    _widgets->buttonClearTopUpTable = NewPushButton(this, "Clear", "button_right");

    _widgets->interestCapitalization = NewCheckBox(this, "Interest Capitalization", "check_box");

    _widgets->generalTable = new QTableWidget(this);
    _widgets->generalTable->setObjectName("data_table");

    _widgets->topUpTable = new QTableWidget(this);
    _widgets->topUpTable->setObjectName("data_table");

    _widgets->takeOffTable = new QTableWidget(this);
    _widgets->takeOffTable->setObjectName("data_table");

    _widgets->backgroundCalendar = NewWidget(this, "calendar_background");
    _widgets->calendar = new Calendar(_widgets->backgroundCalendar);
    _widgets->backgroundCalendar->hide();
}

void DepositCalculatorUI::setGeometry() {
    setMainInputContainer();
    setAddInputContainer();
    setOutputContainer();
    setTableContainer();
}

bool DepositCalculatorUI::setInput() {
    double depositAmount = _widgets->boxData[DEPOSIT_AMOUNT]->text().toDouble();
    double interestRate = _widgets->boxData[DEPOSIT_INTEREST_RATE]->text().toDouble();
    int frequencyOfPayments = _widgets->frequencyActiveAction.first;
    bool interestCapitalization = _widgets->interestCapitalization->isChecked();
    double taxRate = _widgets->boxData[DEPOSIT_TAX_RATE]->text().toDouble();
    double placementCount = _widgets->boxData[DEPOSIT_PLACEMENT_PERIOD]->text().toDouble();
    int placementPeriodType = _widgets->periodActiveAction.first;
    QDate startDate = QDate::fromString(_widgets->dateOfPlacementButton->text(), "dd-MM-yyyy");
    QDate endDate = setEndDate(startDate, placementPeriodType, placementCount);
    QVector<QDate> paymentDays = setPaymentDays(startDate, endDate, frequencyOfPayments);

    return _controller->setInput(depositAmount, interestRate, interestCapitalization, taxRate, startDate, endDate, paymentDays, _widgets->topUpList, _widgets->takeOffList);
}

QVector<QDate> DepositCalculatorUI::setPaymentDays(QDate startDate, QDate endDate, int frequencyOfPayments) {
    QVector<QDate> paymentDays;

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
        paymentDays.append(itDate);
    }

    if (paymentDays.back() > endDate) {
        paymentDays.pop_back();
        paymentDays.push_back(endDate);
    } else if (paymentDays.back() < endDate) {
        paymentDays.append(endDate);
    }

    return paymentDays;
}

QDate DepositCalculatorUI::setEndDate(QDate startDate, int periodType, int periodCount) {
    QDate endDate;

    if (periodType == DAYS) {
        endDate = startDate.addDays(periodCount);
    } else if (periodType == WEEKS) {
        endDate = startDate.addDays(periodCount * 7);
    } else if (periodType == MONTHS) {
        endDate = startDate.addMonths(periodCount);
    } else if (periodType == YEARS) {
        endDate = startDate.addYears(periodCount);
    }

    return endDate;
}

void DepositCalculatorUI::getOutput() {
    double accuredInterest = 0;
    double totalAmount = 0;
    double taxAmount = 0;

    accuredInterest = _controller->getAccuredInterest();
    totalAmount = _controller->getTotalAmount();
    taxAmount = _controller->getTaxAmount();

    _widgets->boxData[DEPOSIT_ACCURED_INTEREST]->setText(QString::number(accuredInterest, 'f', 2));
    _widgets->boxData[DEPOSIT_TOTAL_AMOUNT]->setText(QString::number(totalAmount, 'f', 2));
    _widgets->boxData[DEPOSIT_TAX_AMOUNT]->setText(QString::number(taxAmount, 'f', 2));
}

void DepositCalculatorUI::connectWidgetsToSlots() {
    connect(_widgets->dateButton, &QPushButton::clicked, this, &DepositCalculatorUI::calendarShow);
    connect(_widgets->dateOfPlacementButton, &QPushButton::clicked, this, &DepositCalculatorUI::calendarShow);
    connect(_widgets->calendar, &QCalendarWidget::clicked, this, &DepositCalculatorUI::setDate);
    connect(_widgets->calculateButton, &QPushButton::clicked, this, &DepositCalculatorUI::Calculate);
    connect(_widgets->topUpButton, &QPushButton::clicked, this, &DepositCalculatorUI::addTopUp);
    connect(_widgets->takeOffButton, &QPushButton::clicked, this, &DepositCalculatorUI::addTakeOff);
    connect(_widgets->setGeneralListButton, &QPushButton::clicked, this, &DepositCalculatorUI::showGeneralTable);
    connect(_widgets->setTopUpListButton, &QPushButton::clicked, this, &DepositCalculatorUI::showTopUpTable);
    connect(_widgets->setTakeOffListButton, &QPushButton::clicked, this, &DepositCalculatorUI::showTakeOffTable);
    connect(_widgets->buttonClearTakeOffTable, &QPushButton::clicked, this, &DepositCalculatorUI::clearTakeOffList);
    connect(_widgets->buttonClearTopUpTable, &QPushButton::clicked, this, &DepositCalculatorUI::clearTopUpList);
    connect(_widgets->buttonClearGeneralTable, &QPushButton::clicked, this, &DepositCalculatorUI::clearGeneralList);
}

void DepositCalculatorUI::setFrequencyOfPaymentsButton() {
    QMenu *menu = new QMenu(this);
    std::map<Frequencies, QString> keyAndName;

    keyAndName.insert(std::make_pair(DAILY, "Daily"));
    keyAndName.insert(std::make_pair(WEEKLY, "Weekly"));
    keyAndName.insert(std::make_pair(MONTHLY, "Monthly"));
    keyAndName.insert(std::make_pair(QUARTERLY, "Quarterly"));
    keyAndName.insert(std::make_pair(SEMI_ANNUALLY, "Semi-Annualy"));
    keyAndName.insert(std::make_pair(YEARLY, "Yearly"));
    keyAndName.insert(std::make_pair(END_OF_TERM, "End of Term"));

    for (const auto &it : keyAndName) {
        QAction *action = new QAction(this);
        action->setText(it.second);
        action->setData(it.first);
        menu->addAction(action);
        connect(action, &QAction::triggered, this, &DepositCalculatorUI::setFrequency);
    }
    _widgets->frequencyOfPaymentsButton->setMenu(menu);
    _widgets->frequencyOfPaymentsButton->setPopupMode(QToolButton::InstantPopup);

    setFrequencyButtonActiveAction(menu->actions()[MONTHLY]);
}

void DepositCalculatorUI::setPlacementPeriodButton() {
    QMenu *menu = new QMenu(this);
    std::map<Periods, QString> keyAndName;

    keyAndName.insert(std::make_pair(DAYS, "Days"));
    keyAndName.insert(std::make_pair(WEEKS, "Weeks"));
    keyAndName.insert(std::make_pair(MONTHS, "Months"));
    keyAndName.insert(std::make_pair(YEARS, "Years"));

    for (const auto &it : keyAndName) {
        QAction *action = new QAction(this);
        action->setText(it.second);
        action->setData(it.first);
        menu->addAction(action);
        connect(action, &QAction::triggered, this, &DepositCalculatorUI::setPeriod);
    }
    _widgets->placementPeriodButton->setMenu(menu);
    _widgets->placementPeriodButton->setPopupMode(QToolButton::InstantPopup);

    setPeriodButtonActiveAction(menu->actions()[MONTHS]);
}

void DepositCalculatorUI::setOutputContainer() {
    _widgets->outputContainer->setGeometry(10, _widgets->mainInputContainer->y() + _widgets->mainInputContainer->height() + 10, 320, 250);

    Layout layout;
    layout.SetStartPoints(_widgets->outputContainer->x(), _widgets->outputContainer->y());
    layout.SetEndPoints(_widgets->outputContainer->x() + _widgets->outputContainer->width(), _widgets->outputContainer->y() + _widgets->outputContainer->height());
    layout.SetRows(3);
    layout.SetColumns(1);
    layout.SetLeftSpacing(10);
    layout.SetRightSpacing(10);
    layout.SetAboveSpacing(35);
    layout.SetBottomSpacing(10);
    layout.SetHorizontalSpacing(2);
    layout.SetVerticalSpacing(35);
    layout.SetAutoSize();

    layout.AddWidget(_widgets->box[DEPOSIT_ACCURED_INTEREST]);
    layout.AddWidget(_widgets->box[DEPOSIT_TOTAL_AMOUNT]);
    layout.AddWidget(_widgets->box[DEPOSIT_TAX_AMOUNT]);

    layout.SetTitle(_widgets->box[DEPOSIT_ACCURED_INTEREST], _widgets->boxTitle[DEPOSIT_ACCURED_INTEREST], Layout::CenterH, Layout::Above, 16, 0, -10);
    layout.SetTitle(_widgets->box[DEPOSIT_TOTAL_AMOUNT], _widgets->boxTitle[DEPOSIT_TOTAL_AMOUNT], Layout::CenterH, Layout::Above, 16, 0, -10);
    layout.SetTitle(_widgets->box[DEPOSIT_TAX_AMOUNT], _widgets->boxTitle[DEPOSIT_TAX_AMOUNT], Layout::CenterH, Layout::Above, 16, 0, -10);

    layout.SetField(_widgets->box[DEPOSIT_ACCURED_INTEREST], _widgets->boxData[DEPOSIT_ACCURED_INTEREST], Layout::Left, 5);
    layout.SetField(_widgets->box[DEPOSIT_TOTAL_AMOUNT], _widgets->boxData[DEPOSIT_TOTAL_AMOUNT], Layout::Left, 5);
    layout.SetField(_widgets->box[DEPOSIT_TAX_AMOUNT], _widgets->boxData[DEPOSIT_TAX_AMOUNT], Layout::Left, 5);
}

void DepositCalculatorUI::setTableContainer() {
    Layout layout;

    int x0 = _widgets->mainInputContainer->x() + _widgets->mainInputContainer->width() + 20;
    int y0 = _widgets->addInputContainer->y() + _widgets->addInputContainer->height() + 26 + 45 + 20;

    int xMax = this->width() - 10;
    int yMax = this->height() - 10;

    layout.SetStartPoints(x0, y0);
    layout.SetEndPoints(xMax, yMax);
    layout.SetRows(1);
    layout.SetColumns(1);
    layout.SetAutoSize();

    layout.AddWidget(_widgets->tablesContainer);
    _widgets->generalTable->setGeometry(_widgets->tablesContainer->x(), _widgets->tablesContainer->y(), _widgets->tablesContainer->width(), _widgets->tablesContainer->height());
    _widgets->topUpTable->setGeometry(_widgets->tablesContainer->x(), _widgets->tablesContainer->y(), _widgets->tablesContainer->width(), _widgets->tablesContainer->height());
    _widgets->takeOffTable->setGeometry(_widgets->tablesContainer->x(), _widgets->tablesContainer->y(), _widgets->tablesContainer->width(), _widgets->tablesContainer->height());
}

void DepositCalculatorUI::setTable() {
    _widgets->generalTable->setColumnCount(4);
    QStringList headerLabelsGeneralTable;
    headerLabelsGeneralTable << "Date" << "Operation Type" << "Operation Sum" << "Deposit Sum";
    _widgets->generalTable->setHorizontalHeaderLabels(headerLabelsGeneralTable);
    _widgets->generalTable->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    _widgets->generalTable->setEditTriggers(QAbstractItemView::NoEditTriggers);

    _widgets->takeOffTable->setColumnCount(2);
    QStringList headerLabelsTakeOff;
    headerLabelsTakeOff << "Date" << "Sum";
    _widgets->takeOffTable->setHorizontalHeaderLabels(headerLabelsTakeOff);
    _widgets->takeOffTable->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    _widgets->takeOffTable->setEditTriggers(QAbstractItemView::NoEditTriggers);

    _widgets->topUpTable->setColumnCount(2);
    QStringList headerLabelsTopUpTable;
    headerLabelsTopUpTable << "Date" << "Sum";
    _widgets->topUpTable->setHorizontalHeaderLabels(headerLabelsTopUpTable);
    _widgets->topUpTable->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    _widgets->topUpTable->setEditTriggers(QAbstractItemView::NoEditTriggers);
}

void DepositCalculatorUI::setAddInputContainer() {
    _widgets->addInputContainer->setGeometry(_widgets->mainInputContainer->x() + _widgets->mainInputContainer->width() + 10, 10, 930, 170);
    Layout layout;

    layout.SetStartPoints(_widgets->addInputContainer->x(), _widgets->addInputContainer->y());
    layout.SetEndPoints(_widgets->addInputContainer->x() + _widgets->addInputContainer->width(), _widgets->addInputContainer->y() + _widgets->addInputContainer->height());
    layout.SetRows(2);
    layout.SetColumns(3);
    layout.SetLeftSpacing(10);
    layout.SetRightSpacing(10);
    layout.SetAboveSpacing(35);
    layout.SetBottomSpacing(10);
    layout.SetVerticalSpacing(35);
    layout.SetHorizontalSpacing(10);
    layout.SetAutoSize();

    layout.AddWidget(_widgets->dateOfPlacementButton);
    layout.SetHorizontalSpacing(2);
    layout.AddWidget(_widgets->dateButton, 0.5);
    layout.SetHorizontalSpacing(10);
    layout.AddWidget(_widgets->box[DEPOSIT_OPERATION_SUM], 0.5);
    layout.AddWidget(_widgets->interestCapitalization);
    layout.NextRow();
    layout.AddWidget(_widgets->box[DEPOSIT_TAX_RATE]);
    layout.SetHorizontalSpacing(2);
    layout.AddWidget(_widgets->topUpButton, 0.5);
    layout.SetHorizontalSpacing(10);
    layout.AddWidget(_widgets->takeOffButton, 0.5);
    layout.AddWidget(_widgets->calculateButton);
    layout.NextRow();
    layout.SetHorizontalSpacing(2);
    layout.AddWidget(_widgets->setTopUpListButton, 0.5);
    layout.SetHorizontalSpacing(10);
    layout.AddWidget(_widgets->buttonClearTopUpTable, 0.5);
    layout.SetHorizontalSpacing(2);
    layout.AddWidget(_widgets->setTakeOffListButton, 0.5);
    layout.SetHorizontalSpacing(10);
    layout.AddWidget(_widgets->buttonClearTakeOffTable, 0.5);
    layout.SetHorizontalSpacing(2);
    layout.AddWidget(_widgets->setGeneralListButton, 0.5);
    layout.SetHorizontalSpacing(10);
    layout.AddWidget(_widgets->buttonClearGeneralTable, 0.5);

    layout.SetTitle(_widgets->dateOfPlacementButton, _widgets->boxTitle[DEPOSIT_DATE_OF_PLACEMENT], Layout::CenterH, Layout::Above, 16, 0, -10);
    layout.SetTitle(_widgets->box[DEPOSIT_OPERATION_SUM], _widgets->boxTitle[DEPOSIT_OPERATION_SUM], Layout::CenterH, Layout::Above, 16, 0, -10);
    layout.SetTitle(_widgets->box[DEPOSIT_TAX_RATE], _widgets->boxTitle[DEPOSIT_TAX_RATE], Layout::CenterH, Layout::Above, 16, 0, -10);
    layout.SetTitle(_widgets->dateButton, _widgets->boxTitle[DEPOSIT_OPERATION_DATE], Layout::CenterH, Layout::Above, 16, 0, -10);

    layout.SetField(_widgets->box[DEPOSIT_TAX_RATE], _widgets->boxData[DEPOSIT_TAX_RATE], Layout::CenterH, 0);
    layout.SetField(_widgets->box[DEPOSIT_OPERATION_SUM], _widgets->boxData[DEPOSIT_OPERATION_SUM], Layout::CenterH, 0);
}

void DepositCalculatorUI::setMainInputContainer() {
    _widgets->mainInputContainer->setGeometry(10, 10, 320, 335);

    Layout layout;
    layout.SetStartPoints(_widgets->mainInputContainer->x(), _widgets->mainInputContainer->y());
    layout.SetEndPoints(_widgets->mainInputContainer->x() + _widgets->mainInputContainer->width(), _widgets->mainInputContainer->y() + _widgets->mainInputContainer->height());
    layout.SetRows(4);
    layout.SetColumns(1);
    layout.SetLeftSpacing(10);
    layout.SetRightSpacing(10);
    layout.SetAboveSpacing(35);
    layout.SetBottomSpacing(10);
    layout.SetHorizontalSpacing(2);
    layout.SetVerticalSpacing(35);
    layout.SetAutoSize();

    layout.AddWidget(_widgets->box[DEPOSIT_AMOUNT]);
    layout.AddWidget(_widgets->box[DEPOSIT_INTEREST_RATE]);
    layout.ChangeColumns(2);
    layout.AddWidget(_widgets->box[DEPOSIT_PLACEMENT_PERIOD]);
    layout.AddWidget(_widgets->placementPeriodButton);
    layout.ChangeColumns(1);
    layout.AddWidget(_widgets->frequencyOfPaymentsButton);

    layout.SetTitle(_widgets->box[DEPOSIT_AMOUNT], _widgets->boxTitle[DEPOSIT_AMOUNT], Layout::CenterH, Layout::Above, 16, 0, -10);
    layout.SetTitle(_widgets->box[DEPOSIT_INTEREST_RATE], _widgets->boxTitle[DEPOSIT_INTEREST_RATE], Layout::CenterH, Layout::Above, 16, 0, -10);
    layout.SetTitle(_widgets->box[DEPOSIT_PLACEMENT_PERIOD], _widgets->boxTitle[DEPOSIT_PLACEMENT_PERIOD], Layout::Left, Layout::Above, 16, _widgets->box[DEPOSIT_PLACEMENT_PERIOD]->width()/2 + 10, -10);
    layout.SetTitle(_widgets->frequencyOfPaymentsButton, _widgets->boxTitle[DEPOSIT_FREQUENCY_OF_PAYMENTS], Layout::CenterH, Layout::Above, 16, 0, -10);

    layout.SetField(_widgets->box[DEPOSIT_AMOUNT], _widgets->boxData[DEPOSIT_AMOUNT], Layout::Left, 5);
    layout.SetField(_widgets->box[DEPOSIT_INTEREST_RATE], _widgets->boxData[DEPOSIT_INTEREST_RATE], Layout::Left, 5);
    layout.SetField(_widgets->box[DEPOSIT_PLACEMENT_PERIOD], _widgets->boxData[DEPOSIT_PLACEMENT_PERIOD], Layout::Left, 5);
}

void DepositCalculatorUI::setInputValidator() {
    _widgets->boxData[DEPOSIT_AMOUNT]->setValidator(new QRegularExpressionValidator(QRegularExpression("[0-9]{1,10}([.][0-9]{1,2})?"), this));
    _widgets->boxData[DEPOSIT_INTEREST_RATE]->setValidator(new QRegularExpressionValidator(QRegularExpression("[0-9]{1,3}([.][0-9]{1,2})?"), this));
    _widgets->boxData[DEPOSIT_TAX_RATE]->setValidator(new QRegularExpressionValidator(QRegularExpression("[0-9]{1,2}([.][0-9]{1,2})?"), this));
    _widgets->boxData[DEPOSIT_OPERATION_SUM]->setValidator(new QRegularExpressionValidator(QRegularExpression("[0-9]{1,10}([.][0-9]{1,2})?"), this));
    _widgets->boxData[DEPOSIT_PLACEMENT_PERIOD]->setValidator(new QRegularExpressionValidator(QRegularExpression("[0-9]{1,2}"), this));
}

void DepositCalculatorUI::setRow(QTableWidget *table, QString date, QString sum) {
    int currentRow = table->rowCount();
    table->setRowCount(currentRow + 1);

    table->setItem(currentRow, 0, new QTableWidgetItem(date));
    table->setItem(currentRow, 1, new QTableWidgetItem(sum));
}

void DepositCalculatorUI::setRow(QTableWidget *table, QString date, QString type, QString sum, QString depositSum) {
    int currentRow = table->rowCount();
    table->setRowCount(currentRow + 1);

    table->setItem(currentRow, 0, new QTableWidgetItem(date));
    table->setItem(currentRow, 1, new QTableWidgetItem(type));
    table->setItem(currentRow, 2, new QTableWidgetItem(sum));
    table->setItem(currentRow, 3, new QTableWidgetItem(depositSum));
}

void DepositCalculatorUI::setFrequencyButtonActiveAction(QAction *action) {
    _widgets->frequencyActiveAction.first = action->data().toInt();
    _widgets->frequencyActiveAction.second = action;

    _widgets->frequencyOfPaymentsButton->setText(action->text());
}

void DepositCalculatorUI::setPeriodButtonActiveAction(QAction *action) {
    _widgets->periodActiveAction.first = action->data().toInt();
    _widgets->periodActiveAction.second = action;

    _widgets->placementPeriodButton->setText(action->text());
}

void DepositCalculatorUI::fillGeneralList() {
    _widgets->generalTable->setRowCount(0);
    std::vector<std::tuple<QDate, QString, double, double>> generalList = _controller->getGeneralList();

    for (const auto& tuple : generalList) {
        QString date = std::get<0>(tuple).toString("dd-MM-yyyy");
        QString type = std::get<1>(tuple);
        QString operationSum = QString::number(std::get<2>(tuple));
        QString depositSum = QString::number(std::get<3>(tuple));

        setRow(_widgets->generalTable, date, type, operationSum, depositSum);
    }
}

void DepositCalculatorUI::setStyle() {
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
            QLineEdit#data {
                background-color: rgba(0, 0, 0, 0);
                color: rgb(37, 37, 37);
                font-size: 16px;
                border: none;
                border-radius: 10;
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
            QToolButton QMenu {
                background-color: rgb(255, 255, 255);
                color: rgb(72, 75, 79);
            }
            QToolButton QMenu::item:selected {
                background-color: rgb(230,230,230);
                border: 1px rgb(230,230,230);
                border-radius: 5;
            }
        )";
    _widgets->depositCalcWindow->setStyleSheet(styleSheet);

    for (auto it : _widgets->boxData) {
        it.second->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
    }

    _widgets->boxData[DEPOSIT_ACCURED_INTEREST]->setReadOnly(true);
    _widgets->boxData[DEPOSIT_TOTAL_AMOUNT]->setReadOnly(true);
    _widgets->boxData[DEPOSIT_TAX_AMOUNT]->setReadOnly(true);
}

void DepositCalculatorUI::clearTakeOffList() {
    _widgets->takeOffList.clear();
    _widgets->takeOffTable->setRowCount(0);
}

void DepositCalculatorUI::clearTopUpList() {
    _widgets->topUpList.clear();
    _widgets->topUpTable->setRowCount(0);
}

void DepositCalculatorUI::clearGeneralList() {
    _widgets->generalList.clear();
    _widgets->generalTable->setRowCount(0);
}

void DepositCalculatorUI::showGeneralTable() {
    _widgets->takeOffTable->hide();
    _widgets->topUpTable->hide();
    _widgets->generalTable->show();
}

void DepositCalculatorUI::showTopUpTable() {
    _widgets->generalTable->hide();
    _widgets->takeOffTable->hide();
    _widgets->topUpTable->show();
}

void DepositCalculatorUI::showTakeOffTable() {
    _widgets->generalTable->hide();
    _widgets->topUpTable->hide();
    _widgets->takeOffTable->show();
}

void DepositCalculatorUI::addTopUp() {
    if (_widgets->topUpList.size() < 50) {
        QDate date = QDate::fromString(_widgets->dateButton->text(), "dd-MM-yyyy");
        double sum = _widgets->boxData[DEPOSIT_OPERATION_SUM]->text().toDouble();

        _widgets->topUpList.insert(std::make_pair(date, sum));
        _widgets->topUpTable->setRowCount(0);

        for (auto it : _widgets->topUpList) {
            setRow(_widgets->topUpTable, it.first.toString("dd-MM-yyyy"), QString::number(it.second, 'f', 2));
        }
    }
    showTopUpTable();
}

void DepositCalculatorUI::addTakeOff() {
    if (_widgets->takeOffList.size() < 50) {
        QDate date = QDate::fromString(_widgets->dateButton->text(), "dd-MM-yyyy");
        double sum = _widgets->boxData[DEPOSIT_OPERATION_SUM]->text().toDouble();

        _widgets->takeOffList.insert(std::make_pair(date, sum));
        _widgets->takeOffTable->setRowCount(0);

        for (auto it : _widgets->takeOffList) {
            setRow(_widgets->takeOffTable, it.first.toString("dd-MM-yyyy"), QString::number(it.second, 'f', 2));
        }
    }
    showTakeOffTable();
}

void DepositCalculatorUI::Calculate() {
    if (setInput()) {
        _controller->Calculate();
        getOutput();
        fillGeneralList();
        showGeneralTable();
    }
}

void DepositCalculatorUI::setPeriod() {
    setPeriodButtonActiveAction(static_cast<QAction*>(sender()));
}

void DepositCalculatorUI::setFrequency() {
    setFrequencyButtonActiveAction(static_cast<QAction*>(sender()));
}

void DepositCalculatorUI::calendarShow() {
    _calendarSender = static_cast<QToolButton*>(sender());

    int calendarWidth = 300;
    int calendarHeight = 300;

    int calendarY = _calendarSender->y() + _calendarSender->height() + 10;
    int calendarX = _calendarSender->x() + _calendarSender->width() / 2 - calendarWidth / 2;

    _widgets->backgroundCalendar->setGeometry(calendarX, calendarY, calendarWidth, calendarHeight);
    _widgets->calendar->setGeometry(10, 10, _widgets->backgroundCalendar->width() - 15, _widgets->backgroundCalendar->height() - 20);
    _widgets->backgroundCalendar->show();
}

void DepositCalculatorUI::setDate() {
    _widgets->backgroundCalendar->hide();
    QDate selectedDate(_widgets->calendar->selectedDate());
    _calendarSender->setText(selectedDate.toString("dd-MM-yyyy"));
}
