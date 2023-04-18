#ifndef GRAPHUI_H
#define GRAPHUI_H


#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QWidget>


class GraphUI : public QWidget
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
    QLineEdit *StepXDef;
    QDoubleSpinBox *StepX;


    QWidget *graphUi;

    GraphUI() {
        graphUi = new QWidget;
        SetupUI();
        RetranslateUI();
    }

    void SetupUI()
    {
        graphUi->setFixedSize(1000, 1000);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(graphUi->sizePolicy().hasHeightForWidth());
        graphUi->setSizePolicy(sizePolicy);
        graphUi->setMinimumSize(QSize(0, 0));
        graphUi->setMaximumSize(QSize(354235, 3453453));
        graphUi->setStyleSheet(QString::fromUtf8("background-color : white;"));
        RangeMin = new QDoubleSpinBox(graphUi);
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
        ScopeMax = new QDoubleSpinBox(graphUi);
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
        FunctionRange = new QLineEdit(graphUi);
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
        ScopeMin = new QDoubleSpinBox(graphUi);
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
        RangeMax = new QDoubleSpinBox(graphUi);
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
        FunctionScope = new QLineEdit(graphUi);
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
        graphicsView = new QGraphicsView(graphUi);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));
        graphicsView->setGeometry(QRect(12, 12, 800, 600));
        graphicsView->setMinimumSize(QSize(776, 482));
        XDef = new QLineEdit(graphUi);
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


StepXDef = new QLineEdit(graphUi);
        StepXDef->setObjectName(QString::fromUtf8("StepXDef"));
        StepXDef->setText("Step X");
        StepXDef->setGeometry(QRect(450, 620, 87, 27));
        StepXDef->setFont(font1);
        StepXDef->setLayoutDirection(Qt::LeftToRight);
        StepXDef->setStyleSheet(QString::fromUtf8("background-color: white;\n"
"color: black;\n"
"border: 1px solid rgb(0, 32, 255);\n"
""));
        StepXDef->setAlignment(Qt::AlignCenter);
        StepXDef->setReadOnly(true);
        StepX = new QDoubleSpinBox(graphUi);
        StepX->setObjectName(QString::fromUtf8("StepX"));
        StepX->setGeometry(QRect(420, 650, 151, 20));
        StepX->setStyleSheet(QString::fromUtf8("background-color: white;\n"
"color: black;\n"
"border: 1px solid rgb(0, 32, 255);\n"
""));
        StepX->setWrapping(false);
        StepX->setAlignment(Qt::AlignCenter);
        StepX->setButtonSymbols(QAbstractSpinBox::NoButtons);
        StepX->setMinimum(0.010000000000000);
        StepX->setMaximum(1000000.000000000000000);
        StepX->setSingleStep(0.010000000000000);
        StepX->setStepType(QAbstractSpinBox::DefaultStepType);
        StepX->setValue(0.100000000000000);


        input_x = new QDoubleSpinBox(graphUi);
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
        input_x->setStepType(QAbstractSpinBox::DefaultStepType);
        input_x->setSingleStep(StepX->text().toDouble());
        input_x->setValue(0.000000000000000);

        QMetaObject::connectSlotsByName(graphUi);
    }

    void RetranslateUI()
    {
        graphUi->setWindowTitle(QCoreApplication::translate("GraphUI", "Form", nullptr));
        FunctionRange->setText(QCoreApplication::translate("GraphUI", "Function range ", nullptr));
        FunctionScope->setText(QCoreApplication::translate("GraphUI", " Function scope", nullptr));
        XDef->setText(QCoreApplication::translate("GraphUI", "X", nullptr));
    }
};


#endif // GRAPHUI_H
