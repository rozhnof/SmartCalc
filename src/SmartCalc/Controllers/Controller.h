#pragma once

#include "../Models/Model.h"
#include <QString>
#include "Validate/Validator.h"

using namespace std;


class Controller {

private:
    Model *model;

public:
    bool ResultValidate(QString input) {
        Validator check(input.toStdString());
        return check.Validate();
    }
};
