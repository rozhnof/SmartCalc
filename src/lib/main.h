#include "stdio.h"
#include "stdlib.h"
#include "inttypes.h"


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
void ReadNumber(char* input, char* output, int* input_index, int* output_index);