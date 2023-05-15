#ifndef GRAPHCONTROLLER_H
#define GRAPHCONTROLLER_H

#include "Controller.h"
#include "../Models/GraphModel.h"
#include <QVector>

using namespace std;

class GraphController : public Controller {

private:

    GraphModel *model;
public:

    GraphController() {
        model = new GraphModel;
    }

    void SetInput(QString input) {
        model->SetInput(input.toStdString());
    }

    QVector<double> GetCollectionX(int size, double xMin, double xMax) {
        QVector<double> x(size);

        double stepX = (fabs(xMin) + fabs(xMax)) / size;
        for (int i = 0; i < size; i++)
        {
            x[i] = xMin + stepX * i;
        }
        return x;
    }

    QVector<double> GetCollectionY(QVector<double>& x, double yMin, double yMax) {
        QVector<double> y(x.size());

        for (int i = 0; i < y.size(); i++)
        {
            y[i] = model->Calculate(x[i]);

            if (y[i] > yMax || y[i] < yMin) {
                y[i] = qQNaN();
            }
        }
        return y;
    }
};


#endif // GRAPHCONTROLLER_H
