#include <iostream>
#include <QString>
#include "../Models/Model.h"
#include "Validate/Validate.h"
#include "Graph/Graph.h"


using namespace std;

class Controller {
private:
    string _input_text;
    string _button_text;
    string _result_text;
    long double result;
    char char_postfix[1024];


public:
    Graph *graph;

    Controller() : graph(new Graph) {}

    QString Validate(IValidate *rule, QString input, QString button, int &status) {
        Validator check(rule);

        _input_text = input.toStdString();
        _button_text = button.toStdString();
        _result_text = check.Validate(_input_text, _button_text, status);

        return QString::fromStdString(_result_text);
    }

    void ConvertToPostfix() {
        char* char_infix = new char[_result_text.length() + 1];
        strcpy(char_infix, _result_text.c_str());
        FromInfixToPostfix(char_infix, char_postfix);
        graph->SetInputValues(char_postfix);
    }

    int Calculate(double x_value) {
        result = Calculation(char_postfix, 0);
    }

    long double GetResult() {
        return result;
    }

};

