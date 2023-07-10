#pragma once


#include <QCalendarWidget>
#include <QPainter>
#include <QHeaderView>
#include <QTextCharFormat>
#include <QToolButton>
#include <iostream>
#include <QSpinBox>
#include <QMenu>
#include <QLineEdit>
#include <QLayout>
#include <QScrollArea>
#include <QHBoxLayout>
#include <QComboBox>
#include "Layout.h"


class Calendar : public QCalendarWidget
{
public:

    Calendar(QWidget *parent);

    void SettingsUp();

    void SetWeekdayTextColor(QColor color);

    void RemadeLayout();

    void SetStyle();
};
