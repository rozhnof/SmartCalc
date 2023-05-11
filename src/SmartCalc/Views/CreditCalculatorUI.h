#ifndef CREDITCALCULATORUI_H
#define CREDITCALCULATORUI_H

#include "mainwindow.h"
#include "IPlatformUI.h"

#include <QtCharts>
#include <QColor>
#include <cmath>

using namespace std;



class CreditCalculatorUI : public MainWindow
{
public:
    CreditCalcWidgets *widgets;

    QComboBox *montlyPaymentList;
    QPushButton *annuityPaymentButton;
    QPushButton *differentiatedPaymentButton;

    QChart *chart;
    QChartView *chartView;
    QStackedBarSeries *series;
    QBarSet *bodyBar;
    QBarSet *percentBar;


    enum PaymentPart {
        Body,
        Percent
    };

    CreditCalculatorUI() : MainWindow() {
        this->setWindowTitle("Credit Calculator");
        widgets = new CreditCalcWidgets;
        widgets->creditCalcWindow = this;

        CreateObjects();
        CreateChart();
        SetGeometry();
        SetStyle();
        SetOptions();
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

        connect(annuityPaymentButton, &QPushButton::clicked, this, &CreditCalculatorUI::AnnuityPayment);
    }

    void SetGeometry() {
        this->resize(1200, 800);
        Layout *creditCalcLayout = new Layout(10, 50, this->width() - 10, 50 + 175, 3, 3, 15, 20);

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


        widgets->boxText[CreditSum]->setGeometry(widgets->box[CreditSum]->x() + 10, widgets->box[CreditSum]->y(), 100, 45);
        widgets->boxText[CreditTerm]->setGeometry(widgets->box[CreditTerm]->x() + 10, widgets->box[CreditTerm]->y(), 100, 45);
        widgets->boxText[InterestRate]->setGeometry(widgets->box[InterestRate]->x() + 10, widgets->box[InterestRate]->y(), 300, 45);
        widgets->boxText[TotalPayment]->setGeometry(widgets->box[TotalPayment]->x() + 150, widgets->box[TotalPayment]->y(), 200, 45);
        widgets->boxText[Overpayment]->setGeometry(widgets->box[Overpayment]->x() + 150, widgets->box[Overpayment]->y(), 200, 45);
        montlyPaymentList->setGeometry(widgets->box[MonthlyPayment]->x() + 10, widgets->box[MonthlyPayment]->y(), 280, 45);

        Layout *creditCalcChartLayout = new Layout(0, 50 + 175 + 20, this->width(), this->height() - 20, 1, 1);
        creditCalcChartLayout->AddWidget(chartView);


        delete creditCalcLayout;
        delete creditCalcChartLayout;



    }

    void SetStyle() {
        setStyleSheet("QMainWindow, QChartView {"
                      " background-color: rgb(27, 32, 50);"
                      "}"
                      "QPushButton {"
                      " background-color: rgb(217, 217, 217);"
                      " color: rgb(37, 37, 37);"
                      " border-radius: 10;"
                      " font: 16px;"
                      "}"
                      "QComboBox {"
                      " background-color: rgba(0, 0, 0, 0);"
                      " color: rgb(37, 37, 37);"
                      " font: 16px;"
                      "}"
                      "QTextEdit {"
                      " background-color: rgb(217, 217, 217);"
                      " border-radius: 10;"
                      "}"
                      "QPushButton:pressed {"
                      " background-color: rgb(171, 171, 171);"
                      "}"
                      "QComboBox::drop-down {"
                      "    width: 0px; "
                      "    height: 0px; "
                      "    border: 0px; "
                      "}"
                      "QComboBox QAbstractItemView {"
                      " color: rgb(37, 37, 37);"
                      " background-color: rgb(217, 217, 217);"
                      " padding: 10px;"
                      "}"
                      "QLabel, QLineEdit { "
                      " background-color: rgba(217, 217, 217, 0);"
                      " font: 16px; "
                      " color: rgb(37, 37, 37);"
                      "}");

        widgets->boxTitle[CreditSum]->setStyleSheet("color: rgb(217, 217, 217);");
        widgets->boxTitle[CreditTerm]->setStyleSheet("color: rgb(217, 217, 217);");
        widgets->boxTitle[InterestRate]->setStyleSheet("color: rgb(217, 217, 217);");
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
    }

    void CreateChart() {
        chart = new QChart;
        chartView = new QChartView(chart);
        series = new QStackedBarSeries();

        bodyBar = new QBarSet("Body");
        percentBar = new QBarSet("Percent");

        bodyBar->setColor(QColor(105, 124, 194));
        percentBar->setColor(QColor(132, 157, 245));

        bodyBar->setBorderColor(QColor(27, 32, 50));
        percentBar->setBorderColor(QColor(27, 32, 50));

        chart->setAnimationOptions(QChart::SeriesAnimations);
        chart->setTheme(QChart::ChartThemeBlueNcs);
        chart->legend()->setVisible(true);
        chart->legend()->setAlignment(Qt::AlignBottom);
        chartView->setRenderHint(QPainter::Antialiasing);

        series->setBarWidth(0.75);

        chart->setBackgroundVisible(false);
        chartView->setParent(this);
        chartView->show();
    }


    void AnnuityLoan() {
        double creditSum = widgets->boxText[CreditSum]->text().toDouble();
        double interestRate = widgets->boxText[InterestRate]->text().toDouble();
        double creditTerm = widgets->boxText[CreditTerm]->text().toDouble();

        double monthlyInterestRate = interestRate / 12 / 100;

        double totalPayment = 0;
        double overpayment = 0;
        double monthlyPayment = 0;

        widgets->bodyPayments.clear();
        widgets->percentPayments.clear();
        montlyPaymentList->clear();


        monthlyPayment = creditSum * monthlyInterestRate * pow(1 + monthlyInterestRate, creditTerm) / (pow(1 + monthlyInterestRate, creditTerm) - 1);
        totalPayment = monthlyPayment * creditTerm;
        overpayment = totalPayment - creditSum;

        for (int i = 0; i < creditTerm; i++) {
            double monthlyPercentPayment = creditSum * monthlyInterestRate;
            double monthlyBodyPayment = monthlyPayment - monthlyPercentPayment;
            creditSum -= monthlyPayment;

            widgets->bodyPayments.append(monthlyBodyPayment);
            widgets->percentPayments.append(monthlyPercentPayment);

            montlyPaymentList->addItem(QString::number(monthlyPayment));
        }

        widgets->boxText[TotalPayment]->setText(QString::number(totalPayment));
        widgets->boxText[Overpayment]->setText(QString::number(overpayment));
    }


    void SetupUI() override {
        (*_platform)->SetupUI(widgets);
    }


private slots:
    void AnnuityPayment() {
        AnnuityLoan();
        DrawChartBars();
    }

    void DifferentiatedPayment() {
//        DifferentiatedLoan();
    }

    void DrawChartBars() {
        bodyBar->append(widgets->bodyPayments);
        percentBar->append(widgets->percentPayments);

        series->append(bodyBar);
        series->append(percentBar);

        chart->addSeries(series);
    }
};


#endif // CREDITCALCULATORUI_H
