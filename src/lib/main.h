#include "stdio.h"
#include "stdlib.h"
#include "inttypes.h"


typedef struct NodeOperator NodeOperator;

struct NodeOperator {
    int8_t operator;
    NodeOperator* next;
};

NodeOperator* top = NULL;


void push(NodeOperator* elem);
void pop(NodeOperator* elem);
void NodeOutput();


int IsNumber(char symbol);
int priority(char symbol);

void NumberOrPostfixFunction();
void FromInfixToPostfix();
void PushAllFromStack();
int Operator();
int PrefixFunction();
