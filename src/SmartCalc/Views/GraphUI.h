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

    int row = 1, col = 0, col_max = 3;

    GraphUI() : MainWindow() {
        this->setWindowTitle("Graph");

        widgets = new GraphWidgets;
        controller = new GraphController;

        widgets->graphWindow = this;
        widgets->graph = new QCustomPlot(this);

        this->setFixedSize(1200, 1050);
        widgets->graph->setFixedSize(1200, 975);

        widgets->graphWindow->setStyleSheet("background-color: white;");

        widgets->graph->setInteraction(QCP::iRangeZoom,true);
        widgets->graph->setInteraction(QCP::iRangeDrag, true);

        widgets->graph->xAxis->setLabel("x");
        widgets->graph->yAxis->setLabel("y");
        widgets->graph->xAxis->setRange(-5, 5);
        widgets->graph->yAxis->setRange(-5, 5);

        CreateObjects();

        controller->SetInput(widgets->Input->text().toStdString());
        widgets->values.at(RangeMin)->setValue(-100);
        widgets->values.at(RangeMax)->setValue(100);
        widgets->values.at(ScopeMin)->setValue(-100);
        widgets->values.at(ScopeMax)->setValue(100);
        widgets->values.at(Points)->setMinimum(100);
        widgets->values.at(Points)->setMaximum(1000000);
        widgets->values.at(Points)->setValue(10000);
        widgets->values.at(Points)->setSingleStep(100);

        SetSize();

        DrawGraph();
        DrawLine();
    }

    void SetupUI() override {
        (*_platform)->SetupUI(widgets);
    }

    QLabel *NewLineEdit(QString text) {
        QLabel *newObject = new QLabel(text, this);
        SetStyle(newObject);

        newObject->setAlignment(Qt::AlignLeft | Qt::AlignVCenter);

        return newObject;
    }

    QDoubleSpinBox *NewDoubleSpinBox(const char* member, int parentKey) {
        QDoubleSpinBox *newObject = new QDoubleSpinBox(widgets->titles.at(parentKey));
        newObject->setStyleSheet("border-width: 0px;");

        newObject->setAlignment(Qt::AlignHCenter | Qt::AlignCenter);
        newObject->setButtonSymbols(QAbstractSpinBox::NoButtons);

        newObject->setValue(0);
        newObject->setMinimum(-999999999999999999999999.);
        newObject->setMaximum(999999999999999999999999.);
        newObject->setSingleStep(0.1);
        newObject->setFixedSize(0, 0);

        connect(newObject, SIGNAL(valueChanged(double)), this, member);

        return newObject;
    }

    void SetSize() {
        Layout *graphLayout = new Layout(5, widgets->graph->height() + 5, this->width() - 5, this->height() - 5, 2, 4, 5, 5);
        graphLayout->AddWidget(widgets->titles.at(ScopeMin), 1, 1);
        graphLayout->AddWidget(widgets->titles.at(RangeMin), 1, 1);
        graphLayout->AddWidget(widgets->titles.at(InputX), 1, 1);
        graphLayout->AddWidget(widgets->titles.at(Points), 1, 1);
        graphLayout->AddWidget(widgets->titles.at(ScopeMax), 1, 1);
        graphLayout->AddWidget(widgets->titles.at(RangeMax), 1, 1);
        graphLayout->AddWidget(widgets->Input, 2, 1);
    }

    void SetStyle(QWidget *object) {
        object->setStyleSheet("background-color: white;"
                                 "color: black;"
                                 "border: 1px solid blue;"
                                 "border-radius: 8;");
    }

    void CreateObjects() {
        widgets->titles.insert(make_pair(ScopeMin, NewLineEdit("x min")));
        widgets->titles.insert(make_pair(ScopeMax, NewLineEdit("x max")));
        widgets->titles.insert(make_pair(RangeMin, NewLineEdit("y min")));
        widgets->titles.insert(make_pair(RangeMax, NewLineEdit("y max")));
        widgets->titles.insert(make_pair(InputX, NewLineEdit("  X")));
        widgets->titles.insert(make_pair(Points, NewLineEdit("Points")));

        widgets->values.insert(make_pair(ScopeMin, NewDoubleSpinBox(SLOT(ChangeScope()), ScopeMin)));
        widgets->values.insert(make_pair(RangeMin, NewDoubleSpinBox(SLOT(ChangeRange()), RangeMin)));
        widgets->values.insert(make_pair(InputX, NewDoubleSpinBox(SLOT(reDrawLine()), InputX)));
        widgets->values.insert(make_pair(Points, NewDoubleSpinBox(SLOT(ChangePoints()), Points)));
        widgets->values.insert(make_pair(ScopeMax, NewDoubleSpinBox(SLOT(ChangeScope()), ScopeMax)));
        widgets->values.insert(make_pair(RangeMax, NewDoubleSpinBox(SLOT(ChangeRange()), RangeMax)));

        widgets->Input = new QLineEdit("sin(x)", this);
        SetStyle(widgets->Input);
        widgets->Input->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
        connect(widgets->Input, SIGNAL(returnPressed()), this, SLOT(SetInput()));

        widgets->drawingLine = new QCheckBox(widgets->titles.at(InputX));
        widgets->drawingLine->setStyleSheet("border-width: 0px;"
                                            "font: 10px;");
        widgets->drawingLine->setText("Draw\n line");
        connect(widgets->drawingLine, SIGNAL(stateChanged(int)), this, SLOT(DrawingLineState()));
    }

    void DrawGraph() {
        int countPoints = widgets->values.at(Points)->value();
        QVector<double> x(countPoints), y(countPoints);
        double x0 = widgets->values.at(ScopeMin)->value();
        double step_x = (fabs(x0) + fabs(widgets->values.at(ScopeMax)->value())) / countPoints;


        for (int i = 0; i < countPoints; i++)
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
        widgets->graph->graph(0)->setAdaptiveSampling(1);
        widgets->graph->replot();
    }

    void DrawLine()
    {
            QVector<double> x(2), y(2);

            x[0] = widgets->values.at(InputX)->value();
            x[1] = x[0];

            y[0] = widgets->values.at(RangeMin)->value();
            y[1] = widgets->values.at(RangeMax)->value();

            widgets->graph->addGraph();
            widgets->graph->graph(1)->setData(x, y);
            widgets->graph->graph(1)->setVisible(widgets->drawingLine->isTristate());
            widgets->graph->replot();
    }

private slots:

    void DrawingLineState() {
        bool state = widgets->drawingLine->isTristate();
        widgets->drawingLine->setTristate(!state);

        DrawLine();

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

    void ChangePoints() {
        DrawGraph();
    }
};


#endif // GRAPHUI_H


