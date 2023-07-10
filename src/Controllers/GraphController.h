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

    bool setInput(QString infix, int countPoints, double xMin, double xMax, double yMin, double yMax) {        
        bool status = Validate(infix);

        if (status) {
            GraphInput input;

            input.infix = infix.toStdString();
            input.countPoints = countPoints;
            input.xMax = xMax;
            input.xMin = xMin;
            input.yMax = yMax;
            input.yMin = yMin;

            status = Validate(input);

            if (status) {
                model.setInput(input);
            }
        }

        return status;
    }

    bool Validate(QString &infix) {
        return validatorInfixNotation.Validate(infix);
    }

    bool Validate(const GraphInput &input) {
        return graphValidator.Validate(input);
    }

    void Calculate() {
        model.Calculate();
    }

    QVector<double> getCollectionX() {
        std::vector<double> collectionX = model.getCollectionX();
        return QVector<double>(collectionX.begin(), collectionX.end());
    }

    QVector<double> getCollectionY() {
        std::vector<double> collectionY = model.getCollectionY();
        return QVector<double>(collectionY.begin(), collectionY.end());
    }
};
