#ifndef GRAPHUI_H
#define GRAPHUI_H


#include "mainwindow.h"
#include "../Controllers/GraphController.h"


class GraphUI : public MainWindow
{

Q_OBJECT

private:

    GraphController *controller;
    GraphWidgets *widgets;

    bool _graphStatus = false;

public:

    GraphUI() : MainWindow() {
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
    }

private:

    void SetStyle() {
        setStyleSheet("QWidget { "
                      " background-color: white;"
                      " color: black; }"
                      "QTextEdit, QLineEdit#input  { "
                      " background-color: white;"
                      " border: 1px solid blue;"
                      " border-radius: 8 }"
                      "QDoubleSpinBox#data, QLabel#title { "
                      " background-color: rgba(0, 0, 0, 0);"
                      " font: 14px; "
                      " border-radius: 8 }"
                      );
    }

    void SetGeometry() {
        int screenWidth = QApplication::screens().at(0)->size().width();
        int screenHeight = QApplication::screens().at(0)->size().height();

        this->setFixedSize(screenWidth / 2, screenHeight / 2);
        widgets->graph->setFixedSize(this->width(), this->height() - 75);

        Layout layout;

        layout.SetStartPoints(0, widgets->graph->height());
        layout.SetEndPoints(this->width(), this->height());
        layout.SetColumns(4);
        layout.SetRows(2);
        layout.SetLeftSpacing(5);
        layout.SetRightSpacing(5);
        layout.SetAboveSpacing(5);
        layout.SetBottomSpacing(5);
        layout.SetHorizontalSpacing(5);
        layout.SetVerticalSpacing(5);
        layout.SetAutoSize();

        layout.AddWidget(widgets->box[ScopeMin]);
        layout.AddWidget(widgets->box[RangeMin]);
        layout.AddWidget(widgets->box[InputX]);
        layout.AddWidget(widgets->box[Points]);
        layout.AddWidget(widgets->box[ScopeMax]);
        layout.AddWidget(widgets->box[RangeMax]);
        layout.AddWidget(widgets->Input, 2, 1);

        layout.SetTitle(widgets->box[ScopeMin], widgets->title.at(ScopeMin), Layout::Left, Layout::CenterV, 16, 5, 0);
        layout.SetTitle(widgets->box[RangeMin], widgets->title.at(RangeMin), Layout::Left, Layout::CenterV, 16, 5, 0);
        layout.SetTitle(widgets->box[InputX], widgets->title.at(InputX), Layout::Left, Layout::CenterV, 16, 5, 0);
        layout.SetTitle(widgets->box[Points], widgets->title.at(Points), Layout::Left, Layout::CenterV, 16, 5, 0);
        layout.SetTitle(widgets->box[ScopeMax], widgets->title.at(ScopeMax), Layout::Left, Layout::CenterV, 16, 5, 0);
        layout.SetTitle(widgets->box[RangeMax], widgets->title.at(RangeMax), Layout::Left, Layout::CenterV, 16, 5, 0);
        layout.SetTitle(widgets->box[InputX], widgets->drawingLine, Layout::Left, Layout::CenterV, 16, 5 + widgets->title[InputX]->width(), 0);

        layout.SetField(widgets->box[ScopeMin], widgets->data[ScopeMin], Layout::CenterH, 0);
        layout.SetField(widgets->box[RangeMin], widgets->data[RangeMin], Layout::CenterH, 0);
        layout.SetField(widgets->box[InputX], widgets->data[InputX], Layout::CenterH, 0);
        layout.SetField(widgets->box[Points], widgets->data[Points], Layout::CenterH, 0);
        layout.SetField(widgets->box[ScopeMax], widgets->data[ScopeMax], Layout::CenterH, 0);
        layout.SetField(widgets->box[RangeMax], widgets->data[RangeMax], Layout::CenterH, 0);
    }

    void SetOptions() {
        widgets->graph->xAxis->setLabel("x");
        widgets->graph->yAxis->setLabel("y");
        widgets->graph->xAxis->setRange(-5, 5);
        widgets->graph->yAxis->setRange(-5, 5);

        widgets->graph->setInteraction(QCP::iRangeZoom,true);
        widgets->graph->setInteraction(QCP::iRangeDrag, true);
        widgets->Input->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);

        for (auto it : widgets->data) {
            it.second->setAlignment(Qt::AlignRight);
        }

        for (auto it : widgets->box) {
            it.second->setReadOnly(true);
        }

        for (int i = ScopeMin; i <= InputX; i++) {
            widgets->data.at(i)->setMinimum(-1000000);
            widgets->data.at(i)->setMaximum(1000000);
            widgets->data.at(i)->setSingleStep(0.1);
        }

        widgets->data.at(Points)->setMinimum(1);
        widgets->data.at(Points)->setMaximum(100000);
        widgets->data.at(Points)->setSingleStep(100);

        widgets->data.at(ScopeMin)->setValue(-100);
        widgets->data.at(ScopeMax)->setValue(100);
        widgets->data.at(RangeMin)->setValue(-10);
        widgets->data.at(RangeMax)->setValue(10);
        widgets->data.at(InputX)->setValue(0);
        widgets->data.at(Points)->setValue(10000);

