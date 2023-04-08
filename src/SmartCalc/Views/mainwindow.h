#ifndef MAINWINDOW_H
#define MAINWINDOW_H


#include "BaseView.h"


class MainWindow : public QWidget
{
    Q_OBJECT

public:
    MainWindow() {}
    ~MainWindow() {}

    BaseView *calc;
    BaseView *creditCalc;
    BaseView *depositCalc;
    BaseView *graph;
    BaseView *currentView;
};

#endif // MAINWINDOW_H
