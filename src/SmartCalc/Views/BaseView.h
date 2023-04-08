#ifndef BASEVIEW_H
#define BASEVIEW_H

#include "QWidget"
#include "QMainWindow"
#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QWidget>
#include "IPlatformUI.h"


class BaseView : public QWidget
{
    Q_OBJECT

public:
    BaseView(IPlatformUI *platform) : platformUi(platform){ }

    void show() {
        platformUi->show();
    }

protected:
    IPlatformUI *platformUi;
};






#endif // BASEVIEW_H
