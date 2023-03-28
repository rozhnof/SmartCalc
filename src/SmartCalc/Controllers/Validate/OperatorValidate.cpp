#include "Validate.h"


string OperatorValidate::Validate(string input, const string &button)
{
    int status = 1;
    char last_symbol = input.back();
    char button_symbol = input.back();
     Validator::dot_status = 0;

    if (last_symbol == 'd'){
        status = 0;
    } else if (last_symbol == '(') {
        status = 0;
    } else if (last_symbol == '.') {
        status = 0;
    } else if (last_symbol == '+' || last_symbol == '-' || last_symbol == '*' || last_symbol == '/' || last_symbol == '^' || last_symbol == 'd') {
        if (!(button_symbol == '+' || button_symbol == '-')) {
            status = 0;
        }
    }

    if (status) {
        input = input + button;
    }

    return input;
}
