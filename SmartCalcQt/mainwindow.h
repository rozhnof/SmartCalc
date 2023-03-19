#ifndef MAINWINDOW_H
#define MAINWINDOW_H


#include <QMainWindow>
#include "qcustomplot.h"
#include "../src/lib/main.h"
#include <QApplication>
#include <QLabel>
#include <QMessageBox>
#include "ui_mainwindow.h"
#include <string>


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE



class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;


private slots:
    void set_number();
    void set_operator();
    void set_dot();
    void open_bracket();
    void close_bracket();
    void set_x();

    void func();
    void mod();
    void all_clear();
    void clear();
    void equal();
    void graph();
    char* FromQStringToCharArray(QString qstr_input);

    void pushButton_CreditResult();
};


#endif // MAINWINDOW_H
