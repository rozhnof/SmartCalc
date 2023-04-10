#include <iostream>
#include <QString>
#include <cmath>
#include "../../Views/qcustomplot.h"
#include "../../Models/Model.h"

using namespace std;


class GraphCalc {

private: 

   double _range_min;
   double _range_max;

   double _scope_min;
   double _scope_max;

   double _inputX;
   QString _input;

   Model *calc;

public:

   GraphCalc() {
       calc = new Model;
   }

    void SetRange(double range_min, double range_max) {
        _range_min = range_min;
        _range_max = range_max;
    }

    void SetScope(double scope_min, double scope_max) {
        _scope_min = scope_min;
        _scope_max = scope_max;
    }

    void SetInput(QString input) {
        _input = input;
        string str_input = _input.toStdString();

        char *chr_input = new char[str_input.size()+1];

        strcpy(chr_input,str_input.c_str());
        calc->Convert(chr_input);
    }

    void SetInputX(double inputX) {
        _inputX = inputX;
    }


    void DrawGraph(QVector <double>&x, QVector <double>&y) {
        double x0 = _scope_min;
        double step_x = (fabs(_scope_min) + fabs(_scope_max)) / 10000;

        for (int i = 0; i < 10000; i++)
        {
            x[i] += x0;
            y[i] = calc->Calculate(x[i]);
            x0 += step_x;
        }
    }

    void DrawLine(QVector <double>&x, QVector <double>&y)
    {
        x[0] = _inputX;
        x[1] = _inputX;

        y[0] = _range_min;
        y[1] = _range_max;
    }

};

