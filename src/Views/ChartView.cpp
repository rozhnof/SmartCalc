#include "ChartView.h"

ChartView::ChartView(QWidget *parent) {
  chart = new QChart;
  chartView = new QChartView(chart);

  series = new QStackedBarSeries();
  bodyBar = new QBarSet("Body");
  percentBar = new QBarSet("Percent");
  axisY = new QValueAxis();

  chartView->setRenderHint(QPainter::Antialiasing);
  chart->setAnimationOptions(QChart::SeriesAnimations);
  chart->setTheme(QChart::ChartThemeBlueNcs);
  chart->legend()->setVisible(true);
  chart->legend()->setAlignment(Qt::AlignBottom);

  axisY->setMin(0);
  chart->addAxis(axisY, Qt::AlignLeft);

  chart->setBackgroundVisible(false);
  chartView->setParent(parent);
}

ChartView::~ChartView() {
  delete chart;
  delete chartView;
  delete series;
  delete axisY;
  delete bodyBar;
  delete percentBar;
}

void ChartView::show() { chartView->show(); }

void ChartView::setGeometry(int ax, int ay, int aw, int ah) {
  chartView->setGeometry(ax, ay, aw, ah);
}

void ChartView::Clear() {
  bodyBar->remove(0, bodyBar->count());
  percentBar->remove(0, percentBar->count());
  chart->removeSeries(series);
}

void ChartView::SetData(QVector<double> newBodyBar,
                        QVector<double> newPercentBar) {
  if (series->count()) Clear();

  bodyBar->append(newBodyBar);
  percentBar->append(newPercentBar);

  axisY->setMax(newBodyBar[0] + newPercentBar[0]);

  series->append(bodyBar);
  series->append(percentBar);

  chart->addSeries(series);
  series->attachAxis(axisY);
}

void ChartView::SetBarColor(QColor bodyBarColor, QColor percentBarColor) {
  bodyBar->setColor(bodyBarColor);
  percentBar->setColor(percentBarColor);
}

void ChartView::SetBorderBarColor(QColor bodyBorderBarColor,
                                  QColor percentBorderBarColor) {
  bodyBar->setBorderColor(bodyBorderBarColor);
  percentBar->setBorderColor(percentBorderBarColor);
}

void ChartView::SetLabelsColor(QColor color) { axisY->setLabelsColor(color); }

void ChartView::SetLinePenColor(QColor color) { axisY->setLinePenColor(color); }

void ChartView::SetGridLineColor(QColor color) {
  axisY->setGridLineColor(color);
}

void ChartView::SetBarWidth(qreal width) { series->setBarWidth(width); }
