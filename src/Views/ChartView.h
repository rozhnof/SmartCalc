#pragma once

#include <QColor>
#include <QtCharts>

class ChartView {
 private:
  QChart *chart_;
  QChartView *chartView_;
  QStackedBarSeries *series_;
  QValueAxis *axisY_;
  QBarSet *bodyBar_;
  QBarSet *percentBar_;

 public:
  ChartView(QWidget *parent);
  ~ChartView();

  void show();
  void clear();

  void setGeometry(int ax, int ay, int aw, int ah);
  void setData(QVector<double> newBodyBar, QVector<double> newPercentBar);
  void setBarColor(QColor bodyBarColor, QColor percentBarColor);
  void setBorderBarColor(QColor bodyBorderBarColor,
                         QColor percentBorderBarColor);
  void setLabelsColor(QColor color);
  void setLinePenColor(QColor color);
  void setGridLineColor(QColor color);
  void setBarWidth(qreal width);
};
