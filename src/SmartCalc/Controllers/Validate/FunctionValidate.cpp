#include "Validate.h"


string FunctionValidate::Validate(string input, const string &button)
{
    int status = 0;
    char last_symbol = input.back();

    if (last_symbol == '(' || IsOperator(last_symbol)) {
        status = 1;
    }

    if (status) {
        input = input + button;
    }

    return input;
}
