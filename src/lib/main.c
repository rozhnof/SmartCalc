#include "main.h"
#include <math.h>

int main() {
    char input[] = "x";
    char output[1024] = {0};
    char x[] = "786344374687437.347834534599";

    long double X = 786344374687437.0000034000007834534599;

    FromInfixToPostfix(input, output);

    long double result = Calculation(output, x);
    printf("%.30Lg\n", result);

    // long double original = sinl(cosl(tanl(asinl(acosl(atanl(log10l(logl(sqrtl(powl(X, fmodl(X,2)))))))))));
    printf("%.30Lg\n", X);
    
}
