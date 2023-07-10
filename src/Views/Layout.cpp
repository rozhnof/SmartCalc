#include "Layout.h"


void Layout::SetStartPoints(int x0, int y0) {
    _x0 = x0;
    _y0 = y0;

    _currentX = x0;
    _currentY = y0;
}

void Layout::SetEndPoints(int xMax, int yMax) {
    _xMax = xMax;
    _yMax = yMax;
}

void Layout::SetRows(int rows) {
    _rows = rows;
}

void Layout::SetColumns(int columns) {
    _columns = columns;
}

void Layout::SetHorizontalSpacing(int horizontalSpacing) {
    _horizontalSpacing = horizontalSpacing;
}

void Layout::SetVerticalSpacing(int verticalSpacing) {
    _verticalSpacing = verticalSpacing;
}

void Layout::SetDefaultElementSize(int width, int height) {
    _widgetWidth = width;
    _widgetHeight = height;
}

void Layout::SetAutoSize() {
    _widgetWidth = ((_xMax - _rightSpacing) - (_x0 + _leftSpacing) - ((_columns - 1) * _horizontalSpacing)) / _columns;
    _widgetHeight = ((_yMax - _bottomSpacing) - (_y0 + _aboveSpacing) - ((_rows - 1) * _verticalSpacing)) / _rows;

    _xRemaining = _countXRemaining = ((_xMax - _x0) - (_rightSpacing + _leftSpacing) - ((_columns - 1) * _horizontalSpacing)) % _widgetWidth;
    _yRemaining = _countYRemaining = ((_yMax - _y0) - (_bottomSpacing + _aboveSpacing) - ((_rows - 1) * _verticalSpacing)) % _widgetHeight;
}

void Layout::SetLeftSpacing(int spacing) {
    _leftSpacing = spacing;
    _currentX += spacing;
}

void Layout::SetRightSpacing(int spacing) {
    _rightSpacing = spacing;
}

void Layout::SetAboveSpacing(int spacing) {
    _aboveSpacing = spacing;
    _currentY += spacing;
}

void Layout::SetBottomSpacing(int spacing) {
    _bottomSpacing = spacing;
}

void Layout::ChangeColumns(int columns) {
    SetColumns(columns);
    SetAutoSize();
}

void Layout::AddWidget(QWidget *widget, double colSpan, double rowSpan) {
    _currentColSpan = colSpan;
    _currentRowSpan = rowSpan;
    AddWidgetWithSize(widget, _widgetWidth * colSpan + _horizontalSpacing * (colSpan - 1), _widgetHeight * rowSpan + _verticalSpacing * (rowSpan - 1));
}

void Layout::NextRow() {
    _columnsCounter = 0;
    _countYRemaining--;
    _countXRemaining = _xRemaining;
    _currentX = _x0 + _leftSpacing;

    _rowsCounter++;
    _currentY += (_lastHeight + _verticalSpacing);
}

void Layout::AddWidgetWithSize(QWidget *widget, int width, int height) {
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

void Layout::SetDefaultSpan() {
    _currentColSpan = 1;
    _currentRowSpan = 1;
}

void Layout::SetTitle(QWidget *widget, QWidget *title, AlignH alignH, AlignV alignV, int fontSize, int horizontalSpacing, int verticalSpacing) {
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

void Layout::SetField(QWidget *widget, QWidget *field, AlignH align, int spacing) {
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
