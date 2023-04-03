#include <QErrorMessage>
#include <QMainWindow>
#include <QApplication>
#include <QLabel>
#include <QMessageBox>
#include "ui_mainwindow.h"

#include "Views/mainwindow.h"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MainWindow calc(new MacUI);
    calc.show();

    return a.exec();
}
