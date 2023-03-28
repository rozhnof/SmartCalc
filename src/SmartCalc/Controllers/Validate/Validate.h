#include <iostream>
#include <QString>
#include "../../Models/Model.h"


using namespace std;


class IValidate {
public:
    virtual string Validate(string input, const string &button) = 0;
};

class Validator {
private:
    IValidate* alg;
    string _input_text;
    string _button_text;
    string _result_text;
    
public:
    static bool dot_status;

    Validator(IValidate* rule);
    QString Validate(QString input, QString button);
};

class NumberValidate : public IValidate {   
public:
    string Validate(string input, const string &button) override;
};

class OperatorValidate : public IValidate {
public:
    string Validate(string input, const string &button) override;
};

class DotValidate : public IValidate {
public:
    string Validate(string input, const string &button) override;
};

class OpenBracketValidate : public IValidate {
public:
    string Validate(string input, const string &button) override;
};

class CloseBracketValidate : public IValidate {
public:
    string Validate(string input, const string &button) override;
};

class FunctionValidate : public IValidate {
public:
    string Validate(string input, const string &button) override;
};

class xValidate : public IValidate {
public:
    string Validate(string input, const string &button) override;
};

class ClearInput : public IValidate {
public:
    string Validate(string input, const string &button) override;
};

class ResultValidate : public IValidate {
public:
    string Validate(string input, const string &button) override;
};

class FactorialValidate : public IValidate {
public:
    string Validate(string input, const string &button) override;
};
