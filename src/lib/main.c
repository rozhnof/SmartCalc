#include "main.h"


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

int main() {
    char input[] = "((2+3))";
    char output[1024] = {0};

    FromInfixToPostfix(input, output);

    printf("%s\n", output);
}

