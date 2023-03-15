#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#ifdef __cplusplus

extern "C" {

#endif

#include "../main.h"

#ifdef __cplusplus
}

#endif

#include <QMainWindow>



QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_11_clicked();

private:
    Ui::MainWindow *ui;
};


#endif // MAINWINDOW_H
