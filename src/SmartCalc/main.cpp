#include <QApplication>
#include "Views/CalculatorUI.h"



int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    CalculatorUI calc;
    calc.show();

    return a.exec();
}
