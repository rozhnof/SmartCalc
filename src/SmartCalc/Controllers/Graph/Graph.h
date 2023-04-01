#include <iostream>
#include <QString>
#include <cmath>
#include "../../Views/qcustomplot.h"
#include "../../Models/Model.h"

using namespace std;

class GraphBack {

private:
    QCustomPlot *custom_plot;

    double _range_min;
    double _range_max;
    double _range;

    double _scope_min;
    double _scope_max;
    double _scope;

    double _x_input;

public:

    // GraphBack(double scope_min, double scope_max, double range_min, double range_max) : 
    // _scope_min(scope_min), 
    // _scope_max(scope_max),
    // _range_min(scope_min), 
    // _range_max(scope_max) {}

    void GetDrawGraphValues(QVector<double> &x, QVector<double> &y) {
        double x0 = _scope_min;
        double step_x = _scope / 10000;
        _scope = fabsl(_scope_min) + fabsl(_scope_max);

        for (int i = 0; i < 10000; i++)
        {
            x[i] += x0;
            y[i] = Calculation(char_output, x[i]);
            x0 += step_x;
        }
    }

    void GetDrawLineValues(QVector<double> &x, QVector<double> &y) {
        y[0] = _range_min;
        y[1] = _range_max;
    }
};
