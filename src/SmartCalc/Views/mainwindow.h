#ifndef MAINWINDOW_H
#define MAINWINDOW_H


#include <QWidget>
#include <QTabWidget>
#include <iostream>
#include "IPlatformUI.h"
#include <unordered_map>
#include <QMainWindow>


class MainWindow : public QMainWindow
{

public:
    IPlatformUI **_platform;

    MainWindow() : QMainWindow(nullptr) {}

    virtual void SetupUI() {}

    ~MainWindow() {}
};

#endif // MAINWINDOW_H
