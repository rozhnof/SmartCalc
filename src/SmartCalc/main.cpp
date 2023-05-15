#include <QApplication>
#include "Views/Calculator.h"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Calculator *calc = new Calculator;
    calc->show();

    return a.exec();
}
