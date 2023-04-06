//#include "Graph.h"
//#include "ui_Graph.h"
//#include "../Controllers/Graph/Graph.h"

//Graph::Graph(QWidget *parent) : QWidget(parent), ui(new Ui::Graph)
//{
//    ui->setupUi(this);
//    graph = new QCustomPlot(ui->graphicsView);
//    graph->setFixedSize(800, 600);
//    graph->setInteraction(QCP::iRangeZoom,true);
//    graph->setInteraction(QCP::iRangeDrag, true);

//    graph->xAxis->setLabel("x");
//    graph->yAxis->setLabel("y");
//    graph->xAxis->setRange(-5, 5);
//    graph->yAxis->setRange(-5, 5);

//    connect(ui->input_x, SIGNAL(valueChanged(double)), this, SLOT(DrawLine()));
//}

//void Graph::DrawLine() {
//    QVector <double>x(2, ui->input_x->text().toDouble()), y(2);
//    y[0] = ui->RangeMin->text().toDouble();
//    y[1] = ui->RangeMax->text().toDouble();

//    graph->addGraph();
//    graph->graph(0)->setData(x, y);
//    graph->replot();
//}

//Graph::~Graph()
//{
//    delete ui;
//}

