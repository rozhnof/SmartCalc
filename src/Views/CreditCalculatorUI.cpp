#include "CreditCalculatorUI.h"

CreditCalculatorUI::CreditCalculatorUI()
    : MainWindow(),
      controller_(new CreditCalcController),
      widgets_(new CreditCalcWidgets) {
  widgets_->chartView = new ChartView(this);
  widgets_->creditCalcWindow = this;

  initWidgets();
  setGeometry();
  setOptions();
  setInputValidator();
  connectWidgetsToSlots();
}

CreditCalculatorUI::~CreditCalculatorUI() {
  delete controller_;
  delete widgets_;
}

void CreditCalculatorUI::SetupUI() { (*platform_)->SetupUI(widgets_); }

void CreditCalculatorUI::initWidgets() {
  widgets_->box.insert(std::make_pair(CREDIT_SUM, new QTextEdit(this)));
  widgets_->box.insert(std::make_pair(CREDIT_TERM, new QTextEdit(this)));
  widgets_->box.insert(
      std::make_pair(CREDIT_INTEREST_RATE, new QTextEdit(this)));
  widgets_->box.insert(
      std::make_pair(CREDIT_TOTAL_PAYMENT, new QTextEdit(this)));
  widgets_->box.insert(std::make_pair(CREDIT_OVERPAYMENT, new QTextEdit(this)));
  widgets_->box.insert(
      std::make_pair(CREDIT_MONTHLY_PAYMENT, new QTextEdit(this)));

  widgets_->title.insert(
      std::make_pair(CREDIT_SUM, new QLabel("Credit Sum", this)));
  widgets_->title.insert(
      std::make_pair(CREDIT_TERM, new QLabel("Credit Term", this)));
  widgets_->title.insert(
      std::make_pair(CREDIT_INTEREST_RATE, new QLabel("Interest Rate", this)));
  widgets_->title.insert(
      std::make_pair(CREDIT_TOTAL_PAYMENT, new QLabel("Total Payment", this)));
  widgets_->title.insert(
      std::make_pair(CREDIT_OVERPAYMENT, new QLabel("Overpayment", this)));
  widgets_->title.insert(std::make_pair(CREDIT_MONTHLY_PAYMENT,
                                        new QLabel("Montly Payments", this)));

  widgets_->data.insert(
      std::make_pair(CREDIT_SUM, NewLineEdit(this, "1000", "inputCreditSum")));
  widgets_->data.insert(
      std::make_pair(CREDIT_TERM, NewLineEdit(this, "12", "inputCreditTerm")));
  widgets_->data.insert(std::make_pair(
      CREDIT_INTEREST_RATE, NewLineEdit(this, "10", "inputInterestRate")));
  widgets_->data.insert(
      std::make_pair(CREDIT_TOTAL_PAYMENT, new QLineEdit(this)));
  widgets_->data.insert(
      std::make_pair(CREDIT_OVERPAYMENT, new QLineEdit(this)));

  widgets_->annuityPaymentButton = new QPushButton("Annuity Payment", this);
  widgets_->differentiatedPaymentButton =
      new QPushButton("Differentiated Payment", this);
  widgets_->monthlyPaymentList = new QComboBox(this);
}

void CreditCalculatorUI::connectWidgetsToSlots() {
  connect(widgets_->annuityPaymentButton, &QPushButton::clicked, this,
          &CreditCalculatorUI::AnnuityPayment);
  connect(widgets_->differentiatedPaymentButton, &QPushButton::clicked, this,
          &CreditCalculatorUI::DifferentiatedPayment);
}

