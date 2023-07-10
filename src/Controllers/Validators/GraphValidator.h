#pragma once


#include <iostream>
#include <algorithm>
#include <QString>
#include "../../Services/Service.h"


class GraphValidator {
public:
    bool Validate(const GraphInput &input);
};
