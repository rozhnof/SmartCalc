#include <QApplication>
#include "Views/MacUI.h"
#include "Views/BaseView.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);



    BaseView calc(new MacUI);
    calc.show();



    return a.exec();
}
