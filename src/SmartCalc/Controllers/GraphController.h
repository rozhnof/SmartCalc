#ifndef GRAPHCONTROLLER_H
#define GRAPHCONTROLLER_H

#include "Controller.h"
#include "../Models/GraphModel.h"

using namespace std;

class GraphController : public Controller {

private:

    GraphModel *model;
public:

    GraphController() {
        model = new GraphModel;
    }

    void SetInput(string input) {
        model->SetInput(input);
    }

    double GetResult(double x) {
        return model->Calculate(x);
    }
};


#endif // GRAPHCONTROLLER_H
