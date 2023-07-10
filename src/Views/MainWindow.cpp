#include <MainWindow.h>



MainWindow::MainWindow() : QMainWindow(nullptr) {}

void MainWindow::SetupUI() {}

MainWindow::~MainWindow() {}

QCheckBox *MainWindow::NewCheckBox(QWidget *parent, QString text, QString objectName) {
    QCheckBox *newObject = new QCheckBox(parent);
    if (!objectName.isEmpty()) newObject->setObjectName(objectName);
    if (!text.isEmpty()) newObject->setText(text);
    return newObject;
}

QWidget *MainWindow::NewWidget(QWidget *parent, QString objectName) {
    QWidget *newObject = new QWidget(parent);
    if (!objectName.isEmpty()) newObject->setObjectName(objectName);
    return newObject;
}

QLabel *MainWindow::NewLabel(QWidget *parent, QString text, QString objectName) {
    QLabel *newObject = new QLabel(parent);
    if (!text.isEmpty()) newObject->setText(text);
    if (!objectName.isEmpty()) newObject->setObjectName(objectName);
    return newObject;
}

QDoubleSpinBox *MainWindow::NewDoubleSpinBox(QWidget *parent, QString objectName) {
    QDoubleSpinBox *newObject = new QDoubleSpinBox(parent);
    newObject->setObjectName(objectName);
    newObject->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
    newObject->setButtonSymbols(QAbstractSpinBox::NoButtons);
    return newObject;
}

QLineEdit *MainWindow::NewLineEdit(QWidget *parent, QString text, QString objectName) {
    QLineEdit *newObject = new QLineEdit(parent);
    if (!text.isEmpty()) newObject->setText(text);
    if (!objectName.isEmpty()) newObject->setObjectName(objectName);
    return newObject;
}

QPushButton *MainWindow::NewPushButton(QWidget *parent, QString text, QString objectName) {
    QPushButton *newObject = new QPushButton(parent);
    if (!text.isEmpty()) newObject->setText(text);
    if (!objectName.isEmpty()) newObject->setObjectName(objectName);
    return newObject;
}

QToolButton *MainWindow::NewToolButton(QWidget *parent, QString text, QString objectName) {
    QToolButton *newObject = new QToolButton(parent);
    if (!text.isEmpty()) newObject->setText(text);
    if (!objectName.isEmpty()) newObject->setObjectName(objectName);
    return newObject;
}
