#include "GraphUI.h"



GraphUI::GraphUI() : MainWindow(), _controller(new GraphController), _widgets(new GraphWidgets) {
    _widgets->graphWindow = this;
    _widgets->graph = new QCustomPlot(this);
    _widgets->graph->addGraph();
    _widgets->graph->addGraph();

    initWidgets();
    setOptions();
    setGeometry();
    setStyle();
    connectWidgetsToSlots();
}

GraphUI::~GraphUI() {
    delete _controller;
    delete _widgets;
}

void GraphUI::setStyle() {
    QString styleSheet = R"(
                        QWidget {
                            background-color: white;
                            color: black;
                        }
                        QTextEdit, QLineEdit#input  {
                            background-color: white;
                            border: 1px solid blue;
                            border-radius: 8;
                        }
                        QDoubleSpinBox#data, QLabel#title {
                            background-color: rgba(0, 0, 0, 0);
                            font: 14px;
                            border-radius: 8;
                        })";
    setStyleSheet(styleSheet);
}

void GraphUI::setGeometry() {
    int screenWidth = QApplication::screens().at(0)->size().width();
    int screenHeight = QApplication::screens().at(0)->size().height();

    this->setFixedSize(screenWidth / 2, screenHeight / 2);
    _widgets->graph->setFixedSize(this->width(), this->height() - 75);

    Layout layout;

    layout.SetStartPoints(0, _widgets->graph->height());
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

    layout.AddWidget(_widgets->box[SCOPE_MIN]);
    layout.AddWidget(_widgets->box[RANGE_MIN]);
    layout.AddWidget(_widgets->box[INPUT_X]);
    layout.AddWidget(_widgets->box[POINTS]);
    layout.AddWidget(_widgets->box[SCOPE_MAX]);
    layout.AddWidget(_widgets->box[RANGE_MAX]);
    layout.AddWidget(_widgets->inputLineEdit, 2, 1);

    layout.SetTitle(_widgets->box[SCOPE_MIN], _widgets->title.at(SCOPE_MIN), Layout::Left, Layout::CenterV, 16, 5, 0);
    layout.SetTitle(_widgets->box[RANGE_MIN], _widgets->title.at(RANGE_MIN), Layout::Left, Layout::CenterV, 16, 5, 0);
    layout.SetTitle(_widgets->box[INPUT_X], _widgets->title.at(INPUT_X), Layout::Left, Layout::CenterV, 16, 5, 0);
    layout.SetTitle(_widgets->box[POINTS], _widgets->title.at(POINTS), Layout::Left, Layout::CenterV, 16, 5, 0);
    layout.SetTitle(_widgets->box[SCOPE_MAX], _widgets->title.at(SCOPE_MAX), Layout::Left, Layout::CenterV, 16, 5, 0);
    layout.SetTitle(_widgets->box[RANGE_MAX], _widgets->title.at(RANGE_MAX), Layout::Left, Layout::CenterV, 16, 5, 0);
    layout.SetTitle(_widgets->box[INPUT_X], _widgets->checkBoxLineDrawing, Layout::Left, Layout::CenterV, 16, 5 + _widgets->title[INPUT_X]->width(), 0);

    layout.SetField(_widgets->box[SCOPE_MIN], _widgets->data[SCOPE_MIN], Layout::CenterH, 0);
    layout.SetField(_widgets->box[RANGE_MIN], _widgets->data[RANGE_MIN], Layout::CenterH, 0);
    layout.SetField(_widgets->box[INPUT_X], _widgets->data[INPUT_X], Layout::CenterH, 0);
    layout.SetField(_widgets->box[POINTS], _widgets->data[POINTS], Layout::CenterH, 0);
    layout.SetField(_widgets->box[SCOPE_MAX], _widgets->data[SCOPE_MAX], Layout::CenterH, 0);
    layout.SetField(_widgets->box[RANGE_MAX], _widgets->data[RANGE_MAX], Layout::CenterH, 0);
}

void GraphUI::setOptions() {
    _widgets->graph->xAxis->setLabel("x");
    _widgets->graph->yAxis->setLabel("y");
    _widgets->graph->xAxis->setRange(-5, 5);
    _widgets->graph->yAxis->setRange(-5, 5);

    _widgets->graph->setInteraction(QCP::iRangeZoom,true);
    _widgets->graph->setInteraction(QCP::iRangeDrag, true);
    _widgets->inputLineEdit->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);

    for (auto it : _widgets->data) {
        it.second->setAlignment(Qt::AlignRight);
    }

    for (auto it : _widgets->box) {
        it.second->setReadOnly(true);
    }

    for (int i = SCOPE_MIN; i <= INPUT_X; i++) {
        _widgets->data.at(i)->setMinimum(-1000000);
        _widgets->data.at(i)->setMaximum(1000000);
        _widgets->data.at(i)->setSingleStep(0.1);
    }

    _widgets->data.at(POINTS)->setMinimum(1000);
    _widgets->data.at(POINTS)->setMaximum(10000000);
    _widgets->data.at(POINTS)->setSingleStep(1000);

    _widgets->data.at(SCOPE_MIN)->setValue(-100);
    _widgets->data.at(SCOPE_MAX)->setValue(100);
    _widgets->data.at(RANGE_MIN)->setValue(-10);
    _widgets->data.at(RANGE_MAX)->setValue(10);
    _widgets->data.at(INPUT_X)->setValue(0);
    _widgets->data.at(POINTS)->setValue(10000);

    _widgets->graph->graph(1)->setVisible(false);
}