        widgets->graph->graph(1)->setVisible(false);
    }

    void CreateObjects() {
        widgets->box.insert(make_pair(ScopeMin, new QTextEdit(this)));
        widgets->box.insert(make_pair(RangeMin, new QTextEdit(this)));
        widgets->box.insert(make_pair(InputX, new QTextEdit(this)));
        widgets->box.insert(make_pair(Points, new QTextEdit(this)));
        widgets->box.insert(make_pair(ScopeMax, new QTextEdit(this)));
        widgets->box.insert(make_pair(RangeMax, new QTextEdit(this)));

        widgets->data.insert(make_pair(ScopeMin, NewDoubleSpinBox(this, "data")));
        widgets->data.insert(make_pair(RangeMin, NewDoubleSpinBox(this, "data")));
        widgets->data.insert(make_pair(InputX, NewDoubleSpinBox(this, "data")));
        widgets->data.insert(make_pair(Points, NewDoubleSpinBox(this, "data")));
        widgets->data.insert(make_pair(ScopeMax, NewDoubleSpinBox(this, "data")));
        widgets->data.insert(make_pair(RangeMax, NewDoubleSpinBox(this, "data")));

        widgets->Input = NewLineEdit(this, "", "input");
        widgets->title.insert(make_pair(ScopeMin, NewLabel(this, "x min", "title")));
        widgets->title.insert(make_pair(RangeMin, NewLabel(this, "y min", "title")));
        widgets->title.insert(make_pair(InputX, NewLabel(this, "  X", "title")));
        widgets->title.insert(make_pair(Points, NewLabel(this, "Points", "title")));
        widgets->title.insert(make_pair(ScopeMax, NewLabel(this, "x max", "title")));
        widgets->title.insert(make_pair(RangeMax, NewLabel(this, "y max", "title")));

        widgets->drawingLine = new QCheckBox(this);
    }

    void Connects() {
        connect(widgets->data[ScopeMin], &QDoubleSpinBox::valueChanged, this, &GraphUI::ChangeScope);
        connect(widgets->data[ScopeMax], &QDoubleSpinBox::valueChanged, this, &GraphUI::ChangeScope);
        connect(widgets->data[RangeMin], &QDoubleSpinBox::valueChanged, this, &GraphUI::ChangeScope);
        connect(widgets->data[RangeMax], &QDoubleSpinBox::valueChanged, this, &GraphUI::ChangeScope);
        connect(widgets->data[Points], &QDoubleSpinBox::valueChanged, this, &GraphUI::DrawGraph);
        connect(widgets->data[InputX], &QDoubleSpinBox::valueChanged, this, &GraphUI::DrawLine);
        connect(widgets->drawingLine, &QCheckBox::stateChanged, this, &GraphUI::DrawingLineState);
        connect(widgets->Input, &QLineEdit::returnPressed, this, &GraphUI::SetInput);
        connect(widgets->Input, &QLineEdit::textChanged, this, &GraphUI::RealTimeValodate);
    }

private slots:

    void RealTimeValodate() {
        int status = controller->ResultValidate(widgets->Input->text());

        if (status) {
            widgets->Input->setStyleSheet(""
                          " background-color: white;"
                          " border: 1px solid blue;"
                          " border-radius: 8;"

                          );
        } else {
            widgets->Input->setStyleSheet(
                          " background-color: white;"
                          " border: 1px solid red;"
                          " border-radius: 8;"
                          );
        }
    }

    void DrawGraph() {
        if (_graphStatus) {
            int countPoints = widgets->data[Points]->value();
            double xMin = widgets->data[ScopeMin]->value();
            double xMax = widgets->data[ScopeMax]->value();
            double yMin = widgets->data[RangeMin]->value();
            double yMax = widgets->data[RangeMax]->value();

            QVector<double> x = controller->GetCollectionX(countPoints, xMin, xMax);
            QVector<double> y = controller->GetCollectionY(x, yMin, yMax);

            widgets->graph->graph(0)->setData(x, y);
            widgets->graph->graph(0)->setVisible(true);
            widgets->graph->replot();
        }
    }

    void DrawLine()
    {
        QVector<double> x(2, widgets->data.at(InputX)->value()), y(2);

        y[0] = widgets->data.at(RangeMin)->value();
        y[1] = widgets->data.at(RangeMax)->value();

        widgets->graph->graph(1)->setData(x, y);
        widgets->graph->replot();
    }

    void DrawingLineState() {
        bool state = widgets->drawingLine->isTristate();
        widgets->drawingLine->setTristate(!state);
        widgets->graph->graph(1)->setVisible(!state);
        DrawLine();
        widgets->graph->replot();
    }

    void ChangeScope() {
        widgets->data.at(ScopeMin)->setMaximum(widgets->data.at(ScopeMax)->value());
        widgets->data.at(ScopeMax)->setMinimum(widgets->data.at(ScopeMin)->value());
        DrawGraph();
    }

    void ChangeRange() {
        widgets->data.at(RangeMin)->setMaximum(widgets->data.at(RangeMax)->value());
        widgets->data.at(RangeMax)->setMinimum(widgets->data.at(RangeMin)->value());
        DrawGraph();
        DrawLine();
    }

    void SetInput() {
        _graphStatus = controller->ResultValidate(widgets->Input->text());

        if (_graphStatus) {
            controller->SetInput(widgets->Input->text());
            DrawGraph();
        } else {
            widgets->graph->graph(0)->setVisible(false);
            widgets->graph->replot();
        }
    }

    void ClearInput() {
        widgets->Input->clear();
    }
};


#endif // GRAPHUI_H


