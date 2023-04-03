#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QErrorMessage>
#include <QMainWindow>
#include <QApplication>
#include <QLabel>
#include <QMessageBox>
#include "ui_mainwindow.h"



class ISystem {
public:
    virtual void SetParent(MainWindow window, QWidget parent);
};

class MacUI : public ISystem {
    void SetParent(MainWindow window, QWidget parent) override {

    }
};



QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(ISystem *views);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

private slots:
    void SetNumber();
    void SetOperator();
    void SetFactorial();
    void SetDot();
    void SetOpenBracket();
    void SetCloseBracket();
    void SetX();
    void SetFunction();
    void ClearAll();
    void Equal();
    void DrawGraph();
};

#endif // MAINWINDOW_H
