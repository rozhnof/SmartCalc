#pragma once


#include <QWidget>
#include <QLabel>
#include <QLineEdit>
#include <iostream>


class Layout
{
private:
    int _x0 = 0;
    int _y0 = 0;

    int _xMax;
    int _yMax;

    int _rows = 1;
    int _columns = 1;

    int _rowsCounter = 0;
    int _columnsCounter = 0;

    int _horizontalSpacing = 0;
    int _verticalSpacing = 0;

    int _leftSpacing = 0;
    int _rightSpacing = 0;
    int _aboveSpacing = 0;
    int _bottomSpacing = 0;

    int _widgetWidth;
    int _widgetHeight;

    int _currentX = 0;
    int _currentY = 0;

    int _currentColSpan = 1;
    int _currentRowSpan = 1;

    int _xRemaining = 0;
    int _yRemaining = 0;

    int _countXRemaining = 0;
    int _countYRemaining = 0;

    int _lastWidth = 0;
    int _lastHeight = 0;
public:

    Layout();

    void SetStartPoints(int x0, int y0);

    void SetEndPoints(int xMax, int yMax);

    void SetRows(int rows);

    void SetColumns(int columns);

    void SetHorizontalSpacing(int horizontalSpacing);

    void SetVerticalSpacing(int verticalSpacing);

    void SetDefaultElementSize(int width, int height);

    void SetAutoSize();

    void SetLeftSpacing(int spacing);

    void SetRightSpacing(int spacing);

    void SetAboveSpacing(int spacing);

    void SetBottomSpacing(int spacing);

    void ChangeColumns(int columns);

    void AddWidget(QWidget *widget, double colSpan = 1, double rowSpan = 1);

    void NextRow();


    void AddWidgetWithSize(QWidget *widget, int width, int height);

    void SetDefaultSpan();

    enum AlignH {
        Left,
        Right,
        CenterH
    };

    enum AlignV {
        Above,
        Bottom,
        CenterV
    };


    void SetTitle(QWidget* widget, QWidget* title, AlignH alignH, AlignV alignV, int fontSize, int horizontalSpacing, int verticalSpacing);

    void SetField(QWidget* widget, QWidget* field, AlignH align, int spacing);
};
