#pragma once


#include <QtCharts>
#include <QColor>


class ChartView {

    QChart* chart;
    QChartView *chartView;
    QStackedBarSeries *series;
    QValueAxis *axisY;
    QBarSet *bodyBar;
    QBarSet *percentBar;

public:
    ChartView(QWidget* parent);

    ~ChartView();

    void show();

    void setGeometry(int ax, int ay, int aw, int ah);

    void Clear();

    void SetData(QVector<double> newBodyBar, QVector<double> newPercentBar);

    void SetBarColor(QColor bodyBarColor, QColor percentBarColor);

    void SetBorderBarColor(QColor bodyBorderBarColor, QColor percentBorderBarColor);

    void SetLabelsColor(QColor color);

    void SetLinePenColor(QColor color);

    void SetGridLineColor(QColor color);

    void SetBarWidth(qreal width);
};
