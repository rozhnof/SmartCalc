#include "Validate.h"
#include <vector>

Validator::Validator(IValidate* rule) {
    alg = rule;
}

string Validator::Validate(string input, string button, int &status) {
    return _result_text = alg->Validate(input, button, status);
}

int Validator::IsOperator(string lexema) {
    vector<string> operators = {"+", "-", "/", "*", "^", "mod"};

    for (auto it : operators) {
        if (lexema.substr(0, it.size()) == it) return true;
    }

    return false;
}

int Validator::IsUnaryOperator(char lexema) {
    if (lexema == '+' || lexema == '-') {
        return true;
    }
    return false;
}

int Validator::IsOperator(char lexema) {
    vector<char> operators = {'+', '-', '/', '*', '^', 'd'};

    for (auto it : operators) {
        if (lexema == it) return true;
    }

    return false;
}

int Validator::IsNumber(char symbol) {
    return (symbol >= '0' && symbol <= '9');
}

int Validator::IsFunction(string lexema, int &functionSize) {
    vector<string> functions = {"sin", "cos", "tan", "asin", "acos", "atan", "sqrt", "ln", "log"};

    for (auto it : functions) {
        if (lexema.substr(0, it.size()) == it) {
            functionSize = it.size();
            return true;
        }
    }

    return false;
}


bool Validator::dot_status = 0;
int Validator::brackets_count = 0;
