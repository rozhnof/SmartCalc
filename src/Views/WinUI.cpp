#include <WinUI.h>



void WinUI::SetupUI(CalcWidgets *widgets) {
    setStyle(widgets);
    setGeometry(widgets);
}

void WinUI::SetupUI(CreditCalcWidgets *widgets) {
    setStyle(widgets);
}

void WinUI::setStyle(CalcWidgets *widgets) {
    widgets->inputLineEdit->setAlignment(Qt::AlignRight | Qt::AlignVCenter);
    widgets->calculatorWindow->setStyleSheet(R"(
        QWidget, QLineEdit#input {
        background-color: rgb(27, 32, 50);
        color: white;
        font-size: 26px;
        border: none;
        }
        QPushButton {
        background-color: rgb(46, 49, 68);
        color: white;
        font-size: 14px;
        border-radius: 5;
        }
        QPushButton:hover {
        background-color: rgb(51, 54, 70);
        }
        QPushButton:pressed {
        background-color: rgb(55, 58, 76);
        }
        QPushButton#number,
        QPushButton#dot {
        background-color: rgb(55, 58, 76);
        color: white;
        font-size: 18px;
        border-radius: 5;
        }
        QPushButton#number:hover,
        QPushButton#dot:hover {
        background-color: rgb(51, 54, 72);
        }
        QPushButton#number:pressed,
        QPushButton#dot:pressed {
        background-color: rgb(46, 49, 68);
        }
        QPushButton#equal {
        background-color: rgb(104, 181, 235);
        color: white;
        font-size: 14px;
        border-radius: 5;
        }
        QPushButton#equal:pressed {
        background-color: rgb(53, 163, 211);
        }
        QPushButton#equal:pressed {
        background-color: rgb(82, 144, 187);
        }
        QLineEdit#input_x,
        QPushButton#button_input_x {
        background-color: rgba(46, 49, 68, 1);
        color: white;
        font-size: 14px;
        border-radius: 5;
        border: none;
        }
        )");
}

void WinUI::setStyle(CreditCalcWidgets *widgets) {
    widgets->creditCalcWindow->setStyleSheet(R"(
        QMainWindow, QChartView {
        background-color: rgb(27, 32, 50);
        }
        QPushButton {
        background-color: rgb(217, 217, 217);
        color: rgb(37, 37, 37);
        border-radius: 10;
        font: 16px;
        }
        QComboBox {
        background-color: rgba(0, 0, 0, 0);
        color: rgb(37, 37, 37);
        font: 16px;
        }
        QTextEdit {
        background-color: rgb(217, 217, 217);
        border-radius: 10;
        font: 18px;
        color: rgb(37, 37, 37);
        }
        QPushButton:pressed {
        background-color: rgb(171, 171, 171);
        }
        QComboBox::drop-down {
        width: 0px;
        height: 0px;
        border: 0px;
        }
        QComboBox QAbstractItemView {
        color: rgb(37, 37, 37);
        background-color: rgb(217, 217, 217);
        padding: 10px;
        }
        QLabel, QLineEdit {
        background-color: rgba(217, 217, 217, 0);
        font: 16px;
        color: rgb(37, 37, 37);
        }
        )");

    widgets->title[CREDIT_SUM]->setStyleSheet("color: rgb(217, 217, 217);");
    widgets->title[CREDIT_TERM]->setStyleSheet("color: rgb(217, 217, 217);");
    widgets->title[CREDIT_INTEREST_RATE]->setStyleSheet("color: rgb(217, 217, 217);");

    widgets->chartView->SetBarWidth(0.75);
    widgets->chartView->SetBarColor(QColor(105, 124, 194), QColor(132, 157, 245));
    widgets->chartView->SetBorderBarColor(QColor(27, 32, 50), QColor(27, 32, 50));
    widgets->chartView->SetLabelsColor(QColor(217, 217, 217));
    widgets->chartView->SetLinePenColor(QColor(217, 217, 217));
    widgets->chartView->SetGridLineColor(QColor(217, 217, 217));
}

void WinUI::setGeometry(CalcWidgets *widgets) {
    Layout layout;

    widgets->calculatorWindow->setFixedSize(420, 350);
    layout.SetStartPoints(0, 0);
    layout.SetEndPoints(widgets->calculatorWindow->width(), widgets->calculatorWindow->height());
    layout.SetColumns(7);
    layout.SetRows(7);
    layout.SetLeftSpacing(3);
    layout.SetRightSpacing(3);
    layout.SetAboveSpacing(2);
    layout.SetBottomSpacing(3);
    layout.SetHorizontalSpacing(2);
    layout.SetVerticalSpacing(2);
    layout.SetAutoSize();

    layout.AddWidget(widgets->inputLineEdit, 7, 2);
    widgets->inputXWidget->setGeometry(-160, 0, 160, widgets->inputLineEdit->height());
    layout.AddWidget(widgets->buttonDictionary[BUTTON_X]);
    layout.AddWidget(widgets->buttonDictionary[BUTTON_OPEN_BRACKET]);
    layout.AddWidget(widgets->buttonDictionary[BUTTON_CLOSE_BRACKET]);
    layout.AddWidget(widgets->buttonAllClear);
    layout.AddWidget(widgets->buttonClear);
    layout.AddWidget(widgets->buttonDictionary[BUTTON_EXP]);
    layout.AddWidget(widgets->buttonDictionary[BUTTON_DIV]);

    layout.AddWidget(widgets->buttonDictionary[BUTTON_MOD]);
    layout.AddWidget(widgets->buttonDictionary[BUTTON_POW]);
    layout.AddWidget(widgets->buttonDictionary[BUTTON_FACTORIAL]);
    layout.AddWidget(widgets->buttonDictionary[BUTTON_7]);
    layout.AddWidget(widgets->buttonDictionary[BUTTON_8]);
    layout.AddWidget(widgets->buttonDictionary[BUTTON_9]);
    layout.AddWidget(widgets->buttonDictionary[BUTTON_MUL]);

    layout.AddWidget(widgets->buttonDictionary[BUTTON_LOG]);
    layout.AddWidget(widgets->buttonDictionary[BUTTON_LN]);
    layout.AddWidget(widgets->buttonDictionary[BUTTON_SQRT]);
    layout.AddWidget(widgets->buttonDictionary[BUTTON_4]);
    layout.AddWidget(widgets->buttonDictionary[BUTTON_5]);
    layout.AddWidget(widgets->buttonDictionary[BUTTON_6]);
    layout.AddWidget(widgets->buttonDictionary[BUTTON_SUB]);

    layout.AddWidget(widgets->buttonDictionary[BUTTON_ASIN]);
    layout.AddWidget(widgets->buttonDictionary[BUTTON_ACOS]);
    layout.AddWidget(widgets->buttonDictionary[BUTTON_ATAN]);
    layout.AddWidget(widgets->buttonDictionary[BUTTON_1]);
    layout.AddWidget(widgets->buttonDictionary[BUTTON_2]);
    layout.AddWidget(widgets->buttonDictionary[BUTTON_3]);
    layout.AddWidget(widgets->buttonDictionary[BUTTON_SUM]);

    layout.AddWidget(widgets->buttonDictionary[BUTTON_SIN]);
    layout.AddWidget(widgets->buttonDictionary[BUTTON_COS]);
    layout.AddWidget(widgets->buttonDictionary[BUTTON_TAN]);
    layout.AddWidget(widgets->buttonDictionary[BUTTON_0], 2);
    layout.AddWidget(widgets->buttonDictionary[BUTTON_DOT]);
    layout.AddWidget(widgets->buttonEqual);
}
