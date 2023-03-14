#include "main.h"




int main() {
    char input[] = "2*(3+(6+7*(2-9))+4)*3+7";
    char output[1024] = {0};

    FromInfixToPostfix(input, output);
    
    printf("%s\n", output);
}

