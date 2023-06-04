#ifndef LAYOUT_H
#define LAYOUT_H

#include <QWidget>
#include <QLabel>
#include <QLineEdit>
#include <iostream>
using namespace std;

class Layout2
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

public:

    Layout2() {}

    void SetStartPoints(int x0, int y0) {
        _x0 = x0;
        _y0 = y0;

        _currentX = x0;
        _currentY = y0;
    }

    void SetEndPoints(int xMax, int yMax) {
        _xMax = xMax;
        _yMax = yMax;
    }

    void SetRows(int rows) {
        _rows = rows;
    }

    void SetColumns(int columns) {
        _columns = columns;
    }

    void SetHorizontalSpacing(int horizontalSpacing) {
        _horizontalSpacing = horizontalSpacing;
    }

    void SetVerticalSpacing(int verticalSpacing) {
        _verticalSpacing = verticalSpacing;
    }

    void SetDefaultElementSize(int width, int height) {
        _widgetWidth = width;
        _widgetHeight = height;
    }

    void SetAutoSize() {
        _widgetWidth = ((_xMax - _rightSpacing) - (_x0 + _leftSpacing) - ((_columns - 1) * _horizontalSpacing)) / _columns;
        _widgetHeight = ((_yMax - _bottomSpacing) - (_y0 + _aboveSpacing) - ((_rows - 1) * _verticalSpacing)) / _rows;
    }

    void SetLeftSpacing(int spacing) {
        _leftSpacing = spacing;
        _currentX += spacing;
    }

    void SetRightSpacing(int spacing) {
        _rightSpacing = spacing;
    }

    void SetAboveSpacing(int spacing) {
        _aboveSpacing = spacing;
        _currentY += spacing;
    }

    void SetBottomSpacing(int spacing) {
        _bottomSpacing = spacing;
    }

    void ChangeColumns(int columns) {
        SetColumns(columns);
        SetAutoSize();
    }

    void AddWidget(QWidget *widget, int rowSpan = 1, int columnSpan = 1) {
        AddWidgetWithSize(widget, _widgetWidth * rowSpan, _widgetHeight * columnSpan);
    }

    void AddWidgetWithSize(QWidget *widget, int width, int height) {
        widget->setGeometry(_currentX, _currentY, width, height);

        _columnsCounter += (width / _widgetWidth) + (1 && (width % _widgetWidth));

        if (_columnsCounter >= _columns) {
            _columnsCounter = 0;
            _currentX = _x0 + _leftSpacing;

            _rowsCounter++;
            _currentY += (height + _verticalSpacing);
        } else {
            _currentX += (width + _horizontalSpacing);
        }
    }

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


    void AddTitle(QWidget* widget, QWidget* title, AlignH align0, AlignV align1, int fontSize, int horizontalSpacing, int verticalSpacing) {
        QFont font;
        font.setPointSize(fontSize);
        title->setFont(font);

        int x = 0;
        int y = 0;
        int widthHint = title->sizeHint().width();
        int heightHint = title->sizeHint().height();

        if (align0 == Left) {
            x = widget->x() + horizontalSpacing;
        } else if (align0 == Right) {
            x = widget->x() + widget->width() - widthHint - horizontalSpacing;
        } else if (align0 == CenterH) {
            x = widget->x() + widget->width() / 2 - widthHint / 2;
        }

        if (align1 == Above) {
            y = widget->y() - heightHint + verticalSpacing;
        } else if (align1 == Bottom) {
            y = widget->y() + widget->height() + verticalSpacing;
        } else if (align1 == CenterV) {
            y = widget->y() + widget->height() / 2 - heightHint / 2;
        }
        title->setGeometry(x, y, widthHint, heightHint);
    }

    void AddField(QWidget* widget, QWidget* field, AlignH align, int spacing = 0) {
        int x = 0;
        int width = widget->width();

        int y = widget->y();
        int height = widget->height();

        if (align == AlignH::Left) {
            x = widget->x() + spacing;
        } else if (align == AlignH::Right) {
            x = widget->x();
        } else if (align == AlignH::CenterH) {
            x = widget->x() + widget->width() / 2 - width / 2;
        }
        width -= spacing;

        field->setGeometry(x, y, width, height);
    }
};


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
        Center,
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

    void AddWidget(QWidget* widget, QWidget *pWidget, int spacerX, int spacerY, Location loc = Center, int width = 0) {
        int x0 = 0;
        int x1 = 0;

        int y0 = 0;
        int y1 = 0;

        int height = 0;

        if (loc == Center) {
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

#endif // LAYOUT_H
