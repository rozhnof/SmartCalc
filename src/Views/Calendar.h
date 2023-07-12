#pragma once

#include <QCalendarWidget>
#include <QComboBox>
#include <QHBoxLayout>
#include <QHeaderView>
#include <QLayout>
#include <QLineEdit>
#include <QMenu>
#include <QPainter>
#include <QScrollArea>
#include <QSpinBox>
#include <QTextCharFormat>
#include <QToolButton>
#include <iostream>

#include "Layout.h"

class Calendar : public QCalendarWidget {
 public:
  Calendar(QWidget *parent);

  void settingsUp();

  void remadeLayout();

  void setWeekdayTextColor(QColor color);
  void setStyle();
};
