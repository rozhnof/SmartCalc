#include "GraphModel.h"

GraphModel::GraphModel() {}

GraphModel::~GraphModel() {}

void GraphModel::setInput(GraphInput input) {
  _input = input;
  _input.postfix = service.GetPostfixNotation(input.infix);
}

void GraphModel::Calculate() { _output = service.GetGraphResult(_input); }

GraphOutput GraphModel::getOutput() { return _output; }

std::vector<double> GraphModel::getCollectionX() { return _output.xPoints; }

std::vector<double> GraphModel::getCollectionY() { return _output.yPoints; }
