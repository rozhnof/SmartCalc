#pragma once

#include <QString>
#include <algorithm>
#include <iostream>

#include "../../Services/Service.h"

class GraphValidator {
 public:
  bool Validate(const GraphInput &input);
};
