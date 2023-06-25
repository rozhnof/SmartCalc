#include <stdio.h>
#include "calc.h"

int main() {
    char* input = "(-2-2)";
    char output[255];

    FromInfixToPostfix(input, output);
    printf("%s\n", output);
    printf("%f\n", Calculation(output, 0));
}