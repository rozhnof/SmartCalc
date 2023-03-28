#include "Validate.h"

string ClearInput::Validate(string input, const string &button) {
    if (!input.empty()) {
        for (int i = input.size(); i >= 0 && input[i] != ' '; i--) {
            input[i] = '\0';
        }
    }
    return input;
}
