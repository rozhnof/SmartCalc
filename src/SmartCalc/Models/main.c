#include <stdio.h>
#include "Model.h"

int main() {
    char input[] = "sin(x)";
    char output[1024];
    FromInfixToPostfix(input, output);

    long double result = Calculation(output, 1);

    printf("%Lf\n", result);

}