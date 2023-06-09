#ifndef CREDITCALCULATORUI_H
#define CREDITCALCULATORUI_H

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

    QComboBox *monthlyPaymentList;
    QComboBox *creditTermList;
    QPushButton *annuityPaymentButton;
    QPushButton *differentiatedPaymentButton;

    Layout layout;

    CreditCalculatorUI() : MainWindow() {
        this->setWindowTitle("Credit Calculator");

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

        widgets->data.insert(make_pair(CreditSum, NewQLineEdit(this, "1000", "inputCreditSum")));
        widgets->data.insert(make_pair(CreditTerm, NewQLineEdit(this, "12", "inputCreditTerm")));
        widgets->data.insert(make_pair(InterestRate, NewQLineEdit(this, "10", "inputInterestRate")));
        widgets->data.insert(make_pair(TotalPayment, new QLineEdit(this)));
        widgets->data.insert(make_pair(Overpayment, new QLineEdit(this)));

        annuityPaymentButton = new QPushButton("Annuity Payment", this);
        differentiatedPaymentButton = new QPushButton("Differentiated Payment", this);
        monthlyPaymentList = new QComboBox(this);
        creditTermList = new QComboBox(this);

        connect(annuityPaymentButton, &QPushButton::clicked, this, &CreditCalculatorUI::AnnuityPayment);
        connect(differentiatedPaymentButton, &QPushButton::clicked, this, &CreditCalculatorUI::DifferentiatedPayment);
    }

    void SetGeometry() {
        this->setFixedSize(950, 700);
        widgets->chartView->setGeometry(0, 225, this->width(), this->height() - 225);

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
        layout.AddWidget(annuityPaymentButton);
        layout.AddWidget(differentiatedPaymentButton);

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

        layout.SetField(widgets->box[MonthlyPayment], monthlyPaymentList, Layout::Left, widgets->box[MonthlyPayment]->width()/2);
        layout.SetField(widgets->box[CreditTerm], creditTermList, Layout::Left, widgets->box[CreditTerm]->width() - creditTermList->sizeHint().width());
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

        creditTermList->addItem("Month");
        creditTermList->addItem("Years");
        creditTermList->addItem("Days");
    }

    void SetInput() {
        controller->SetCreditSum(widgets->data[CreditSum]->text().toDouble());
        controller->SetCreditTerm(widgets->data[CreditTerm]->text().toDouble());
        controller->SetInterestRate(widgets->data[InterestRate]->text().toDouble());
    }

    void GetOutput() {
        ClearOutput();

        for(auto var : controller->GetMonthlyPayments()) {
            monthlyPaymentList->addItem(QString::number(var, 'f', 2));
        }

        widgets->data[TotalPayment]->setText(QString::number(controller->GetTotalPayment(), 'f', 2));
        widgets->data[Overpayment]->setText(QString::number(controller->GetOverpayment(), 'f', 2));

        widgets->bodyPayments.append(controller->GetMonthlyBodyPayments());
        widgets->percentPayments.append(controller->GetMonthlyPercentPayments());
    }

    void ClearOutput() {
        monthlyPaymentList->clear();
        widgets->bodyPayments.clear();
        widgets->percentPayments.clear();
    }


    void SetupUI() override {
        (*_platform)->SetupUI(widgets);
    }


private slots:

    void AnnuityPayment() {
        SetInput();
        controller->AnnuityLoan();
        GetOutput();

        DrawChartBars();
    }

    void DifferentiatedPayment() {
        SetInput();
        controller->DifferentiatedLoan();
        GetOutput();

        DrawChartBars();
    }

    void DrawChartBars() {
        widgets->chartView->SetData(widgets->bodyPayments, widgets->percentPayments);
        widgets->chartView->show();

        if (monthlyPaymentList->count() == 1) {
            monthlyPaymentList->setDisabled(true);
        } else {
             monthlyPaymentList->setDisabled(false);
        }
    }
};



#endif // CREDITCALCULATORUI_H
