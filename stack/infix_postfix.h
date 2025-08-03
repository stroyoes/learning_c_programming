#ifndef INFIX_POSTFIX_H
#define INFIX_POSTFIX_H

#include <stdbool.h>

#define MAX_EXPR_LEN 100 

bool is_operator(char c); // Check if the token is an operator
int precedence(char op); // Get the precedence value 
bool is_higher_precedence(char op1, char op2); // Compare and check if precedence(op1) > precedence(op2)
void infix_to_postfix(const char* infix, char* postfix); // Get the postfix expression from an infix 
int evaluate_postfix(const char* postfix); // Evaluate and the get the result of a postfix expression

#endif


