#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "qcustomplot.h"
#include <QApplication>
#include <QLabel>
#include "ui_mainwindow.h"
#include <QMessageBox>
#include "../Controllers/Controller.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void IncorrectSymbol();

private:
    Ui::MainWindow *ui;
    Controller *action;


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
    // void DrawGraph();
    // void CreditResult();
};


#endif // MAINWINDOW_H
