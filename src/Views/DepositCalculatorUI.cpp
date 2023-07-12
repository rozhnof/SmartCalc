#include "DepositCalculatorUI.h"

DepositCalculatorUI::DepositCalculatorUI()
    : MainWindow(),
      controller_(new DepositCalcController),
      widgets_(new DepositCalcWidgets) {
  widgets_->depositCalcWindow = this;

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
  delete controller_;
  delete widgets_;
}

void DepositCalculatorUI::initWidgets() {
  this->setFixedSize(1280, 615);

  widgets_->mainInputContainer = NewWidget(this, "container");
  widgets_->addInputContainer = NewWidget(this, "container");
  widgets_->outputContainer = NewWidget(this, "container");
  widgets_->tablesContainer = NewWidget(this, "table_container");

  widgets_->box.insert(std::make_pair(DEPOSIT_AMOUNT, NewWidget(this, "box")));
  widgets_->box.insert(
      std::make_pair(DEPOSIT_INTEREST_RATE, NewWidget(this, "box")));
  widgets_->box.insert(
      std::make_pair(DEPOSIT_PLACEMENT_PERIOD, NewWidget(this, "box_left")));
  widgets_->box.insert(
      std::make_pair(DEPOSIT_OPERATION_SUM, NewWidget(this, "box_right")));
  widgets_->box.insert(
      std::make_pair(DEPOSIT_TAX_RATE, NewWidget(this, "box")));
  widgets_->box.insert(
      std::make_pair(DEPOSIT_ACCURED_INTEREST, NewWidget(this, "box")));
  widgets_->box.insert(
      std::make_pair(DEPOSIT_TOTAL_AMOUNT, NewWidget(this, "box")));
  widgets_->box.insert(
      std::make_pair(DEPOSIT_TAX_AMOUNT, NewWidget(this, "box")));

  widgets_->boxTitle.insert(std::make_pair(
      DEPOSIT_AMOUNT, NewLabel(this, "Deposit Amount", "title")));
  widgets_->boxTitle.insert(std::make_pair(
      DEPOSIT_INTEREST_RATE, NewLabel(this, "Interest Rate", "title")));
  widgets_->boxTitle.insert(std::make_pair(
      DEPOSIT_PLACEMENT_PERIOD, NewLabel(this, "Placement period", "title")));
  widgets_->boxTitle.insert(
      std::make_pair(DEPOSIT_FREQUENCY_OF_PAYMENTS,
                     NewLabel(this, "Frequency of Payments", "title")));
  widgets_->boxTitle.insert(std::make_pair(
      DEPOSIT_DATE_OF_PLACEMENT, NewLabel(this, "Date of Placement", "title")));
  widgets_->boxTitle.insert(
      std::make_pair(DEPOSIT_OPERATION_DATE, NewLabel(this, "Date", "title")));
  widgets_->boxTitle.insert(
      std::make_pair(DEPOSIT_OPERATION_SUM, NewLabel(this, "Sum", "title")));
  widgets_->boxTitle.insert(
      std::make_pair(DEPOSIT_TAX_RATE, NewLabel(this, "Tax Rate", "title")));
  widgets_->boxTitle.insert(std::make_pair(
      DEPOSIT_ACCURED_INTEREST, NewLabel(this, "Accrued Interest", "title")));
  widgets_->boxTitle.insert(std::make_pair(
      DEPOSIT_TOTAL_AMOUNT, NewLabel(this, "Total Amount", "title")));
  widgets_->boxTitle.insert(std::make_pair(
      DEPOSIT_TAX_AMOUNT, NewLabel(this, "Tax Amount", "title")));

  widgets_->boxData.insert(
      std::make_pair(DEPOSIT_AMOUNT, NewLineEdit(this, "10000", "data")));
  widgets_->boxData.insert(
      std::make_pair(DEPOSIT_INTEREST_RATE, NewLineEdit(this, "10", "data")));
  widgets_->boxData.insert(std::make_pair(DEPOSIT_PLACEMENT_PERIOD,
                                          NewLineEdit(this, "10", "data")));
  widgets_->boxData.insert(
      std::make_pair(DEPOSIT_TAX_RATE, NewLineEdit(this, "", "data")));
  widgets_->boxData.insert(
      std::make_pair(DEPOSIT_OPERATION_SUM, NewLineEdit(this, "", "data")));
  widgets_->boxData.insert(
      std::make_pair(DEPOSIT_ACCURED_INTEREST, NewLineEdit(this, "", "data")));
  widgets_->boxData.insert(
      std::make_pair(DEPOSIT_TOTAL_AMOUNT, NewLineEdit(this, "", "data")));
  widgets_->boxData.insert(
      std::make_pair(DEPOSIT_TAX_AMOUNT, NewLineEdit(this, "", "data")));

  widgets_->calculateButton = NewPushButton(this, "Calculate", "button");
  widgets_->dateOfPlacementButton = NewPushButton(
      this, QDate::currentDate().toString("dd-MM-yyyy"), "button");
  widgets_->frequencyOfPaymentsButton = NewToolButton(this, "", "button");

  widgets_->setTopUpListButton =
      NewPushButton(this, "Top Up List", "button_left");
  widgets_->setTakeOffListButton =
      NewPushButton(this, "Take Off List", "button_left");
  widgets_->setGeneralListButton =
      NewPushButton(this, "General List", "button_left");
  widgets_->topUpButton = NewPushButton(this, "Top Up", "button_left");
  widgets_->dateButton = NewPushButton(
      this, QDate::currentDate().toString("dd-MM-yyyy"), "button_left");

  widgets_->takeOffButton = NewPushButton(this, "Take Off", "button_right");
  widgets_->placementPeriodButton = NewToolButton(this, "", "button_right");
  widgets_->buttonClearGeneralTable =
      NewPushButton(this, "Clear", "button_right");
  widgets_->buttonClearTakeOffTable =
      NewPushButton(this, "Clear", "button_right");
  widgets_->buttonClearTopUpTable =
      NewPushButton(this, "Clear", "button_right");

  widgets_->interestCapitalization =
      NewCheckBox(this, "Interest Capitalization", "check_box");

  widgets_->generalTable = new QTableWidget(this);
  widgets_->generalTable->setObjectName("data_table");

  widgets_->topUpTable = new QTableWidget(this);
  widgets_->topUpTable->setObjectName("data_table");

  widgets_->takeOffTable = new QTableWidget(this);
  widgets_->takeOffTable->setObjectName("data_table");

  widgets_->backgroundCalendar = NewWidget(this, "calendar_background");
  widgets_->calendar = new Calendar(widgets_->backgroundCalendar);
  widgets_->backgroundCalendar->hide();
}

