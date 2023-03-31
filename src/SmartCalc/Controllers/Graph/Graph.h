#include <iostream>
#include <QString>
#include <cmath>
#include "../../Views/qcustomplot.h"
#include "../../Models/Model.h"

using namespace std;

class Graph {

private:
    double _range_min;
    double _range_max;
    double _range;

    double _scope_min;
    double _scope_max;
    double _scope;

    double _x_input;

    char* char_output;

    QCustomPlot *custom_plot;



public:

    Graph() : custom_plot(new QCustomPlot) {
        custom_plot->setInteraction(QCP::iRangeZoom,true);
    }

    void ShowGraph() {
        custom_plot->show();
    }



    void SetDefaultRangeMin(double min) {
        _range_min = min;
    }

    void SetDefaultRangeMax(double max) {
        _range_max = max;
    }

    void SetDefaultScopeMin(double min) {
       _scope_min = min;
    }

    void SetDefaultScopeMax(double max) {
        _scope_max = max;
    }



    void SetRangeMin(double min) {
        _range_min = min;
        SetGraphAxis();
    }

    void SetRangeMax(double max) {
        _range_max = max;
        SetGraphAxis();
    }

    void SetScopeMin(double min) {
       _scope_min = min;
       SetGraphAxis();
    }

    void SetScopeMax(double max) {
        _scope_max = max;
        SetGraphAxis();
    }

    void SetXValue(double x) {
        _x_input = x;
    }

    void Draw() {
        QVector<double> x(10000), y(10000), x_line(10000), y_line(10000);

        double x0 = _scope_min;
        double y0 = _range_min;

        double step_x = _scope / 10000;
        double step_y = _range / 10000;

        for (int i = 0; i < 10000; i++)
        {
            x[i] += x0;
            y[i] = Calculation(char_output, x[i]);
            x0 += step_x;

            x_line[i] = _x_input;
            y_line[i] += y0;
            y0 += step_y;
        }

        custom_plot->addGraph();
        custom_plot->graph(0)->setData(x, y);

        custom_plot->addGraph();
        custom_plot->graph(1)->setData(x_line, y_line);

        custom_plot->replot();
    }

   void SetGraphAxis() {
       custom_plot->xAxis->setLabel("x");
       custom_plot->yAxis->setLabel("y");
       custom_plot->xAxis->setRange(_scope_min, _scope_max);
       custom_plot->yAxis->setRange(_range_min, _range_max);
   }

   int SetInputValues(char* str) {
       char_output = str;
   }
};
