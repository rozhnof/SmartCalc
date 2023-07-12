#include "CalculatorUI.h"

CalculatorUI::CalculatorUI()
    : MainWindow(),
      controller_(new CalculatorController),
      widgets_(new CalcWidgets) {
  widgets_->calculatorWindow = this;

  initWidgets();
  connectWidgetsToSlots();
}

CalculatorUI::~CalculatorUI() {
  delete controller_;
  delete widgets_;
}

void CalculatorUI::SetupUI() {
  resetWidgets();
  (*platform_)->SetupUI(widgets_);
}

void CalculatorUI::initInputXWidget() {
  widgets_->inputXWidget = NewWidget(this, "input_x");
  widgets_->inputXWidget->setWindowTitle("Input X");

  QPushButton *buttonEnter =
      NewPushButton(widgets_->inputXWidget, "Enter X", "button_input_x");

  widgets_->inputXLineEdit =
      NewLineEdit(widgets_->inputXWidget, "0", "input_x");
  widgets_->inputXLineEdit->setAlignment(Qt::AlignVCenter | Qt::AlignHCenter);
  widgets_->inputXLineEdit->setValidator(new QRegularExpressionValidator(
      QRegularExpression("[0-9]{1,15}([.][0-9]{1,15})?"), this));

  QGridLayout *layout = new QGridLayout(widgets_->inputXWidget);
  layout->addWidget(widgets_->inputXLineEdit, 0, 0);
  layout->addWidget(buttonEnter, 1, 0);
  widgets_->inputXWidget->setLayout(layout);

  connect(buttonEnter, &QPushButton::clicked, this,
          &CalculatorUI::CalculateWithX);
  connect(widgets_->inputXLineEdit, &QLineEdit::returnPressed, this,
          &CalculatorUI::CalculateWithX);

  widgets_->animation = new QPropertyAnimation(widgets_->inputXWidget, "pos");
}

void CalculatorUI::initWidgets() {
  widgets_->inputLineEdit = NewLineEdit(this, "0", "input");
  widgets_->buttonAllClear = NewPushButton(this, "AC", "clear");
  widgets_->buttonClear = NewPushButton(this, "C", "clear");
  widgets_->buttonEqual = NewPushButton(this, "=", "equal");

  widgets_->buttonDictionary.insert(
      std::make_pair(BUTTON_0, NewPushButton(this, "0", "number")));
  widgets_->buttonDictionary.insert(
      std::make_pair(BUTTON_1, NewPushButton(this, "1", "number")));
  widgets_->buttonDictionary.insert(
      std::make_pair(BUTTON_2, NewPushButton(this, "2", "number")));
  widgets_->buttonDictionary.insert(
      std::make_pair(BUTTON_3, NewPushButton(this, "3", "number")));
  widgets_->buttonDictionary.insert(
      std::make_pair(BUTTON_4, NewPushButton(this, "4", "number")));
  widgets_->buttonDictionary.insert(
      std::make_pair(BUTTON_5, NewPushButton(this, "5", "number")));
  widgets_->buttonDictionary.insert(
      std::make_pair(BUTTON_6, NewPushButton(this, "6", "number")));
  widgets_->buttonDictionary.insert(
      std::make_pair(BUTTON_7, NewPushButton(this, "7", "number")));
  widgets_->buttonDictionary.insert(
      std::make_pair(BUTTON_8, NewPushButton(this, "8", "number")));
  widgets_->buttonDictionary.insert(
      std::make_pair(BUTTON_9, NewPushButton(this, "9", "number")));

  widgets_->buttonDictionary.insert(
      std::make_pair(BUTTON_SIN, NewPushButton(this, "sin", "function")));
  widgets_->buttonDictionary.insert(
      std::make_pair(BUTTON_COS, NewPushButton(this, "cos", "function")));
  widgets_->buttonDictionary.insert(
      std::make_pair(BUTTON_TAN, NewPushButton(this, "tan", "function")));
  widgets_->buttonDictionary.insert(
      std::make_pair(BUTTON_ASIN, NewPushButton(this, "asin", "function")));
  widgets_->buttonDictionary.insert(
      std::make_pair(BUTTON_ACOS, NewPushButton(this, "acos", "function")));
  widgets_->buttonDictionary.insert(
      std::make_pair(BUTTON_ATAN, NewPushButton(this, "atan", "function")));
  widgets_->buttonDictionary.insert(
      std::make_pair(BUTTON_LOG, NewPushButton(this, "log", "function")));
  widgets_->buttonDictionary.insert(
      std::make_pair(BUTTON_SQRT, NewPushButton(this, "sqrt", "function")));
  widgets_->buttonDictionary.insert(
      std::make_pair(BUTTON_LN, NewPushButton(this, "ln", "function")));

  widgets_->buttonDictionary.insert(
      std::make_pair(BUTTON_SUM, NewPushButton(this, "+", "operator")));
  widgets_->buttonDictionary.insert(
      std::make_pair(BUTTON_SUB, NewPushButton(this, "-", "operator")));
  widgets_->buttonDictionary.insert(
      std::make_pair(BUTTON_MUL, NewPushButton(this, "*", "operator")));
  widgets_->buttonDictionary.insert(
      std::make_pair(BUTTON_DIV, NewPushButton(this, "/", "operator")));
  widgets_->buttonDictionary.insert(
      std::make_pair(BUTTON_MOD, NewPushButton(this, "%", "mod")));
  widgets_->buttonDictionary.insert(
      std::make_pair(BUTTON_POW, NewPushButton(this, "^", "pow")));

  widgets_->buttonDictionary.insert(
      std::make_pair(BUTTON_X, NewPushButton(this, "x", "x")));
  widgets_->buttonDictionary.insert(
      std::make_pair(BUTTON_DOT, NewPushButton(this, ".", "dot")));
  widgets_->buttonDictionary.insert(
      std::make_pair(BUTTON_EXP, NewPushButton(this, "E", "exp")));

  widgets_->buttonDictionary.insert(
      std::make_pair(BUTTON_FACTORIAL, NewPushButton(this, "!", "factorial")));
  widgets_->buttonDictionary.insert(
      std::make_pair(BUTTON_OPEN_BRACKET, NewPushButton(this, "(", "bracket")));
  widgets_->buttonDictionary.insert(std::make_pair(
      BUTTON_CLOSE_BRACKET, NewPushButton(this, ")", "bracket")));

  initInputXWidget();
}