void DepositCalculatorUI::setGeometry() {
  setMainInputContainer();
  setAddInputContainer();
  setOutputContainer();
  setTableContainer();
}

bool DepositCalculatorUI::setInput() {
  double depositAmount = widgets_->boxData[DEPOSIT_AMOUNT]->text().toDouble();
  double interestRate =
      widgets_->boxData[DEPOSIT_INTEREST_RATE]->text().toDouble();
  int frequencyOfPayments = widgets_->frequencyActiveAction.first;
  bool interestCapitalization = widgets_->interestCapitalization->isChecked();
  double taxRate = widgets_->boxData[DEPOSIT_TAX_RATE]->text().toDouble();
  double placementCount =
      widgets_->boxData[DEPOSIT_PLACEMENT_PERIOD]->text().toDouble();
  int placementPeriodType = widgets_->periodActiveAction.first;
  QDate startDate =
      QDate::fromString(widgets_->dateOfPlacementButton->text(), "dd-MM-yyyy");
  QDate endDate = setEndDate(startDate, placementPeriodType, placementCount);
  QVector<QDate> paymentDays =
      setPaymentDays(startDate, endDate, frequencyOfPayments);

  return controller_->setInput(
      depositAmount, interestRate, interestCapitalization, taxRate, startDate,
      endDate, paymentDays, widgets_->topUpList, widgets_->takeOffList);
}

