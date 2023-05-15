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
    Layout *graphLayout;

    GraphUI() : MainWindow() {
        this->setWindowTitle("Graph");

        widgets = new GraphWidgets;
        controller = new GraphController;

        widgets->graphWindow = this;
        widgets->graph = new QCustomPlot(this);
        widgets->graph->addGraph();
        widgets->graph->addGraph();

        CreateObjects();
        SetOptions();
        SetGeometry();
        SetStyle();
        Connects();

        controller->SetInput(widgets->Input->text().toStdString());
        DrawGraph();
    }

    void SetupUI() override {
        (*_platform)->SetupUI(widgets);
    }

    void SetStyle() {
        setStyleSheet("QWidget { "
                      " background-color: white;"
                      " color: black; }"
                      "QLabel#title {"
                      " border: 1px solid blue;"
                      " border-radius: 8; }"
                      "QLineEdit#title {"
                      " border: 1px solid blue;"
                      " border-radius: 8; }"
                      "QDoubleSpinBox#value {"
                      " border-width: 0px;"
                      " border-radius: 8; }"
                      "QCheckBox#value {"
                      " border-width: 0px;"
                      " border-radius: 8;"
                      " font: 8px }"
                      );
    }

    void SetGeometry() {
        this->setFixedSize(1200, 1050);
        widgets->graph->setFixedSize(1200, 975);
        graphLayout = new Layout(5, widgets->graph->height() + 5, this->width() - 5, this->height() - 5, 2, 4, 5, 5);

        graphLayout->AddWidget(widgets->titles.at(ScopeMin));
        graphLayout->AddWidget(widgets->titles.at(RangeMin));
        graphLayout->AddWidget(widgets->titles.at(InputX));
        graphLayout->AddWidget(widgets->titles.at(Points));
        graphLayout->AddWidget(widgets->titles.at(ScopeMax));
        graphLayout->AddWidget(widgets->titles.at(RangeMax));
        graphLayout->AddWidget(widgets->Input, 2, 1);

        graphLayout->AddWidget(widgets->values.at(ScopeMin), widgets->titles.at(ScopeMin), 45, 1);
        graphLayout->AddWidget(widgets->values.at(RangeMin), widgets->titles.at(RangeMin), 45, 1);
        graphLayout->AddWidget(widgets->values.at(InputX), widgets->titles.at(InputX), 45, 1);
        graphLayout->AddWidget(widgets->values.at(Points), widgets->titles.at(Points), 45, 1);
        graphLayout->AddWidget(widgets->values.at(ScopeMax), widgets->titles.at(ScopeMax), 45, 1);
        graphLayout->AddWidget(widgets->values.at(RangeMax), widgets->titles.at(RangeMax), 45, 1);
        graphLayout->AddWidget(widgets->drawingLine, widgets->titles.at(InputX), 5, 1, Layout::Right, 20);

        delete graphLayout;
    }

    void SetOptions() {
        widgets->graph->xAxis->setLabel("x");
        widgets->graph->yAxis->setLabel("y");
        widgets->graph->xAxis->setRange(-5, 5);
        widgets->graph->yAxis->setRange(-5, 5);

        widgets->graph->setInteraction(QCP::iRangeZoom,true);
        widgets->graph->setInteraction(QCP::iRangeDrag, true);
        widgets->Input->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);

        for (int i = ScopeMin; i <= InputX; i++) {
            widgets->values.at(i)->setMinimum(-1000000);
            widgets->values.at(i)->setMaximum(1000000);
            widgets->values.at(i)->setSingleStep(0.1);
        }

        widgets->values.at(Points)->setMinimum(1);
        widgets->values.at(Points)->setMaximum(100000);
        widgets->values.at(Points)->setSingleStep(100);

        widgets->values.at(ScopeMin)->setValue(-100);
        widgets->values.at(ScopeMax)->setValue(100);
        widgets->values.at(RangeMin)->setValue(-10);
        widgets->values.at(RangeMax)->setValue(10);
        widgets->values.at(InputX)->setValue(0);
        widgets->values.at(Points)->setValue(10000);

        widgets->graph->graph(1)->setVisible(false);
    }

    void CreateObjects() {
        widgets->Input = NewQLineEdit(this, "sin(x)", "title");
        widgets->titles.insert(make_pair(ScopeMin, NewLabel(this, "x min", "title")));
        widgets->titles.insert(make_pair(RangeMin, NewLabel(this, "y min", "title")));
        widgets->titles.insert(make_pair(InputX, NewLabel(this, "  X", "title")));
        widgets->titles.insert(make_pair(Points, NewLabel(this, "Points", "title")));
        widgets->titles.insert(make_pair(ScopeMax, NewLabel(this, "x max", "title")));
        widgets->titles.insert(make_pair(RangeMax, NewLabel(this, "y max", "title")));

        widgets->values.insert(make_pair(ScopeMin, NewDoubleSpinBox(widgets->titles.at(ScopeMin), "value")));
        widgets->values.insert(make_pair(RangeMin, NewDoubleSpinBox(widgets->titles.at(RangeMin), "value")));
        widgets->values.insert(make_pair(InputX, NewDoubleSpinBox(widgets->titles.at(InputX), "value")));
        widgets->values.insert(make_pair(Points, NewDoubleSpinBox(widgets->titles.at(Points), "value")));
        widgets->values.insert(make_pair(ScopeMax, NewDoubleSpinBox(widgets->titles.at(ScopeMax), "value")));
        widgets->values.insert(make_pair(RangeMax, NewDoubleSpinBox(widgets->titles.at(RangeMax), "value")));
        widgets->drawingLine = new QCheckBox(widgets->titles[InputX]);

    }

    void Connects() {
        connect(widgets->values.at(ScopeMin), SIGNAL(valueChanged(double)), SLOT(ChangeScope()));
        connect(widgets->values.at(ScopeMax), SIGNAL(valueChanged(double)), SLOT(ChangeScope()));
        connect(widgets->values.at(RangeMin), SIGNAL(valueChanged(double)), SLOT(ChangeRange()));
        connect(widgets->values.at(RangeMax), SIGNAL(valueChanged(double)), SLOT(ChangeRange()));
        connect(widgets->values.at(Points), SIGNAL(valueChanged(double)), SLOT(ChangePoints()));
        connect(widgets->values.at(InputX), SIGNAL(valueChanged(double)), SLOT(reDrawLine()));
        connect(widgets->drawingLine, SIGNAL(stateChanged(int)), SLOT(DrawingLineState()));
        connect(widgets->Input, SIGNAL(returnPressed()), SLOT(SetInput()));
    }

    void DrawGraph() {
        int countPoints = widgets->values.at(Points)->value();
        QVector<double> x(countPoints, 0), y(countPoints, 0);

        CalcValues(x, y, countPoints);

        widgets->graph->graph(0)->setData(x, y);
        widgets->graph->replot();
    }

    void CalcValues(QVector<double> &x, QVector<double> &y, int countPoints) {
        double xMin = widgets->values.at(ScopeMin)->value();
        double xMax = widgets->values.at(ScopeMax)->value();
        double yMin = widgets->values.at(RangeMin)->value();
        double yMax = widgets->values.at(RangeMax)->value();

        double stepX = (fabs(xMin) + fabs(xMax)) / countPoints;

        for (int i = 0; i < countPoints; i++)
        {
            x[i] = xMin + stepX * i;
            y[i] = controller->GetResult(x[i]);

            if (y[i] > yMax || y[i] < yMin) {
                y[i] = qQNaN();
            }
        }
    }

    void DrawLine()
    {
        QVector<double> x(2, widgets->values.at(InputX)->value()), y(2);

        y[0] = widgets->values.at(RangeMin)->value();
        y[1] = widgets->values.at(RangeMax)->value();

        widgets->graph->graph(1)->setData(x, y);
        widgets->graph->replot();
    }


private slots:

    void DrawingLineState() {
        bool state = widgets->drawingLine->isTristate();
        widgets->drawingLine->setTristate(!state);
        widgets->graph->graph(1)->setVisible(!state);

        widgets->graph->replot();
    }

    void ChangeScope() {
        widgets->values.at(ScopeMin)->setMaximum(widgets->values.at(ScopeMax)->value());
        widgets->values.at(ScopeMax)->setMinimum(widgets->values.at(ScopeMin)->value());
        DrawGraph();
    }

    void ChangeRange() {
        widgets->values.at(RangeMin)->setMaximum(widgets->values.at(RangeMax)->value());
        widgets->values.at(RangeMax)->setMinimum(widgets->values.at(RangeMin)->value());
        DrawGraph();
        DrawLine();
    }

    void ChangePoints() {
        DrawGraph();
    }

    void SetInput() {
        controller->SetInput(widgets->Input->text().toStdString());
        DrawGraph();
    }

    void ClearInput() {
        widgets->Input->clear();
    }

    void reDrawLine()
    {
        DrawLine();
    }

    void reDrawGraph()
    {
        DrawGraph();
    }
};


#endif // GRAPHUI_H


