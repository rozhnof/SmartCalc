#ifndef GRAPHUI_H
#define GRAPHUI_H


#include "mainwindow.h"
#include "IPlatformUI.h"
#include "../Controllers/GraphController.h"

using namespace std;

class GraphUI : public MainWindow
{

Q_OBJECT

public:

    GraphController *controller;
    GraphWidgets *widgets;

    QWidget *layoutWidget;
    QGridLayout *layout;

    int row = 1, col = 0, col_max = 3;

    GraphUI() : MainWindow() {
        this->setWindowTitle("Graph");

        widgets = new GraphWidgets;
        controller = new GraphController;

        widgets->graphWindow = this;
        widgets->graph = new QCustomPlot(this);

        layoutWidget = new QWidget(this);
        layout = new QGridLayout(layoutWidget);
        this->setCentralWidget(layoutWidget);

        this->setMinimumSize(400, 350);
        this->resize(800, 700);

        widgets->graphWindow->setStyleSheet("background-color: white;");

        widgets->graph->setInteraction(QCP::iRangeZoom,true);
        widgets->graph->setInteraction(QCP::iRangeDrag, true);

        widgets->graph->xAxis->setLabel("x");
        widgets->graph->yAxis->setLabel("y");
        widgets->graph->xAxis->setRange(-5, 5);
        widgets->graph->yAxis->setRange(-5, 5);

        layout->addWidget(widgets->graph, 0, 0, 1, 4);

        CreateObjects();

        controller->SetInput(widgets->titles.at(LineInput)->text().toStdString());
        DrawGraph();
        DrawLine();
    }

    void SetupUI() override {
        (*_platform)->SetupUI(widgets);
    }

    QLineEdit *NewLineEdit(QString text) {
        QLineEdit *newObject = new QLineEdit(text, this);
        int width = 1;
        if (text == "Input") width = 2;

        SetStyle(newObject);
        newObject->setAlignment(Qt::AlignHCenter | Qt::AlignCenter);
        SetLayout(newObject, width);

        newObject->setReadOnly(true);

        return newObject;
    }

    QDoubleSpinBox *NewDoubleSpinBox(const char* member) {
        QDoubleSpinBox *newObject = new QDoubleSpinBox(this);
        int width = 1;

        SetStyle(newObject);
        SetLayout(newObject, width);

        newObject->setAlignment(Qt::AlignHCenter | Qt::AlignCenter);
        newObject->setButtonSymbols(QAbstractSpinBox::NoButtons);

        newObject->setValue(0);
        newObject->setMinimum(-INFINITY);
        newObject->setMaximum(INFINITY);
        newObject->setSingleStep(0.1);

        connect(newObject, SIGNAL(valueChanged(double)), this, member);

        return newObject;
    }

    void SetStyle(QWidget *object) {
        object->setStyleSheet("background-color: white;"
                                 "color: black;"
                                 "border: 1px solid blue;"
                                 "border-radius: 8;");
    }

    void SetLayout(QWidget *object, int width) {
        layout->setContentsMargins(0, 0, 0, 0);
        layout->addWidget(object, row, col, 1, width);

        col++;
        if (col > col_max) {
            col = 0;
            row++;
        }
    }

    void CreateObjects() {
        widgets->titles.insert(make_pair(LineScope, NewLineEdit("Scope")));
        widgets->titles.insert(make_pair(LineRange, NewLineEdit("Range")));
        widgets->titles.insert(make_pair(LineX, NewLineEdit("X")));
        widgets->titles.insert(make_pair(LineStepX, NewLineEdit("Step X")));

        widgets->values.insert(make_pair(ScopeMin, NewDoubleSpinBox(SLOT(ChangeScope()))));
        widgets->values.insert(make_pair(RangeMin, NewDoubleSpinBox(SLOT(ChangeScope()))));
        widgets->values.insert(make_pair(X, NewDoubleSpinBox(SLOT(reDrawLine()))));
        widgets->values.insert(make_pair(StepX, NewDoubleSpinBox(SLOT(reDrawGraph()))));
        widgets->values.insert(make_pair(ScopeMax, NewDoubleSpinBox(SLOT(ChangeScope()))));
        widgets->values.insert(make_pair(RangeMax, NewDoubleSpinBox(SLOT(ChangeScope()))));

        widgets->titles.insert(make_pair(LineInput, NewLineEdit("sin(x)")));
        widgets->titles.at(LineInput)->setReadOnly(false);
        connect(widgets->titles.at(LineInput), SIGNAL(returnPressed()), this, SLOT(SetInput()));
    }

    void DrawGraph() {
        QVector<double> x(10000), y(10000);

        double x0 = widgets->values.at(ScopeMin)->value();
        double step_x = (fabs(x0) + fabs(widgets->values.at(ScopeMax)->value())) / 10000;


        for (int i = 0; i < 10000; i++)
        {
            x[i] += x0;
            y[i] = controller->GetResult(x[i]);
            x0 += step_x;

            if (y[i] >= widgets->values.at(RangeMax)->value() || y[i] <= widgets->values.at(RangeMin)->value()) {
                if (i == 0) {
                    y[i] = widgets->values.at(RangeMax)->value();
                } else {
                    y[i] = qQNaN();
                }
            }
        }

        widgets->graph->addGraph();
        widgets->graph->graph(0)->setData(x, y);
        widgets->graph->replot();
    }

    void DrawLine()
    {
        QVector<double> x(2), y(2);

        x[0] = widgets->values.at(X)->value();
        x[1] = x[0];

        y[0] = widgets->values.at(RangeMin)->value();
        y[1] = widgets->values.at(RangeMax)->value();

        widgets->graph->addGraph();
        widgets->graph->graph(1)->setData(x, y);
        widgets->graph->replot();
    }

private slots:

    void SetInput() {
        controller->SetInput(widgets->titles.at(LineInput)->text().toStdString());
        DrawGraph();
    }

    void ClearInput() {
        widgets->titles.at(LineInput)->clear();
    }

    void ChangeScope() {
        DrawLine();
        DrawGraph();
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


