#ifndef CREDITCALCULATORUI_H
#define CREDITCALCULATORUI_H

#include "mainwindow.h"
#include "IPlatformUI.h"
#include "../Controllers/CreditCalcController.h"

#include <QtCharts>
#include <QColor>
#include <cmath>

using namespace std;


class ChartView : public QChartView {

    QStackedBarSeries *series;
    QBarSet *bodyBar;
    QBarSet *percentBar;

public:
    ChartView(CreditCalcWidgets *widgets, QChart* chart = new QChart) : QChartView(chart) {
        this->setRenderHint(QPainter::Antialiasing);
        chart->setAnimationOptions(QChart::SeriesAnimations);
        chart->setTheme(QChart::ChartThemeBlueNcs);
        chart->legend()->setVisible(true);
        chart->legend()->setAlignment(Qt::AlignBottom);

        series = new QStackedBarSeries();
        series->setBarWidth(0.75);

        bodyBar = new QBarSet("Body");
        percentBar = new QBarSet("Percent");

        bodyBar->setColor(QColor(105, 124, 194));
        percentBar->setColor(QColor(132, 157, 245));

        bodyBar->setBorderColor(QColor(27, 32, 50));
        percentBar->setBorderColor(QColor(27, 32, 50));

        bodyBar->append(widgets->bodyPayments);
        percentBar->append(widgets->percentPayments);

        series->append(bodyBar);
        series->append(percentBar);

        chart->addSeries(series);

        QValueAxis *axisY = new QValueAxis();
        axisY->setLinePenColor(QColor(27, 32, 50));
        axisY->setGridLineColor(QColor(217, 217, 217));
        axisY->setLabelsColor(QColor(217, 217, 217));
        chart->addAxis(axisY, Qt::AlignLeft);
        series->attachAxis(axisY);

        chart->setBackgroundVisible(false);
    }

    ~ChartView() {
        delete series;
        delete bodyBar;
        delete percentBar;

    }
};

class CreditCalculatorUI : public MainWindow
{
public:
    CreditCalcWidgets *widgets;
    CreditCalcController *controller;

    QComboBox *montlyPaymentList;
    QComboBox *creditTermList;
    QPushButton *annuityPaymentButton;
    QPushButton *differentiatedPaymentButton;

    ChartView* chartView;

    enum PaymentPart {
        Body,
        Percent
    };

    CreditCalculatorUI() : MainWindow() {
        this->setWindowTitle("Credit Calculator");
        controller = new CreditCalcController;

        widgets = new CreditCalcWidgets;
        widgets->creditCalcWindow = this;

        CreateObjects();
        SetGeometry();
        SetOptions();
        AnnuityPayment();
    }

    void CreateObjects() {
        widgets->box.insert(make_pair(CreditSum, new QTextEdit(this)));
        widgets->box.insert(make_pair(CreditTerm, new QTextEdit(this)));
        widgets->box.insert(make_pair(InterestRate, new QTextEdit(this)));
        widgets->box.insert(make_pair(TotalPayment, new QTextEdit(this)));
        widgets->box.insert(make_pair(Overpayment, new QTextEdit(this)));
        widgets->box.insert(make_pair(MonthlyPayment, new QTextEdit(this)));

        widgets->boxTitle.insert(make_pair(CreditSum, new QLabel("Credit Sum", this)));
        widgets->boxTitle.insert(make_pair(CreditTerm, new QLabel("Credit Term", this)));
        widgets->boxTitle.insert(make_pair(InterestRate, new QLabel("Interest Rate", this)));
        widgets->boxTitle.insert(make_pair(TotalPayment, new QLabel("Total Payment", this)));
        widgets->boxTitle.insert(make_pair(Overpayment, new QLabel("Overpayment", this)));
        widgets->boxTitle.insert(make_pair(MonthlyPayment, new QLabel("Montly Payments", this)));

        widgets->boxText.insert(make_pair(CreditSum, new QLineEdit("10000", this)));
        widgets->boxText.insert(make_pair(CreditTerm, new QLineEdit("12", this)));
        widgets->boxText.insert(make_pair(InterestRate, new QLineEdit("10", this)));
        widgets->boxText.insert(make_pair(TotalPayment, new QLineEdit(this)));
        widgets->boxText.insert(make_pair(Overpayment, new QLineEdit(this)));

        annuityPaymentButton = new QPushButton("Annuity Payment", this);
        differentiatedPaymentButton = new QPushButton("Differentiated Payment", this);
        montlyPaymentList = new QComboBox(this);
        creditTermList = new QComboBox(this);

        connect(annuityPaymentButton, &QPushButton::clicked, this, &CreditCalculatorUI::AnnuityPayment);
        connect(differentiatedPaymentButton, &QPushButton::clicked, this, &CreditCalculatorUI::DifferentiatedPayment);
    }

    void SetGeometry() {
        this->setFixedSize(1200, 800);
        Layout *creditCalcLayout = new Layout(15, 50, this->width() - 15, 50 + 175, 3, 3, 15, 20);

        creditCalcLayout->AddWidget(widgets->box[CreditSum]);
        creditCalcLayout->AddWidget(widgets->box[CreditTerm]);
        creditCalcLayout->AddWidget(widgets->box[InterestRate]);

        creditCalcLayout->AddWidget(annuityPaymentButton, 1.5);
        creditCalcLayout->AddWidget(differentiatedPaymentButton, 1.5);

        creditCalcLayout->AddWidget(widgets->box[TotalPayment]);
        creditCalcLayout->AddWidget(widgets->box[Overpayment]);
        creditCalcLayout->AddWidget(widgets->box[MonthlyPayment]);


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
        creditTermList->setGeometry(widgets->box[CreditTerm]->x() + widgets->box[CreditTerm]->width() - 90, widgets->box[CreditTerm]->y(), 90, widgets->box[CreditSum]->height());

        delete creditCalcLayout;
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

        creditTermList->addItem("Month");
        creditTermList->addItem("Years");
        creditTermList->addItem("Days");
    }

    void SetInput() {
        controller->SetCreditSum(widgets->boxText[CreditSum]->text().toDouble());
        controller->SetCreditTerm(widgets->boxText[CreditTerm]->text().toDouble());
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
        chartView = new ChartView(widgets);
        chartView->setParent(this);
        chartView->setGeometry(0, 250, 1200, 550);
        chartView->show();

        if (montlyPaymentList->count() == 1) {
            montlyPaymentList->setDisabled(true);
        } else {
             montlyPaymentList->setDisabled(false);
        }
    }
};



#endif // CREDITCALCULATORUI_H
