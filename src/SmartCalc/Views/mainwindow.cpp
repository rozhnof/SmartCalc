
#include "mainwindow.h"

void MainWindow::resizeEvent(QResizeEvent *e)
{
    qDebug() << e->size();
    QWidget::resizeEvent(e);
}
