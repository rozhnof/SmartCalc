#include "main.h"


int main() {
    char input[] = "3+4*2/(1-5)^2";
    char output[1024] = {0};

    FromInfixToPostfix(input, output);
    
    printf("%s\n", output);
}

