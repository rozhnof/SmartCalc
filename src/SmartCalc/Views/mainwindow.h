#ifndef MAINWINDOW_H
#define MAINWINDOW_H


#include <QWidget>
#include <QTabWidget>
#include <iostream>
#include "IPlatformUI.h"
#include <unordered_map>
#include <QMainWindow>


class MainWindow : public QMainWindow
{

public:
    IPlatformUI **_platform;

    MainWindow() : QMainWindow(nullptr) {}

    virtual void SetupUI() {}

    ~MainWindow() {}


    QLabel *NewLabel(QString text, QWidget *parent, QString objectName) {
        QLabel *newObject = new QLabel(text, parent);
        newObject->setObjectName(objectName);
        return newObject;
    }

    QDoubleSpinBox *NewDoubleSpinBox(QWidget *parent, QString objectName) {
        QDoubleSpinBox *newObject = new QDoubleSpinBox(parent);
        newObject->setObjectName(objectName);
        newObject->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
        newObject->setButtonSymbols(QAbstractSpinBox::NoButtons);
        return newObject;
    }

    QLineEdit *NewQLineEdit(QString text, QWidget *parent, QString objectName) {
        QLineEdit *newObject = new QLineEdit(text, parent);
        newObject->setObjectName(objectName);
        return newObject;
    }

    QPushButton *NewPushButton(QString text, QWidget *parent, QString objectName) {
        QPushButton *newObject = new QPushButton(text, parent);
        newObject->setObjectName(objectName);
        return newObject;
    }
};

#endif // MAINWINDOW_H
