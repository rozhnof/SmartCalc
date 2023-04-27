#ifndef GRAPHUI_H
#define GRAPHUI_H


#include "mainwindow.h"
#include "IPlatformUI.h"



class GraphUI : public MainWindow
{


public:

    GraphWidgets *widgets;
    QGridLayout *gridLayout;

    Model *model;

    int row = 0, col = 0, col_max = 3;

    GraphUI() : MainWindow() {
        model = new Model;
        widgets = new GraphWidgets;

        widgets->mainWindow = this;
        window = new QWidget(this);
        widgets->_graph = new QCustomPlot(this);
        widgets->Window = window;
        window->setGeometry(0 + 5, 600 + 5, 800 - 10, 100 - 10);

        gridLayout = new QGridLayout(window);
        gridLayout->setContentsMargins(0, 0, 0, 0);

        widgets->rangeText = CreateObjects("Range");
        widgets->scopeText = CreateObjects("Scope");
        widgets->xText = CreateObjects("X");
        widgets->xStepText = CreateObjects("Step X");


        widgets->rangeMin = CreateObjects();
        widgets->rangeMax = CreateObjects();
        widgets->scopeMin = CreateObjects();
        widgets->scopeMax = CreateObjects();
        widgets->xInput = CreateObjects();
        widgets->xStep = CreateObjects();

        widgets->Input = new QLineEdit("Input", window);
        widgets->Input->setStyleSheet("color: black;"
                              "border: 1px solid blue;"
                              "border-radius: 10;");
        gridLayout->addWidget(widgets->Input, row, col, 1, 2);

        connect(widgets->xInput, &QDoubleSpinBox::valueChanged, this, &GraphUI::reDrawLine);
        connect(widgets->xStep, &QDoubleSpinBox::valueChanged, this, &GraphUI::SetStepX);
        connect(widgets->rangeMin, &QDoubleSpinBox::valueChanged, this, &GraphUI::ChangeScope);
        connect(widgets->rangeMax, &QDoubleSpinBox::valueChanged, this, &GraphUI::ChangeScope);
        connect(widgets->scopeMin, &QDoubleSpinBox::valueChanged, this, &GraphUI::ChangeScope);
        connect(widgets->scopeMax, &QDoubleSpinBox::valueChanged, this, &GraphUI::ChangeScope);
    }

    QLineEdit *CreateObjects(QString text) {
        QLineEdit* newObj = new QLineEdit(text, window);
        newObj->setStyleSheet("color: black;"
                              "border: 1px solid blue;"
                              "border-radius: 10;");
        gridLayout->addWidget(newObj, row, col++);

        if (col > col_max) {
            row++;
            col = 0;
        }
        return newObj;
    }

    QDoubleSpinBox *CreateObjects() {
        QDoubleSpinBox* newObj = new QDoubleSpinBox(window);
        newObj->setStyleSheet("color: black;"
                              "border: 1px solid blue;"
                              "border-radius: 10;");
        newObj->setButtonSymbols(QAbstractSpinBox::NoButtons);
        gridLayout->addWidget(newObj, row, col++);

        newObj->setValue(0);
        newObj->setMinimum(-INFINITY);
        newObj->setMaximum(INFINITY);

        if (col > col_max) {
            row++;
            col = 0;
        }
        return newObj;
    }


    void SetupUI() override {
        (*_platform)->SetupUI(widgets);
    }

    void DrawGraph() {
        QVector<double> x(10000), y(10000);

        double x0 = widgets->scopeMin->value();
        double step_x = (fabs(x0) + fabs(widgets->scopeMax->value())) / 10000;

        model->SetInput("sin(x)");

        for (int i = 0; i < 10000; i++)
        {
            x[i] += x0;
            y[i] = model->Calculate(x[i]);
            x0 += step_x;
        }

        widgets->_graph->addGraph();
        widgets->_graph->graph(0)->setData(x, y);
        widgets->_graph->replot();
    }

    void DrawLine()
    {
        QVector<double> x(2), y(2);

        x[0] = widgets->xInput->value();
        x[1] = widgets->xInput->value();

        y[0] = widgets->rangeMin->value();
        y[1] = widgets->rangeMax->value();

        widgets->_graph->addGraph();
        widgets->_graph->graph(1)->setData(x, y);
        widgets->_graph->replot();
    }

private slots:
    void ChangeScope() {
        widgets->scopeMax->setMinimum(widgets->scopeMin->value());
        widgets->scopeMin->setMaximum(widgets->scopeMax->value());

        DrawGraph();
        DrawLine();
    }

    void reDrawLine()
    {
        DrawLine();
    }

    void reDrawGraph()
    {
        DrawGraph();
    }

    void SetStepX() {
        widgets->xInput->setSingleStep(widgets->xStep->value());
    }
};


#endif // GRAPHUI_H


