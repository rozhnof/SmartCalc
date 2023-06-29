#pragma once


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

    QCheckBox *NewCheckBox(QWidget *parent, QString text = "", QString objectName = "") {
        QCheckBox *newObject = new QCheckBox(parent);
        if (!objectName.isEmpty()) newObject->setObjectName(objectName);
        if (!text.isEmpty()) newObject->setText(text);
        return newObject;
    }

    QWidget *NewWidget(QWidget *parent, QString objectName = "") {
        QWidget *newObject = new QWidget(parent);
        if (!objectName.isEmpty()) newObject->setObjectName(objectName);
        return newObject;
    }

    QLabel *NewLabel(QWidget *parent, QString text = "", QString objectName = "") {
        QLabel *newObject = new QLabel(parent);
        if (!text.isEmpty()) newObject->setText(text);
        if (!objectName.isEmpty()) newObject->setObjectName(objectName);
        return newObject;
    }

    QDoubleSpinBox *NewDoubleSpinBox(QWidget *parent, QString objectName) {
        QDoubleSpinBox *newObject = new QDoubleSpinBox(parent);
        newObject->setObjectName(objectName);
        newObject->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
        newObject->setButtonSymbols(QAbstractSpinBox::NoButtons);
        return newObject;
    }

    QLineEdit *NewLineEdit(QWidget *parent, QString text = "", QString objectName = "") {
        QLineEdit *newObject = new QLineEdit(parent);
        if (!text.isEmpty()) newObject->setText(text);
        if (!objectName.isEmpty()) newObject->setObjectName(objectName);
        return newObject;
    }

    QPushButton *NewPushButton(QWidget *parent, QString text = "", QString objectName = "") {
        QPushButton *newObject = new QPushButton(parent);
        if (!text.isEmpty()) newObject->setText(text);
        if (!objectName.isEmpty()) newObject->setObjectName(objectName);
        return newObject;
    }

    QToolButton *NewToolButton(QWidget *parent, QString text = "", QString objectName = "") {
        QToolButton *newObject = new QToolButton(parent);
        if (!text.isEmpty()) newObject->setText(text);
        if (!objectName.isEmpty()) newObject->setObjectName(objectName);
        return newObject;
    }
};
