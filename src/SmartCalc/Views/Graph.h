#ifndef GRAPH_H
#define GRAPH_H

#include <QWidget>
#include "qcustomplot.h"
#include "GraphUI.h"
#include <iostream>
#include <cmath>
#include "../Models/calc.h"
#include "../Controllers/GraphCalc/GraphCalc.h"


class Graph : public GraphUI
{
    Q_OBJECT

public:
    Graph()
    {
        graph = new QCustomPlot(graphicsView);
        calculate = new GraphCalc;

        graph->setFixedSize(800, 600);
        graph->setInteraction(QCP::iRangeZoom,true);
        graph->setInteraction(QCP::iRangeDrag, true);

        graph->xAxis->setLabel("x");
        graph->yAxis->setLabel("y");
        graph->xAxis->setRange(-5, 5);
        graph->yAxis->setRange(-5, 5);

        connect(input_x, SIGNAL(valueChanged(double)), this, SLOT(reDrawLine()));
        connect(StepX, SIGNAL(valueChanged(double)), this, SLOT(SetStepX()));

        connect(RangeMax, SIGNAL(valueChanged(double)), this, SLOT(ChangeScope()));
        connect(RangeMin, SIGNAL(valueChanged(double)), this, SLOT(ChangeScope()));
        connect(ScopeMax, SIGNAL(valueChanged(double)), this, SLOT(ChangeScope()));
        connect(ScopeMin, SIGNAL(valueChanged(double)), this, SLOT(ChangeScope()));
    }

    void DrawGraph() {
        QVector <double>x(10000), y(10000);

        calculate->SetInputX(input_x->value());
        calculate->SetRange(RangeMin->value(), RangeMax->value());
        calculate->SetScope(ScopeMin->value(), ScopeMax->value());

        calculate->DrawGraph(x, y);

        graph->addGraph();
        graph->graph(0)->setData(x, y);
        graph->replot();
    }

    void DrawLine()
    {
        QVector <double>x(2), y(2);
        calculate->SetInputX(input_x->value());
        calculate->SetRange(RangeMin->value(), RangeMax->value());
        calculate->SetScope(ScopeMin->value(), ScopeMax->value());

        calculate->DrawLine(x, y);

        graph->addGraph();
        graph->graph(1)->setData(x, y);
        graph->replot();
    }

private:
    QCustomPlot *graph;
    GraphCalc *calculate;

private slots:
    void ChangeScope() {
        ScopeMax->setMinimum(ScopeMin->value());
        ScopeMin->setMaximum(ScopeMax->value());

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
        input_x->setSingleStep(StepX->value());
    }

    void Show() {
        calculate->SetInput("x 1 +");
        DrawGraph();
        DrawLine();
        graphUi->show();
    }
};

#endif // GRAPH_H
