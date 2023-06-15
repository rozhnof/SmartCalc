#include "calc.h"


void PushOperator(char symbol, ConvertHelper* val) {
    NodeOperator* elem = malloc(sizeof(NodeOperator));

    elem->next = val->top;
    elem->oper = symbol;

    val->top = elem;
}

void PopOperator(ConvertHelper* val) {
    NodeOperator* tmp = val->top;
    val->top = val->top->next;
    free(tmp);
    tmp = NULL;
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

int IsNumber(char symbol) {
    return (symbol >= '0' && symbol <= '9');
}

int IsOperator(char symbol) {
    return (symbol == '+' || symbol == '-' || symbol == '*' || symbol == '/' || symbol == '^' || symbol == '~');
}

void PushOutAll(char* output, ConvertHelper* val) {
    while (val->top != NULL) {
        output[val->out_idx++] = val->top->oper;
        output[val->out_idx++] = ' ';
        PopOperator(val);
    }
}

int OperatorIsLeftAssociativity(char symbol) {
    return (IsOperator(symbol) && symbol != '^' && symbol != '~');
}

void PushOutOperatorsBetweenBrackets(char* output, ConvertHelper* val) {
    while (val->top != NULL && val->top->oper != '(') {        
        PushOut(output, val);
    }

    if (val->top != NULL && val->top->oper == '(') {
        PopOperator(val);
    }
}

void PushOut(char* output, ConvertHelper* val) {
    output[val->out_idx++] = val->top->oper;
    output[val->out_idx++] = ' ';
    PopOperator(val);
}

int PushOutConditions(char symbol, ConvertHelper* val) {
    return (val->top != NULL && (Priority(val->top->oper) >= Priority(symbol) || 
                    (OperatorIsLeftAssociativity(val->top->oper) && 
                    Priority(val->top->oper) == Priority(symbol))));
}

void ReadNumber(char* input, char* output, ConvertHelper* val) { 
    while (IsNumber(input[val->in_idx]) || input[val->in_idx] == '.') {
        output[val->out_idx++] = input[val->in_idx++];
    }
    if (input[val->in_idx] == 'e' || input[val->in_idx] == 'E') {
        output[val->out_idx++] = input[val->in_idx++];
        if (input[val->in_idx] == '+' || input[val->in_idx] == '-') {
            output[val->out_idx++] = input[val->in_idx++];
        }
        while (IsNumber(input[val->in_idx])) {
            output[val->out_idx++] = input[val->in_idx++];
        }
    }
    val->in_idx--;
}

int IsUnaryOperator(char* input, int input_index) {
    int result = 0;

    if (input[input_index] == '-' || input[input_index] == '+') {
        if (input_index == 0) {
            result = 1;
        } else if (IsOperator(input[input_index - 1])) {
            result = 1;
        } else if (input[input_index - 1] == '(') {
            result = 1;
        }
    }
    return result;
}

int Function(char* input, char* output, ConvertHelper* val) {
    int result = 1;

    if (!strncmp(input, "sin", 3)) {
        DecisionFunction(input + 3, output, SIN, val);
    } else if (!strncmp(input, "cos", 3)) {
        DecisionFunction(input + 3, output, COS, val);
    } else if (!strncmp(input, "tan", 3)) {
        DecisionFunction(input + 3, output, TAN, val);
    } else if (!strncmp(input, "asin", 4)) {
        DecisionFunction(input + 4, output, ASIN, val);
    } else if (!strncmp(input, "acos", 4)) {
        DecisionFunction(input + 4, output, ACOS, val);
    } else if (!strncmp(input, "atan", 4)) {
        DecisionFunction(input + 4, output, ATAN, val);
    } else if (!strncmp(input, "sqrt", 4)) {
        DecisionFunction(input + 4, output, SQRT, val);
    } else if (!strncmp(input, "ln", 2)) {
        DecisionFunction(input + 2, output, LN, val);
    } else if (!strncmp(input, "log", 3)) {
        DecisionFunction(input + 3, output, LOG, val);
    } else {
        result = 0;
    }
    return result;
}

int DecisionFunction(char* input, char* output, char function, ConvertHelper* val) {
    PushOperator(function, val);

    char f_output[1024] = {0};
    Converter(input, f_output, val);  
    strcat(output, f_output);

    return 0;
}

void PushOutAndPush(char symbol, char* output, ConvertHelper* val) {
    while (PushOutConditions(symbol, val)) {
        PushOut(output, val);
    }
    PushOperator(symbol, val);
}

void Converter(char* input, char* output, ConvertHelper* val) {
    val->in_idx = 0;
    val->out_idx = 0;

    while (input[val->in_idx] != '\0') {
        if (input[val->in_idx] == 'x') {
            output[val->out_idx++] = 'x';
        } else if (IsNumber(input[val->in_idx])) {
            ReadNumber(input, output, val);
        } else if (input[val->in_idx] == '!') {
            output[val->out_idx++] = '!';
        } else if (Function(input + val->in_idx, output + val->out_idx, val)) {
            val->in_idx = strlen(input) - 1;
            val->out_idx = strlen(output);
        } else if (input[val->in_idx] == '(') {
            PushOperator('(', val);
        } else if (input[val->in_idx] == ')') {
            PushOutOperatorsBetweenBrackets(output, val);
        } else if (IsUnaryOperator(input, val->in_idx)) {
            if (input[val->in_idx] == '-') {
                PushOutAndPush('~', output, val);
            }
        } else if (IsOperator(input[val->in_idx])) {
            PushOutAndPush(input[val->in_idx], output, val);
        } else if (input[val->in_idx] == '%') {
            PushOutAndPush('%', output, val);
            val->in_idx += 2;
        }
        output[val->out_idx++] = ' ';
        val->in_idx++;
    }
    PushOutAll(output, val);
}

void FromInfixToPostfix(char* input, char* output) {
    ConvertHelper val = {0};
    val.top = NULL;

    Converter(input, output, &val);
}
