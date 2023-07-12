#include "ChartView.h"

ChartView::ChartView(QWidget *parent) {
  chart_ = new QChart;
  chartView_ = new QChartView(chart_);

  series_ = new QStackedBarSeries();
  bodyBar_ = new QBarSet("Body");
  percentBar_ = new QBarSet("Percent");
  axisY_ = new QValueAxis();

  chartView_->setRenderHint(QPainter::Antialiasing);
  chart_->setAnimationOptions(QChart::SeriesAnimations);
  chart_->setTheme(QChart::ChartThemeBlueNcs);
  chart_->legend()->setVisible(true);
  chart_->legend()->setAlignment(Qt::AlignBottom);

  axisY_->setMin(0);
  chart_->addAxis(axisY_, Qt::AlignLeft);

  chart_->setBackgroundVisible(false);
  chartView_->setParent(parent);
}

ChartView::~ChartView() {
  delete chart_;
  delete chartView_;
  delete series_;
  delete axisY_;
  delete bodyBar_;
  delete percentBar_;
}

void ChartView::show() { chartView_->show(); }

void ChartView::setGeometry(int ax, int ay, int aw, int ah) {
  chartView_->setGeometry(ax, ay, aw, ah);
}

void ChartView::clear() {
  bodyBar_->remove(0, bodyBar_->count());
  percentBar_->remove(0, percentBar_->count());
  chart_->removeSeries(series_);
}

void ChartView::setData(QVector<double> newBodyBar,
                        QVector<double> newPercentBar) {
  if (series_->count()) clear();

  bodyBar_->append(newBodyBar);
  percentBar_->append(newPercentBar);

  axisY_->setMax(newBodyBar[0] + newPercentBar[0]);

  series_->append(bodyBar_);
  series_->append(percentBar_);

  chart_->addSeries(series_);
  series_->attachAxis(axisY_);
}

void ChartView::setBarColor(QColor bodyBarColor, QColor percentBarColor) {
  bodyBar_->setColor(bodyBarColor);
  percentBar_->setColor(percentBarColor);
}

void ChartView::setBorderBarColor(QColor bodyBorderBarColor,
                                  QColor percentBorderBarColor) {
  bodyBar_->setBorderColor(bodyBorderBarColor);
  percentBar_->setBorderColor(percentBorderBarColor);
}

void ChartView::setLabelsColor(QColor color) { axisY_->setLabelsColor(color); }

void ChartView::setLinePenColor(QColor color) {
  axisY_->setLinePenColor(color);
}

void ChartView::setGridLineColor(QColor color) {
  axisY_->setGridLineColor(color);
}

void ChartView::setBarWidth(qreal width) { series_->setBarWidth(width); }