QVector<QDate> DepositCalculatorUI::setPaymentDays(QDate startDate,
                                                   QDate endDate,
                                                   int frequencyOfPayments) {
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

QDate DepositCalculatorUI::setEndDate(QDate startDate, int periodType,
                                      int periodCount) {
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

  accuredInterest = controller_->getAccuredInterest();
  totalAmount = controller_->getTotalAmount();
  taxAmount = controller_->getTaxAmount();

  widgets_->boxData[DEPOSIT_ACCURED_INTEREST]->setText(
      QString::number(accuredInterest, 'f', 2));
  widgets_->boxData[DEPOSIT_TOTAL_AMOUNT]->setText(
      QString::number(totalAmount, 'f', 2));
  widgets_->boxData[DEPOSIT_TAX_AMOUNT]->setText(
      QString::number(taxAmount, 'f', 2));
}

void DepositCalculatorUI::connectWidgetsToSlots() {
  connect(widgets_->dateButton, &QPushButton::clicked, this,
          &DepositCalculatorUI::calendarShow);
  connect(widgets_->dateOfPlacementButton, &QPushButton::clicked, this,
          &DepositCalculatorUI::calendarShow);
  connect(widgets_->calendar, &QCalendarWidget::clicked, this,
          &DepositCalculatorUI::setDate);
  connect(widgets_->calculateButton, &QPushButton::clicked, this,
          &DepositCalculatorUI::Calculate);
  connect(widgets_->topUpButton, &QPushButton::clicked, this,
          &DepositCalculatorUI::addTopUp);
  connect(widgets_->takeOffButton, &QPushButton::clicked, this,
          &DepositCalculatorUI::addTakeOff);
  connect(widgets_->setGeneralListButton, &QPushButton::clicked, this,
          &DepositCalculatorUI::showGeneralTable);
  connect(widgets_->setTopUpListButton, &QPushButton::clicked, this,
          &DepositCalculatorUI::showTopUpTable);
  connect(widgets_->setTakeOffListButton, &QPushButton::clicked, this,
          &DepositCalculatorUI::showTakeOffTable);
  connect(widgets_->buttonClearTakeOffTable, &QPushButton::clicked, this,
          &DepositCalculatorUI::clearTakeOffList);
  connect(widgets_->buttonClearTopUpTable, &QPushButton::clicked, this,
          &DepositCalculatorUI::clearTopUpList);
  connect(widgets_->buttonClearGeneralTable, &QPushButton::clicked, this,
          &DepositCalculatorUI::clearGeneralList);
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
    connect(action, &QAction::triggered, this,
            &DepositCalculatorUI::setFrequency);
  }
  widgets_->frequencyOfPaymentsButton->setMenu(menu);
  widgets_->frequencyOfPaymentsButton->setPopupMode(QToolButton::InstantPopup);

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
  widgets_->placementPeriodButton->setMenu(menu);
  widgets_->placementPeriodButton->setPopupMode(QToolButton::InstantPopup);

  setPeriodButtonActiveAction(menu->actions()[MONTHS]);
}

void DepositCalculatorUI::setOutputContainer() {
  widgets_->outputContainer->setGeometry(
      10,
      widgets_->mainInputContainer->y() +
          widgets_->mainInputContainer->height() + 10,
      320, 250);

  Layout layout;
  layout.setStartPoints(widgets_->outputContainer->x(),
                        widgets_->outputContainer->y());
  layout.setEndPoints(
      widgets_->outputContainer->x() + widgets_->outputContainer->width(),
      widgets_->outputContainer->y() + widgets_->outputContainer->height());
  layout.setRows(3);
  layout.setColumns(1);
  layout.setLeftSpacing(10);
  layout.setRightSpacing(10);
  layout.setAboveSpacing(35);
  layout.setBottomSpacing(10);
  layout.setHorizontalSpacing(2);
  layout.setVerticalSpacing(35);
  layout.setAutoSize();

  layout.AddWidget(widgets_->box[DEPOSIT_ACCURED_INTEREST]);
  layout.AddWidget(widgets_->box[DEPOSIT_TOTAL_AMOUNT]);
  layout.AddWidget(widgets_->box[DEPOSIT_TAX_AMOUNT]);

  layout.SetTitle(widgets_->box[DEPOSIT_ACCURED_INTEREST],
                  widgets_->boxTitle[DEPOSIT_ACCURED_INTEREST], Layout::CenterH,
                  Layout::Above, 16, 0, -10);
  layout.SetTitle(widgets_->box[DEPOSIT_TOTAL_AMOUNT],
                  widgets_->boxTitle[DEPOSIT_TOTAL_AMOUNT], Layout::CenterH,
                  Layout::Above, 16, 0, -10);
  layout.SetTitle(widgets_->box[DEPOSIT_TAX_AMOUNT],
                  widgets_->boxTitle[DEPOSIT_TAX_AMOUNT], Layout::CenterH,
                  Layout::Above, 16, 0, -10);

  layout.SetField(widgets_->box[DEPOSIT_ACCURED_INTEREST],
                  widgets_->boxData[DEPOSIT_ACCURED_INTEREST], Layout::Left, 5);
  layout.SetField(widgets_->box[DEPOSIT_TOTAL_AMOUNT],
                  widgets_->boxData[DEPOSIT_TOTAL_AMOUNT], Layout::Left, 5);
  layout.SetField(widgets_->box[DEPOSIT_TAX_AMOUNT],
                  widgets_->boxData[DEPOSIT_TAX_AMOUNT], Layout::Left, 5);
}

