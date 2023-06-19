#ifndef CALENDAR_H
#define CALENDAR_H


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
    Calendar(QWidget *parent) : QCalendarWidget(parent) {
        this->setGridVisible(false);
        this->setSelectionMode(QCalendarWidget::SingleSelection);
        this->setFirstDayOfWeek(Qt::DayOfWeek::Monday);
        this->setLocale(QLocale("en_US"));
        this->setVerticalHeaderFormat(QCalendarWidget::NoVerticalHeader);
        this->setMaximumDate(QDate(2100, 1, 1));
        this->setMinimumDate(QDate(2000, 1, 1));

        SetWeekdayTextColor(QColor(108, 112, 119));

        SetButtons();
    }

    void SetWeekdayTextColor(QColor color) {
        QTextCharFormat format;
        format.setForeground(color);
        for (int i = Qt::DayOfWeek::Monday; i <= Qt::DayOfWeek::Sunday; i++) {
            this->setWeekdayTextFormat(static_cast<Qt::DayOfWeek>(i), format);
        }
    }

    void paintCell(QPainter *painter, const QRect &rect, QDate date) const override {
        painter->save();

        painter->setBrush(QColor(255, 255, 255));
        painter->drawRect(rect);

        if (date == selectedDate()) {
            painter->setBrush(QColor(223, 226, 230));
            painter->drawRoundedRect(rect, 5, 5);
        }

        if (date.month() == selectedDate().month()) {
            painter->setPen(QColor(40, 43, 48));
            painter->drawText(rect, Qt::TextSingleLine | Qt::AlignCenter, QString::number(date.day()));
        } else {
            painter->setPen(QColor(132, 135, 141));
            painter->drawText(rect, Qt::TextSingleLine | Qt::AlignCenter, QString::number(date.day()));
        }
        painter->restore();
    }

    void SetButtons() {
        QWidget *calendar = this->findChild<QWidget*>("qt_calendar_calendarview");
        QWidget *calendarArea = this->findChild<QWidget*>("qt_calendar_navigationbar");

        QToolButton *toolButtonLeft = this->findChild<QToolButton*>("qt_calendar_prevmonth");
        QToolButton *toolButtonRight = this->findChild<QToolButton*>("qt_calendar_nextmonth");
        QToolButton *yearBox = this->findChild<QToolButton*>("qt_calendar_yearbutton");
        QSpinBox *yearEdit = this->findChild<QSpinBox*>("qt_calendar_yearedit");
        QToolButton *monthMenu = this->findChild<QToolButton*>("qt_calendar_monthbutton");


        QLayout *horizontalBar = calendarArea->layout();

        horizontalBar->removeWidget(toolButtonLeft);
        horizontalBar->removeWidget(toolButtonRight);
        horizontalBar->removeWidget(yearBox);
        horizontalBar->removeWidget(monthMenu);
        horizontalBar->removeWidget(yearEdit);

        QLayout *layout = this->layout();
        layout->removeWidget(calendar);
        layout->removeWidget(calendarArea);


        QSpacerItem *horizontalSpacer = new QSpacerItem(QSpacerItem(this->width()/2, 0, QSizePolicy::MinimumExpanding, QSizePolicy::Fixed));

        horizontalBar->addWidget(yearBox);
        horizontalBar->addWidget(monthMenu);

        horizontalBar->addItem(horizontalSpacer);

        horizontalBar->addWidget(toolButtonLeft);
        horizontalBar->addWidget(toolButtonRight);

        layout->addWidget(calendarArea);
        layout->addWidget(calendar);

        this->setStyleSheet("QWidget#qt_calendar_navigationbar"
                            "{"
                            "   background-color: rgb(255,255,255);"
                            "   color: rgb(40, 43, 48);"
                            "}"
                            "QCalendarWidget QTableView"
                            "{"
                            "    background-color: white;"
                            "}");

        yearBox->setStyleSheet("QToolButton { "
                               "    color: rgb(89, 100, 231);"
                               "}"
                               "QToolButton:hover {"
                               "  background-color: rgb(230,230,230);"
                               "  border: 1px rgb(230,230,230);"
                               "  border-radius: 5;"
                               "}"
                               "");
        yearEdit->setStyleSheet("QSpinBox { "
                                "   color: rgb(89, 100, 231);"
                                "   background-color: rgb(255,255,255);"
                                "   font-weight: bold;"
                                "}"
                                "QSpinBox:focus { "
                                "   border: none; "
                                "   outline: none;"
                                "}");
        monthMenu->setStyleSheet("QToolButton { "
                                 "  color: rgb(89, 100, 231);"
                                 "}"
                                 "QToolButton:hover {"
                                 "  background-color: rgb(230,230,230);"
                                 "  border: 1px rgb(230,230,230);"
                                 "  border-radius: 5;"
                                 "}"
                                 "QToolButton::menu-indicator {"
                                 "  width:0px;"
                                 "}"
                                 "QToolButton QMenu {"
                                 "  background-color: rgb(255, 255, 255);"
                                 "  color: rgb(72, 75, 79);"
                                 "  border: none;"
                                 "  border-radius: 5;"
                                 "}"
                                 "QToolButton QMenu::item {"
                                 "  background-color: rgb(255, 255, 255);"
                                 "  border-radius: 5px;"
                                 "}"
                                 "QToolButton QMenu::item:selected {"
                                 "  background-color: rgb(230,230,230);"
                                 "  border: 1px rgb(230,230,230);"
                                 "  border-radius: 5;"
                                 "}"
                                 );



        yearEdit->setButtonSymbols(QAbstractSpinBox::NoButtons);

        toolButtonLeft->setIcon(QIcon(":/buttons/left.png"));
        toolButtonRight->setIcon(QIcon(":/buttons/right.png"));

    }
};

#endif // CALENDAR_H
