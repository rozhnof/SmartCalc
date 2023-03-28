#include "Validate.h"


string OpenBracketValidate::Validate(string input, const string &button)
{
    int status = 0;
    char last_symbol = input.back();

    if (IsOperator(last_symbol)) {
        status = 1;
    } else if (last_symbol == '(') {
        status = 1;
    } 

    if (status) {
        input = input + button;
    }

    return input;
}
