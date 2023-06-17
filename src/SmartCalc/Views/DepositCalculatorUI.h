#ifndef DEPOSITCALCULATORUI_H
#define DEPOSITCALCULATORUI_H

#include "mainwindow.h"
#include "IPlatformUI.h"
#include "../Controllers/DepositCalcController.h"
#include <cmath>
#include "Calendar.h"

using namespace std;


class DepositCalculatorUI : public MainWindow
{
public:
    DepositCalcWidgets *widgets;
    DepositCalcController *controller;

    QPushButton *topUp;
    QPushButton *takeOff;

    QLineEdit* area;
    QLineEdit* date;
    QLineEdit* sum;

    Calendar *calendar;

    DepositCalculatorUI() : MainWindow() {
        this->setWindowTitle("Deposit Calculator");

        controller = new DepositCalcController;
        widgets = new DepositCalcWidgets;

        widgets->chartView = new ChartView(this);
        widgets->depositCalcWindow = this;

        CreateObjects();
        SetGeometry();
        SetOptions();
    }

    void CreateObjects() {
//        calendar = new Calendar(this, QRect(0, 0, 300, 300));

        topUp = new QPushButton(this);
        takeOff = new QPushButton(this);

        area = new QLineEdit(this);
        date = new QLineEdit(this);
        sum = new QLineEdit(this);

        area->setReadOnly(true);
        date->setReadOnly(true);
        sum->setReadOnly(true);

        area->setGeometry(100, 100, 320, 220);
        area->setStyleSheet("background-color: rgb(105, 124, 194);");
        topUp->setStyleSheet("background-color: rgb(217, 217, 217); color: rgb(37, 37, 37); border: none; border-radius: 10;");
        takeOff->setStyleSheet("background-color: rgb(217, 217, 217); color: rgb(37, 37, 37); border: none; border-radius: 10;");
        date->setStyleSheet("background-color: rgb(217, 217, 217); color: rgb(37, 37, 37); border: none; border-top-left-radius: 10; border-bottom-left-radius: 10;");
        sum->setStyleSheet("background-color: rgb(217, 217, 217); color: rgb(37, 37, 37); border: none; border-top-right-radius: 10; border-bottom-right-radius: 10;");

        Layout layout;
        layout.SetStartPoints(area->x(), area->y());
        layout.SetEndPoints(area->width(), area->height());
        layout.SetLeftSpacing(15);
        layout.SetRightSpacing(15);
        layout.SetAboveSpacing(15);
        layout.SetBottomSpacing(15);
        layout.SetHorizontalSpacing(2);
        layout.SetVerticalSpacing(15);
        layout.SetRows(3);
        layout.SetColumns(2);
        layout.SetAutoSize();

        layout.AddWidget(date);
        layout.AddWidget(sum);

        layout.AddWidget(topUp, 1);
        layout.AddWidget(takeOff, 1);


        cout << date->y() << endl;
        cout << topUp->y() << endl;




    }

    void SetGeometry() {
        this->setFixedSize(950, 700);
        widgets->chartView->setGeometry(0, 225, this->width(), this->height() - 225);

        Layout layout;


    }

    void SetOptions() {

    }

    void SetInput() {

    }

    void GetOutput() {

    }

    void ClearOutput() {

    }

    void SetupUI() override {
        (*_platform)->SetupUI(widgets);
    }


private slots:

};



#endif // DEPOSITCALCULATORUI_H
