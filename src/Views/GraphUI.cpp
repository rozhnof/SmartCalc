#include "GraphUI.h"

GraphUI::GraphUI()
    : MainWindow(),
      controller_(new GraphController),
      widgets_(new GraphWidgets) {
  widgets_->graphWindow = this;
  widgets_->graph = new QCustomPlot(this);
  widgets_->graph->addGraph();
  widgets_->graph->addGraph();

  initWidgets();
  setOptions();
  setGeometry();
  setStyle();
  connectWidgetsToSlots();
}

GraphUI::~GraphUI() {
  delete controller_;
  delete widgets_;
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
  widgets_->graph->setFixedSize(this->width(), this->height() - 75);

  Layout layout;

  layout.setStartPoints(0, widgets_->graph->height());
  layout.setEndPoints(this->width(), this->height());
  layout.setColumns(4);
  layout.setRows(2);
  layout.setLeftSpacing(5);
  layout.setRightSpacing(5);
  layout.setAboveSpacing(5);
  layout.setBottomSpacing(5);
  layout.setHorizontalSpacing(5);
  layout.setVerticalSpacing(5);
  layout.setAutoSize();

  layout.AddWidget(widgets_->box[SCOPE_MIN]);
  layout.AddWidget(widgets_->box[RANGE_MIN]);
  layout.AddWidget(widgets_->box[INPUT_X]);
  layout.AddWidget(widgets_->box[POINTS]);
  layout.AddWidget(widgets_->box[SCOPE_MAX]);
  layout.AddWidget(widgets_->box[RANGE_MAX]);
  layout.AddWidget(widgets_->inputLineEdit, 2, 1);

  layout.SetTitle(widgets_->box[SCOPE_MIN], widgets_->title.at(SCOPE_MIN),
                  Layout::Left, Layout::CenterV, 16, 5, 0);
  layout.SetTitle(widgets_->box[RANGE_MIN], widgets_->title.at(RANGE_MIN),
                  Layout::Left, Layout::CenterV, 16, 5, 0);
  layout.SetTitle(widgets_->box[INPUT_X], widgets_->title.at(INPUT_X),
                  Layout::Left, Layout::CenterV, 16, 5, 0);
  layout.SetTitle(widgets_->box[POINTS], widgets_->title.at(POINTS),
                  Layout::Left, Layout::CenterV, 16, 5, 0);
  layout.SetTitle(widgets_->box[SCOPE_MAX], widgets_->title.at(SCOPE_MAX),
                  Layout::Left, Layout::CenterV, 16, 5, 0);
  layout.SetTitle(widgets_->box[RANGE_MAX], widgets_->title.at(RANGE_MAX),
                  Layout::Left, Layout::CenterV, 16, 5, 0);
  layout.SetTitle(widgets_->box[INPUT_X], widgets_->checkBoxLineDrawing,
                  Layout::Left, Layout::CenterV, 16,
                  5 + widgets_->title[INPUT_X]->width(), 0);

  layout.SetField(widgets_->box[SCOPE_MIN], widgets_->data[SCOPE_MIN],
                  Layout::CenterH, 0);
  layout.SetField(widgets_->box[RANGE_MIN], widgets_->data[RANGE_MIN],
                  Layout::CenterH, 0);
  layout.SetField(widgets_->box[INPUT_X], widgets_->data[INPUT_X],
                  Layout::CenterH, 0);
  layout.SetField(widgets_->box[POINTS], widgets_->data[POINTS],
                  Layout::CenterH, 0);
  layout.SetField(widgets_->box[SCOPE_MAX], widgets_->data[SCOPE_MAX],
                  Layout::CenterH, 0);
  layout.SetField(widgets_->box[RANGE_MAX], widgets_->data[RANGE_MAX],
                  Layout::CenterH, 0);
}

void GraphUI::setOptions() {
  widgets_->graph->xAxis->setLabel("x");
  widgets_->graph->yAxis->setLabel("y");
  widgets_->graph->xAxis->setRange(-5, 5);
  widgets_->graph->yAxis->setRange(-5, 5);

  widgets_->graph->setInteraction(QCP::iRangeZoom, true);
  widgets_->graph->setInteraction(QCP::iRangeDrag, true);
  widgets_->inputLineEdit->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);

  for (auto it : widgets_->data) {
    it.second->setAlignment(Qt::AlignRight);
  }

  for (auto it : widgets_->box) {
    it.second->setReadOnly(true);
  }

  for (int i = SCOPE_MIN; i <= INPUT_X; i++) {
    widgets_->data.at(i)->setMinimum(-1000000);
    widgets_->data.at(i)->setMaximum(1000000);
    widgets_->data.at(i)->setSingleStep(0.1);
  }

  widgets_->data.at(POINTS)->setMinimum(1000);
  widgets_->data.at(POINTS)->setMaximum(10000000);
  widgets_->data.at(POINTS)->setSingleStep(1000);

  widgets_->data.at(SCOPE_MIN)->setValue(-100);
  widgets_->data.at(SCOPE_MAX)->setValue(100);
  widgets_->data.at(RANGE_MIN)->setValue(-10);
  widgets_->data.at(RANGE_MAX)->setValue(10);
  widgets_->data.at(INPUT_X)->setValue(0);
  widgets_->data.at(POINTS)->setValue(10000);

  widgets_->graph->graph(1)->setVisible(false);
}

