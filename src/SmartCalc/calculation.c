#include "SmartCalc.h"


void PopNumber(NodeNumber* *top) {
    NodeNumber* tmp = *top;
    *top = (**top).next;
    free(tmp);
}

void PushNumber(long double number, NodeNumber* *top) {
    NodeNumber* elem = malloc(sizeof(NodeNumber));

    elem->next = *top;
    elem->number = number;

    *top = elem;
}

void PushStrNumber(char* str_number, NodeNumber* *top) {
    NodeNumber* elem = malloc(sizeof(NodeNumber));

    long double number = 0;
    sscanf(str_number, "%Lf", &number);

    elem->next = *top;
    elem->number = number;

    *top = elem;
}


void CalculateTwoNumbersFromStack(char operation, NodeNumber* *top) {
    long double result = 0;

    long double number2 = (**top).number;
    PopNumber(top);

    long double number1 = (**top).number;
    PopNumber(top);

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

    PushNumber(result, top);
}

void Factorial(NodeNumber* *top) {
    long double number = (**top).number;
    long double result = 1;

    while (number > 0) {
        result *= number;
        number--;
    }
    
    (**top).number = result;
}

int IsTrigonometricFunction(char number) {
    return (number >= 1 && number <= 9);
}

void DecisionTrigonometricFunction(char number, NodeNumber* *top) {
    if (number == SIN) {
        (**top).number = sinl((**top).number);
    } else if (number == COS) {
        (**top).number = cosl((**top).number);
    } else if (number == TAN) {
        (**top).number = tanl((**top).number);
    } else if (number == ASIN) {
        (**top).number = asinl((**top).number);
    } else if (number == ACOS) {
        (**top).number = acosl((**top).number);
    } else if (number == ATAN) {
        (**top).number = atanl((**top).number);
    } else if (number == SQRT) {
        (**top).number = sqrtl((**top).number);
    } else if (number == LN) {
        (**top).number = logl((**top).number);
    } else if (number == LOG) {
        (**top).number = log10l((**top).number);
    }
}

long double Calculation(char* output, double x) {
    char tmp_output[1024] = {0};
    for (int i = 0; output[i] != '\0'; i++) {
        tmp_output[i] = output[i];
    }

    NodeNumber* top = NULL;

    char* elem = strtok(tmp_output, " ");
    while (elem != NULL) {
        if (elem[0] == 'x') {
            PushNumber(x, &top);
        } else if (IsNumber(elem[0])) {
            PushStrNumber(elem, &top);
        } else if ((IsOperator(elem[0]) || elem[0] == MOD ) && elem[0] != '~') {
            CalculateTwoNumbersFromStack(elem[0], &top);
        } else if (elem[0] == '!') {
            Factorial(&top);
        } else if (elem[0] == '~') {
            top->number = 0 - top->number;
        } else if (IsTrigonometricFunction(elem[0])) {
            DecisionTrigonometricFunction(elem[0], &top);
        }
        elem = strtok(NULL, " ");
    }
    long double result = top->number;
    PopNumber(&top);

    return result;
}