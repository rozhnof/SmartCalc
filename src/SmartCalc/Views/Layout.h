#pragma once


#include <QWidget>
#include <QLabel>
#include <QLineEdit>
#include <iostream>

using namespace std;

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

    Layout() {}

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

        _xRemaining = _countXRemaining = ((_xMax - _x0) - (_rightSpacing + _leftSpacing) - ((_columns - 1) * _horizontalSpacing)) % _widgetWidth;
        _yRemaining = _countYRemaining = ((_yMax - _y0) - (_bottomSpacing + _aboveSpacing) - ((_rows - 1) * _verticalSpacing)) % _widgetHeight;
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

    void AddWidget(QWidget *widget, double colSpan = 1, double rowSpan = 1) {
        _currentColSpan = colSpan;
        _currentRowSpan = rowSpan;
        AddWidgetWithSize(widget, _widgetWidth * colSpan + _horizontalSpacing * (colSpan - 1), _widgetHeight * rowSpan + _verticalSpacing * (rowSpan - 1));
    }

    void NextRow() {
        _columnsCounter = 0;
        _countYRemaining--;
        _countXRemaining = _xRemaining;
        _currentX = _x0 + _leftSpacing;

        _rowsCounter++;
        _currentY += (_lastHeight + _verticalSpacing);
    }


    void AddWidgetWithSize(QWidget *widget, int width, int height) {
        if (_countXRemaining > 0) {
            width++;
            _countXRemaining--;
        }
        if (_countYRemaining > 0) {
            height++;
        }

        widget->setGeometry(_currentX, _currentY, width, height);
        _lastWidth = width;
        _lastHeight = height;

        _columnsCounter += _currentColSpan;
        SetDefaultSpan();

        if (_columnsCounter >= _columns) {
            NextRow();
        } else {
            _currentX += (width + _horizontalSpacing);
        }

        widget->show();
    }

    void SetDefaultSpan() {
        _currentColSpan = 1;
        _currentRowSpan = 1;
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


    void SetTitle(QWidget* widget, QWidget* title, AlignH alignH, AlignV alignV, int fontSize, int horizontalSpacing, int verticalSpacing) {
        QFont font;
        font.setPointSize(fontSize);
        title->setFont(font);

        int x = 0;
        int y = 0;
        int widthHint = title->sizeHint().width();
        int heightHint = title->sizeHint().height();

        if (alignH == Left) {
            x = widget->x() + horizontalSpacing;
        } else if (alignH == Right) {
            x = widget->x() + widget->width() - widthHint - horizontalSpacing;
        } else if (alignH == CenterH) {
            x = widget->x() + widget->width() / 2 - widthHint / 2;
        }

        if (alignV == Above) {
            y = widget->y() - heightHint + verticalSpacing;
        } else if (alignV == Bottom) {
            y = widget->y() + widget->height() + verticalSpacing;
        } else if (alignV == CenterV) {
            y = widget->y() + widget->height() / 2 - heightHint / 2;
        }
        title->setGeometry(x, y, widthHint, heightHint);
    }

    void SetField(QWidget* widget, QWidget* field, AlignH align, int spacing) {
        int x = 0;
        int y = 0;

        int height = 0;
        int width = 0;

        width = widget->width() - spacing;
        height = widget->height();
        y = widget->y() + widget->height() / 2 - height / 2;

        if (align == Left) {
            x = widget->x() + spacing;
        } else if (align == Right) {
            x = widget->x() + widget->width() - width - spacing;
        } else if (align == CenterH) {
            x = widget->x() + widget->width() / 2 - width / 2;
        }

        field->setGeometry(x, y, width, height);
    }
};
