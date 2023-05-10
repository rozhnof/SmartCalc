#ifndef CREDITCALCULATORUI_H
#define CREDITCALCULATORUI_H

#include "mainwindow.h"
#include "IPlatformUI.h"

#include <QtCharts>
#include <cmath>

using namespace std;



class CreditCalculatorUI : public MainWindow
{
public:
    CreditCalcWidgets *widgets;
    QStackedBarSeries *barChart;


    QComboBox *montlyPaymentList;
    QComboBox *montlyBodyPaymentList;
    QComboBox *montlyPercentPaymentList;

    QPushButton *result;

    QChartView *chartView;
    QChart *chart;

    enum PaymentPart {
        Body,
        Percent
    };

    CreditCalculatorUI() : MainWindow() {
        this->setWindowTitle("Credit Calculator");

        widgets = new CreditCalcWidgets;

        widgets->creditCalcWindow = this;

        this->setFixedSize(1200, 800);


        widgets->values.insert(make_pair(CreditSum, new QLineEdit("10000", this)));
        widgets->values.insert(make_pair(CreditTerm, new QLineEdit("12", this)));
        widgets->values.insert(make_pair(InterestRate, new QLineEdit("10", this)));


        widgets->values.insert(make_pair(TotalPayment, new QLineEdit("Total Payment", this)));
        widgets->values.insert(make_pair(Overpayment, new QLineEdit("Overpayment", this)));

        result = new QPushButton("=", this);
        montlyPaymentList = new QComboBox(this);
        montlyBodyPaymentList = new QComboBox(this);
        montlyPercentPaymentList = new QComboBox(this);


        connect(result, &QPushButton::clicked, this, &CreditCalculatorUI::DrawChart);


        SetGeometry();

    }



    void AnnuityLoan() {
        double creditSum = widgets->values[CreditSum]->text().toDouble();
        double interestRate = widgets->values[InterestRate]->text().toDouble();
        double creditTerm = widgets->values[CreditTerm]->text().toDouble();

        double monthlyInterestRate = interestRate / 12 / 100;

        double totalPayment = 0;
        double overpayment = 0;
        double monthlyPayment = 0;

        widgets->bodyPayments.clear();
        widgets->percentPayments.clear();
        montlyPaymentList->clear();
        montlyBodyPaymentList->clear();
        montlyPercentPaymentList->clear();


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
            montlyBodyPaymentList->addItem(QString::number(monthlyBodyPayment));
            montlyPercentPaymentList->addItem(QString::number(monthlyPercentPayment));
        }

        widgets->values[TotalPayment]->setText(QString::number(totalPayment));
        widgets->values[Overpayment]->setText(QString::number(overpayment));
    }


    void SetStyle(QLineEdit *widget) {
        widget->setStyleSheet("background-color:black;");
    }

    void CreateObjects() {

    }

    void SetGeometry() {
        Layout *creditCalcLayout = new Layout(10, 610, 1190, 790, 3, 3, 10, 10);
        creditCalcLayout->AddWidget(widgets->values[CreditSum]);
        creditCalcLayout->AddWidget(widgets->values[CreditTerm]);
        creditCalcLayout->AddWidget(widgets->values[InterestRate]);

        creditCalcLayout->AddWidget(widgets->values[TotalPayment]);
        creditCalcLayout->AddWidget(widgets->values[Overpayment]);
        creditCalcLayout->AddWidget(result);

        creditCalcLayout->AddWidget(montlyPaymentList);
        creditCalcLayout->AddWidget(montlyBodyPaymentList);
        creditCalcLayout->AddWidget(montlyPercentPaymentList);
    }


    void SetupUI() override {
        (*_platform)->SetupUI(widgets);
    }


private slots:
    void DrawChart() {
        QBarSet *bodyBar = new QBarSet("Body");
        QBarSet *percentBar = new QBarSet("Percent");

        QStackedBarSeries *series = new QStackedBarSeries();
        chart = new QChart();
        chart->setTitle("Credit");

        AnnuityLoan();

        cout << widgets->bodyPayments.size() << endl;

        bodyBar->append(widgets->bodyPayments);
        percentBar->append(widgets->percentPayments);

        series->append(bodyBar);
        series->append(percentBar);
        chart->addSeries(series);

        chart->setAnimationOptions(QChart::SeriesAnimations);
        chart->setTheme(QChart::ChartThemeBlueNcs);

        chart->legend()->setVisible(true);
        chart->legend()->setAlignment(Qt::AlignBottom);

        chartView = new QChartView(chart);
        chartView->setRenderHint(QPainter::Antialiasing);

        chartView->setParent(this);
        chartView->setGeometry(0, 0, 1200, 600);
        chartView->show();
    }
};


#endif // CREDITCALCULATORUI_H
