#include "Validate.h"


string CloseBracketValidate::Validate(string input, const string &button, int &status) {
    status = 0;
    char last_symbol = input.back();

    if (Validator::brackets_count) {
        if (last_symbol == '!') {
            status = 1;
        } else if (last_symbol == 'x') {
            status = 1;
        } else if (last_symbol == ')') {
            status = 1;
        } else if (Validator::IsNumber(last_symbol)) {
            status = 1;
        }
    }

    if (status) {
        Validator::brackets_count--;
        input = input + button;
    }

    return input;
}
