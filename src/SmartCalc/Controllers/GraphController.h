#pragma once


#include "../Models/GraphModel.h"
#include "Validators/GraphValidator.h"
#include "Validators/CalcValidator.h"


class GraphController {

private:
    GraphModel *model;

public:

    GraphController() {
        model = new GraphModel;
    }

    void SetInput(GraphInput &input) {
        model->setInput(input);
    }

    bool Validate(QString &input) {
        InfixNotationValidator validator(input);
        return validator.Validate();
    }

    GraphOutput Calculate() {
        model->Calculate();
    }
};