void GraphUI::initWidgets() {
  widgets_->box.insert(std::make_pair(SCOPE_MIN, new QTextEdit(this)));
  widgets_->box.insert(std::make_pair(RANGE_MIN, new QTextEdit(this)));
  widgets_->box.insert(std::make_pair(INPUT_X, new QTextEdit(this)));
  widgets_->box.insert(std::make_pair(POINTS, new QTextEdit(this)));
  widgets_->box.insert(std::make_pair(SCOPE_MAX, new QTextEdit(this)));
  widgets_->box.insert(std::make_pair(RANGE_MAX, new QTextEdit(this)));

  widgets_->data.insert(
      std::make_pair(SCOPE_MIN, NewDoubleSpinBox(this, "data")));
  widgets_->data.insert(
      std::make_pair(RANGE_MIN, NewDoubleSpinBox(this, "data")));
  widgets_->data.insert(
      std::make_pair(INPUT_X, NewDoubleSpinBox(this, "data")));
  widgets_->data.insert(std::make_pair(POINTS, NewDoubleSpinBox(this, "data")));
  widgets_->data.insert(
      std::make_pair(SCOPE_MAX, NewDoubleSpinBox(this, "data")));
  widgets_->data.insert(
      std::make_pair(RANGE_MAX, NewDoubleSpinBox(this, "data")));

  widgets_->inputLineEdit = NewLineEdit(this, "sin(x)", "input");
  widgets_->title.insert(
      std::make_pair(SCOPE_MIN, NewLabel(this, "x min", "title")));
  widgets_->title.insert(
      std::make_pair(RANGE_MIN, NewLabel(this, "y min", "title")));
  widgets_->title.insert(
      std::make_pair(INPUT_X, NewLabel(this, "  X", "title")));
  widgets_->title.insert(
      std::make_pair(POINTS, NewLabel(this, "POINTS", "title")));
  widgets_->title.insert(
      std::make_pair(SCOPE_MAX, NewLabel(this, "x max", "title")));
  widgets_->title.insert(
      std::make_pair(RANGE_MAX, NewLabel(this, "y max", "title")));

  widgets_->checkBoxLineDrawing = new QCheckBox(this);
}

void GraphUI::connectWidgetsToSlots() {
  connect(widgets_->data[INPUT_X], &QDoubleSpinBox::valueChanged, this,
          &GraphUI::drawLine);
  connect(widgets_->checkBoxLineDrawing, &QCheckBox::stateChanged, this,
          &GraphUI::drawingLineState);
  connect(widgets_->inputLineEdit, &QLineEdit::returnPressed, this,
          &GraphUI::drawGraph);
}

void GraphUI::drawLine() {
  QVector<double> x(2, widgets_->data.at(INPUT_X)->value()), y(2);

  y[0] = widgets_->data.at(RANGE_MIN)->value();
  y[1] = widgets_->data.at(RANGE_MAX)->value();

  widgets_->graph->graph(1)->setData(x, y);
  widgets_->graph->replot();
}

void GraphUI::drawingLineState() {
  bool status = widgets_->checkBoxLineDrawing->isChecked();

  if (status) {
    drawLine();
  }

  widgets_->graph->graph(1)->setVisible(status);
  widgets_->graph->replot();
}

void GraphUI::drawGraph() {
  QString input = widgets_->inputLineEdit->text();
  double countPOINTS = widgets_->data[POINTS]->text().toDouble();
  double xMin = widgets_->data[SCOPE_MIN]->text().toDouble();
  double xMax = widgets_->data[SCOPE_MAX]->text().toDouble();
  double yMin = widgets_->data[RANGE_MIN]->text().toDouble();
  double yMax = widgets_->data[RANGE_MAX]->text().toDouble();

  bool status =
      controller_->setInput(input, countPOINTS, xMin, xMax, yMin, yMax);

  if (status) {
    controller_->Calculate();
    widgets_->graph->graph(0)->setData(controller_->getCollectionX(),
                                       controller_->getCollectionY());
  }

  widgets_->graph->graph(0)->setVisible(true);
  widgets_->graph->replot();
}
