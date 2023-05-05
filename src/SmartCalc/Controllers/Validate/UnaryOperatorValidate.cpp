#include "Validate.h"


string UnaryOperatorValidate::Validate(string input, const string &button, int &status)
{
    status = 0;
    char last_symbol = input.back();

    if (last_symbol == 0) {
        status = 1;
        input += "-";
    } else if (Validator::IsNumber(last_symbol)) {
        int index = input.size()-1;

        while (index > 0 && Validator::IsNumber(input[index])) {
            index--;
        }


        if (index >= 0) {
            if (Validator::IsNumber(input[index])) {
                if (input[index] == '+') {
                    input.insert(index, "-");
                } else {
                    input.insert(index, "+");
                }
            } else {
                if (input[index] == '+') {
                    input[index] = '-';
                } else {
                    input[index] = '+';
                }
            }
        } else {
            input.insert(index, "-");
        }

    }

    if (Validator::IsOperator(last_symbol)) {
        status = 1;
    }

    return input;
}




