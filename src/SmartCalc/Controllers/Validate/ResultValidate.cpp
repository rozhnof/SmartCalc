#include "Validate.h"


string ResultValidate::Validate(string input, const string &button, int &status)
{
    status = 1;
    char last_symbol = input.back();

    if (Validator::IsOperator(last_symbol)) {
        status = 0;
    } else if (last_symbol == '(') {
        status = 0;
    } else if (input.empty()) {
        status = 0;
    }

    if (!status) {
        input = "Error";
    }

    return input;
}