void DepositCalculatorUI::setTableContainer() {
  Layout layout;

  int x0 = widgets_->mainInputContainer->x() +
           widgets_->mainInputContainer->width() + 20;
  int y0 = widgets_->addInputContainer->y() +
           widgets_->addInputContainer->height() + 26 + 45 + 20;

  int xMax = this->width() - 10;
  int yMax = this->height() - 10;

  layout.setStartPoints(x0, y0);
  layout.setEndPoints(xMax, yMax);
  layout.setRows(1);
  layout.setColumns(1);
  layout.setAutoSize();

  layout.AddWidget(widgets_->tablesContainer);
  widgets_->generalTable->setGeometry(
      widgets_->tablesContainer->x(), widgets_->tablesContainer->y(),
      widgets_->tablesContainer->width(), widgets_->tablesContainer->height());
  widgets_->topUpTable->setGeometry(
      widgets_->tablesContainer->x(), widgets_->tablesContainer->y(),
      widgets_->tablesContainer->width(), widgets_->tablesContainer->height());
  widgets_->takeOffTable->setGeometry(
      widgets_->tablesContainer->x(), widgets_->tablesContainer->y(),
      widgets_->tablesContainer->width(), widgets_->tablesContainer->height());
}

void DepositCalculatorUI::setTable() {
  widgets_->generalTable->setColumnCount(4);
  QStringList headerLabelsGeneralTable;
  headerLabelsGeneralTable << "Date"
                           << "Operation Type"
                           << "Operation Sum"
                           << "Deposit Sum";
  widgets_->generalTable->setHorizontalHeaderLabels(headerLabelsGeneralTable);
  widgets_->generalTable->horizontalHeader()->setSectionResizeMode(
      QHeaderView::Stretch);
  widgets_->generalTable->setEditTriggers(QAbstractItemView::NoEditTriggers);

  widgets_->takeOffTable->setColumnCount(2);
  QStringList headerLabelsTakeOff;
  headerLabelsTakeOff << "Date"
                      << "Sum";
  widgets_->takeOffTable->setHorizontalHeaderLabels(headerLabelsTakeOff);
  widgets_->takeOffTable->horizontalHeader()->setSectionResizeMode(
      QHeaderView::Stretch);
  widgets_->takeOffTable->setEditTriggers(QAbstractItemView::NoEditTriggers);

  widgets_->topUpTable->setColumnCount(2);
  QStringList headerLabelsTopUpTable;
  headerLabelsTopUpTable << "Date"
                         << "Sum";
  widgets_->topUpTable->setHorizontalHeaderLabels(headerLabelsTopUpTable);
  widgets_->topUpTable->horizontalHeader()->setSectionResizeMode(
      QHeaderView::Stretch);
  widgets_->topUpTable->setEditTriggers(QAbstractItemView::NoEditTriggers);
}

