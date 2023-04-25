#include <QApplication>
#include "Views/CalculatorUI.h"
#include "Views/CreditCalculatorUI.h"



int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    CreditCalculatorUI calc;
    calc.show();


//    MainWindow calc;
//    calc.show();


    return a.exec();
}
