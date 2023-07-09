#pragma once

#include "mainwindow.h"
#include "IPlatformUI.h"
#include "../Controllers/CreditCalcController.h"
#include <cmath>

using namespace std;

class CreditCalculatorUI : public MainWindow
{
    CreditCalcWidgets *_widgets;
    CreditCalcController *_controller;
public:
    CreditCalculatorUI() : MainWindow(), _controller(new CreditCalcController), _widgets(new CreditCalcWidgets) {
        _widgets->chartView = new ChartView(this);
        _widgets->creditCalcWindow = this;

        initWidgets();
        setGeometry();
        setOptions();
        setInputValidator();
        connectWidgetsToSlots();
    }

    ~CreditCalculatorUI() {
        delete _controller;
        delete _widgets;
    }

    void SetupUI() override {
        (*_platform)->SetupUI(_widgets);
    }

private:
    void initWidgets() {
        _widgets->box.insert(make_pair(CREDIT_SUM, new QTextEdit(this)));
        _widgets->box.insert(make_pair(CREDIT_TERM, new QTextEdit(this)));
        _widgets->box.insert(make_pair(CREDIT_INTEREST_RATE, new QTextEdit(this)));
        _widgets->box.insert(make_pair(CREDIT_TOTAL_PAYMENT, new QTextEdit(this)));
        _widgets->box.insert(make_pair(CREDIT_OVERPAYMENT, new QTextEdit(this)));
        _widgets->box.insert(make_pair(CREDIT_MONTHLY_PAYMENT, new QTextEdit(this)));

        _widgets->title.insert(make_pair(CREDIT_SUM, new QLabel("Credit Sum", this)));
        _widgets->title.insert(make_pair(CREDIT_TERM, new QLabel("Credit Term", this)));
        _widgets->title.insert(make_pair(CREDIT_INTEREST_RATE, new QLabel("Interest Rate", this)));
        _widgets->title.insert(make_pair(CREDIT_TOTAL_PAYMENT, new QLabel("Total Payment", this)));
        _widgets->title.insert(make_pair(CREDIT_OVERPAYMENT, new QLabel("Overpayment", this)));
        _widgets->title.insert(make_pair(CREDIT_MONTHLY_PAYMENT, new QLabel("Montly Payments", this)));

        _widgets->data.insert(make_pair(CREDIT_SUM, NewLineEdit(this, "1000", "inputCreditSum")));
        _widgets->data.insert(make_pair(CREDIT_TERM, NewLineEdit(this, "12", "inputCreditTerm")));
        _widgets->data.insert(make_pair(CREDIT_INTEREST_RATE, NewLineEdit(this, "10", "inputInterestRate")));
        _widgets->data.insert(make_pair(CREDIT_TOTAL_PAYMENT, new QLineEdit(this)));
        _widgets->data.insert(make_pair(CREDIT_OVERPAYMENT, new QLineEdit(this)));

        _widgets->annuityPaymentButton = new QPushButton("Annuity Payment", this);
        _widgets->differentiatedPaymentButton = new QPushButton("Differentiated Payment", this);
        _widgets->monthlyPaymentList = new QComboBox(this);
    }

    void connectWidgetsToSlots() {
        connect(_widgets->annuityPaymentButton, &QPushButton::clicked, this, &CreditCalculatorUI::AnnuityPayment);
        connect(_widgets->differentiatedPaymentButton, &QPushButton::clicked, this, &CreditCalculatorUI::DifferentiatedPayment);
    }

