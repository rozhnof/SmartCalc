#include "main.h"


typedef struct NodeOperator NodeOperator;

struct NodeOperator {
    int8_t operator;
    NodeOperator* next;
};


NodeOperator* top = NULL;

void push(NodeOperator* elem) {
    elem->next = top;
    top = elem;
}

void pop(NodeOperator* elem) {
    top = elem->next;
    elem = NULL;
}

void NodeOutput() {
    NodeOperator* tmp_top = top;

    while (tmp_top != NULL) {
        printf("%c\n", tmp_top->operator);
        tmp_top = tmp_top->next;
    }
}


int Priority(char symbol) {
    int result = 0;

    switch (symbol) {
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
    return (symbol == '+' || symbol == '-' || symbol == '*' || symbol == '/' || symbol == '^');
}

void AllFromStack(char* output, int output_index) {
    while (top != NULL) {
        output[output_index++] = top->operator;
        pop(top);
    }
}

void OperatorToStack(char symbol) {
    NodeOperator* node_operators = malloc(sizeof(NodeOperator));
    node_operators->operator = symbol;
    push(node_operators);
}

int OperatorIsLeftAssociativity(char symbol) {
    return (IsOperator(symbol) && symbol != '^');
}

void OperatorsBetweenBracketsToOutput(char* output, int* output_index) {
    while (top->operator != '(') {
        PushOutFromStackToOutput(output, output_index);
    }
    pop(top);
}

void PushOutFromStackToOutput(char* output, int *output_index) {
    output[(*output_index)++] = top->operator;
    pop(top);
}

int PushOutConditions(char symbol) {
    return (top != NULL && (IsPrefixFunction(top->operator) || 
                    Priority(top->operator) >= Priority(symbol) || 
                    (OperatorIsLeftAssociativity(top->operator) && 
                    Priority(top->operator) == Priority(symbol))));
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

void FromInfixToPostfix(char* input, char* output) {
    int input_index = 0;
    int output_index = 0;

    while (input[input_index] != '\0') {
        if (IsNumber(input[input_index])) {
            ReadNumber(input, output, &input_index, &output_index);
            output[output_index++] = ' ';
        } else if (IsPostfixFunction(input[input_index])) {
            output[output_index++] = input[input_index];
            output[output_index++] = ' ';
        } else if (IsPrefixFunction(input[input_index])) {
            OperatorToStack(input[input_index]);
        } else if (input[input_index] == '(') {
            OperatorToStack(input[input_index]);
        } else if (input[input_index] == ')') {
            OperatorsBetweenBracketsToOutput(output, &output_index);
            output[output_index++] = ' ';
        } else if (IsOperator(input[input_index])) {
            while (PushOutConditions(input[input_index])) {
                PushOutFromStackToOutput(output, &output_index);
                output[output_index++] = ' ';
            }
            OperatorToStack(input[input_index]);
        }
        input_index++;
    }
    AllFromStack(output, output_index);
}
