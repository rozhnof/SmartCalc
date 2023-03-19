#include "main.h"

int main() {
    char input[] = "12+1";
    char output[1024];
    printf("%s\n", input);

    FromInfixToPostfix(input, output);

    printf("%s\n", output);
}