#pragma once

#include <QDebug>
#include <QVector>

#include "../Models/GraphModel.h"
#include "Validators/GraphValidator.h"
#include "Validators/InfixNotationValidator.h"

class GraphController {
 private:
  GraphModel model_;
  InfixNotationValidator validatorInfixNotation_;
  GraphValidator graphValidator_;

 public:
  bool setInput(QString infix, int countPoints, double xMin, double xMax,
                double yMin, double yMax);

  QVector<double> getCollectionX();
  QVector<double> getCollectionY();

  bool Validate(QString &infix);
  bool Validate(const GraphInput &input);

  void Calculate();
};
