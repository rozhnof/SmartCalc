#include "main.h"


typedef struct NodeNumber NodeNumber;

struct NodeNumber {
    long double number;
    NodeNumber* next;
};


NodeNumber* top = NULL;

void push(NodeNumber* elem) {
    elem->next = top;
    top = elem;
}

void pop(NodeNumber* elem) {
    top = elem->next;
    elem = NULL;
}

void NodeOutput() {
    NodeNumber* tmp_top = top;

    while (tmp_top != NULL) {
        printf("%c\n", tmp_top->number);
        tmp_top = tmp_top->next;
    }
}

void NumberToStack(long double number) {
    NodeNumber* node_numbers = malloc(sizeof(NodeNumber));
    node_numbers->number = number;
    push(node_numbers);
}

void FromStrToNumber(char* output) {

}

void Calculation(char* output) {
    int output_index = 0;

    if (IsNumber(output[output_index])) {
        FromStrToNumber(output)
    }
}