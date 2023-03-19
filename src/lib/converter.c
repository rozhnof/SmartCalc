#include "main.h"


void PushOperator(NodeOperator* elem, NodeOperator* top) {
    elem->next = top;
    top = elem;
}

void PopOperator(NodeOperator* elem, NodeOperator* top) {
    top = elem->next;
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

void AllFromStack(char* output, int output_index, NodeOperator* top) {
    while (top != NULL) {
        output[output_index++] = top->oper;
        output[output_index++] = ' ';
        PopOperator(top, top);
    }
}

void OperatorToStack(char symbol, NodeOperator* top) {
    NodeOperator* node_operators = malloc(sizeof(NodeOperator));
    node_operators->oper = symbol;
    PushOperator(node_operators, top);
}

int OperatorIsLeftAssociativity(char symbol) {
    return (IsOperator(symbol) && symbol != '^' && symbol != '~');
}

void OperatorsBetweenBracketsToOutput(char* output, int* output_index, NodeOperator* top) {
    while (top != NULL && top->oper != '(') {
        PushOutFromStackToOutput(output, output_index, top);
    }
    if (top->oper == '(') {
        PopOperator(top, top);
    } else {
        exit(1); // ------------------------------------------------------------------------------------------------------------------------ remade
    }
}

void PushOutFromStackToOutput(char* output, int *output_index, NodeOperator* top) {
    output[(*output_index)++] = top->oper;
    output[(*output_index)++] = ' ';
    PopOperator(top, top);
}

int PushOutConditions(char symbol, NodeOperator* top) {
    return (top != NULL && (Priority(top->oper) >= Priority(symbol) || 
                    (OperatorIsLeftAssociativity(top->oper) && 
                    Priority(top->oper) == Priority(symbol))));
}

void ReadNumber(char* input, char* output, int* input_index, int* output_index, NodeOperator* top) {
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

int Function(char* input, char* output, NodeOperator* top) {
    int result = 1;

    if (!strncmp(input, "sin", 3)) {
        DecisionFunction(input + 3, output, SIN, top);
    } else if (!strncmp(input, "cos", 3)) {
        DecisionFunction(input + 3, output, COS, top);
    } else if (!strncmp(input, "tan", 3)) {
        DecisionFunction(input + 3, output, TAN, top);
    } else if (!strncmp(input, "asin", 4)) {
        DecisionFunction(input + 4, output, ASIN, top);
    } else if (!strncmp(input, "acos", 4)) {
        DecisionFunction(input + 4, output, ACOS, top);
    } else if (!strncmp(input, "atan", 4)) {
        DecisionFunction(input + 4, output, ATAN, top);
    } else if (!strncmp(input, "sqrt", 4)) {
        DecisionFunction(input + 4, output, SQRT, top);
    } else if (!strncmp(input, "ln", 2)) {
        DecisionFunction(input + 2, output, LN, top);
    } else if (!strncmp(input, "log", 3)) {
        DecisionFunction(input + 3, output, LOG, top);
    } else {
        result = 0;
    }
    return result;
}

int DecisionFunction(char* input, char* output, char function, NodeOperator* top) {
    OperatorToStack(function, top);

    char f_output[1024] = {0};

    FromInfixToPostfix(input, f_output);  
    strcat(output, f_output);

    return 0;
}

void PushOutAndPush(char symbol, char* output, int* output_index, NodeOperator* top) {
    while (PushOutConditions(symbol, top)) {
        PushOutFromStackToOutput(output, output_index, top);
    }
    OperatorToStack(symbol, top);
}

void FromInfixToPostfix(char* input, char* output) {
    int input_index = 0;
    int output_index = 0;
    NodeOperator* top_operator = NULL;

    while (input[input_index] != '\0') {
        if (input[input_index] == 'x') {
            output[output_index++] = 'x';
        } else if (IsNumber(input[input_index])) {
            ReadNumber(input, output, &input_index, &output_index, top_operator);
        } else if (IsPostfixFunction(input[input_index])) {
            output[output_index++] = input[input_index];
        } else if (Function(input + input_index, output + output_index, top_operator)) {
            input_index = strlen(input) - 1;
            output_index = strlen(output);
        } else if (input[input_index] == '(') {
            OperatorToStack(input[input_index], top_operator);
        } else if (input[input_index] == ')') {
            OperatorsBetweenBracketsToOutput(output, &output_index, top_operator);
        } else if (IsUnaryOperator(input, input_index)) {
            if (input[input_index] == '-') {
                PushOutAndPush('~', output, &output_index, top_operator);
            }
        } else if (IsOperator(input[input_index])) {
            PushOutAndPush(input[input_index], output, &output_index, top_operator);
        } else if (!strncmp(input + input_index, "mod", 3)) {
            PushOutAndPush(MOD, output, &output_index, top_operator);
            input_index += 2;
        }
        output[output_index++] = ' ';
        input_index++;
    }
    AllFromStack(output, output_index, top_operator);
}
