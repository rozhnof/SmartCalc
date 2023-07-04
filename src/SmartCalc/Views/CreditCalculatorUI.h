#pragma once


#include "mainwindow.h"
#include "IPlatformUI.h"
#include "../Controllers/CreditCalcController.h"
#include <cmath>

using namespace std;


class CreditCalculatorUI : public MainWindow
{
public:
    CreditCalcWidgets *widgets;
    CreditCalcController *controller;

    CreditCalculatorUI() : MainWindow() {
        controller = new CreditCalcController;
        widgets = new CreditCalcWidgets;

        widgets->chartView = new ChartView(this);
        widgets->creditCalcWindow = this;

        CreateObjects();
        SetGeometry();
        SetOptions();
        DifferentiatedPayment();
    }

    void CreateObjects() {
        widgets->box.insert(make_pair(CreditSum, new QTextEdit(this)));
        widgets->box.insert(make_pair(CreditTerm, new QTextEdit(this)));
        widgets->box.insert(make_pair(InterestRate, new QTextEdit(this)));
        widgets->box.insert(make_pair(TotalPayment, new QTextEdit(this)));
        widgets->box.insert(make_pair(Overpayment, new QTextEdit(this)));
        widgets->box.insert(make_pair(MonthlyPayment, new QTextEdit(this)));

        widgets->title.insert(make_pair(CreditSum, new QLabel("Credit Sum", this)));
        widgets->title.insert(make_pair(CreditTerm, new QLabel("Credit Term", this)));
        widgets->title.insert(make_pair(InterestRate, new QLabel("Interest Rate", this)));
        widgets->title.insert(make_pair(TotalPayment, new QLabel("Total Payment", this)));
        widgets->title.insert(make_pair(Overpayment, new QLabel("Overpayment", this)));
        widgets->title.insert(make_pair(MonthlyPayment, new QLabel("Montly Payments", this)));

        widgets->data.insert(make_pair(CreditSum, NewLineEdit(this, "1000", "inputCreditSum")));
        widgets->data.insert(make_pair(CreditTerm, NewLineEdit(this, "12", "inputCreditTerm")));
        widgets->data.insert(make_pair(InterestRate, NewLineEdit(this, "10", "inputInterestRate")));
        widgets->data.insert(make_pair(TotalPayment, new QLineEdit(this)));
        widgets->data.insert(make_pair(Overpayment, new QLineEdit(this)));

        widgets->annuityPaymentButton = new QPushButton("Annuity Payment", this);
        widgets->differentiatedPaymentButton = new QPushButton("Differentiated Payment", this);
        widgets->monthlyPaymentList = new QComboBox(this);
        widgets->creditTermList = new QComboBox(this);

        connect(widgets->annuityPaymentButton, &QPushButton::clicked, this, &CreditCalculatorUI::AnnuityPayment);
        connect(widgets->differentiatedPaymentButton, &QPushButton::clicked, this, &CreditCalculatorUI::DifferentiatedPayment);
    }

