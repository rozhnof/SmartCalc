#include "main.h"
#include <string.h>


typedef struct NodeOperator NodeOperator;

struct NodeOperator {
    int8_t operator;
    NodeOperator* next;
};

NodeOperator* top_operator = NULL;

void PushOperator(NodeOperator* elem) {
    elem->next = top_operator;
    top_operator = elem;
}

void PopOperator(NodeOperator* elem) {
    top_operator = elem->next;
    elem = NULL;
}

int Priority(char symbol) {
    int result = 0;

    if (symbol == '~') {
        result = 4;
    } else if (symbol == '^') {
        result = 3;
    } else if (symbol == 'M') {
        result = 2;
    } else if (symbol == '*') {
        result = 2;
    } else if (symbol == '/') {
        result = 2;
    } else if (symbol == '+') {
        result = 1;
    } else if (symbol == '-') {
        result = 1;
    }
    return result;
}

int IsPostfixFunction(char symbol) {
    return (symbol == '!');
}

int IsNumber(char symbol) {
    return (symbol >= '0' && symbol <= '9');
}

int IsOperator(char symbol) {
    return (symbol == '+' || symbol == '-' || symbol == '*' || symbol == '/' || symbol == '^' || symbol == '~');
}

void AllFromStack(char* output, int output_index) {
    while (top_operator != NULL) {
        output[output_index++] = top_operator->operator;
        output[output_index++] = ' ';
        PopOperator(top_operator);
    }
}

void OperatorToStack(char symbol) {
    NodeOperator* node_operators = malloc(sizeof(NodeOperator));
    node_operators->operator = symbol;
    PushOperator(node_operators);
}

int OperatorIsLeftAssociativity(char symbol) {
    return (IsOperator(symbol) && symbol != '^' && symbol != '~');
}

void OperatorsBetweenBracketsToOutput(char* output, int* output_index) {
    while (top_operator != NULL && top_operator->operator != '(') {
        PushOutFromStackToOutput(output, output_index);
    }
    if (top_operator->operator == '(') {
        PopOperator(top_operator);
    } else {
        exit(1); // ------------------------------------------------------------------------------------------------------------------------ remade
    }
}

void PushOutFromStackToOutput(char* output, int *output_index) {
    output[(*output_index)++] = top_operator->operator;
    output[(*output_index)++] = ' ';
    PopOperator(top_operator);
}

int PushOutConditions(char symbol) {
    return (top_operator != NULL && (Priority(top_operator->operator) >= Priority(symbol) || 
                    (OperatorIsLeftAssociativity(top_operator->operator) && 
                    Priority(top_operator->operator) == Priority(symbol))));
}

void ReadNumber(char* input, char* output, int* input_index, int* output_index) {
    int i = *input_index;
    int j = *output_index;

    while (IsNumber(input[i]) || input[i] == '.') {
        output[j++] = input[i++];
    }
    *input_index = i - 1;
    *output_index = j;
}

int IsUnaryOperator(char* input, int input_index) {
    int result = 0;

    if (input[input_index] == '-' || input[input_index] == '+') {
        if (input_index == 0 || IsOperator(input[input_index - 1]) || input[input_index - 1] == '(') {
            result = 1;
        }
    }
    return result;
}

int Function(char* input, char* output) {
    int result = 1;

    if (!strncmp(input, "sin", 3)) {
        DecisionFunction(input + 3, output, SIN);
    } else if (!strncmp(input, "cos", 3)) {
        DecisionFunction(input + 3, output, COS);
    } else if (!strncmp(input, "tan", 3)) {
        DecisionFunction(input + 3, output, TAN);
    } else if (!strncmp(input, "asin", 4)) {
        DecisionFunction(input + 4, output, ASIN);
    } else if (!strncmp(input, "acos", 4)) {
        DecisionFunction(input + 4, output, ACOS);
    } else if (!strncmp(input, "atan", 4)) {
        DecisionFunction(input + 4, output, ATAN);
    } else if (!strncmp(input, "sqrt", 4)) {
        DecisionFunction(input + 4, output, SQRT);
    } else if (!strncmp(input, "ln", 2)) {
        DecisionFunction(input + 2, output, LN);
    } else if (!strncmp(input, "log", 3)) {
        DecisionFunction(input + 3, output, LOG);
    } else {
        result = 0;
    }
    return result;
}

int DecisionFunction(char* input, char* output, char function) {
    OperatorToStack(function);

    int f_input_index = 0;
    char f_output[1024] = {0};

    FromInfixToPostfix(input, f_output);  
    strcat(output, f_output);
}

void PushOutAndPush(char symbol, char* output, int* output_index) {
    while (PushOutConditions(symbol)) {
        PushOutFromStackToOutput(output, output_index);
    }
    OperatorToStack(symbol);
}

void FromInfixToPostfix(char* input, char* output) {
    int input_index = 0;
    int output_index = 0;

    while (input[input_index] != '\0') {
        if (input[input_index] == 'x') {
            output[output_index++] = 'x';
        } else if (IsNumber(input[input_index])) {
            ReadNumber(input, output, &input_index, &output_index);
        } else if (IsPostfixFunction(input[input_index])) {
            output[output_index++] = input[input_index];
        } else if (Function(input + input_index, output + output_index)) {
            input_index = strlen(input) - 1;
            output_index = strlen(output);
        } else if (input[input_index] == '(') {
            OperatorToStack(input[input_index]);
        } else if (input[input_index] == ')') {
            OperatorsBetweenBracketsToOutput(output, &output_index);
        } else if (IsUnaryOperator(input, input_index)) {
            if (input[input_index] == '-') {
                PushOutAndPush('~', output, &output_index);
            }
        } else if (IsOperator(input[input_index])) {
            PushOutAndPush(input[input_index], output, &output_index);
        } else if (!strncmp(input + input_index, "mod", 3)) {
            PushOutAndPush(MOD, output, &output_index);
            input_index += 2;
        }
        output[output_index++] = ' ';
        input_index++;
    }
    AllFromStack(output, output_index);
}
