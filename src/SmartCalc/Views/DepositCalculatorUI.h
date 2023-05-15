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
        this->setFixedSize(1200, 800);
        widgets->chartView->setGeometry(0, 250, 1200, 550);
        Layout *depositCalcLayout = new Layout(15, 50, this->width() - 15, 50 + 175, 3, 3, 15, 20);

        depositCalcLayout->AddWidget(widgets->box[CreditSum]);
        depositCalcLayout->AddWidget(widgets->box[CreditTerm]);
        depositCalcLayout->AddWidget(widgets->box[InterestRate]);

        depositCalcLayout->AddWidget(annuityPaymentButton, 1.5);
        depositCalcLayout->AddWidget(differentiatedPaymentButton, 1.5);

        depositCalcLayout->AddWidget(widgets->box[TotalPayment]);
        depositCalcLayout->AddWidget(widgets->box[Overpayment]);
        depositCalcLayout->AddWidget(widgets->box[MonthlyPayment]);


        widgets->boxTitle[CreditSum]->setGeometry(widgets->box[CreditSum]->x(), widgets->box[CreditSum]->y() - 35, 300, 25);
        widgets->boxTitle[CreditTerm]->setGeometry(widgets->box[CreditTerm]->x(), widgets->box[CreditTerm]->y() - 35, 300, 25);
        widgets->boxTitle[InterestRate]->setGeometry(widgets->box[InterestRate]->x(), widgets->box[InterestRate]->y() - 35, 300, 25);
        widgets->boxTitle[TotalPayment]->setGeometry(widgets->box[TotalPayment]->x() + 10, widgets->box[TotalPayment]->y(), 100, 45);
        widgets->boxTitle[Overpayment]->setGeometry(widgets->box[Overpayment]->x() + 10, widgets->box[Overpayment]->y(), 100, 45);
        widgets->boxTitle[MonthlyPayment]->setGeometry(widgets->box[MonthlyPayment]->x() + 225, widgets->box[MonthlyPayment]->y(), 125, 45);


        widgets->boxText[CreditSum]->setGeometry(widgets->box[CreditSum]->x() + 10, widgets->box[CreditSum]->y(), widgets->box[CreditSum]->width() - 20, widgets->box[CreditSum]->height());
        widgets->boxText[CreditTerm]->setGeometry(widgets->box[CreditTerm]->x() + 10, widgets->box[CreditTerm]->y(), widgets->box[CreditSum]->width() - 20, widgets->box[CreditSum]->height());
        widgets->boxText[InterestRate]->setGeometry(widgets->box[InterestRate]->x() + 10, widgets->box[InterestRate]->y(), widgets->box[CreditSum]->width() - 20, widgets->box[CreditSum]->height());
        widgets->boxText[TotalPayment]->setGeometry(widgets->box[TotalPayment]->x() + 150, widgets->box[TotalPayment]->y(), 200, 45);
        widgets->boxText[Overpayment]->setGeometry(widgets->box[Overpayment]->x() + 150, widgets->box[Overpayment]->y(), 200, 45);
        montlyPaymentList->setGeometry(widgets->box[MonthlyPayment]->x() + 10, widgets->box[MonthlyPayment]->y(), 280, 45);
        CreditTermList->setGeometry(widgets->box[CreditTerm]->x() + widgets->box[CreditTerm]->width() - 90, widgets->box[CreditTerm]->y(), 90, widgets->box[CreditSum]->height());

        delete depositCalcLayout;
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
