#include "SmartCalc.h"


int SetNumberValid(char* input) {
    int status = 1;
    int current_elem = strlen(input) - 1;
    int last_elem = current_elem - 1;

    if (input[last_elem] == 'x'){
        status = 0;
    } else if (input[last_elem] == '!') {
        status = 0;
    } else if (input[last_elem] == ')') {
        status = 0;
    } else if (input[last_elem] == 'd') {
        status = 1;
    } else if (input[last_elem] == '0' && last_elem == 0) {
        status = 2;
        input[last_elem] = input[current_elem];
        input[current_elem] = '\0';
    } else if ((IsOperator(input[last_elem-1]) || input[last_elem-1] == '(') && input[last_elem] == '0') {
        input[last_elem] = input[current_elem];
        input[current_elem] = '\0';
        status = 2;
    }

    return status;
}

int SetOperatorValid(char* input) {
    int status = 1;
    int current_elem = strlen(input) - 1;
    int last_elem = current_elem - 1;

    if (last_elem < 0) {
        status = 0;
    } else if (input[last_elem] == 'd') {
        status = 0;
    } else if (input[last_elem] == '.'){
        status = 0;
    } else if (input[last_elem] == '(') {
        status = 0;
    } else if (IsOperator(input[last_elem]) && !IsUnaryOperator(input, current_elem)) {
        status = 0;
    } else if (IsOperator(input[last_elem-1]) && IsOperator(input[last_elem])) {
        input[last_elem] = input[current_elem];
        input[current_elem] = '\0';
        status = 2;
    } else if (input[current_elem] == '!' && input[last_elem] == '!') {
        status = 0;
    } else if (input[current_elem] == '!') {
        int i = last_elem;
        for (; i >= 0 && IsNumber(input[i]); i--);
        if (input[i] == '.') {
            status = 0;
        }
    } else if (input[last_elem] == 'g') {
        status = 0;
    } else if (input[last_elem] == 'n') {
        status = 0;
    } else if (input[last_elem] == 't') {
        status = 0;
    } else if (input[last_elem] == 's') {
        status = 0;
    }
    return status;
}

int SetDotValid(char* input) {
    int status = 1;
    int current_elem = strlen(input) - 1;
    int last_elem = current_elem - 1;

    if (last_elem < 0) {
        status = 0;
    } else if (!IsNumber(input[last_elem])) {
        status = 0;
    } else if (IsOperator(input[last_elem])) {
        status = 0;
    } 

    if (status) {
        while (IsNumber(input[last_elem])) {
            last_elem--;
        }

        if (input[last_elem] == '.') {
            status = 0;
        }        
    }

    return status;
}

int SetOpenBracketValid(char* input) {
    int status = 1;
    int current_elem = strlen(input) - 1;
    int last_elem = current_elem - 1;

    if (IsNumber(input[last_elem])) {
        status = 0;
    } else if (input[last_elem] == ')') {
        status = 0;
    } else if (input[last_elem] == '.') {
        status = 0;
    } else if (input[last_elem] == '!') {
        status = 0;
    } else if (input[last_elem] == 'x') {
        status = 0;
    }
    return status;
}

int SetCloseBracketValid(char* input) {
    int status = 1;
    int current_elem = strlen(input) - 1;
    int last_elem = current_elem - 1;
    int count_brackets = 0;

    for (int i = last_elem; i >= 0; i--) {
        if (input[i] == '(') {
            count_brackets++;
        } else if (input[i] == ')') {
            count_brackets--;
        }
    }

    if (count_brackets <= 0) {
        status = 0;
    }

    if (status && !IsNumber(input[last_elem]) && input[last_elem] != ')' && input[last_elem] != 'x') {
        status = 0;
    } 

    return status;
}

int SetFuncValid(char* input) {
    int status = 1;
    int last_elem = strlen(input) - 1;
   
    if (IsNumber(input[last_elem])) {
        status = 0;
    } else if (input[last_elem] == '!') {
        status = 0;
    } else if (input[last_elem] == 'x') {
        status = 0;
    } else if (input[last_elem] == '.') {
        status = 0;
    } else if (input[last_elem] == ')') {
        status = 0;
    }

    return status;
}

int SetModValid(char* input) {
    int status = 0;
    int last_elem = strlen(input) - 1;

    if (IsNumber(input[last_elem])) {
        status = 1;
    } else if (input[last_elem] == 'x') {
        status = 1;
    } else if (input[last_elem] == ')') {
        status = 1;
    } else if (input[last_elem] == '(') {
        status = 0;
    }

    return status;
}

int XValid(char* input) {
    int status = 0;
   
    if (input[0] == '\0') {
        input[0] = '0';
        input[1] = '\0';
    }

    for (int i = 0; !status && input[i] != '\0'; i++) {
        if (IsNumber(input[i]) || input[i] == '.') {
            status = 1;
            break;
        }
    }
    return status;
}

int SetXValid(char* input) {
    int status = 0;
    int last_elem = strlen(input) - 1;

    if (last_elem == -1) {
        status = 1;
    } else if (IsOperator(input[last_elem])) {
        status = 1;
    } else if (input[last_elem] == 'd') {
        status = 1;
    } else if (input[last_elem] == '(') {
        status = 1; 
    }

    return status;
}

int IsNeedToClear(int index, int last_elem, char symbol) {
    return (index >= last_elem-1-4 && symbol != 'd' && symbol != 'x' && !IsOperator(symbol) && symbol != '(');
}

int ClearInput(char* input) {
    int status = 0;
    int last_elem = strlen(input) - 1;

    if (input[last_elem] == '(') {
        if (last_elem != -1) {
            if (IsOperator(input[last_elem-1]) || input[last_elem-1] == '(') {
                input[last_elem] = '\0';
            } else {
                for (int i = last_elem-1; IsNeedToClear(i, last_elem, input[i]); i--) {
                    input[i] = '\0';
                }
            }
            status = 1; 
        }
    } else if (last_elem >= 0) {
        if (input[last_elem] == 'd') {
            input[last_elem-2] = '\0';
            input[last_elem-1] = '\0';
            input[last_elem] = '\0';
        } else {
            input[last_elem] = '\0';
        }
        status = 1;              
    }
    return status;
}

int ResultInputValid(char* input) {
    int status = 1;
    int last_elem = strlen(input) - 1;

    if (last_elem == -1) {
        status = 0;
    } else if (input[last_elem] == '(') {
        status = 0;
    } else if (input[last_elem] == '.') {
        status = 0;
    } else if (input[last_elem] == 'd') {
        status = 0;
    } else if (IsOperator(input[last_elem])) {
        status = 0;
    } 

    return status;
}