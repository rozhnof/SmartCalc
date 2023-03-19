#ifndef SRC_LIB_MAIN_H
#define SRC_LIB_MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include <string.h>
#include <math.h>


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


typedef struct Credit {
    double sum;
    double term;
    double percent;

    double first_monthly_payment;
    double monthly_payment;
    double total_payment;
    double overpayment;
} Credit;



typedef struct NodeOperator NodeOperator;

typedef struct NodeOperator {
    int8_t oper;
    NodeOperator* next;
};


void FromInfixToPostfix(char* input, char* output);
long double Calculation(char* output, double x);
int SetNumberValid(char* input);
int SetOperatorValid(char* input);
int SetDotValid(char* input);
int SetOpenBracketValid(char* input);
int SetCloseBracketValid(char* input);
int SetFuncValid(char* input);
int SetModValid(char* input);
int SetXValid(char* input);
int XValid(char* input);
int ClearInput(char* input);
int ResultInputValid(char* input);


void AnnuityLoan(Credit* values);
void DifferentiatedLoan(Credit* values);


int Priority(char symbol);

int IsOperator(char symbol);
int IsNumber(char symbol);
int IsPostfixFunction(char symbol);
int IsUnaryOperator(char* input, int input_index);

int PushOutConditions(char symbol, NodeOperator* top);
void PushOutFromStackToOutput(char* output, int *output_index, NodeOperator* top);
void OperatorsBetweenBracketsToOutput(char* output, int* output_index, NodeOperator* top);
int OperatorIsLeftAssociativity(char symbol);
void OperatorToStack(char symbol, NodeOperator* top);
void AllFromStack(char* output, int output_index, NodeOperator* top);
void ReadNumber(char* input, char* output, int* input_index, int* output_index, NodeOperator* top);
void PushOutAndPush(char symbol, char* output, int* output_index, NodeOperator* top);

int Function(char* input, char* output, NodeOperator* top);
int DecisionFunction(char* input, char* output, char function, NodeOperator* top);

void PushNumberToStack(char* str_number);
void NumberToStack(long double number);
void Factorial();


#ifdef __cplusplus
}
#endif

#endif  // SRC_LIB_MAIN_H