    void setGeometry() {
        this->setFixedSize(950, 700);
        _widgets->chartView->setGeometry(0, 225, this->width(), this->height() - 225);

        Layout layout;

        layout.SetStartPoints(0, 0);
        layout.SetEndPoints(950, 225);
        layout.SetColumns(3);
        layout.SetRows(3);
        layout.SetLeftSpacing(14);
        layout.SetRightSpacing(14);
        layout.SetAboveSpacing(50);
        layout.SetBottomSpacing(0);
        layout.SetHorizontalSpacing(12);
        layout.SetVerticalSpacing(20);
        layout.SetAutoSize();

        layout.AddWidget(_widgets->box[CREDIT_SUM]);
        layout.AddWidget(_widgets->box[CREDIT_TERM]);
        layout.AddWidget(_widgets->box[CREDIT_INTEREST_RATE]);

        layout.ChangeColumns(2);
        layout.AddWidget(_widgets->annuityPaymentButton);
        layout.AddWidget(_widgets->differentiatedPaymentButton);

        layout.ChangeColumns(3);
        layout.AddWidget(_widgets->box[CREDIT_TOTAL_PAYMENT]);
        layout.AddWidget(_widgets->box[CREDIT_OVERPAYMENT]);
        layout.AddWidget(_widgets->box[CREDIT_MONTHLY_PAYMENT]);

        layout.SetTitle(_widgets->box[CREDIT_SUM], _widgets->title[CREDIT_SUM], Layout::Left, Layout::Above, 16, 0, -10);
        layout.SetTitle(_widgets->box[CREDIT_TERM], _widgets->title[CREDIT_TERM], Layout::Left, Layout::Above, 16, 0, -10);
        layout.SetTitle(_widgets->box[CREDIT_INTEREST_RATE], _widgets->title[CREDIT_INTEREST_RATE], Layout::Left, Layout::Above, 16, 0, -10);
        layout.SetTitle(_widgets->box[CREDIT_TOTAL_PAYMENT], _widgets->title[CREDIT_TOTAL_PAYMENT], Layout::Left, Layout::CenterV, 16, 5, 0);
        layout.SetTitle(_widgets->box[CREDIT_OVERPAYMENT], _widgets->title[CREDIT_OVERPAYMENT], Layout::Left, Layout::CenterV, 16, 5, 0);
        layout.SetTitle(_widgets->box[CREDIT_MONTHLY_PAYMENT], _widgets->title[CREDIT_MONTHLY_PAYMENT], Layout::Left, Layout::CenterV, 16, 5, 0);

        layout.SetField(_widgets->box[CREDIT_SUM], _widgets->data[CREDIT_SUM],Layout::Left, 15);
        layout.SetField(_widgets->box[CREDIT_TERM], _widgets->data[CREDIT_TERM], Layout::Left, 15);
        layout.SetField(_widgets->box[CREDIT_INTEREST_RATE], _widgets->data[CREDIT_INTEREST_RATE], Layout::Left, 15);
        layout.SetField(_widgets->box[CREDIT_TOTAL_PAYMENT], _widgets->data[CREDIT_TOTAL_PAYMENT], Layout::Right, 15);
        layout.SetField(_widgets->box[CREDIT_OVERPAYMENT], _widgets->data[CREDIT_OVERPAYMENT], Layout::Right, 15);

        layout.SetField(_widgets->box[CREDIT_MONTHLY_PAYMENT], _widgets->monthlyPaymentList, Layout::Left, _widgets->box[CREDIT_MONTHLY_PAYMENT]->width()/2);
    }

    void setOptions() {
        _widgets->data[CREDIT_TOTAL_PAYMENT]->setReadOnly(true);
        _widgets->data[CREDIT_OVERPAYMENT]->setReadOnly(true);

        _widgets->data[CREDIT_SUM]->setAlignment(Qt::AlignLeft);
        _widgets->data[CREDIT_TERM]->setAlignment(Qt::AlignLeft);
        _widgets->data[CREDIT_INTEREST_RATE]->setAlignment(Qt::AlignLeft);
        _widgets->data[CREDIT_TOTAL_PAYMENT]->setAlignment(Qt::AlignRight);
        _widgets->data[CREDIT_OVERPAYMENT]->setAlignment(Qt::AlignRight);

        _widgets->box[CREDIT_SUM]->setReadOnly(true);
        _widgets->box[CREDIT_TERM]->setReadOnly(true);
        _widgets->box[CREDIT_INTEREST_RATE]->setReadOnly(true);
        _widgets->box[CREDIT_TOTAL_PAYMENT]->setReadOnly(true);
        _widgets->box[CREDIT_OVERPAYMENT]->setReadOnly(true);
        _widgets->box[CREDIT_MONTHLY_PAYMENT]->setReadOnly(true);
    }

    void setInputValidator() {
        _widgets->data[CREDIT_SUM]->setValidator(new QRegularExpressionValidator(QRegularExpression("[0-9]{1,10}[.][0-9]{0,2}"), this));
        _widgets->data[CREDIT_TERM]->setValidator(new QRegularExpressionValidator(QRegularExpression("[0-9]{0,2}"), this));
        _widgets->data[CREDIT_INTEREST_RATE]->setValidator(new QRegularExpressionValidator(QRegularExpression("[0-9]{1,2}[.][0-9]{0,2}"), this));
    }

    bool setInput() {
        double creditSum = _widgets->data[CREDIT_SUM]->text().toDouble();
        double creditTerm = _widgets->data[CREDIT_TERM]->text().toDouble();
        double interestRate = _widgets->data[CREDIT_INTEREST_RATE]->text().toDouble();

        return _controller->setInput(creditSum, creditTerm, interestRate);
    }

    void getOutput() {
        _widgets->monthlyPaymentList->clear();
        for (auto it : _controller->getMonthlyPayments()) {
            _widgets->monthlyPaymentList->addItem(QString::number(it, 'f', 2));
        }

        _widgets->data[CREDIT_TOTAL_PAYMENT]->setText(QString::number(_controller->getTotalPayment(), 'f', 2));
        _widgets->data[CREDIT_OVERPAYMENT]->setText(QString::number(_controller->getOverpayment(), 'f', 2));
    }

    void Calculate(Service::CreditPaymentsType type) {
        if (setInput()) {
            _controller->Calculate(type);
            getOutput();
            DrawChartBars();
        }
    }

private slots:
    void AnnuityPayment() {
        Calculate(Service::ANNUITY);
    }

    void DifferentiatedPayment() {
        Calculate(Service::DIFFERENTIATED);
    }

    void DrawChartBars() {
        _widgets->chartView->SetData(_controller->getMonthlyBodyPayments(), _controller->getMonthlyPercentPayments());
        _widgets->chartView->show();
    }
};