void DepositCalculatorUI::setAddInputContainer() {
  widgets_->addInputContainer->setGeometry(
      widgets_->mainInputContainer->x() +
          widgets_->mainInputContainer->width() + 10,
      10, 930, 170);
  Layout layout;

  layout.setStartPoints(widgets_->addInputContainer->x(),
                        widgets_->addInputContainer->y());
  layout.setEndPoints(
      widgets_->addInputContainer->x() + widgets_->addInputContainer->width(),
      widgets_->addInputContainer->y() + widgets_->addInputContainer->height());
  layout.setRows(2);
  layout.setColumns(3);
  layout.setLeftSpacing(10);
  layout.setRightSpacing(10);
  layout.setAboveSpacing(35);
  layout.setBottomSpacing(10);
  layout.setVerticalSpacing(35);
  layout.setHorizontalSpacing(10);
  layout.setAutoSize();

  layout.AddWidget(widgets_->dateOfPlacementButton);
  layout.setHorizontalSpacing(2);
  layout.AddWidget(widgets_->dateButton, 0.5);
  layout.setHorizontalSpacing(10);
  layout.AddWidget(widgets_->box[DEPOSIT_OPERATION_SUM], 0.5);
  layout.AddWidget(widgets_->interestCapitalization);
  layout.NextRow();
  layout.AddWidget(widgets_->box[DEPOSIT_TAX_RATE]);
  layout.setHorizontalSpacing(2);
  layout.AddWidget(widgets_->topUpButton, 0.5);
  layout.setHorizontalSpacing(10);
  layout.AddWidget(widgets_->takeOffButton, 0.5);
  layout.AddWidget(widgets_->calculateButton);
  layout.NextRow();
  layout.setHorizontalSpacing(2);
  layout.AddWidget(widgets_->setTopUpListButton, 0.5);
  layout.setHorizontalSpacing(10);
  layout.AddWidget(widgets_->buttonClearTopUpTable, 0.5);
  layout.setHorizontalSpacing(2);
  layout.AddWidget(widgets_->setTakeOffListButton, 0.5);
  layout.setHorizontalSpacing(10);
  layout.AddWidget(widgets_->buttonClearTakeOffTable, 0.5);
  layout.setHorizontalSpacing(2);
  layout.AddWidget(widgets_->setGeneralListButton, 0.5);
  layout.setHorizontalSpacing(10);
  layout.AddWidget(widgets_->buttonClearGeneralTable, 0.5);

  layout.SetTitle(widgets_->dateOfPlacementButton,
                  widgets_->boxTitle[DEPOSIT_DATE_OF_PLACEMENT],
                  Layout::CenterH, Layout::Above, 16, 0, -10);
  layout.SetTitle(widgets_->box[DEPOSIT_OPERATION_SUM],
                  widgets_->boxTitle[DEPOSIT_OPERATION_SUM], Layout::CenterH,
                  Layout::Above, 16, 0, -10);
  layout.SetTitle(widgets_->box[DEPOSIT_TAX_RATE],
                  widgets_->boxTitle[DEPOSIT_TAX_RATE], Layout::CenterH,
                  Layout::Above, 16, 0, -10);
  layout.SetTitle(widgets_->dateButton,
                  widgets_->boxTitle[DEPOSIT_OPERATION_DATE], Layout::CenterH,
                  Layout::Above, 16, 0, -10);

  layout.SetField(widgets_->box[DEPOSIT_TAX_RATE],
                  widgets_->boxData[DEPOSIT_TAX_RATE], Layout::CenterH, 0);
  layout.SetField(widgets_->box[DEPOSIT_OPERATION_SUM],
                  widgets_->boxData[DEPOSIT_OPERATION_SUM], Layout::CenterH, 0);
}

void DepositCalculatorUI::setMainInputContainer() {
  widgets_->mainInputContainer->setGeometry(10, 10, 320, 335);

  Layout layout;
  layout.setStartPoints(widgets_->mainInputContainer->x(),
                        widgets_->mainInputContainer->y());
  layout.setEndPoints(
      widgets_->mainInputContainer->x() + widgets_->mainInputContainer->width(),
      widgets_->mainInputContainer->y() +
          widgets_->mainInputContainer->height());
  layout.setRows(4);
  layout.setColumns(1);
  layout.setLeftSpacing(10);
  layout.setRightSpacing(10);
  layout.setAboveSpacing(35);
  layout.setBottomSpacing(10);
  layout.setHorizontalSpacing(2);
  layout.setVerticalSpacing(35);
  layout.setAutoSize();

  layout.AddWidget(widgets_->box[DEPOSIT_AMOUNT]);
  layout.AddWidget(widgets_->box[DEPOSIT_INTEREST_RATE]);
  layout.ChangeColumns(2);
  layout.AddWidget(widgets_->box[DEPOSIT_PLACEMENT_PERIOD]);
  layout.AddWidget(widgets_->placementPeriodButton);
  layout.ChangeColumns(1);
  layout.AddWidget(widgets_->frequencyOfPaymentsButton);

  layout.SetTitle(widgets_->box[DEPOSIT_AMOUNT],
                  widgets_->boxTitle[DEPOSIT_AMOUNT], Layout::CenterH,
                  Layout::Above, 16, 0, -10);
  layout.SetTitle(widgets_->box[DEPOSIT_INTEREST_RATE],
                  widgets_->boxTitle[DEPOSIT_INTEREST_RATE], Layout::CenterH,
                  Layout::Above, 16, 0, -10);
  layout.SetTitle(
      widgets_->box[DEPOSIT_PLACEMENT_PERIOD],
      widgets_->boxTitle[DEPOSIT_PLACEMENT_PERIOD], Layout::Left, Layout::Above,
      16, widgets_->box[DEPOSIT_PLACEMENT_PERIOD]->width() / 2 + 10, -10);
  layout.SetTitle(widgets_->frequencyOfPaymentsButton,
                  widgets_->boxTitle[DEPOSIT_FREQUENCY_OF_PAYMENTS],
                  Layout::CenterH, Layout::Above, 16, 0, -10);

  layout.SetField(widgets_->box[DEPOSIT_AMOUNT],
                  widgets_->boxData[DEPOSIT_AMOUNT], Layout::Left, 5);
  layout.SetField(widgets_->box[DEPOSIT_INTEREST_RATE],
                  widgets_->boxData[DEPOSIT_INTEREST_RATE], Layout::Left, 5);
  layout.SetField(widgets_->box[DEPOSIT_PLACEMENT_PERIOD],
                  widgets_->boxData[DEPOSIT_PLACEMENT_PERIOD], Layout::Left, 5);
}

