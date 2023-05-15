#ifndef CHARTVIEW_H
#define CHARTVIEW_H

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
    ChartView(QWidget* parent) {
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

    void show() {
        chartView->show();
    }

    void setGeometry(int ax, int ay, int aw, int ah)
    {
        chartView->setGeometry(ax, ay, aw, ah);
    }

    void Clear() {
        bodyBar->remove(0, bodyBar->count());
        percentBar->remove(0, percentBar->count());
        chart->removeSeries(series);
    }

    void SetData(QVector<double>& newBodyBar, QVector<double>& newPercentBar) {
        if (series->count()) Clear();

        bodyBar->append(newBodyBar);
        percentBar->append(newPercentBar);

        axisY->setMax(newBodyBar[0] + newPercentBar[0]);

        series->append(bodyBar);
        series->append(percentBar);

        chart->addSeries(series);
        series->attachAxis(axisY);
    }

    void SetBarColor(QColor bodyBarColor, QColor percentBarColor) {
        bodyBar->setColor(bodyBarColor);
        percentBar->setColor(percentBarColor);
    }

    void SetBorderBarColor(QColor bodyBorderBarColor, QColor percentBorderBarColor) {
        bodyBar->setBorderColor(bodyBorderBarColor);
        percentBar->setBorderColor(percentBorderBarColor);
    }

    void SetLabelsColor(QColor color) {
        axisY->setLabelsColor(color);
    }

    void SetLinePenColor(QColor color) {
        axisY->setLinePenColor(color);
    }

    void SetGridLineColor(QColor color) {
        axisY->setGridLineColor(color);
    }

    void SetBarWidth(qreal width) {
        series->setBarWidth(width);
    }

    ~ChartView() {
        delete series;
        delete bodyBar;
        delete percentBar;

    }
};

#endif // CHARTVIEW_H
