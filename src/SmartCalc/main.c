#include "SmartCalc.h"

int main() {
    char input[1024] = "x+x";
    char x_input_str[1024] = "2";

    char output[1024] = "";
    long double x_input_value = 0;

    FromInfixToPostfix(input, output);
    sscanf(x_input_str, "%Lf", &x_input_value);
    long double result = Calculation(output, x_input_value);;

    printf("%s\n", input);
    printf("%s\n", output);
    printf("%s\n", x_input_str);
    printf("%Lf\n", x_input_value);
    printf("%Lf\n", result);
}