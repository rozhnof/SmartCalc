#pragma once

#include <QLabel>
#include <QLineEdit>
#include <QWidget>
#include <iostream>

class Layout {
 private:
  int x0_ = 0;
  int y0_ = 0;

  int xMax_;
  int yMax_;

  int rows_ = 1;
  int columns_ = 1;

  int rowsCounter_ = 0;
  int columnsCounter_ = 0;

  int horizontalSpacing_ = 0;
  int verticalSpacing_ = 0;

  int leftSpacing_ = 0;
  int rightSpacing_ = 0;
  int aboveSpacing_ = 0;
  int bottomSpacing_ = 0;

  int widgetWidth_;
  int widgetHeight_;

  int currentX_ = 0;
  int currentY_ = 0;

  int currentColSpan_ = 1;
  int currentRowSpan_ = 1;

  int xRemaining_ = 0;
  int yRemaining_ = 0;

  int countXRemaining_ = 0;
  int countYRemaining_ = 0;

  int lastWidth_ = 0;
  int lastHeight_ = 0;

 public:
  enum AlignH { Left, Right, CenterH };
  enum AlignV { Above, Bottom, CenterV };

  void setStartPoints(int x0, int y0);
  void setEndPoints(int xMax, int yMax);
  void setRows(int rows);
  void setColumns(int columns);
  void setHorizontalSpacing(int horizontalSpacing);
  void setVerticalSpacing(int verticalSpacing);
  void setDefaultElementSize(int width, int height);
  void setAutoSize();
  void setLeftSpacing(int spacing);
  void setRightSpacing(int spacing);
  void setAboveSpacing(int spacing);
  void setBottomSpacing(int spacing);
  void setDefaultSpan();

  void ChangeColumns(int columns);
  void NextRow();

  void AddWidget(QWidget* widget, double colSpan = 1, double rowSpan = 1);
  void AddWidgetWithSize(QWidget* widget, int width, int height);

  void SetTitle(QWidget* widget, QWidget* title, AlignH alignH, AlignV alignV,
                int fontSize, int horizontalSpacing, int verticalSpacing);
  void SetField(QWidget* widget, QWidget* field, AlignH align, int spacing);
};
