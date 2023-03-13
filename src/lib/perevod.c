#include "main.h"

int priority(char symbol) {
    int result = 0;

    switch (symbol) {
        case '(':
        case ')':
        {
            result = 4;
            break;
        }
        case '^':
        {
            result = 3;
            break;
        }
        case '/':
        case '*':
        {
            result = 2;
            break;
        }
        case '+':
        case '-':
        {
            result = 1;
            break;
        }
    }
    return result;
}

int IsPostfixFunction(char symbol) {
    return (symbol == '!');
}

int IsNumber(char symbol) {
    return (symbol >= '0' && symbol <= '9');
}

int IsPrefixFunction() {

}

int IsOperator(char symbol) {
    return (symbol == '+' || symbol == '-' || symbol == '*' || symbol == '/');
}

void PushAllFromStack(char* output, int* output_size) {

}

void FromInfixToPostfix(char* input, char* output) {
    int input_index = 0;
    int output_index = 0;

    while (input[input_index] != '\0') {
        if (IsNumber) {

        } else {
            output[output_index++] = ' ';

            if (IsPostfixFunction) {

            } else if (IsPrefixFunction) {

            } else if (IsOperator) {

            }

            output[output_index++] = ' ';
        } 
        
        input_index++;
    }
}

