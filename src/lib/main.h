#include "stdio.h"
#include "stdlib.h"
#include "inttypes.h"


typedef struct NodeOperator NodeOperator;

struct NodeOperator {
    int8_t operator;
    NodeOperator* next;
};



void push(NodeOperator* elem);
void pop(NodeOperator* elem);
void NodeOutput();


int Priority(char symbol);

int IsOperator(char symbol);
int IsNumber(char symbol);
void FromInfixToPostfix(char* input, char* output);
int IsPostfixFunction(char symbol);
int IsPrefixFunction();
void AllFromStack(char* output, int output_index);