void DepositCalculatorUI::setInputValidator() {
  widgets_->boxData[DEPOSIT_AMOUNT]->setValidator(
      new QRegularExpressionValidator(
          QRegularExpression("[0-9]{1,10}([.][0-9]{1,2})?"), this));
  widgets_->boxData[DEPOSIT_INTEREST_RATE]->setValidator(
      new QRegularExpressionValidator(
          QRegularExpression("[0-9]{1,3}([.][0-9]{1,2})?"), this));
  widgets_->boxData[DEPOSIT_TAX_RATE]->setValidator(
      new QRegularExpressionValidator(
          QRegularExpression("[0-9]{1,2}([.][0-9]{1,2})?"), this));
  widgets_->boxData[DEPOSIT_OPERATION_SUM]->setValidator(
      new QRegularExpressionValidator(
          QRegularExpression("[0-9]{1,10}([.][0-9]{1,2})?"), this));
  widgets_->boxData[DEPOSIT_PLACEMENT_PERIOD]->setValidator(
      new QRegularExpressionValidator(QRegularExpression("[0-9]{1,2}"), this));
}

void DepositCalculatorUI::setRow(QTableWidget *table, QString date,
                                 QString sum) {
  int currentRow = table->rowCount();
  table->setRowCount(currentRow + 1);

  table->setItem(currentRow, 0, new QTableWidgetItem(date));
  table->setItem(currentRow, 1, new QTableWidgetItem(sum));
}

void DepositCalculatorUI::setRow(QTableWidget *table, QString date,
                                 QString type, QString sum,
                                 QString depositSum) {
  int currentRow = table->rowCount();
  table->setRowCount(currentRow + 1);

  table->setItem(currentRow, 0, new QTableWidgetItem(date));
  table->setItem(currentRow, 1, new QTableWidgetItem(type));
  table->setItem(currentRow, 2, new QTableWidgetItem(sum));
  table->setItem(currentRow, 3, new QTableWidgetItem(depositSum));
}

void DepositCalculatorUI::setFrequencyButtonActiveAction(QAction *action) {
  widgets_->frequencyActiveAction.first = action->data().toInt();
  widgets_->frequencyActiveAction.second = action;

  widgets_->frequencyOfPaymentsButton->setText(action->text());
}

void DepositCalculatorUI::setPeriodButtonActiveAction(QAction *action) {
  widgets_->periodActiveAction.first = action->data().toInt();
  widgets_->periodActiveAction.second = action;

  widgets_->placementPeriodButton->setText(action->text());
}

