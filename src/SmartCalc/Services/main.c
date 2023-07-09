#include <stdio.h>
#include "calc.h"


int main() {
    char infix[] = "0.0000000000000001/0";
    char* postfix = FromInfixToPostfix(infix);
    printf("%s\n", postfix);
    printf("%f\n", Calculation(postfix, 0));
}