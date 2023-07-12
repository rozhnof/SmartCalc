#include "Calendar.h"

Calendar::Calendar(QWidget *parent) : QCalendarWidget(parent) {
  settingsUp();
  remadeLayout();
  setStyle();
}

void Calendar::settingsUp() {
  setGridVisible(false);
  setSelectionMode(QCalendarWidget::SingleSelection);
  setFirstDayOfWeek(Qt::DayOfWeek::Monday);
  setLocale(QLocale("en_US"));
  setVerticalHeaderFormat(QCalendarWidget::NoVerticalHeader);
  setMaximumDate(QDate(2100, 1, 1));
  setMinimumDate(QDate(2000, 1, 1));
  setSelectedDate(QDate::currentDate());
  setWeekdayTextColor(QColor(108, 112, 119));
}

void Calendar::setWeekdayTextColor(QColor color) {
  QTextCharFormat format;
  format.setForeground(color);
  for (int i = Qt::DayOfWeek::Monday; i <= Qt::DayOfWeek::Sunday; i++) {
    setWeekdayTextFormat(static_cast<Qt::DayOfWeek>(i), format);
  }
}

void Calendar::remadeLayout() {
  QWidget *calendar = findChild<QWidget *>("qt_calendar_calendarview");
  QWidget *calendarArea = findChild<QWidget *>("qt_calendar_navigationbar");
  QToolButton *toolButtonLeft =
      findChild<QToolButton *>("qt_calendar_prevmonth");
  QToolButton *toolButtonRight =
      findChild<QToolButton *>("qt_calendar_nextmonth");
  QToolButton *yearBox = findChild<QToolButton *>("qt_calendar_yearbutton");
  QSpinBox *yearEdit = findChild<QSpinBox *>("qt_calendar_yearedit");
  QToolButton *monthMenu = findChild<QToolButton *>("qt_calendar_monthbutton");

  QLayout *horizontalBar = calendarArea->layout();

  horizontalBar->removeWidget(toolButtonLeft);
  horizontalBar->removeWidget(toolButtonRight);
  horizontalBar->removeWidget(yearBox);
  horizontalBar->removeWidget(monthMenu);
  horizontalBar->removeWidget(yearEdit);

  QLayout *layout = this->layout();
  layout->removeWidget(calendar);
  layout->removeWidget(calendarArea);

  QSpacerItem *horizontalSpacer = new QSpacerItem(QSpacerItem(
      width() / 2, 0, QSizePolicy::MinimumExpanding, QSizePolicy::Fixed));
  horizontalBar->addWidget(yearBox);
  horizontalBar->addWidget(monthMenu);
  horizontalBar->addItem(horizontalSpacer);
  horizontalBar->addWidget(toolButtonLeft);
  horizontalBar->addWidget(toolButtonRight);
  layout->addWidget(calendarArea);
  layout->addWidget(calendar);

  yearEdit->setButtonSymbols(QAbstractSpinBox::NoButtons);
  toolButtonLeft->setIcon(QIcon());
  toolButtonRight->setIcon(QIcon());
  toolButtonLeft->setText("<");
  toolButtonRight->setText(">");
}

void Calendar::setStyle() {
  setStyleSheet(
      R"(
            QWidget#qt_calendar_navigationbar {
                background-color: rgb(255,255,255);
            }
            QWidget#qt_calendar_calendarview {
                background-color: rgb(255,255,255);
                color: rgb(154, 156, 161);
            }
            QCalendarWidget QTableView {
                background-color: rgb(255,255,255);
            }
            QCalendarWidget QTableView::item:selected {
                background-color: rgb(223, 226, 230);
                color: rgba(40, 43, 48, 1);
            }
            QCalendarWidget QTableView::item:hover {
                background-color: rgb(239, 241, 243);
                color: rgba(66, 70, 77, 1);
            }
            QToolButton#qt_calendar_prevmonth, QToolButton#qt_calendar_nextmonth {
                background-color: rgba(0, 0, 0, 0);
                color: rgba(66, 70, 77, 1);
            }
            QToolButton#qt_calendar_prevmonth:hover, QToolButton#qt_calendar_nextmonth:hover {
                background-color: rgb(230,230,230);
                border-radius: 5;
            }
            QToolButton#qt_calendar_prevmonth:pressed, QToolButton#qt_calendar_nextmonth:pressed {
                background-color: rgb(220,220,220);
                border-radius: 5;
            }
            QToolButton {
                color: rgb(89, 100, 231);
            }
            QToolButton:hover {
                background-color: rgb(230,230,230);
                border: 1px rgb(230,230,230);
                border-radius: 5;
            }
            QSpinBox {
                color: rgb(89, 100, 231);
                background-color: rgb(255,255,255);
                font-weight: bold;
            }
            QSpinBox:focus {
                border: none;
                outline: none;
            }
            QToolButton::menu-indicator {
                width: 0px;
            }
            QToolButton QMenu {
                background-color: rgb(255, 255, 255);
                color: rgb(72, 75, 79);
            }
            QToolButton QMenu::item {
                background-color: rgb(255, 255, 255);
                border-radius: 5px;
            }
            QToolButton QMenu::item:selected {
                background-color: rgb(230,230,230);
                border: 1px rgb(230,230,230);
                border-radius: 5;
            }
            )");
}
