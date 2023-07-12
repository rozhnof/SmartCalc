#include "CalculatorUI.h"

CalculatorUI::CalculatorUI()
    : MainWindow(),
      _controller(new CalculatorController),
      _widgets(new CalcWidgets) {
  _widgets->calculatorWindow = this;

  initWidgets();
  connectWidgetsToSlots();
}

CalculatorUI::~CalculatorUI() {
  delete _controller;
  delete _widgets;
}

void CalculatorUI::SetupUI() {
  resetWidgets();
  (*_platform)->SetupUI(_widgets);
}

void CalculatorUI::initInputXWidget() {
  _widgets->inputXWidget = NewWidget(this, "input_x");
  _widgets->inputXWidget->setWindowTitle("Input X");

  QPushButton *buttonEnter =
      NewPushButton(_widgets->inputXWidget, "Enter X", "button_input_x");

  _widgets->inputXLineEdit =
      NewLineEdit(_widgets->inputXWidget, "0", "input_x");
  _widgets->inputXLineEdit->setAlignment(Qt::AlignVCenter | Qt::AlignHCenter);
  _widgets->inputXLineEdit->setValidator(new QRegularExpressionValidator(
      QRegularExpression("[0-9]{1,15}([.][0-9]{1,15})?"), this));

  QGridLayout *layout = new QGridLayout(_widgets->inputXWidget);
  layout->addWidget(_widgets->inputXLineEdit, 0, 0);
  layout->addWidget(buttonEnter, 1, 0);
  _widgets->inputXWidget->setLayout(layout);

  connect(buttonEnter, &QPushButton::clicked, this,
          &CalculatorUI::CalculateWithX);
  connect(_widgets->inputXLineEdit, &QLineEdit::returnPressed, this,
          &CalculatorUI::CalculateWithX);

  _widgets->animation = new QPropertyAnimation(_widgets->inputXWidget, "pos");
}

void CalculatorUI::initWidgets() {
  _widgets->inputLineEdit = NewLineEdit(this, "0", "input");
  _widgets->buttonAllClear = NewPushButton(this, "AC", "clear");
  _widgets->buttonClear = NewPushButton(this, "C", "clear");
  _widgets->buttonEqual = NewPushButton(this, "=", "equal");

  _widgets->buttonDictionary.insert(
      std::make_pair(BUTTON_0, NewPushButton(this, "0", "number")));
  _widgets->buttonDictionary.insert(
      std::make_pair(BUTTON_1, NewPushButton(this, "1", "number")));
  _widgets->buttonDictionary.insert(
      std::make_pair(BUTTON_2, NewPushButton(this, "2", "number")));
  _widgets->buttonDictionary.insert(
      std::make_pair(BUTTON_3, NewPushButton(this, "3", "number")));
  _widgets->buttonDictionary.insert(
      std::make_pair(BUTTON_4, NewPushButton(this, "4", "number")));
  _widgets->buttonDictionary.insert(
      std::make_pair(BUTTON_5, NewPushButton(this, "5", "number")));
  _widgets->buttonDictionary.insert(
      std::make_pair(BUTTON_6, NewPushButton(this, "6", "number")));
  _widgets->buttonDictionary.insert(
      std::make_pair(BUTTON_7, NewPushButton(this, "7", "number")));
  _widgets->buttonDictionary.insert(
      std::make_pair(BUTTON_8, NewPushButton(this, "8", "number")));
  _widgets->buttonDictionary.insert(
      std::make_pair(BUTTON_9, NewPushButton(this, "9", "number")));

  _widgets->buttonDictionary.insert(
      std::make_pair(BUTTON_SIN, NewPushButton(this, "sin", "function")));
  _widgets->buttonDictionary.insert(
      std::make_pair(BUTTON_COS, NewPushButton(this, "cos", "function")));
  _widgets->buttonDictionary.insert(
      std::make_pair(BUTTON_TAN, NewPushButton(this, "tan", "function")));
  _widgets->buttonDictionary.insert(
      std::make_pair(BUTTON_ASIN, NewPushButton(this, "asin", "function")));
  _widgets->buttonDictionary.insert(
      std::make_pair(BUTTON_ACOS, NewPushButton(this, "acos", "function")));
  _widgets->buttonDictionary.insert(
      std::make_pair(BUTTON_ATAN, NewPushButton(this, "atan", "function")));
  _widgets->buttonDictionary.insert(
      std::make_pair(BUTTON_LOG, NewPushButton(this, "log", "function")));
  _widgets->buttonDictionary.insert(
      std::make_pair(BUTTON_SQRT, NewPushButton(this, "sqrt", "function")));
  _widgets->buttonDictionary.insert(
      std::make_pair(BUTTON_LN, NewPushButton(this, "ln", "function")));

  _widgets->buttonDictionary.insert(
      std::make_pair(BUTTON_SUM, NewPushButton(this, "+", "operator")));
  _widgets->buttonDictionary.insert(
      std::make_pair(BUTTON_SUB, NewPushButton(this, "-", "operator")));
  _widgets->buttonDictionary.insert(
      std::make_pair(BUTTON_MUL, NewPushButton(this, "*", "operator")));
  _widgets->buttonDictionary.insert(
      std::make_pair(BUTTON_DIV, NewPushButton(this, "/", "operator")));
  _widgets->buttonDictionary.insert(
      std::make_pair(BUTTON_MOD, NewPushButton(this, "%", "mod")));
  _widgets->buttonDictionary.insert(
      std::make_pair(BUTTON_POW, NewPushButton(this, "^", "pow")));

  _widgets->buttonDictionary.insert(
      std::make_pair(BUTTON_X, NewPushButton(this, "x", "x")));
  _widgets->buttonDictionary.insert(
      std::make_pair(BUTTON_DOT, NewPushButton(this, ".", "dot")));
  _widgets->buttonDictionary.insert(
      std::make_pair(BUTTON_EXP, NewPushButton(this, "E", "exp")));

  _widgets->buttonDictionary.insert(
      std::make_pair(BUTTON_FACTORIAL, NewPushButton(this, "!", "factorial")));
  _widgets->buttonDictionary.insert(
      std::make_pair(BUTTON_OPEN_BRACKET, NewPushButton(this, "(", "bracket")));
  _widgets->buttonDictionary.insert(std::make_pair(
      BUTTON_CLOSE_BRACKET, NewPushButton(this, ")", "bracket")));

  initInputXWidget();
}

