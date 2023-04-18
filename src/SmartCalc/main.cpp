#include <QApplication>
#include "Views/CalculatorUI.h"



int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    CalculatorUI calc(new MacUI);
    calc.show();

    return a.exec();
}
