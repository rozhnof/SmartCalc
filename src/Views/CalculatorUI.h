#pragma once


#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QPushButton>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QWidget>
#include "MainWindow.h"
#include <QVector>
#include <QResizeEvent>
#include <QDebug>
#include "../Controllers/CalculatorController.h"


class CalculatorUI : public MainWindow
{
    Q_OBJECT

private:
    CalculatorController *_controller;
    CalcWidgets *_widgets;

public:
    CalculatorUI();

    ~CalculatorUI();

    void SetupUI() override;

private:

    void initInputXWidget();

    void initWidgets();

    void connectWidgetsToSlots();

    void resetWidgets();

private slots:

    void setLexema();

    void clearButton();

    void clearAllButton();

    void showInputX();

    void hideInputX();

    void equalButton();

    void CalculateWithX();

    void Calculate(QString input, double x);
};
