#ifndef MAINWINDOW_H
#define MAINWINDOW_H


#include <QWidget>
#include <QTabWidget>
#include <iostream>
#include "IPlatformUI.h"
#include <unordered_map>
#include "Controllers/Controller.h"
#include <QMainWindow>


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    QWidget *window;

    IPlatformUI **_platform;
    Controller *controller;

    MainWindow() : QMainWindow(nullptr)
    {
        controller = new Controller;
        this->resize(840, 720);
    }

    virtual void SetupUI() {}

    ~MainWindow() {}
};

#endif // MAINWINDOW_H
