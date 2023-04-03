#include "../Models/Model.h"
#include "Validate/Validate.h"
#include "Graph/Graph.h"


using namespace std;

class Controller {
private:
    GraphBack *graph;

    string _input_text;
    string _button_text;
    string _result_text;
    double result;
    char char_postfix[1024];

public:

    Controller() : graph(new GraphBack) {}

    QString Validate(IValidate *rule, QString input, QString button, int &status) {
        Validator check(rule);

        _input_text = input.toStdString();
        _button_text = button.toStdString();
        _result_text = check.Validate(_input_text, _button_text, status);

        return QString::fromStdString(_result_text);
    }

    double GetResult() {

    }


};

