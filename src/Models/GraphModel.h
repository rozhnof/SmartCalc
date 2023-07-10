#pragma once


#include "../Services/Service.h"


class GraphModel {

private:
    Service service;

    GraphInput _input;
    GraphOutput _output;

public:

    GraphModel() {}
    ~GraphModel() {}

    void setInput(GraphInput input) {
        _input = input;
        _input.postfix = service.GetPostfixNotation(input.infix);
    }
    
    void Calculate() {
        _output = service.GetGraphResult(_input);
    }

    GraphOutput getOutput() {
        return _output;
    }

    std::vector<double> getCollectionX() {
        return _output.xPoints;
    }

    std::vector<double> getCollectionY() {
        return _output.yPoints;
    }
};

