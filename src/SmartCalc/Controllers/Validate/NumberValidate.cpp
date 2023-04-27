#include "Validate.h"


string NumberValidate::Validate(string input, const string &button, int &status)
{
    status = 1;
    char last_symbol = input.back();

    if (last_symbol == '!'){
        status = 0;
    } else if (last_symbol == 'x') {
        status = 0;
    } else if (last_symbol == ')') {
        status = 0;
    } else if (last_symbol == '0') {
        if (input.size() == 1) {
            input.pop_back();
        }
    }

    if (status) {
        input = input + button;
    }

    return input;
}
