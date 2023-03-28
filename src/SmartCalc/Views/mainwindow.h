#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "qcustomplot.h"
#include <QApplication>
#include <QLabel>
#include "ui_mainwindow.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    char* FromQStringToCharArray(QString qstr_input);


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
    void Clear();
    void Equal();
    void DrawGraph();
    void CreditResult();
};


#endif // MAINWINDOW_H
