#ifndef GRAPH_H
#define GRAPH_H

#include <QWidget>
#include "qcustomplot.h"
#include "GraphUI.h"
#include <iostream>
#include <cmath>
#include "../Models/calc.h"


class Graph : public GraphUI
{
    Q_OBJECT

public:
    Graph()
    {
        graph = new QCustomPlot(graphicsView);

        graph->setFixedSize(800, 600);
        graph->setInteraction(QCP::iRangeZoom,true);
        graph->setInteraction(QCP::iRangeDrag, true);

        graph->xAxis->setLabel("x");
        graph->yAxis->setLabel("y");
        graph->xAxis->setRange(-5, 5);
        graph->yAxis->setRange(-5, 5);

        connect(input_x, SIGNAL(valueChanged(double)), this, SLOT(DrawLine()));

        DrawGraph();
        graphUi->show();
    }

    void DrawGraph() {
        QVector <double>x(10000), y(10000);

        double x0 = ScopeMin->value();
        double step_x = (fabs(ScopeMin->value()) + fabs(ScopeMax->value())) / 10000;

        for (int i = 0; i < 10000; i++)
        {
            x[i] += x0;
            y[i] = Calculation(" ", x[i]);
            x0 += step_x;
        }
    }

private:
    QCustomPlot *graph;



private slots:
    void DrawLine()
    {
        double step = StepX->text().toDouble();
        double xv = input_x->text().toDouble();

        input_x->setSingleStep(step);
        
        QVector <double>x(2, (xv)), y(2);
        y[0] = RangeMin->text().toDouble();
        y[1] = RangeMax->text().toDouble();

        graph->addGraph();
        graph->graph(0)->setData(x, y);
        graph->replot();
    }
};

#endif // GRAPH_H
