#include <iostream>


class Validator {
private:
    bool _number = true;
    bool _operator = true;
    bool _unaryOperator = true;
    bool _function = true;
    bool _openBracket = true;
    bool _closeBracket = false;
    bool _x = true;
    bool _dot = false;
    bool _factorial = false;
    bool _exp = false;

    int _bracketCount = 0;
    int _dotCount = 0;

    bool _validateStatus = true;
    bool _functionStatus = true;

    int _size;
    std::string _input;

public:
    Validator(const std::string &input) : _input(input), _size(input.size()) {}

    bool IsUnaryOperator(char lexema) {
        if (lexema == '+' || lexema == '-') {
            return true;
        }
        return false;
    }

    bool IsOperator(const char &lexema) {
        std::vector<char> operators = {'+', '-', '/', '*', '^', '%'};

        for (auto it : operators) {
            if (lexema == it) return true;
        }

        return false;
    }

    bool IsNumber(const char &symbol) {
        return (symbol >= '0' && symbol <= '9');
    }

    int IsFunction(const std::string &lexema, int &functionSize) {
        std::vector<std::string> functions = {"sin", "cos", "tan", "asin", "acos", "atan", "sqrt", "ln", "log"};

        for (auto &it : functions) {
            if (lexema.size() >= it.size() && lexema.substr(0, it.size()) == it) {
                functionSize = it.size();
                return true;
            }
        }

        return false;
    }

    bool Validate() {
        if (_size == 0) {
            return false;
        }

        int functionSize = 0;
        if (!IsNumber(_input[0]) && _input[0] != 'x' && !IsFunction(_input, functionSize) && _input[0] != '(' && !IsUnaryOperator(_input[0])) {
            return false;
        }

        for (int i = 0; i < _size; i++) {
            if (IsNumber(_input[i])) {
                SetNumber();
            } else if (IsOperator(_input[i])) {
                SetOperator();
            } else if (IsFunction(_input.substr(i), functionSize)) {
                SetFunction();
                i += (functionSize - 1);
            } else if (_input[i] == 'x') {
                SetX();
            } else if (_input[i] == '(') {
                SetOpenBracket();
            } else if (_input[i] == ')') {
                SetCloseBracket();
            } else if (_input[i] == '.') {
                SetDot();
            } else if (_input[i] == '!') {
                SetFactorial();
            } else if (_input[i] == 'e' || _input[i] == 'E') {
                SetExp();
            } else {
                return false;
            }
        }

        if (_bracketCount < 0 || _input.back() == '(' || IsOperator(_input.back()) || !_functionStatus) {
            return false;
        }

        return _validateStatus && _functionStatus;
    }

    void SetNumber() {
        if (_number) {
            _number = true;
            _operator = true;
            _closeBracket = true;
            _dot = true;
            _exp = true;

            _function = false;
            _openBracket = false;
            _x = false;
            _unaryOperator = false;

            if (_dotCount == 0) {
                _factorial = true;
            } else {
                _factorial = false;
            }
        } else {
            _validateStatus = false;
        }
    }

    void SetOperator() {
        if (_operator) {
            _number = true;
             _function = true;
             _openBracket = true;
             _x = true;
             _unaryOperator = true;

            _operator = false;
            _closeBracket = false;
            _dot = false;
            _factorial = false;
            _exp = false;
            _dotCount = 0;
        } else if (_unaryOperator) {
            _number = true;
            _operator = false;
            _function = true;
            _openBracket = true;
            _closeBracket = false;
            _x = true;
            _dot = false;
            _unaryOperator = false;
            _factorial = false;
            _exp = false;
        } else {
            _validateStatus = false;
        }
    }

    void SetFunction() {
        if (_function) {
            _number = false;
            _operator = false;
            _function = false;
            _openBracket = true;
            _closeBracket = false;
            _x = false;
            _dot = false;
            _unaryOperator = false;
            _factorial = false;
            _exp = false;

            _functionStatus = false;
        } else {
            _validateStatus = false;
        }
    }

    void SetFactorial() {
        if (_factorial) {
            _number = false;
            _operator = true;
            _function = false;
            _openBracket = false;
            _closeBracket = false;
            _x = false;
            _dot = false;
            _unaryOperator = true;
            _factorial = false;
            _exp = false;
        } else {
            _validateStatus = false;
        }
    }

    void SetX() {
        if (_x) {
            _number = false;
            _operator = true;
            _function = false;
            _openBracket = false;
            _closeBracket = true;
            _x = false;
            _dot = false;
            _unaryOperator = true;
            _factorial = false;
            _exp = false;
        } else {
            _validateStatus = false;
        }
    }

    void SetOpenBracket() {
        if (_openBracket) {
            _number = true;
            _operator = false;
            _function = true;
            _openBracket = true;
            _closeBracket = false;
            _x = true;
            _dot = false;
            _unaryOperator = true;
            _factorial = false;
            _exp = false;

            _bracketCount++;
        } else {
            _validateStatus = false;
        }
    }

    void SetCloseBracket() {
        if (_closeBracket) {
            _number = false;
            _operator = true;
            _function = false;
            _openBracket = false;
            _closeBracket = true;
            _x = false;
            _dot = false;
            _unaryOperator = true;
            _factorial = false;
            _exp = false;

            _functionStatus = true;
            _bracketCount--;
        } else {
            _validateStatus = false;
        }
    }

    void SetDot() {
        if (_dot && _dotCount == 0) {
            _number = true;
            _operator = false;
            _function = false;
            _openBracket = false;
            _closeBracket = false;
            _x = false;
            _dot = false;
            _unaryOperator = false;
            _factorial = false;
            _exp = false;

            _dotCount++;
        } else {
            _validateStatus = false;
        }
    }

    void SetExp() {
        if (_exp) {
            _unaryOperator = true;
            _number = true;

            _operator = false;
            _function = false;
            _openBracket = false;
            _closeBracket = false;
            _x = false;
            _dot = false;
            _factorial = false;
            _exp = false;
        } else {
            _validateStatus = false;
        }
    }
};



