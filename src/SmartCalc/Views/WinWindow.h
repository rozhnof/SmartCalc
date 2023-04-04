#ifndef WINWINDOW_H
#define WINWINDOW_H

#include <QMainWindow>
#include "CalcSlots.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class WinWindow;
}
QT_END_NAMESPACE


class WinWindow : public QMainWindow
{
    Q_OBJECT

public:
    WinWindow(QWidget *parent = nullptr);
    ~WinWindow();


private:
    Ui::WinWindow *ui;
    CalcSlots *cSlots;
};


#endif // WINWINDOW_H