    void SetGeometry() {
        this->setFixedSize(950, 700);
        widgets->chartView->setGeometry(0, 225, this->width(), this->height() - 225);

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

        layout.AddWidget(widgets->box[CreditSum]);
        layout.AddWidget(widgets->box[CreditTerm]);
        layout.AddWidget(widgets->box[InterestRate]);

        layout.ChangeColumns(2);
        layout.AddWidget(widgets->annuityPaymentButton);
        layout.AddWidget(widgets->differentiatedPaymentButton);

        layout.ChangeColumns(3);
        layout.AddWidget(widgets->box[TotalPayment]);
        layout.AddWidget(widgets->box[Overpayment]);
        layout.AddWidget(widgets->box[MonthlyPayment]);

        layout.SetTitle(widgets->box[CreditSum], widgets->title[CreditSum], Layout::Left, Layout::Above, 16, 0, -10);
        layout.SetTitle(widgets->box[CreditTerm], widgets->title[CreditTerm], Layout::Left, Layout::Above, 16, 0, -10);
        layout.SetTitle(widgets->box[InterestRate], widgets->title[InterestRate], Layout::Left, Layout::Above, 16, 0, -10);
        layout.SetTitle(widgets->box[TotalPayment], widgets->title[TotalPayment], Layout::Left, Layout::CenterV, 16, 5, 0);
        layout.SetTitle(widgets->box[Overpayment], widgets->title[Overpayment], Layout::Left, Layout::CenterV, 16, 5, 0);
        layout.SetTitle(widgets->box[MonthlyPayment], widgets->title[MonthlyPayment], Layout::Left, Layout::CenterV, 16, 5, 0);

        layout.SetField(widgets->box[CreditSum], widgets->data[CreditSum],Layout::Left, 15);
        layout.SetField(widgets->box[CreditTerm], widgets->data[CreditTerm], Layout::Left, 15);
        layout.SetField(widgets->box[InterestRate], widgets->data[InterestRate], Layout::Left, 15);
        layout.SetField(widgets->box[TotalPayment], widgets->data[TotalPayment], Layout::Right, 15);
        layout.SetField(widgets->box[Overpayment], widgets->data[Overpayment], Layout::Right, 15);

        layout.SetField(widgets->box[MonthlyPayment], widgets->monthlyPaymentList, Layout::Left, widgets->box[MonthlyPayment]->width()/2);
        layout.SetField(widgets->box[CreditTerm], widgets->creditTermList, Layout::Left, widgets->box[CreditTerm]->width() - widgets->creditTermList->sizeHint().width());
    }

    void SetOptions() {
        widgets->data[TotalPayment]->setReadOnly(true);
        widgets->data[Overpayment]->setReadOnly(true);

        widgets->data[CreditSum]->setAlignment(Qt::AlignLeft);
        widgets->data[CreditTerm]->setAlignment(Qt::AlignLeft);
        widgets->data[InterestRate]->setAlignment(Qt::AlignLeft);
        widgets->data[TotalPayment]->setAlignment(Qt::AlignRight);
        widgets->data[Overpayment]->setAlignment(Qt::AlignRight);

        widgets->box[CreditSum]->setReadOnly(true);
        widgets->box[CreditTerm]->setReadOnly(true);
        widgets->box[InterestRate]->setReadOnly(true);
        widgets->box[TotalPayment]->setReadOnly(true);
        widgets->box[Overpayment]->setReadOnly(true);
        widgets->box[MonthlyPayment]->setReadOnly(true);

        widgets->data[CreditSum]->setValidator(new QRegularExpressionValidator(QRegularExpression("[0-9]{1,10}[.][0-9]{0,2}"), this));
        widgets->data[CreditTerm]->setValidator(new QRegularExpressionValidator(QRegularExpression("[0-9]{0,2}"), this));
        widgets->data[InterestRate]->setValidator(new QRegularExpressionValidator(QRegularExpression("[0-9]{1,2}[.][0-9]{0,2}"), this));

        widgets->creditTermList->addItem("Month");
        widgets->creditTermList->addItem("Years");
        widgets->creditTermList->addItem("Days");
    }

    bool SetInput() {
        double creditSum = widgets->data[CreditSum]->text().toDouble();
        double creditTerm = widgets->data[CreditTerm]->text().toDouble();
        double interestRate = widgets->data[InterestRate]->text().toDouble();

        return controller->setInput(creditSum, creditTerm, interestRate);
    }

    void GetOutput() {
        widgets->monthlyPaymentList->clear();
        for (auto it : controller->getMonthlyPayments()) {
            widgets->monthlyPaymentList->addItem(QString::number(it, 'f', 2));
        }

        widgets->data[TotalPayment]->setText(QString::number(controller->getTotalPayment(), 'f', 2));
        widgets->data[Overpayment]->setText(QString::number(controller->getOverpayment(), 'f', 2));
    }

    void ClearOutput() {
        widgets->monthlyPaymentList->clear();
        widgets->bodyPayments.clear();
        widgets->percentPayments.clear();
    }


    void SetupUI() override {
        (*_platform)->SetupUI(widgets);
    }

    void Calculate(Service::CreditPaymentsType type) {
        if (SetInput()) {
            controller->Calculate(type);
            GetOutput();
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
        widgets->chartView->SetData(controller->getMonthlyBodyPayments(), controller->getMonthlyPercentPayments());
        widgets->chartView->show();
    }
};
