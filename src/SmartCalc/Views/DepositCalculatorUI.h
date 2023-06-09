#ifndef DEPOSITCALCULATORUI_H
#define DEPOSITCALCULATORUI_H

#include "mainwindow.h"
#include "IPlatformUI.h"
#include "../Controllers/DepositCalcController.h"
#include <cmath>

using namespace std;


class DepositCalculatorUI : public MainWindow
{
public:
    DepositCalcWidgets *widgets;
    DepositCalcController *controller;

    QComboBox *montlyPaymentList;
    QComboBox *CreditTermList;
    QPushButton *annuityPaymentButton;
    QPushButton *differentiatedPaymentButton;

    DepositCalculatorUI() : MainWindow() {
        this->setWindowTitle("Deposit Calculator");

        controller = new DepositCalcController;
        widgets = new DepositCalcWidgets;

        widgets->chartView = new ChartView(this);
        widgets->depositCalcWindow = this;

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

        widgets->boxTitle.insert(make_pair(CreditSum, new QLabel("Deposit Sum", this)));
        widgets->boxTitle.insert(make_pair(CreditTerm, new QLabel("Deposit Term", this)));
        widgets->boxTitle.insert(make_pair(InterestRate, new QLabel("Interest Rate", this)));
        widgets->boxTitle.insert(make_pair(TotalPayment, new QLabel("Total Payment", this)));
        widgets->boxTitle.insert(make_pair(Overpayment, new QLabel("Overpayment", this)));
        widgets->boxTitle.insert(make_pair(MonthlyPayment, new QLabel("Montly Payments", this)));

        widgets->boxText.insert(make_pair(CreditSum, NewQLineEdit(this, "1000", "inputCreditSum")));
        widgets->boxText.insert(make_pair(CreditTerm, NewQLineEdit(this, "12", "inputCreditTerm")));
        widgets->boxText.insert(make_pair(InterestRate, NewQLineEdit(this, "10", "inputInterestRate")));
        widgets->boxText.insert(make_pair(TotalPayment, new QLineEdit(this)));
        widgets->boxText.insert(make_pair(Overpayment, new QLineEdit(this)));

        annuityPaymentButton = new QPushButton("Annuity Payment", this);
        differentiatedPaymentButton = new QPushButton("Differentiated Payment", this);
        montlyPaymentList = new QComboBox(this);
        CreditTermList = new QComboBox(this);

        connect(annuityPaymentButton, &QPushButton::clicked, this, &DepositCalculatorUI::AnnuityPayment);
        connect(differentiatedPaymentButton, &QPushButton::clicked, this, &DepositCalculatorUI::DifferentiatedPayment);
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
        layout.AddWidget(annuityPaymentButton);
        layout.AddWidget(differentiatedPaymentButton);

        layout.ChangeColumns(3);
        layout.AddWidget(widgets->box[TotalPayment]);
        layout.AddWidget(widgets->box[Overpayment]);
        layout.AddWidget(widgets->box[MonthlyPayment]);

        layout.SetTitle(widgets->box[CreditSum], widgets->boxTitle[CreditSum], Layout::Left, Layout::Above, 16, 0, -10);
        layout.SetTitle(widgets->box[CreditTerm], widgets->boxTitle[CreditTerm], Layout::Left, Layout::Above, 16, 0, -10);
        layout.SetTitle(widgets->box[InterestRate], widgets->boxTitle[InterestRate], Layout::Left, Layout::Above, 16, 0, -10);
        layout.SetTitle(widgets->box[TotalPayment], widgets->boxTitle[TotalPayment], Layout::Left, Layout::CenterV, 16, 5, 0);
        layout.SetTitle(widgets->box[Overpayment], widgets->boxTitle[Overpayment], Layout::Left, Layout::CenterV, 16, 5, 0);
        layout.SetTitle(widgets->box[MonthlyPayment], widgets->boxTitle[MonthlyPayment], Layout::Left, Layout::CenterV, 16, 5, 0);

        layout.SetField(widgets->box[CreditSum], widgets->boxText[CreditSum],Layout::Left, 15);
        layout.SetField(widgets->box[CreditTerm], widgets->boxText[CreditTerm], Layout::Left, 15);
        layout.SetField(widgets->box[InterestRate], widgets->boxText[InterestRate], Layout::Left, 15);
        layout.SetField(widgets->box[TotalPayment], widgets->boxText[TotalPayment], Layout::Right, 15);
        layout.SetField(widgets->box[Overpayment], widgets->boxText[Overpayment], Layout::Right, 15);
    }

    void SetOptions() {
        widgets->boxText[TotalPayment]->setReadOnly(true);
        widgets->boxText[Overpayment]->setReadOnly(true);

        widgets->boxText[CreditSum]->setAlignment(Qt::AlignLeft);
        widgets->boxText[CreditTerm]->setAlignment(Qt::AlignLeft);
        widgets->boxText[InterestRate]->setAlignment(Qt::AlignLeft);
        widgets->boxText[TotalPayment]->setAlignment(Qt::AlignRight);
        widgets->boxText[Overpayment]->setAlignment(Qt::AlignRight);

        widgets->box[CreditSum]->setReadOnly(true);
        widgets->box[CreditTerm]->setReadOnly(true);
        widgets->box[InterestRate]->setReadOnly(true);
        widgets->box[TotalPayment]->setReadOnly(true);
        widgets->box[Overpayment]->setReadOnly(true);
        widgets->box[MonthlyPayment]->setReadOnly(true);

        CreditTermList->addItem("Month");
        CreditTermList->addItem("Years");
        CreditTermList->addItem("Days");
    }

    void SetInput() {
        controller->SetDepositSum(widgets->boxText[CreditSum]->text().toDouble());
        controller->SetDepositTerm(widgets->boxText[CreditTerm]->text().toDouble());
        controller->SetInterestRate(widgets->boxText[InterestRate]->text().toDouble());
    }

    void GetOutput() {
        ClearOutput();

        for(auto var : controller->GetMonthlyPayments()) {
            montlyPaymentList->addItem(QString::number(var));
        }

        widgets->boxText[TotalPayment]->setText(QString::number(controller->GetTotalPayment()));
        widgets->boxText[Overpayment]->setText(QString::number(controller->GetOverpayment()));

        widgets->bodyPayments.append(controller->GetMonthlyBodyPayments());
        widgets->percentPayments.append(controller->GetMonthlyPercentPayments());
    }

    void ClearOutput() {
        montlyPaymentList->clear();
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

        if (montlyPaymentList->count() == 1) {
            montlyPaymentList->setDisabled(true);
        } else {
             montlyPaymentList->setDisabled(false);
        }
    }
};



#endif // DEPOSITCALCULATORUI_H
