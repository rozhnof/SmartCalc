/********************************************************************************
** Form generated from reading UI file 'GraphUI.ui'
**
** Created by: Qt User Interface Compiler version 6.2.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GRAPHUI_H
#define UI_GRAPHUI_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_GraphUI
{
public:
    QDoubleSpinBox *RangeMin;
    QDoubleSpinBox *ScopeMax;
    QLineEdit *FunctionRange;
    QDoubleSpinBox *ScopeMin;
    QDoubleSpinBox *RangeMax;
    QLineEdit *FunctionScope;
    QGraphicsView *graphicsView;
    QLineEdit *XDef;
    QDoubleSpinBox *input_x;

    void setupUi(QWidget *GraphUI)
    {
        if (GraphUI->objectName().isEmpty())
            GraphUI->setObjectName(QString::fromUtf8("GraphUI"));
        GraphUI->resize(825, 681);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(GraphUI->sizePolicy().hasHeightForWidth());
        GraphUI->setSizePolicy(sizePolicy);
        GraphUI->setMinimumSize(QSize(0, 0));
        GraphUI->setMaximumSize(QSize(354235, 3453453));
        GraphUI->setStyleSheet(QString::fromUtf8("background-color : white;"));
        RangeMin = new QDoubleSpinBox(GraphUI);
        RangeMin->setObjectName(QString::fromUtf8("RangeMin"));
        RangeMin->setGeometry(QRect(140, 640, 66, 18));
        QFont font;
        font.setPointSize(9);
        RangeMin->setFont(font);
        RangeMin->setStyleSheet(QString::fromUtf8("background-color: white;\n"
"color: black;\n"
"border: 1px solid rgb(0, 32, 255);\n"
""));
        RangeMin->setAlignment(Qt::AlignCenter);
        RangeMin->setButtonSymbols(QAbstractSpinBox::NoButtons);
        RangeMin->setMinimum(-1000000.000000000000000);
        RangeMin->setMaximum(1000000.000000000000000);
        RangeMin->setValue(-2.000000000000000);
        ScopeMax = new QDoubleSpinBox(GraphUI);
        ScopeMax->setObjectName(QString::fromUtf8("ScopeMax"));
        ScopeMax->setGeometry(QRect(20, 660, 66, 18));
        ScopeMax->setFont(font);
        ScopeMax->setStyleSheet(QString::fromUtf8("background-color: white;\n"
"color: black;\n"
"border: 1px solid rgb(0, 32, 255);\n"
""));
        ScopeMax->setAlignment(Qt::AlignCenter);
        ScopeMax->setButtonSymbols(QAbstractSpinBox::NoButtons);
        ScopeMax->setMinimum(-1000000.000000000000000);
        ScopeMax->setMaximum(1000000.000000000000000);
        ScopeMax->setValue(50.000000000000000);
        FunctionRange = new QLineEdit(GraphUI);
        FunctionRange->setObjectName(QString::fromUtf8("FunctionRange"));
        FunctionRange->setGeometry(QRect(130, 620, 91, 18));
        FunctionRange->setFont(font);
        FunctionRange->setLayoutDirection(Qt::LeftToRight);
        FunctionRange->setStyleSheet(QString::fromUtf8("background-color: white;\n"
"color: black;\n"
"border: 1px solid rgb(0, 32, 255);\n"
""));
        FunctionRange->setAlignment(Qt::AlignCenter);
        FunctionRange->setReadOnly(true);
        ScopeMin = new QDoubleSpinBox(GraphUI);
        ScopeMin->setObjectName(QString::fromUtf8("ScopeMin"));
        ScopeMin->setGeometry(QRect(20, 640, 66, 18));
        ScopeMin->setFont(font);
        ScopeMin->setStyleSheet(QString::fromUtf8("background-color: white;\n"
"color: black;\n"
"border: 1px solid rgb(0, 32, 255);\n"
""));
        ScopeMin->setAlignment(Qt::AlignCenter);
        ScopeMin->setButtonSymbols(QAbstractSpinBox::NoButtons);
        ScopeMin->setKeyboardTracking(true);
        ScopeMin->setMinimum(-1000000.000000000000000);
        ScopeMin->setMaximum(1000000.000000000000000);
        ScopeMin->setValue(-50.000000000000000);
        RangeMax = new QDoubleSpinBox(GraphUI);
        RangeMax->setObjectName(QString::fromUtf8("RangeMax"));
        RangeMax->setGeometry(QRect(140, 660, 66, 18));
        RangeMax->setFont(font);
        RangeMax->setStyleSheet(QString::fromUtf8("background-color: white;\n"
"color: black;\n"
"border: 1px solid rgb(0, 32, 255);\n"
""));
        RangeMax->setAlignment(Qt::AlignCenter);
        RangeMax->setButtonSymbols(QAbstractSpinBox::NoButtons);
        RangeMax->setMinimum(-1000000.000000000000000);
        RangeMax->setMaximum(1000000.000000000000000);
        RangeMax->setValue(2.000000000000000);
        FunctionScope = new QLineEdit(GraphUI);
        FunctionScope->setObjectName(QString::fromUtf8("FunctionScope"));
        FunctionScope->setGeometry(QRect(12, 620, 91, 18));
        FunctionScope->setFont(font);
        FunctionScope->setLayoutDirection(Qt::LeftToRight);
        FunctionScope->setStyleSheet(QString::fromUtf8("background-color: white;\n"
"color: black;\n"
"border: 1px solid rgb(0, 32, 255);\n"
""));
        FunctionScope->setAlignment(Qt::AlignCenter);
        FunctionScope->setReadOnly(true);
        graphicsView = new QGraphicsView(GraphUI);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));
        graphicsView->setGeometry(QRect(12, 12, 800, 600));
        graphicsView->setMinimumSize(QSize(776, 482));
        XDef = new QLineEdit(GraphUI);
        XDef->setObjectName(QString::fromUtf8("XDef"));
        XDef->setGeometry(QRect(610, 620, 87, 27));
        QFont font1;
        font1.setPointSize(20);
        XDef->setFont(font1);
        XDef->setLayoutDirection(Qt::LeftToRight);
        XDef->setStyleSheet(QString::fromUtf8("background-color: white;\n"
"color: black;\n"
"border: 1px solid rgb(0, 32, 255);\n"
""));
        XDef->setAlignment(Qt::AlignCenter);
        XDef->setReadOnly(true);
        input_x = new QDoubleSpinBox(GraphUI);
        input_x->setObjectName(QString::fromUtf8("input_x"));
        input_x->setGeometry(QRect(580, 650, 151, 20));
        input_x->setStyleSheet(QString::fromUtf8("background-color: white;\n"
"color: black;\n"
"border: 1px solid rgb(0, 32, 255);\n"
""));
        input_x->setWrapping(false);
        input_x->setAlignment(Qt::AlignCenter);
        input_x->setButtonSymbols(QAbstractSpinBox::NoButtons);
        input_x->setMinimum(-1000000.000000000000000);
        input_x->setMaximum(1000000.000000000000000);
        input_x->setSingleStep(0.010000000000000);
        input_x->setStepType(QAbstractSpinBox::DefaultStepType);
        input_x->setValue(0.000000000000000);

        retranslateUi(GraphUI);

        QMetaObject::connectSlotsByName(GraphUI);
    } // setupUi

    void retranslateUi(QWidget *GraphUI)
    {
        GraphUI->setWindowTitle(QCoreApplication::translate("GraphUI", "Form", nullptr));
        FunctionRange->setText(QCoreApplication::translate("GraphUI", "Function range ", nullptr));
        FunctionScope->setText(QCoreApplication::translate("GraphUI", " Function scope", nullptr));
        XDef->setText(QCoreApplication::translate("GraphUI", "X", nullptr));
    } // retranslateUi

};

namespace Ui {
    class GraphUI: public Ui_GraphUI {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GRAPHUI_H