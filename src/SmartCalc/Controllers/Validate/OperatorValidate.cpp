#include "Validate.h"


string OperatorValidate::Validate(string input, const string &button, int &status)
{
    status = 1;
    char last_symbol = input.back();
    char button_symbol = input.back();
    Validator::dot_status = 0;

    if (input.empty()) {
        status = 0;
    } if (last_symbol == '(') {
        status = 0;
    } else if (last_symbol == '.') {
        status = 0;
    } else if (Validator::IsOperator(last_symbol)) {
        status = 0;
    }

    if (status) {
        input = input + button;
    }

    return input;
}
