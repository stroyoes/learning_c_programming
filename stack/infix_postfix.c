#include "infix_postfix.h"
#include "stack.h"


bool is_operator(char c) {
  return c == '+' || c == '-' || c == '*' || c == '/' || c == '^';
}

int precedence(char op) {
  switch (op) {
    case '^': return 3;
    case '*':
    case '/': return 2;
    case '+':
    case '-': return 1; //  NOTE: Intentionally fall through
    default: return 0;
  }
}

bool is_higher_precedence(char op1, char op2) {
  int p1 = precedence(op1);
  int p2 = precedence(op2);

  if (p1 == p2) {
    return op1 != '^'; //  NOTE: The ^ operator (exponentiation) is right-associative. All others like +, -, *, / are left-associative.

  }

  return p1 > p2;
}

bool is_space(char c) {
  return c == ' ' || c == '\t' || c == '\n' || c == '\v' || c == '\f' || c == '\r';  
}

bool is_digit(char c) {
  return c >= '0' && c <= '9';
}

void infix_to_postfix(const char *infix, char *postfix) {
  stack_t op_stack; // To hold the operators and left parenthesis 
  init_stack(&op_stack);

  int j = 0;

  //  NOTE: Simply infix[i] means infix[i] != '\0' 
  for (int i = 0; infix[i]; i++) {
    char token = infix[i];

    if (is_space(token))
      continue; // Just skip spaces in infix expression 

    if (is_digit(token)) {
      while (is_digit(infix[i])) {
        postfix[j++] = infix[i++]; // The i++ here reads the full number and one step ahead i.e. 'i' points to some operator 
      }
      postfix[j++] = ' '; // Add a space b/w numbers in the postfix
      i--; // We do this to backtrack and read the operator again (so that we can push it to stack)
    } else if (token == '(' ) {
      push(&op_stack, token);
    } else if (token == ')' ) {
      while (!is_empty(&op_stack) && peek(&op_stack) != '(' ) {
        postfix[j++] = pop(&op_stack);
        postfix[j++] = ' ';
      }
      pop(&op_stack); // Pop the '(' 
    } else if (is_operator(token)) {
      while (!is_empty(&op_stack) && is_operator(peek(&op_stack)) && is_higher_precedence(peek(&op_stack), token)) {
        postfix[j++] = pop(&op_stack);
        postfix[j++] = ' ';
      } 
      push(&op_stack, token);
    }
  }

  //  NOTE: The rest of the operators are added into the postfix string's end
  while (!is_empty(&op_stack)) {
    postfix[j++] = pop(&op_stack);
    postfix[j++] = ' ';
  }
  
  // Terminate the postfix string 
  postfix[j] = '\0';
}

int apply_operator(int a, int b, char op) {
  switch (op) {
    case '+': return a + b;
    case '-': return a - b;
    case '*': return a * b;
    case '/': return b == 0 ? 0 : a / b;
    case '^': {
      int result = 1;
      for (int i = 0; i < b; i++) {
        result *= a; // Repeated multiplication 
      }
      return result;
    }
    default: return 0;
  
  }
}

int evaluate_postfix(const char *postfix) {
  stack_t val_stack; // To contain the values after performing operations and finally the result

  init_stack(&val_stack);

  for (int i = 0; postfix[i]; i++) {
    if (is_space(postfix[i])) 
      continue;

    if (is_digit(postfix[i])) {
      int num = 0;
      while (is_digit(postfix[i])) {
        num = num * 10 + (postfix[i++] - '0'); 
        //  NOTE: Shifting the number left (X10) and adding the next digit. Also remember num_as_char - '0' gives the number itself (as intger).
      }
      push(&val_stack, num);
      i--; // Backtrack if its not a digit 
    } else if (is_operator(postfix[i])) {
      int a = pop(&val_stack);
      int b = pop(&val_stack);

      int result = apply_operator(b, a, postfix[i]);
      push(&val_stack, result);
    }
  }

  // Pop the last remainig number 
  return pop(&val_stack);
}



