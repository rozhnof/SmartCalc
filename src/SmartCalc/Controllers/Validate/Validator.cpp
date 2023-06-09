#include "Validate.h"

#include <vector>

Validator::Validator(IValidate* rule) {
    alg = rule;
}

string Validator::Validate(string input, string button, int &status) {
    return _result_text = alg->Validate(input, button, status);
}

int Validator::IsOperator(char symbol) {
    int status = 0;

    if (symbol == '+') {
        status = 1;
    } else if (symbol == '-') {
        status = 1;
    } else if (symbol == '*') {
        status = 1;
    } else if (symbol == '/') {
        status = 1;
    } else if (symbol == '^') {
        status = 1;
    } else if (symbol == 'd') {
        status = 1;
    }

    return status;
}

int Validator::IsNumber(char symbol) {
    return (symbol >= '0' && symbol <= '9');
}

bool Validator::dot_status = 0;
int Validator::brackets_count = 0;
