#ifndef GRAPHUI_H
#define GRAPHUI_H


#include "mainwindow.h"
#include "IPlatformUI.h"
#include "../Controllers/GraphController.h"

class GraphUI : public MainWindow
{

Q_OBJECT

public:

    GraphController *controller;
    GraphWidgets *widgets;
    QGridLayout *gridLayout;

    int row = 1, col = 0, col_max = 3;

    GraphUI() : MainWindow() {
        this->setWindowTitle("Graph");

        widgets = new GraphWidgets;

        widgets->graphWindow = this;
        widgets->graph = new QCustomPlot(this);

        CreateObjects();
    }

    QLineEdit *NewObject(QString text) {
        QLineEdit *newObject = new QLineEdit(text, this);
        SetStyle(newObject);
        return newObject;
    }

    QDoubleSpinBox *NewObject(const char* slot) {
        QDoubleSpinBox *newObject = new QDoubleSpinBox(this);
        SetStyle(newObject);
        newObject->setValue(0);
        newObject->setMinimum(-INFINITY);
        newObject->setMaximum(INFINITY);
        connect(newObject, SIGNAL(valueChanged(double)), this, slot);
        return newObject;
    }

    void SetStyle(QWidget *object) {
        object->setStyleSheet("background-color: white;"
                                 "color: black;"
                                 "border: 1px solid blue;"
                                 "border-radius: 10;");
    }

    void CreateObjects() {
//        widgets->titles.insert(make_pair(LineInput, NewObject("Input")));
//        widgets->titles.insert(make_pair(LineScope, NewObject("Scope")));
//        widgets->titles.insert(make_pair(LineRange, NewObject("Range")));
//        widgets->titles.insert(make_pair(LineX, NewObject("X")));

        widgets->values.insert(make_pair(ScopeMin, NewObject(SLOT(ChangeScope()))));
        widgets->values.insert(make_pair(ScopeMax, NewObject(SLOT(ChangeScope()))));
        widgets->values.insert(make_pair(RangeMin, NewObject(SLOT(ChangeScope()))));
        widgets->values.insert(make_pair(RangeMax, NewObject(SLOT(ChangeScope()))));
        widgets->values.insert(make_pair(X, NewObject(SLOT(reDrawLine()))));
        widgets->values.insert(make_pair(StepX, NewObject(SLOT(reDrawGraph()))));
    }


    void SetupUI() override {
        (*_platform)->SetupUI(widgets);
    }

    void DrawGraph() {
        QVector<double> x(10000), y(10000);

        double x0 = widgets->values.at(ScopeMin)->value();
        double step_x = (fabs(x0) + fabs(widgets->values.at(ScopeMax)->value())) / 10000;

        controller->SetInput("sin(x)");

        for (int i = 0; i < 10000; i++)
        {
            x[i] += x0;
            y[i] = controller->GetResult(x[i]);
            x0 += step_x;
        }

        widgets->graph->addGraph();
        widgets->graph->graph(0)->setData(x, y);
        widgets->graph->replot();
    }

    void DrawLine()
    {
        QVector<double> x(2), y(2);

        x[0] = widgets->values.at(X)->value();
        x[1] = widgets->values.at(X)->value();

        y[0] = widgets->values.at(RangeMin)->value();
        y[1] = widgets->values.at(RangeMax)->value();

        widgets->graph->addGraph();
        widgets->graph->graph(1)->setData(x, y);
        widgets->graph->replot();
    }

private slots:
    void ChangeScope() {
//        widgets->scopeMax->setMinimum(widgets->values.at(ScopeMin)->value());
//        widgets->scopeMin->setMaximum(widgets->values.at(ScopeMax)->value());

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
        widgets->values.at(X)->setSingleStep(widgets->values.at(StepX)->value());
    }
};


#endif // GRAPHUI_H


