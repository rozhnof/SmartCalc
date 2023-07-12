#include <stdio.h>

#include "calc.h"

int main() {
  double x = 1.5;
  char* postfix = FromInfixToPostfix("cos(4)");
  printf("%s\n", postfix);
  printf("%lf\n", Calculation(postfix, x));
  // printf("%lf\n", sin(cos(tan(sqrt(pow(x, pow(x, x)))))));
}