void CreditCalculatorUI::setGeometry() {
  this->setFixedSize(950, 700);
  widgets_->chartView->setGeometry(0, 225, this->width(), this->height() - 225);

  Layout layout;

  layout.setStartPoints(0, 0);
  layout.setEndPoints(950, 225);
  layout.setColumns(3);
  layout.setRows(3);
  layout.setLeftSpacing(14);
  layout.setRightSpacing(14);
  layout.setAboveSpacing(50);
  layout.setBottomSpacing(0);
  layout.setHorizontalSpacing(12);
  layout.setVerticalSpacing(20);
  layout.setAutoSize();

  layout.AddWidget(widgets_->box[CREDIT_SUM]);
  layout.AddWidget(widgets_->box[CREDIT_TERM]);
  layout.AddWidget(widgets_->box[CREDIT_INTEREST_RATE]);

  layout.ChangeColumns(2);
  layout.AddWidget(widgets_->annuityPaymentButton);
  layout.AddWidget(widgets_->differentiatedPaymentButton);

  layout.ChangeColumns(3);
  layout.AddWidget(widgets_->box[CREDIT_TOTAL_PAYMENT]);
  layout.AddWidget(widgets_->box[CREDIT_OVERPAYMENT]);
  layout.AddWidget(widgets_->box[CREDIT_MONTHLY_PAYMENT]);

  layout.SetTitle(widgets_->box[CREDIT_SUM], widgets_->title[CREDIT_SUM],
                  Layout::Left, Layout::Above, 16, 0, -10);
  layout.SetTitle(widgets_->box[CREDIT_TERM], widgets_->title[CREDIT_TERM],
                  Layout::Left, Layout::Above, 16, 0, -10);
  layout.SetTitle(widgets_->box[CREDIT_INTEREST_RATE],
                  widgets_->title[CREDIT_INTEREST_RATE], Layout::Left,
                  Layout::Above, 16, 0, -10);
  layout.SetTitle(widgets_->box[CREDIT_TOTAL_PAYMENT],
                  widgets_->title[CREDIT_TOTAL_PAYMENT], Layout::Left,
                  Layout::CenterV, 16, 5, 0);
  layout.SetTitle(widgets_->box[CREDIT_OVERPAYMENT],
                  widgets_->title[CREDIT_OVERPAYMENT], Layout::Left,
                  Layout::CenterV, 16, 5, 0);
  layout.SetTitle(widgets_->box[CREDIT_MONTHLY_PAYMENT],
                  widgets_->title[CREDIT_MONTHLY_PAYMENT], Layout::Left,
                  Layout::CenterV, 16, 5, 0);

  layout.SetField(widgets_->box[CREDIT_SUM], widgets_->data[CREDIT_SUM],
                  Layout::Left, 15);
  layout.SetField(widgets_->box[CREDIT_TERM], widgets_->data[CREDIT_TERM],
                  Layout::Left, 15);
  layout.SetField(widgets_->box[CREDIT_INTEREST_RATE],
                  widgets_->data[CREDIT_INTEREST_RATE], Layout::Left, 15);
  layout.SetField(widgets_->box[CREDIT_TOTAL_PAYMENT],
                  widgets_->data[CREDIT_TOTAL_PAYMENT], Layout::Right, 15);
  layout.SetField(widgets_->box[CREDIT_OVERPAYMENT],
                  widgets_->data[CREDIT_OVERPAYMENT], Layout::Right, 15);

  layout.SetField(widgets_->box[CREDIT_MONTHLY_PAYMENT],
                  widgets_->monthlyPaymentList, Layout::Left,
                  widgets_->box[CREDIT_MONTHLY_PAYMENT]->width() / 2);
}

void CreditCalculatorUI::setOptions() {
  widgets_->data[CREDIT_TOTAL_PAYMENT]->setReadOnly(true);
  widgets_->data[CREDIT_OVERPAYMENT]->setReadOnly(true);

  widgets_->data[CREDIT_SUM]->setAlignment(Qt::AlignLeft);
  widgets_->data[CREDIT_TERM]->setAlignment(Qt::AlignLeft);
  widgets_->data[CREDIT_INTEREST_RATE]->setAlignment(Qt::AlignLeft);
  widgets_->data[CREDIT_TOTAL_PAYMENT]->setAlignment(Qt::AlignRight);
  widgets_->data[CREDIT_OVERPAYMENT]->setAlignment(Qt::AlignRight);

  widgets_->box[CREDIT_SUM]->setReadOnly(true);
  widgets_->box[CREDIT_TERM]->setReadOnly(true);
  widgets_->box[CREDIT_INTEREST_RATE]->setReadOnly(true);
  widgets_->box[CREDIT_TOTAL_PAYMENT]->setReadOnly(true);
  widgets_->box[CREDIT_OVERPAYMENT]->setReadOnly(true);
  widgets_->box[CREDIT_MONTHLY_PAYMENT]->setReadOnly(true);
}

void CreditCalculatorUI::setInputValidator() {
  widgets_->data[CREDIT_SUM]->setValidator(new QRegularExpressionValidator(
      QRegularExpression("[0-9]{1,10}[.][0-9]{0,2}"), this));
  widgets_->data[CREDIT_TERM]->setValidator(
      new QRegularExpressionValidator(QRegularExpression("[0-9]{0,2}"), this));
  widgets_->data[CREDIT_INTEREST_RATE]->setValidator(
      new QRegularExpressionValidator(
          QRegularExpression("[0-9]{1,2}[.][0-9]{0,2}"), this));
}

bool CreditCalculatorUI::setInput() {
  double creditSum = widgets_->data[CREDIT_SUM]->text().toDouble();
  double creditTerm = widgets_->data[CREDIT_TERM]->text().toDouble();
  double interestRate = widgets_->data[CREDIT_INTEREST_RATE]->text().toDouble();

  return controller_->setInput(creditSum, creditTerm, interestRate);
}

void CreditCalculatorUI::getOutput() {
  widgets_->monthlyPaymentList->clear();
  for (auto it : controller_->getMonthlyPayments()) {
    widgets_->monthlyPaymentList->addItem(QString::number(it, 'f', 2));
  }

  widgets_->data[CREDIT_TOTAL_PAYMENT]->setText(
      QString::number(controller_->getTotalPayment(), 'f', 2));
  widgets_->data[CREDIT_OVERPAYMENT]->setText(
      QString::number(controller_->getOverpayment(), 'f', 2));
}

void CreditCalculatorUI::Calculate(Service::CreditPaymentsType type) {
  if (setInput()) {
    controller_->Calculate(type);
    getOutput();
    DrawChartBars();
  }
}

void CreditCalculatorUI::AnnuityPayment() { Calculate(Service::ANNUITY); }

void CreditCalculatorUI::DifferentiatedPayment() {
  Calculate(Service::DIFFERENTIATED);
}

void CreditCalculatorUI::DrawChartBars() {
  widgets_->chartView->setData(controller_->getMonthlyBodyPayments(),
                               controller_->getMonthlyPercentPayments());
  widgets_->chartView->show();
}
