#ifndef IWIDGETS_H
#define IWIDGETS_H


#include <QVector>
#include <QPushButton>
#include <unordered_map>
#include <QLabel>
#include <QMainWindow>
#include "qcustomplot.h"
#include <QtCharts>
#include <QColor>

using namespace std;



class Layout
{
private:
    double _rowsCount = 0;
    double _colsCount = 0;
    int _rowsMax;
    int _colsMax;

    int _spacerX;
    int _spacerY;

    int _elemWidth;
    int _elemHeight;

    int _currentX;
    int _currentY;

    int _x0;

    int _remainingX;
    int _remainingY;

    int _remainingXcount;
    int _remainingYcount;

public:
    enum Location {
        Centre,
        Left,
        Right,
    };

    Layout(int x0, int y0, int xMax, int yMax, int rows, int cols, int spacerX = 0, int spacerY = 0) :
        _rowsMax(rows), _colsMax(cols), _spacerX(spacerX), _spacerY(spacerY), _x0(x0)
    {
        int generalWidth = (xMax - x0) - (_spacerX * (_colsMax - 1));
        int generalHeight = (yMax - y0) - (_spacerY * (_rowsMax - 1));

        _elemWidth = generalWidth / _colsMax;
        _elemHeight = generalHeight / _rowsMax;

        _remainingX = _remainingXcount = generalWidth % _colsMax;
        _remainingY = _remainingYcount = generalHeight % _rowsMax;

        _currentX = _x0;
        _currentY = y0;
    }


    void AddWidget(QWidget* widget, double width = 1, double height = 1) {
        int currentWidth = (_elemWidth * width) + ((width - 1) * _spacerX);
        int currentHeight = (_elemHeight * height) + ((height - 1) * _spacerY);

        if (_remainingXcount-- > 0) currentWidth += 1;
        if (_remainingYcount > 0) currentHeight += 1;

        widget->setGeometry(_currentX, _currentY, currentWidth, currentHeight);

        _colsCount += width;
        _currentX += currentWidth + _spacerX;

        if (_colsCount >= _colsMax) {
            _colsCount = 0;
            _rowsCount += height;

            _currentY += currentHeight + _spacerY;
            _currentX = _x0;
            _remainingXcount = _remainingX;
            _remainingYcount--;
        }
    }

    void AddWidget(QWidget* widget, QWidget *pWidget, int spacerX, int spacerY, Location loc = Centre, int width = 0) {
        int x0 = 0;
        int x1 = 0;

        int y0 = 0;
        int y1 = 0;

        int height = 0;

        if (loc == Centre) {
            x0 = spacerX;
            x1 = pWidget->width() - spacerX;

            width = x1 - x0;
            height = y1 - y0;
        } else if (loc == Left) {
            x0 = spacerX;
            x1 = x0 + width;
        } else if (loc == Right) {
            x1 = pWidget->width() - spacerX;
            x0 = x1 - width;
        }

        y0 = spacerY;
        y1 = pWidget->height() - spacerY;
        height = y1 - y0;

        widget->setGeometry(x0, y0, width, height);
    }
};



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



typedef struct CalcWidgets {
    QMainWindow *calcWindow;

    QLabel *Input;
    unordered_map<int, QPushButton*> calcButtons;
} CalcWidgets;

typedef struct GraphWidgets  {
    QWidget *graphWindow;
    QCustomPlot *graph;

    QLineEdit *Input;
    QCheckBox* drawingLine;
    unordered_map<int, QLabel*> titles;
    unordered_map<int, QDoubleSpinBox*> values;

} GraphWidgets;

typedef struct CreditCalcWidgets  {
    QWidget *creditCalcWindow;
    ChartView* chartView;

    unordered_map<int, QTextEdit*> box;
    unordered_map<int, QLabel*> boxTitle;
    unordered_map<int, QLineEdit*> boxText;

    QVector<double> bodyPayments;
    QVector<double> percentPayments;

} CreditCalcWidgets;


typedef struct DepositCalcWidgets  {
    QWidget *depositCalcWindow;

    QLabel *label;
} DepositCalcWidgets;


enum CreditCalcObjectsEnum {
    CreditSum,
    CreditTerm,
    InterestRate,
    TotalPayment,
    Overpayment,
    MonthlyPayment
};


enum GraphObjectsEnum {
    ScopeMin,
    ScopeMax,
    RangeMin,
    RangeMax,
    InputX,
    Points
};

enum CalcObjectsEnum {
    Button0,
    Button1,
    Button2,
    Button3,
    Button4,
    Button5,
    Button6,
    Button7,
    Button8,
    Button9,
    ButtonDot,

    ButtonX,

    ButtonSin,
    ButtonCos,
    ButtonTan,
    ButtonAsin,
    ButtonAcos,
    ButtonAtan,
    ButtonLog,
    ButtonLn,
    ButtonSqrt,

    ButtonSum,
    ButtonSub,
    ButtonMul,
    ButtonDiv,
    ButtonMod,
    ButtonPow,
    ButtonFactorial,

    ButtonOpenBracket,
    ButtonCloseBracket,

    ButtonC,
    ButtonAC,
    ButtonUnaryOperator,
    ButtonEXP,
    ButtonResult,
};

#endif // IWIDGETS_H
