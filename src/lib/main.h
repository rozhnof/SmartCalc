#ifdef __cplusplus

extern "C" {

#endif


#include "stdio.h"
#include "stdlib.h"
#include "inttypes.h"


#define SIN 1
#define COS 2
#define TAN 3
#define ASIN 4
#define ACOS 5
#define ATAN 6
#define SQRT 7
#define LN 8
#define LOG 9
#define MOD 'M'


void FromInfixToPostfix(char* input, char* output);

int Priority(char symbol);

int IsOperator(char symbol);
int IsNumber(char symbol);
int IsPostfixFunction(char symbol);

int PushOutConditions(char symbol);
void PushOutFromStackToOutput(char* output, int *output_index);
void OperatorsBetweenBracketsToOutput(char* output, int* output_index);
int OperatorIsLeftAssociativity(char symbol);
void OperatorToStack(char symbol);
void AllFromStack(char* output, int output_index);
void ReadNumber(char* input, char* output, int* input_index, int* output_index);
void PushOutAndPush(char symbol, char* output, int* output_index);

int Function(char* input, char* output);
int DecisionFunction(char* input, char* output, char function);


long double Calculation(char* output, char* x);

void PushNumberToStack(char* str_number);
void NumberToStack(long double number);
void Factorial();
void NodeOutput();


#ifdef __cplusplus
}

#endif