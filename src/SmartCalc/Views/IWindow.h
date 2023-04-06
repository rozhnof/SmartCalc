#ifndef IWINDOW_H
#define IWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>


class IWindow : public QMainWindow
{
    Q_OBJECT

public:


private:
    IWindow *_window;
};

#endif // IWINDOW_H