void CalculatorUI::connectWidgetsToSlots() {
  for (auto it : widgets_->buttonDictionary) {
    connect(it.second, &QPushButton::clicked, this, &CalculatorUI::setLexema);
  }

  connect(widgets_->buttonClear, &QPushButton::clicked, this,
          &CalculatorUI::clearButton);
  connect(widgets_->buttonAllClear, &QPushButton::clicked, this,
          &CalculatorUI::clearAllButton);
  connect(widgets_->buttonEqual, &QPushButton::clicked, this,
          &CalculatorUI::equalButton);
  connect(widgets_->inputLineEdit, &QLineEdit::returnPressed, this,
          &CalculatorUI::equalButton);
}

void CalculatorUI::resetWidgets() {
  widgets_->inputLineEdit->hide();
  for (auto it : widgets_->buttonDictionary) {
    it.second->hide();
  }
}

void CalculatorUI::setLexema() {
  widgets_->inputLineEdit->setText(
      widgets_->inputLineEdit->text() +
      static_cast<QPushButton *>(sender())->text());
}

void CalculatorUI::clearButton() {
  if (!widgets_->inputLineEdit->text().isEmpty()) {
    QString input = widgets_->inputLineEdit->text();
    input.chop(1);
    widgets_->inputLineEdit->setText(input);
  }
}

void CalculatorUI::clearAllButton() { widgets_->inputLineEdit->setText(""); }

void CalculatorUI::showInputX() {
  widgets_->animation->setDuration(200);
  widgets_->animation->setStartValue(QPoint(widgets_->inputXWidget->x(), 0));
  widgets_->animation->setEndValue(QPoint(0, 0));
  widgets_->animation->start();
}

void CalculatorUI::hideInputX() {
  widgets_->animation->setDuration(300);
  widgets_->animation->setStartValue(QPoint(widgets_->inputXWidget->x(), 0));
  widgets_->animation->setEndValue(QPoint(-160, 0));
  widgets_->animation->start();
}

void CalculatorUI::equalButton() {
  if (widgets_->inputLineEdit->text().contains('x')) {
    showInputX();
  } else {
    Calculate(widgets_->inputLineEdit->text(), 0);
  }
}

void CalculatorUI::CalculateWithX() {
  hideInputX();
  Calculate(widgets_->inputLineEdit->text(),
            widgets_->inputXLineEdit->text().toDouble());
}

void CalculatorUI::Calculate(QString input, double x) {
  if (controller_->Validate(input)) {
    widgets_->inputLineEdit->setText(
        QString::number(controller_->GetResult(input, x), 'g', 8));
  }
}
