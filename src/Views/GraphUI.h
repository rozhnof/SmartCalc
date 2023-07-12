#pragma once

#include "../Controllers/GraphController.h"
#include "MainWindow.h"
#include "qcustomplot.h"

class GraphUI : public MainWindow {
  Q_OBJECT

 private:
  GraphController *controller_;
  GraphWidgets *widgets_;

 public:
  GraphUI();
  ~GraphUI();

 private:
  void setStyle();
  void setGeometry();
  void setOptions();

  void initWidgets();
  void connectWidgetsToSlots();

 private slots:
  void drawLine();
  void drawingLineState();
  void drawGraph();
};
