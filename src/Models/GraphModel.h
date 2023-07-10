#pragma once


#include "../Services/Service.h"


class GraphModel {

private:
    Service service;

    GraphInput _input;
    GraphOutput _output;

public:

    GraphModel();
    ~GraphModel();

    void setInput(GraphInput input);
    
    void Calculate();

    GraphOutput getOutput();

    std::vector<double> getCollectionX();

    std::vector<double> getCollectionY();
};

