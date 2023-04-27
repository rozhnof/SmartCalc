#ifndef GRAPHCONTROLLER_H
#define GRAPHCONTROLLER_H

#include "Controller.h"

using namespace std;

class GraphController {

private:

    Model *model;
public:

    GraphController() {
        model = new Model;
    }

    void SetInput(string input) {
        model->SetInput(input);
    }

    double GetResult(double x) {
        return model->Calculate(x);
    }
};


#endif // GRAPHCONTROLLER_H
