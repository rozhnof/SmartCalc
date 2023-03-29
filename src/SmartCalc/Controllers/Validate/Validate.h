#include <iostream>
#include <QString>


using namespace std;


class IValidate {
public:
    virtual string Validate(string input, const string &button, int &status) = 0;
};

class Validator {
private:
    IValidate* alg;
    string _result_text;
    
public:
    static bool dot_status;
    static int brackets_count;
    static int IsOperator(char symbol);
    static int IsNumber(char symbol);

    Validator(IValidate* rule);
    string Validate(string input, string button, int &status);
};

class NumberValidate : public IValidate {   
public:
    string Validate(string input, const string &button, int &status) override;
};

class OperatorValidate : public IValidate {
public:
    string Validate(string input, const string &button, int &status) override;
};

class DotValidate : public IValidate {
public:
    string Validate(string input, const string &button, int &status) override;
};

class OpenBracketValidate : public IValidate {
public:
    string Validate(string input, const string &button, int &status) override;
};

class CloseBracketValidate : public IValidate {
public:
    string Validate(string input, const string &button, int &status) override;
};

class FunctionValidate : public IValidate {
public:
    string Validate(string input, const string &button, int &status) override;
};

class xValidate : public IValidate {
public:
    string Validate(string input, const string &button, int &status) override;
};

class ResultValidate : public IValidate {
public:
    string Validate(string input, const string &button, int &status) override;
};

class FactorialValidate : public IValidate {
public:
    string Validate(string input, const string &button, int &status) override;
};