void GraphUI::initWidgets() {
    _widgets->box.insert(std::make_pair(SCOPE_MIN, new QTextEdit(this)));
    _widgets->box.insert(std::make_pair(RANGE_MIN, new QTextEdit(this)));
    _widgets->box.insert(std::make_pair(INPUT_X, new QTextEdit(this)));
    _widgets->box.insert(std::make_pair(POINTS, new QTextEdit(this)));
    _widgets->box.insert(std::make_pair(SCOPE_MAX, new QTextEdit(this)));
    _widgets->box.insert(std::make_pair(RANGE_MAX, new QTextEdit(this)));

    _widgets->data.insert(std::make_pair(SCOPE_MIN, NewDoubleSpinBox(this, "data")));
    _widgets->data.insert(std::make_pair(RANGE_MIN, NewDoubleSpinBox(this, "data")));
    _widgets->data.insert(std::make_pair(INPUT_X, NewDoubleSpinBox(this, "data")));
    _widgets->data.insert(std::make_pair(POINTS, NewDoubleSpinBox(this, "data")));
    _widgets->data.insert(std::make_pair(SCOPE_MAX, NewDoubleSpinBox(this, "data")));
    _widgets->data.insert(std::make_pair(RANGE_MAX, NewDoubleSpinBox(this, "data")));

    _widgets->inputLineEdit = NewLineEdit(this, "sin(x)", "input");
    _widgets->title.insert(std::make_pair(SCOPE_MIN, NewLabel(this, "x min", "title")));
    _widgets->title.insert(std::make_pair(RANGE_MIN, NewLabel(this, "y min", "title")));
    _widgets->title.insert(std::make_pair(INPUT_X, NewLabel(this, "  X", "title")));
    _widgets->title.insert(std::make_pair(POINTS, NewLabel(this, "POINTS", "title")));
    _widgets->title.insert(std::make_pair(SCOPE_MAX, NewLabel(this, "x max", "title")));
    _widgets->title.insert(std::make_pair(RANGE_MAX, NewLabel(this, "y max", "title")));

    _widgets->checkBoxLineDrawing = new QCheckBox(this);
}

void GraphUI::connectWidgetsToSlots() {
    connect(_widgets->data[INPUT_X], &QDoubleSpinBox::valueChanged, this, &GraphUI::drawLine);
    connect(_widgets->checkBoxLineDrawing, &QCheckBox::stateChanged, this, &GraphUI::drawingLineState);
    connect(_widgets->inputLineEdit, &QLineEdit::returnPressed, this, &GraphUI::drawGraph);
}

void GraphUI::drawLine()
{
    QVector<double> x(2, _widgets->data.at(INPUT_X)->value()), y(2);

    y[0] = _widgets->data.at(RANGE_MIN)->value();
    y[1] = _widgets->data.at(RANGE_MAX)->value();

    _widgets->graph->graph(1)->setData(x, y);
    _widgets->graph->replot();
}

void GraphUI::drawingLineState() {
    bool status = _widgets->checkBoxLineDrawing->isChecked();

    if (status) {
        drawLine();
    }

    _widgets->graph->graph(1)->setVisible(status);
    _widgets->graph->replot();
}

void GraphUI::drawGraph() {
    QString input = _widgets->inputLineEdit->text();
    double countPOINTS = _widgets->data[POINTS]->text().toDouble();
    double xMin = _widgets->data[SCOPE_MIN]->text().toDouble();
    double xMax = _widgets->data[SCOPE_MAX]->text().toDouble();
    double yMin = _widgets->data[RANGE_MIN]->text().toDouble();
    double yMax = _widgets->data[RANGE_MAX]->text().toDouble();

    bool status = _controller->setInput(input, countPOINTS, xMin, xMax, yMin, yMax);

    if (status) {
        _controller->Calculate();
        _widgets->graph->graph(0)->setData(_controller->getCollectionX(), _controller->getCollectionY());
    }

    _widgets->graph->graph(0)->setVisible(true);
    _widgets->graph->replot();
}
