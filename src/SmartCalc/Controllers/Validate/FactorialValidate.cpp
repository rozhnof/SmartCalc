#include "Validate.h"


string FactorialValidate::Validate(string input, const string &button, int &status)
{
    status = 0;
    char last_symbol = input.back();

    if (!Validator::dot_status) {
        if (Validator::IsNumber(last_symbol)){
            status = 1;
        } else if (last_symbol == 'x') {
            status = 1;
        } else if (last_symbol == ')') {
            status = 1;
        } 

        if (status) {
            input = input + button;
        }
    }

    return input;
}
