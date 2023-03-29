#include "Validate.h"


string DotValidate::Validate(string input, const string &button, int &status) {
    status = 0;
    char last_symbol = input.back();

    if (Validator::IsNumber(last_symbol) && !Validator::dot_status) {
        status = 1;
        Validator::dot_status = 1;
    }

    if (status) {
        input = input + button;
    }

    return input;
}
