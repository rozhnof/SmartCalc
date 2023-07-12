#ifndef SRC_LIB_MAIN_H
#define SRC_LIB_MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

#include <inttypes.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIN 's'
#define COS 'c'
#define TAN 't'
#define ASIN 'S'
#define ACOS 'C'
#define ATAN 'T'
#define SQRT 'Q'
#define LN 'l'
#define LOG 'L'

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
  double number;
  NodeNumber* next;
};

typedef struct ConvertHelper {
  int in_idx;
  int out_idx;
  NodeOperator* top;
} ConvertHelper;

char* FromInfixToPostfix(char* input);
void PushOperator(char symbol, ConvertHelper* val);
void PopOperator(ConvertHelper* val);
int Priority(char symbol);
int IsNumber(char symbol);
int IsOperator(char symbol);
void PushOutAll(char* output, ConvertHelper* val);
int OperatorIsLeftAssociativity(char symbol);
void PushOutOperatorsBetweenBrackets(char* output, ConvertHelper* val);
void PushOut(char* output, ConvertHelper* val);
int PushOutConditions(char symbol, ConvertHelper* val);
void ReadNumber(char* input, char* output, ConvertHelper* val);
int IsUnaryOperator(char* input, int input_index);
int isFunction(char symbol);
void PushOutAndPush(char symbol, char* output, ConvertHelper* val);

double Calculation(const char* postfix, double x);
void PopNumber(NodeNumber** top);
void PushNumber(double number, NodeNumber** top);
void PushStrNumber(char* str_number, NodeNumber** top);
void CalculateTwoNumbersFromStack(char operation, NodeNumber** top);
void Factorial(NodeNumber** top);
void DecisionTrigonometricFunction(char number, NodeNumber** top);


#ifdef __cplusplus
}
#endif

#endif  // SRC_LIB_MAIN_H
