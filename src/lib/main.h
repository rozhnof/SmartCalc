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


void FromInfixToPostfix(char* input, char* output);

int Priority(char symbol);

int IsOperator(char symbol);
int IsNumber(char symbol);
int IsPostfixFunction(char symbol);
int IsPrefixFunction();

int PushOutConditions(char symbol);
void PushOutFromStackToOutput(char* output, int *output_index);
void OperatorsBetweenBracketsToOutput(char* output, int* output_index);
int OperatorIsLeftAssociativity(char symbol);
void OperatorToStack(char symbol);
void AllFromStack(char* output, int output_index);
