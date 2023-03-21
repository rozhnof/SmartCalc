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
} NodeOperator;

typedef struct NodeNumber NodeNumber;

struct NodeNumber {
    long double number;
    NodeNumber* next;
};


typedef struct ConvertHelper {
    int in_idx;
    int out_idx;
    NodeOperator* top;
} ConvertHelper;



void FromInfixToPostfix(char* input, char* output);
void PushOperator(char symbol, ConvertHelper* val);
void PopOperator(ConvertHelper* val);
int Priority(char symbol);
int IsNumber(char symbol);
int IsOperator(char symbol);
void PushOutAll(char* output, ConvertHelper* val);
int OperatorIsLeftAssociativity(char symbol);
void OperatorsBetweenBracketsToOutput(char* output, ConvertHelper* val);
void PushOut(char* output, ConvertHelper* val);
int PushOutConditions(char symbol, ConvertHelper* val);
void ReadNumber(char* input, char* output, ConvertHelper* val); 
int IsUnaryOperator(char* input, int input_index);
int Function(char* input, char* output, ConvertHelper* val);
int DecisionFunction(char* input, char* output, char function, ConvertHelper* val);
void PushOutAndPush(char symbol, char* output, ConvertHelper* val);
void Converter(char* input, char* output, ConvertHelper* val);

long double Calculation(char* output, double x);
void PopNumber(NodeNumber* *top);
void PushNumber(long double number, NodeNumber* *top);
void PushStrNumber(char* str_number, NodeNumber* *top);
void CalculateTwoNumbersFromStack(char operation, NodeNumber* *top);
void Factorial(NodeNumber* *top);
int IsTrigonometricFunction(char number);
void DecisionTrigonometricFunction(char number, NodeNumber* *top);

int SetNumberValid(char* input);
int SetOperatorValid(char* input);
int SetDotValid(char* input);
int SetOpenBracketValid(char* input);
int SetCloseBracketValid(char* input);
int SetFuncValid(char* input);
int SetModValid(char* input);
int XValid(char* input);
int SetXValid(char* input);
int ClearInput(char* input);
int IsNeedToClear(int index, int last_elem, char symbol);
int ResultInputValid(char* input);

void AnnuityLoan(Credit* values);
void DifferentiatedLoan(Credit* values);


#ifdef __cplusplus
}
#endif

#endif  // SRC_LIB_MAIN_H
