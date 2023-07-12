#pragma once

#include "../Services/Service.h"

class GraphModel {
 private:
  Service service_;
  GraphInput input_;
  GraphOutput output_;

 public:
  GraphModel();
  ~GraphModel();

  void setInput(GraphInput input);

  GraphOutput getOutput();
  std::vector<double> getCollectionX();
  std::vector<double> getCollectionY();

  void Calculate();
};
