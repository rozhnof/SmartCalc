#include "Validate.h"


string NumberValidate::Validate(string input, const string &button)
{
    int status = 1;
    char last_symbol = input.back();

    if (last_symbol == '!'){
        status = 0;
    } else if (last_symbol == 'x') {
        status = 0;
    } else if (last_symbol == ')') {
        status = 0;
    }
    if (status) {
        input = input + button;
    }

    return input;
}
