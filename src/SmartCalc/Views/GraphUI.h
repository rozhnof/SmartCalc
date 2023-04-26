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

        widgets->rangeText = new QLineEdit(window);
        widgets->scopeText = new QLineEdit(window);
        widgets->xText = new QLineEdit(window);
        widgets->xStepText = new QLineEdit(window);

        widgets->rangeMin = new QDoubleSpinBox(window);
        widgets->rangeMax = new QDoubleSpinBox(window);
        widgets->scopeMin = new QDoubleSpinBox(window);
        widgets->scopeMax = new QDoubleSpinBox(window);
        widgets->xInput = new QDoubleSpinBox(window);
        widgets->xStep = new QDoubleSpinBox(window);

        gridLayout->addWidget(widgets->rangeText, 0, 0);
        widgets->Window->setStyleSheet("QWidget * { background-color: white; color: black; border: 1px solid rgb(0, 32, 255); border-radius: 5px }");
        widgets->rangeText->setText("Range");

        gridLayout->addWidget(widgets->scopeText, 0, 1);
        widgets->scopeText->setText("Scope");

        gridLayout->addWidget(widgets->xText, 0, 2);
        widgets->xText->setText("X");

        gridLayout->addWidget(widgets->xStepText, 0, 3);
        widgets->xStepText->setText("Step X");

        gridLayout->addWidget(widgets->rangeMin, 1, 0);
        widgets->rangeMin->setValue(1);
        widgets->rangeMin->setMinimum(-100000000.0);
        widgets->rangeMin->setMaximum(100000000.0);

        gridLayout->addWidget(widgets->rangeMax, 2, 0);
        widgets->rangeMax->setValue(2);
        widgets->rangeMax->setMinimum(-100000000.0);
        widgets->rangeMax->setMaximum(100000000.0);

        gridLayout->addWidget(widgets->scopeMin, 1, 1);
        widgets->scopeMin->setValue(3);
        widgets->scopeMin->setMinimum(-100000000.0);
        widgets->scopeMin->setMaximum(100000000.0);

        gridLayout->addWidget(widgets->scopeMax, 2, 1);
        widgets->scopeMax->setValue(4);
        widgets->scopeMax->setMinimum(-100000000.0);
        widgets->scopeMax->setMaximum(100000000.0);

        gridLayout->addWidget(widgets->xInput, 1, 2);
        widgets->xInput->setValue(5);
        widgets->xInput->setMinimum(-100000000.0);
        widgets->xInput->setMaximum(100000000.0);

        gridLayout->addWidget(widgets->xStep, 1, 3);
        widgets->xStep->setValue(6);
        widgets->xStep->setMinimum(-100000000.0);
        widgets->xStep->setMaximum(100000000.0);
        widgets->xStep->setSingleStep(0.1);


//        connect(widgets->xInput, SIGNAL(valueChanged(double)), this, SLOT(reDrawLine()));
//        connect(widgets->xStep, SIGNAL(valueChanged(double)), this, SLOT(SetStepX()));
//        connect(widgets->rangeMin, SIGNAL(valueChanged(double)), this, SLOT(ChangeScope()));
//        connect(widgets->rangeMax, SIGNAL(valueChanged(double)), this, SLOT(ChangeScope()));
//        connect(widgets->scopeMin, SIGNAL(valueChanged(double)), this, SLOT(ChangeScope()));
//        connect(widgets->scopeMax, SIGNAL(valueChanged(double)), this, SLOT(ChangeScope()));

        connect(widgets->xInput, &QDoubleSpinBox::valueChanged, this, &GraphUI::reDrawLine);
        connect(widgets->xStep, &QDoubleSpinBox::valueChanged, this, &GraphUI::SetStepX);
        connect(widgets->rangeMin, &QDoubleSpinBox::valueChanged, this, &GraphUI::ChangeScope);
        connect(widgets->rangeMax, &QDoubleSpinBox::valueChanged, this, &GraphUI::ChangeScope);
        connect(widgets->scopeMin, &QDoubleSpinBox::valueChanged, this, &GraphUI::ChangeScope);
        connect(widgets->scopeMax, &QDoubleSpinBox::valueChanged, this, &GraphUI::ChangeScope);
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


