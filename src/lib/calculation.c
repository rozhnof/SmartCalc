#include "main.h"
#include <string.h>
#include <math.h>


typedef struct NodeNumber NodeNumber;

struct NodeNumber {
    long double number;
    NodeNumber* next;
};

NodeNumber* top_number = NULL;

void PushNumber(NodeNumber* elem) {
    elem->next = top_number;
    top_number = elem;
}

void PopNumber(NodeNumber* elem) {
    top_number = elem->next;
    elem = NULL;
}

void NodeOutput() {
    NodeNumber* tmp_top_number = top_number;

    while (tmp_top_number != NULL) {
        printf("%.20Lf\n", tmp_top_number->number);
        tmp_top_number = tmp_top_number->next;
    }
}

void NumberToStack(long double number) {
    NodeNumber* node_numbers = malloc(sizeof(NodeNumber));
    node_numbers->number = number;
    PushNumber(node_numbers);
}

void PushNumberToStack(char* str_number) {
    long double number = 0;

    sscanf(str_number, "%Lf", &number);
    NumberToStack(number);
}

void CalculateTwoNumbersFromStack(char operation) {
    long double result = 0;

    long double number2 = top_number->number;
    PopNumber(top_number);

    long double number1 = top_number->number;
    PopNumber(top_number);

    if (operation == '+') {
        result = number1 + number2;
    } else if (operation == '-') {
        result = number1 - number2;
    } else if (operation == '*') {
        result = number1 * number2;
    } else if (operation == '/') {
        result = number1 / number2;
    } else if (operation == '^') {
        result = pow(number1, number2);
    } else if (operation == 'M') {
        result = fmodl(number1, number2);
    } 

    NumberToStack(result);
}

void Factorial() {
    long double number = top_number->number;
    long double int_part = 0;
    long double fract_part = 0;
    long double result = 1;

    fract_part = modfl(number, &int_part);
    if (fabsl(fract_part) < 1e-7) {
        while (int_part > 0) {
            result *= int_part;
            int_part--;
        }
    }
    top_number->number = result;
}

int IsTrigonometricFunction(char number) {
    return (number >= 1 && number <= 9);
}

void DecisionTrigonometricFunction(char number) {
    if (number == SIN) {
        top_number->number = sinl(top_number->number);
    } else if (number == COS) {
        top_number->number = cosl(top_number->number);
    } else if (number == TAN) {
        top_number->number = tanl(top_number->number);
    } else if (number == ASIN) {
        top_number->number = asinl(top_number->number);
    } else if (number == ACOS) {
        top_number->number = acosl(top_number->number);
    } else if (number == ATAN) {
        top_number->number = atanl(top_number->number);
    } else if (number == SQRT) {
        top_number->number = sqrtl(top_number->number);
    } else if (number == LN) {
        top_number->number = logl(top_number->number);
    } else if (number == LOG) {
        top_number->number = log10l(top_number->number);
    }
}

long double Calculation(char* output, char* x) {
    char* elem = strtok(output, " ");
    while (elem != NULL) {
        if (elem[0] == 'x') {
            PushNumberToStack(x);
        } else if (IsNumber(elem[0])) {
            PushNumberToStack(elem);
        } else if (IsOperator(elem[0]) && elem[0] != '~' || elem[0] == 'M') {
            CalculateTwoNumbersFromStack(elem[0]);
        } else if (elem[0] == '!') {
            Factorial();
        } else if (elem[0] == '~') {
            top_number->number = 0 - top_number->number;
        } else if (IsTrigonometricFunction(elem[0])) {
            DecisionTrigonometricFunction(elem[0]);
        }
        elem = strtok(NULL, " ");
    }
    long double result = top_number->number;
    PopNumber(top_number);

    return result;
}