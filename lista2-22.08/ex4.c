#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_SIZE 100

char stack[MAX_SIZE];
int top = -1;

bool isEmpty() {
    return top == -1;
}

void push(char item) {
    stack[++top] = item;
}

char pop() {
    if (isEmpty()) {
        return '\0'; 
    }
    return stack[top--];
}

bool arePair(char char1, char char2) {
    if (char1 == '(' && char2 == ')') return true;
    if (char1 == '{' && char2 == '}') return true;
    if (char1 == '[' && char2 == ']') return true;
    return false;
}

bool isBalanced(const char *exp) {
    int i;
    for (i = 0; i < strlen(exp); i++) {
        char current_char = exp[i];
        if (current_char == '(' || current_char == '{' || current_char == '[') {
            push(current_char);
        }
        else if (current_char == ')' || current_char == '}' || current_char == ']') {
            
            if (isEmpty()) {
                return false;
            }

            char top_char = pop();
            if (! arePair(top_char, current_char)) {
                return false; 
            }
        }
    }

    return isEmpty();
}

void print_balance_result(const char *expression) {
    top = -1; 

    bool result = isBalanced(expression);

    printf("Expressão: \"%s\" -> ", expression);

    if (result) {
        printf("Balanceada\n");
    } else {
        printf("Desbalanceada\n");
    }
}

int main() {
    print_balance_result("[ { ( ) } ]");
    print_balance_result("{ { ( [ ] ) } }"); 
    print_balance_result("{ [ ( ] ) }"); 
    print_balance_result("{ ] ( )");
    print_balance_result("(((");
    print_balance_result("))");
    
    return 0;
}