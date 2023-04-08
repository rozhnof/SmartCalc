#include <QApplication>
#include "Views/MacUI.h"
#include "Views/WinUI.h"
#include "Views/BaseView.h"
#include "Views/IPlatformUI.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    BaseView calc(new MacUI);
    calc.show();

    return a.exec();
}