void CalculatorUI::connectWidgetsToSlots() {
  for (auto it : _widgets->buttonDictionary) {
    connect(it.second, &QPushButton::clicked, this, &CalculatorUI::setLexema);
  }

  connect(_widgets->buttonClear, &QPushButton::clicked, this,
          &CalculatorUI::clearButton);
  connect(_widgets->buttonAllClear, &QPushButton::clicked, this,
          &CalculatorUI::clearAllButton);
  connect(_widgets->buttonEqual, &QPushButton::clicked, this,
          &CalculatorUI::equalButton);
  connect(_widgets->inputLineEdit, &QLineEdit::returnPressed, this,
          &CalculatorUI::equalButton);
}

void CalculatorUI::resetWidgets() {
  _widgets->inputLineEdit->hide();
  for (auto it : _widgets->buttonDictionary) {
    it.second->hide();
  }
}

void CalculatorUI::setLexema() {
  _widgets->inputLineEdit->setText(
      _widgets->inputLineEdit->text() +
      static_cast<QPushButton *>(sender())->text());
}

void CalculatorUI::clearButton() {
  if (!_widgets->inputLineEdit->text().isEmpty()) {
    QString input = _widgets->inputLineEdit->text();
    input.chop(1);
    _widgets->inputLineEdit->setText(input);
  }
}

void CalculatorUI::clearAllButton() { _widgets->inputLineEdit->setText(""); }

void CalculatorUI::showInputX() {
  _widgets->animation->setDuration(200);
  _widgets->animation->setStartValue(QPoint(_widgets->inputXWidget->x(), 0));
  _widgets->animation->setEndValue(QPoint(0, 0));
  _widgets->animation->start();
}

void CalculatorUI::hideInputX() {
  _widgets->animation->setDuration(300);
  _widgets->animation->setStartValue(QPoint(_widgets->inputXWidget->x(), 0));
  _widgets->animation->setEndValue(QPoint(-160, 0));
  _widgets->animation->start();
}

void CalculatorUI::equalButton() {
  if (_widgets->inputLineEdit->text().contains('x')) {
    showInputX();
  } else {
    Calculate(_widgets->inputLineEdit->text(), 0);
  }
}

void CalculatorUI::CalculateWithX() {
  hideInputX();
  Calculate(_widgets->inputLineEdit->text(),
            _widgets->inputXLineEdit->text().toDouble());
}

void CalculatorUI::Calculate(QString input, double x) {
  if (_controller->Validate(input)) {
    _widgets->inputLineEdit->setText(
        QString::number(_controller->GetResult(input, x), 'g', 8));
  }
}
