#pragma once

#include <QString>
#include <algorithm>
#include <iostream>

#include "../../Services/Service.h"

class CreditCalcValidator {
 public:
  bool Validate(const CreditCalculatorInput &input);
};
