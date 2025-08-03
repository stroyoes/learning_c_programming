#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX 100

char stack[MAX];
int top = -1;

// Stack operations
void push(char x) {
    if (top < MAX - 1) {
        stack[++top] = x;
    }
}

char pop() {
    if (top == -1) {
        return '\0'; // return null character on underflow, since the stack holds characters here not integers
    }
    return stack[top--];
}

char peek() {
    if (top == -1) {
        return '\0';
    }
    return stack[top];
}

// Operator checks
bool is_operator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '^';
}

int precedence(char op) {
    switch (op) {
        case '^': return 3;
        case '*':
        case '/': return 2;
        case '+':
        case '-': return 1;
        default: return 0;
    }
}

bool is_higher_precedence(char op1, char op2) {
    int p1 = precedence(op1);
    int p2 = precedence(op2);

    if (p1 == p2) {
        return op1 != '^'; // ^ is right-associative
    }

    return p1 > p2;
}

// Main logic for infix to postfix
int main() {
    char expr[MAX];
    printf("Enter infix expression: ");
    fgets(expr, MAX, stdin); // input with spaces

    for (int i = 0; expr[i] != '\0'; i++) {
        char token = expr[i];

        if (isspace(token)) {
            continue;
        }

        if (isdigit(token) || isalpha(token)) {
            // Operand: print directly
            printf("%c", token);
        }
        else if (token == '(') {
            push(token);
        }
        else if (token == ')') {
            // Pop until '('
            while (peek() != '\0' && peek() != '(') {
                printf("%c", pop());
            }
            pop(); // remove '(' from stack
        }
        else if (is_operator(token)) {
            // Pop while precedence is higher or equal
            while (peek() != '\0' && is_operator(peek()) && is_higher_precedence(peek(), token)) {
                printf("%c", pop());
            }
            push(token);
        }
    }

    // Pop remaining operators
    while (peek() != '\0') {
        printf("%c", pop());
    }

    printf("\n");
    return 0;
}

/* 
Output
------
Enter infix expression: p*(q+r)/s
pqr+*s/

*/
