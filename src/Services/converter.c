#include "calc.h"

void PushOperator(char symbol, ConvertHelper* val) {
  NodeOperator* elem = malloc(sizeof(NodeOperator));

  elem->next = val->top;
  elem->oper = symbol;

  val->top = elem;
}

void PopOperator(ConvertHelper* val) {
  NodeOperator* tmp = val->top;
  val->top = val->top->next;
  free(tmp);
  tmp = NULL;
}

int Priority(char symbol) {
  int result = 0;

  if (symbol == '~') {
    result = 4;
  } else if (symbol == '^') {
    result = 3;
  } else if (symbol == '*') {
    result = 2;
  } else if (symbol == '/') {
    result = 2;
  } else if (symbol == '%') {
    result = 2;
  } else if (symbol == '+') {
    result = 1;
  } else if (symbol == '-') {
    result = 1;
  }
  return result;
}

int IsNumber(char symbol) { return (symbol >= '0' && symbol <= '9'); }

int IsOperator(char symbol) {
  return (symbol == '+' || symbol == '-' || symbol == '*' || symbol == '/' ||
          symbol == '^' || symbol == '~' || symbol == '%');
}

void PushOutAll(char* output, ConvertHelper* val) {
  while (val->top != NULL) {
    output[val->out_idx++] = val->top->oper;

    output[val->out_idx++] = ' ';

    PopOperator(val);
  }
}

int OperatorIsLeftAssociativity(char symbol) {
  return (IsOperator(symbol) && symbol != '^' && symbol != '~');
}

void PushOutOperatorsBetweenBrackets(char* output, ConvertHelper* val) {
  while (val->top->oper != '(') {
    PushOut(output, val);
  }
  PopOperator(val);
}

void PushOut(char* output, ConvertHelper* val) {
  output[val->out_idx++] = val->top->oper;
  output[val->out_idx++] = ' ';
  PopOperator(val);
}

int PushOutConditions(char symbol, ConvertHelper* val) {
  return val->top != NULL && (isFunction(val->top->oper) ||
                              Priority(val->top->oper) > Priority(symbol) ||
                              (OperatorIsLeftAssociativity(val->top->oper) &&
                               Priority(val->top->oper) == Priority(symbol)));
}

void PushOutAndPush(char symbol, char* output, ConvertHelper* val) {
  while (PushOutConditions(symbol, val)) {
    PushOut(output, val);
  }
  PushOperator(symbol, val);
}

void ReadNumber(char* input, char* output, ConvertHelper* val) {
  while (IsNumber(input[val->in_idx]) || input[val->in_idx] == '.') {
    output[val->out_idx++] = input[val->in_idx++];
  }
  if (input[val->in_idx] == 'e' || input[val->in_idx] == 'E') {
    output[val->out_idx++] = input[val->in_idx++];

    if (input[val->in_idx] == '+' || input[val->in_idx] == '-') {
      output[val->out_idx++] = input[val->in_idx++];
    }
    while (IsNumber(input[val->in_idx])) {
      output[val->out_idx++] = input[val->in_idx++];
    }
  }
  val->in_idx--;
}

int IsUnaryOperator(char* input, int input_index) {
  int result = 0;

  if (input[input_index] == '-' || input[input_index] == '+') {
    if (input_index == 0) {
      result = 1;
    } else if (IsOperator(input[input_index - 1])) {
      result = 1;
    } else if (input[input_index - 1] == '(') {
      result = 1;
    }
  }
  return result;
}

int isFunction(char symbol) {
  int result = 0;

  char functions[] = {SIN, COS, TAN, ASIN, ACOS, ATAN, LOG, LN, SQRT};

  for (size_t i = 0; i < strlen(functions); i++) {
    if (symbol == functions[i]) {
      result = 1;
      break;
    }
  }

  return result;
}

char* FromInfixToPostfix(char* input) {
  ConvertHelper val = {0};
  char* postfix = malloc(strlen(input) * 3);
  val.top = NULL;

  while (input[val.in_idx] != '\0') {
    if (input[val.in_idx] == 'x' || input[val.in_idx] == 'E' ||
        input[val.in_idx] == 'e') {
      postfix[val.out_idx++] = input[val.in_idx];
      postfix[val.out_idx++] = ' ';
    } else if (IsNumber(input[val.in_idx])) {
      ReadNumber(input, postfix, &val);
      postfix[val.out_idx++] = ' ';
    } else if (input[val.in_idx] == '!') {
      postfix[val.out_idx++] = '!';
      postfix[val.out_idx++] = ' ';
    } else if (isFunction(input[val.in_idx])) {
      PushOperator(input[val.in_idx], &val);
    } else if (input[val.in_idx] == '(') {
      PushOperator('(', &val);
    } else if (input[val.in_idx] == ')') {
      PushOutOperatorsBetweenBrackets(postfix, &val);
    } else if (IsUnaryOperator(input, val.in_idx)) {
      if (input[val.in_idx] == '-') {
        PushOutAndPush('~', postfix, &val);
      }
    } else if (IsOperator(input[val.in_idx])) {
      PushOutAndPush(input[val.in_idx], postfix, &val);
    }
    val.in_idx++;
  }
  PushOutAll(postfix, &val);
  postfix[val.out_idx] = '\0';

  return postfix;
}
