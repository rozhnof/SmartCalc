#pragma once


#include "../Models/GraphModel.h"
#include "Validators/GraphValidator.h"
#include "Validators/InfixNotationValidator.h"
#include <QVector>
#include <QDebug>


class GraphController {

private:
    GraphModel model;
    InfixNotationValidator validatorInfixNotation;
    GraphValidator graphValidator;

public:

    bool setInput(QString infix, int countPoints, double xMin, double xMax, double yMin, double yMax);

    bool Validate(QString &infix);

    bool Validate(const GraphInput &input);

    void Calculate();

    QVector<double> getCollectionX();

    QVector<double> getCollectionY();
};
