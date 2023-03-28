#include "Validate.h"


Validator::Validator(IValidate* rule) {
    alg = rule;
}

QString Validator::Validate(QString input, QString button) {
    _input_text = input.toStdString();
    _button_text = button.toStdString();
    _result_text = alg->Validate(_input_text, _button_text);

    return QString::fromStdString(_result_text);
}

bool Validator::dot_status = 0;
