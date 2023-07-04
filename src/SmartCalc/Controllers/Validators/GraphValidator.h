#pragma once


#include <iostream>
#include <algorithm>
#include <QString>
#include "../../Services/Service.h"


class GraphValidator {
private:
    GraphInput _input;

public:
    GraphValidator(GraphInput &input) : _input(input) {}

    bool Validate() {
        bool status = true;

       if (_input.countPoints <= 0) {
           status = false;
       } else if (_input.xMax < _input.xMin) {
           status = false;
       } else if (_input.yMax < _input.yMin) {
           status = false;
       }

        return status;
    }
};
