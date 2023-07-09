#pragma once


#include <iostream>
#include <algorithm>
#include <QString>
#include "../../Services/Service.h"


class GraphValidator {
public:
    bool Validate(const GraphInput &input) {
        bool status = true;

       if (input.countPoints <= 0) {
           status = false;
       } else if (input.xMax < input.xMin) {
           status = false;
       } else if (input.yMax < input.yMin) {
           status = false;
       }
        return status;
    }
};