void DepositCalculatorUI::fillGeneralList() {
  widgets_->generalTable->setRowCount(0);
  std::vector<std::tuple<QDate, QString, double, double>> generalList =
      controller_->getGeneralList();

  for (const auto &tuple : generalList) {
    QString date = std::get<0>(tuple).toString("dd-MM-yyyy");
    QString type = std::get<1>(tuple);
    QString operationSum = QString::number(std::get<2>(tuple), 'f', 2);
    QString depositSum = QString::number(std::get<3>(tuple), 'f', 2);

    setRow(widgets_->generalTable, date, type, operationSum, depositSum);
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
  widgets_->depositCalcWindow->setStyleSheet(styleSheet);

  for (auto it : widgets_->boxData) {
    it.second->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
  }

  widgets_->boxData[DEPOSIT_ACCURED_INTEREST]->setReadOnly(true);
  widgets_->boxData[DEPOSIT_TOTAL_AMOUNT]->setReadOnly(true);
  widgets_->boxData[DEPOSIT_TAX_AMOUNT]->setReadOnly(true);
}

void DepositCalculatorUI::clearTakeOffList() {
  widgets_->takeOffList.clear();
  widgets_->takeOffTable->setRowCount(0);
}

void DepositCalculatorUI::clearTopUpList() {
  widgets_->topUpList.clear();
  widgets_->topUpTable->setRowCount(0);
}

void DepositCalculatorUI::clearGeneralList() {
  widgets_->generalList.clear();
  widgets_->generalTable->setRowCount(0);
}

void DepositCalculatorUI::showGeneralTable() {
  widgets_->takeOffTable->hide();
  widgets_->topUpTable->hide();
  widgets_->generalTable->show();
}

void DepositCalculatorUI::showTopUpTable() {
  widgets_->generalTable->hide();
  widgets_->takeOffTable->hide();
  widgets_->topUpTable->show();
}

void DepositCalculatorUI::showTakeOffTable() {
  widgets_->generalTable->hide();
  widgets_->topUpTable->hide();
  widgets_->takeOffTable->show();
}

void DepositCalculatorUI::addTopUp() {
  if (widgets_->topUpList.size() < 50) {
    QDate date = QDate::fromString(widgets_->dateButton->text(), "dd-MM-yyyy");
    double sum = widgets_->boxData[DEPOSIT_OPERATION_SUM]->text().toDouble();

    widgets_->topUpList.insert(std::make_pair(date, sum));
    widgets_->topUpTable->setRowCount(0);

    for (auto it : widgets_->topUpList) {
      setRow(widgets_->topUpTable, it.first.toString("dd-MM-yyyy"),
             QString::number(it.second, 'f', 2));
    }
  }
  showTopUpTable();
}

void DepositCalculatorUI::addTakeOff() {
  if (widgets_->takeOffList.size() < 50) {
    QDate date = QDate::fromString(widgets_->dateButton->text(), "dd-MM-yyyy");
    double sum = widgets_->boxData[DEPOSIT_OPERATION_SUM]->text().toDouble();

    widgets_->takeOffList.insert(std::make_pair(date, sum));
    widgets_->takeOffTable->setRowCount(0);

    for (auto it : widgets_->takeOffList) {
      setRow(widgets_->takeOffTable, it.first.toString("dd-MM-yyyy"),
             QString::number(it.second, 'f', 2));
    }
  }
  showTakeOffTable();
}

void DepositCalculatorUI::Calculate() {
  if (setInput()) {
    controller_->Calculate();
    getOutput();
    fillGeneralList();
    showGeneralTable();
  }
}

void DepositCalculatorUI::setPeriod() {
  setPeriodButtonActiveAction(static_cast<QAction *>(sender()));
}

void DepositCalculatorUI::setFrequency() {
  setFrequencyButtonActiveAction(static_cast<QAction *>(sender()));
}

void DepositCalculatorUI::calendarShow() {
  calendarSender_ = static_cast<QToolButton *>(sender());

  int calendarWidth = 300;
  int calendarHeight = 300;

  int calendarY = calendarSender_->y() + calendarSender_->height() + 10;
  int calendarX =
      calendarSender_->x() + calendarSender_->width() / 2 - calendarWidth / 2;

  widgets_->backgroundCalendar->setGeometry(calendarX, calendarY, calendarWidth,
                                            calendarHeight);
  widgets_->calendar->setGeometry(10, 10,
                                  widgets_->backgroundCalendar->width() - 15,
                                  widgets_->backgroundCalendar->height() - 20);
  widgets_->backgroundCalendar->show();
}

void DepositCalculatorUI::setDate() {
  widgets_->backgroundCalendar->hide();
  QDate selectedDate(widgets_->calendar->selectedDate());
  calendarSender_->setText(selectedDate.toString("dd-MM-yyyy"));
}
