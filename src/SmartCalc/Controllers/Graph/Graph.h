#include <iostream>
#include <QString>
#include <cmath>
#include "../../Views/qcustomplot.h"

using namespace std;

//class Graph {

//private:

//    double _range_min;
//    double _range_max;
//    double _range;

//    double _scope_min;
//    double _scope_max;
//    double _scope;

//    double _x_input;

//public:

//     Graph(double scope_min, double scope_max, double range_min, double range_max) :
//     _scope_min(scope_min),
//     _scope_max(scope_max),
//     _range_min(scope_min),
//     _range_max(scope_max) {}

//    void GetDrawGraphValues(QVector<double> &x, QVector<double> &y) {
//        double x0 = _scope_min;
//        double step_x = _scope / 10000;
//        _scope = fabsl(_scope_min) + fabsl(_scope_max);

//        for (int i = 0; i < 10000; i++)
//        {
//            x[i] += x0;
//            y[i] = Calculation(char_output, x[i]);
//            x0 += step_x;
//        }
//    }


//};

