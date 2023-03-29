#include "Validate.h"


string FunctionValidate::Validate(string input, const string &button, int &status)
{
    status = 0;
    char last_symbol = input.back();

    if (last_symbol == '(' || Validator::IsOperator(last_symbol)) {
        status = 1;
    } else if (input.empty()) {
        status = 1;
    }

    if (status) {
        Validator::brackets_count++;
        input = input + button + "(";
    }

    return input;
}
