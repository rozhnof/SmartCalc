#pragma once

#include <QString>
#include <algorithm>
#include <iostream>

#include "../../Services/Service.h"

class DepositCalcValidator {
 public:
  bool Validate(const DepositCalculatorInput &input);
};
