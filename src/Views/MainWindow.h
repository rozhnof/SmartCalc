#pragma once

#include <QMainWindow>
#include <QTabWidget>
#include <QWidget>
#include <iostream>
#include <unordered_map>

#include "IPlatformUI.h"

class MainWindow : public QMainWindow {
 public:
  IPlatformUI **platform_;

  MainWindow();
  ~MainWindow();

  virtual void SetupUI();

  QCheckBox *NewCheckBox(QWidget *parent, QString text = "",
                         QString objectName = "");
  QWidget *NewWidget(QWidget *parent, QString objectName = "");
  QLabel *NewLabel(QWidget *parent, QString text = "", QString objectName = "");
  QDoubleSpinBox *NewDoubleSpinBox(QWidget *parent, QString objectName);
  QLineEdit *NewLineEdit(QWidget *parent, QString text = "",
                         QString objectName = "");
  QPushButton *NewPushButton(QWidget *parent, QString text = "",
                             QString objectName = "");
  QToolButton *NewToolButton(QWidget *parent, QString text = "",
                             QString objectName = "");
};
