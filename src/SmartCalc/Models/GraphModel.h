#ifndef GRAPHMODEL_H
#define GRAPHMODEL_H

#include "../Services/Service.h"


class GraphModel {

private:
    Service service;

    GraphInput _input;
    GraphOutput _output;
    std::string _postfix;

public:

    GraphModel() {}
    ~GraphModel() {}

    void setInput(const GraphInput &input) {
        _input = input;
        _postfix = service.GetPostfixNotation(input.infix);
    }
    
    GraphOutput Calculate() {
        return service.GetGraphResult(_input, _postfix);
    }
};


#endif // GRAPHMODEL_H
