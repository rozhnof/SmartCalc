#include "main.h"
#include <math.h>

int main() {
    char input[] = "1+(2+(3+4+5+(6*(7+5^6+7-sin(cos(tan(3)))))))";
    char output[1024] = {0};
    char x[] = "0";

    FromInfixToPostfix(input, output);

    long double result = Calculation(output, x);
    printf("%Lg\n", result);
    
}
