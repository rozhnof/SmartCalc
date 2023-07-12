#include "Layout.h"

void Layout::setStartPoints(int x0, int y0) {
  x0_ = x0;
  y0_ = y0;

  currentX_ = x0;
  currentY_ = y0;
}

void Layout::setEndPoints(int xMax, int yMax) {
  xMax_ = xMax;
  yMax_ = yMax;
}

void Layout::setRows(int rows) { rows_ = rows; }

void Layout::setColumns(int columns) { columns_ = columns; }

void Layout::setHorizontalSpacing(int horizontalSpacing) {
  horizontalSpacing_ = horizontalSpacing;
}

void Layout::setVerticalSpacing(int verticalSpacing) {
  verticalSpacing_ = verticalSpacing;
}

void Layout::setDefaultElementSize(int width, int height) {
  widgetWidth_ = width;
  widgetHeight_ = height;
}

void Layout::setAutoSize() {
  widgetWidth_ = ((xMax_ - rightSpacing_) - (x0_ + leftSpacing_) -
                  ((columns_ - 1) * horizontalSpacing_)) /
                 columns_;
  widgetHeight_ = ((yMax_ - bottomSpacing_) - (y0_ + aboveSpacing_) -
                   ((rows_ - 1) * verticalSpacing_)) /
                  rows_;

  xRemaining_ = countXRemaining_ =
      ((xMax_ - x0_) - (rightSpacing_ + leftSpacing_) -
       ((columns_ - 1) * horizontalSpacing_)) %
      widgetWidth_;
  yRemaining_ = countYRemaining_ =
      ((yMax_ - y0_) - (bottomSpacing_ + aboveSpacing_) -
       ((rows_ - 1) * verticalSpacing_)) %
      widgetHeight_;
}

void Layout::setLeftSpacing(int spacing) {
  leftSpacing_ = spacing;
  currentX_ += spacing;
}

void Layout::setRightSpacing(int spacing) { rightSpacing_ = spacing; }

void Layout::setAboveSpacing(int spacing) {
  aboveSpacing_ = spacing;
  currentY_ += spacing;
}

void Layout::setBottomSpacing(int spacing) { bottomSpacing_ = spacing; }

void Layout::ChangeColumns(int columns) {
  setColumns(columns);
  setAutoSize();
}

void Layout::AddWidget(QWidget *widget, double colSpan, double rowSpan) {
  currentColSpan_ = colSpan;
  currentRowSpan_ = rowSpan;
  AddWidgetWithSize(widget,
                    widgetWidth_ * colSpan + horizontalSpacing_ * (colSpan - 1),
                    widgetHeight_ * rowSpan + verticalSpacing_ * (rowSpan - 1));
}

void Layout::NextRow() {
  columnsCounter_ = 0;
  countYRemaining_--;
  countXRemaining_ = xRemaining_;
  currentX_ = x0_ + leftSpacing_;

  rowsCounter_++;
  currentY_ += (lastHeight_ + verticalSpacing_);
}

void Layout::AddWidgetWithSize(QWidget *widget, int width, int height) {
  if (countXRemaining_ > 0) {
    width++;
    countXRemaining_--;
  }
  if (countYRemaining_ > 0) {
    height++;
  }

  widget->setGeometry(currentX_, currentY_, width, height);
  lastWidth_ = width;
  lastHeight_ = height;

  columnsCounter_ += currentColSpan_;
  setDefaultSpan();

  if (columnsCounter_ >= columns_) {
    NextRow();
  } else {
    currentX_ += (width + horizontalSpacing_);
  }

  widget->show();
}

void Layout::setDefaultSpan() {
  currentColSpan_ = 1;
  currentRowSpan_ = 1;
}

void Layout::SetTitle(QWidget *widget, QWidget *title, AlignH alignH,
                      AlignV alignV, int fontSize, int horizontalSpacing,
                      int verticalSpacing) {
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

void Layout::SetField(QWidget *widget, QWidget *field, AlignH align,
                      int spacing) {
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
