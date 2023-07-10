#include <GraphController.h>



bool GraphController::setInput(QString infix, int countPoints, double xMin, double xMax, double yMin, double yMax) {
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

bool GraphController::Validate(QString &infix) {
    return validatorInfixNotation.Validate(infix);
}

bool GraphController::Validate(const GraphInput &input) {
    return graphValidator.Validate(input);
}

void GraphController::Calculate() {
    model.Calculate();
}

QVector<double> GraphController::getCollectionX() {
    std::vector<double> collectionX = model.getCollectionX();
    return QVector<double>(collectionX.begin(), collectionX.end());
}

QVector<double> GraphController::getCollectionY() {
    std::vector<double> collectionY = model.getCollectionY();
    return QVector<double>(collectionY.begin(), collectionY.end());
}
