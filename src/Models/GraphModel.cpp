#include "GraphModel.h"

GraphModel::GraphModel() {}

GraphModel::~GraphModel() {}

void GraphModel::setInput(GraphInput input) {
  input_ = input;
  input_.postfix = service_.GetPostfixNotation(input.infix);
}

void GraphModel::Calculate() { output_ = service_.GetGraphResult(input_); }

GraphOutput GraphModel::getOutput() { return output_; }

std::vector<double> GraphModel::getCollectionX() { return output_.xPoints; }

std::vector<double> GraphModel::getCollectionY() { return output_.yPoints; }
