#include <iostream>
#include <QString>


using namespace std;


class IValidate {
public:
    virtual string Validate(string input, const string &button, int &validateStatus) = 0;
};

class Validator {
private:
    IValidate* alg;
    string _result_text;
    
public:
    static bool dot_status;
    static int brackets_count;
    static int IsOperator(string lexema);
    static int IsUnaryOperator(char lexema);
    static int IsOperator(char lexema);
    static int IsNumber(char lexema);
    static int IsFunction(string lexema, int &functionSize);

    Validator(IValidate* rule);
    Validator() {}
    string Validate(string input, string button, int &validateStatus);
    bool FullValidate(string input);
};

class NumberValidate : public IValidate {   
    string Validate(string input, const string &button, int &validateStatus) override;
};

class OperatorValidate : public IValidate {
    string Validate(string input, const string &button, int &validateStatus) override;
};

class DotValidate : public IValidate {
    string Validate(string input, const string &button, int &validateStatus) override;
};

class OpenBracketValidate : public IValidate {
    string Validate(string input, const string &button, int &validateStatus) override;
};

class CloseBracketValidate : public IValidate {
    string Validate(string input, const string &button, int &validateStatus) override;
};

class FunctionValidate : public IValidate {
    string Validate(string input, const string &button, int &validateStatus) override;
};

class xValidate : public IValidate {
    string Validate(string input, const string &button, int &validateStatus) override;
};

class ResultValidate : public IValidate {
    string Validate(string input, const string &button, int &validateStatus) override;
};

class FactorialValidate : public IValidate {
    string Validate(string input, const string &button, int &validateStatus) override;
};

class UnaryOperatorValidate : public IValidate {
    string Validate(string input, const string &button, int &validateStatus) override;
};


inline bool Validator::FullValidate(string input) {
    bool validateStatus = true;
    bool functionStatus = true;

    class LexemaStatus {
    public:
        bool number = true;
        bool _operator = true;
        bool unaryOperator = true;
        bool function = true;
        bool openBracket = true;
        bool closeBracket = false;
        bool x = true;
        bool dot = false;

        int bracketCount = 0;
        int dotCount = 0;
        int functionSize = 0;
    };
    LexemaStatus status;

    if (input.empty()) {
        return false;
    }

    if (!IsNumber(input[0]) && input[0] != 'x' && !IsFunction(input, status.functionSize) && input[0] != '(' && !IsUnaryOperator(input[0])) {
        return false;
    }

    for (int i = 0; i < input.size(); i++) {

        if (IsNumber(input[i])) {
            if (status.number) {
                status.number = true;
                status._operator = true;
                status.function = false;
                status.openBracket = false;
                status.closeBracket = true;
                status.x = false;
                status.dot = true;
                status.unaryOperator = false;
            } else {
                validateStatus = false;
            }
        }
        else if (IsOperator(input.substr(i))) {
            if (status._operator) {
                status.number = true;
                status._operator = false;
                status.function = true;
                status.openBracket = true;
                status.closeBracket = false;
                status.x = true;
                status.dot = false;
                status.unaryOperator = true;
                status.dotCount = 0;
            } else if (IsUnaryOperator(input[i])) {
                if (status.unaryOperator) {
                    status.number = true;
                    status._operator = false;
                    status.function = true;
                    status.openBracket = true;
                    status.closeBracket = false;
                    status.x = true;
                    status.dot = false;
                    status.unaryOperator = false;
                } else {
                    validateStatus = false;
                }
            } else {
                validateStatus = false;
            }
        } else if (IsFunction(input.substr(i), status.functionSize)) {
            if (status.function) {
                status.number = false;
                status._operator = false;
                status.function = false;
                status.openBracket = true;
                status.closeBracket = false;
                status.x = false;
                status.dot = false;
                status.unaryOperator = false;
                functionStatus = false;

                i += (status.functionSize - 1);
            } else {
                validateStatus = false;
            }

        } else if (input[i] == 'x') {
            if (status.x) {
                status.number = false;
                status._operator = true;
                status.function = false;
                status.openBracket = false;
                status.closeBracket = true;
                status.x = false;
                status.dot = false;
                status.unaryOperator = true;
            } else {
                validateStatus = false;
            }
        } else if (input[i] == '(') {
            if (status.openBracket) {
                status.number = true;
                status._operator = false;
                status.function = true;
                status.openBracket = true;
                status.closeBracket = false;
                status.x = true;
                status.dot = false;
                status.unaryOperator = true;

                status.bracketCount++;
            } else {
                validateStatus = false;
            }
        } else if (input[i] == ')') {
            if (status.closeBracket) {
                status.number = false;
                status._operator = true;
                status.function = false;
                status.openBracket = false;
                status.closeBracket = true;
                status.x = false;
                status.dot = false;
                status.unaryOperator = true;

                functionStatus = true;
                status.bracketCount--;
            } else {
                validateStatus = false;
            }
        } else if (input[i] == '.') {
            if (status.dot && status.dotCount == 0) {
                status.number = true;
                status._operator = false;
                status.function = false;
                status.openBracket = false;
                status.closeBracket = false;
                status.x = false;
                status.dot = false;
                status.unaryOperator = false;

                status.dotCount++;
            } else {
                validateStatus = false;
            }
        } else {
            validateStatus = false;
        }
    }

    if (status.bracketCount < 0 || input.back() == '(' || IsOperator(input.back())) {
        validateStatus = false;
    }

    return validateStatus && functionStatus;
}
