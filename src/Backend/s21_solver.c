#include "backend.h"

double expression_solver(char* expression, double x) {
  stack_t* stack = NULL;
  double num1 = 0;
  double num2 = 0;
  char fullNumber[MAX_STRING_LENGTH] = {};
  char fullFunctions[MAX_STRING_LENGTH] = {};

  int expressionLength = (int)strlen(expression);

  for (int i = 0; i < expressionLength; i++) {
    char checking_char = (expression[i]);
    if (!isdigit(checking_char) && !isalpha(checking_char)) {
      switch (checking_char) {
        case '=':
          double value = 0;
          if (stack != NULL) value = stack->value;
          free(stack);
          return value;
          break;
        case '+':
          stack = pop_last_two_el(stack, &num1, &num2);
          stack = push(stack, num1 + num2, Number, 0);
          break;
        case '-':
          stack = pop_last_two_el(stack, &num1, &num2);
          stack = push(stack, -num1 + num2, Number, 0);
          break;
        case '*':
          stack = pop_last_two_el(stack, &num1, &num2);
          stack = push(stack, num1 * num2, Number, 0);
          break;
        case '/':
          stack = pop_last_two_el(stack, &num1, &num2);
          stack = push(stack, num2 / num1, Number, 0);
          break;
        case '^':
          stack = pop_last_two_el(stack, &num1, &num2);
          stack = push(stack, pow(num2, num1), Number, 0);
          break;
      }
    } else if (isdigit(checking_char)) {
      strcpy(fullNumber, "");
      while (isdigit(checking_char) || checking_char == '.') {
        strncat(fullNumber, &checking_char, 1);
        checking_char = expression[++i];
      }
      stack = push(stack, atof(fullNumber), 0, 1);
    } else if (isalpha(checking_char)) {
      if (checking_char == 'x') {
        stack = push(stack, x, Number, 0);
        continue;
      }
      strcpy(fullFunctions, "");
      while (isalpha(checking_char)) {
        strncat(fullFunctions, &checking_char, 1);
        checking_char = expression[++i];
      }
      num1 = stack->value;
      stack = pop(stack);
      if (!strcmp(fullFunctions, "sin")) {
        stack = push(stack, sin(num1), Number, 0);
      } else if (!strcmp(fullFunctions, "cos")) {
        stack = push(stack, cos(num1), Number, 0);
      } else if (!strcmp(fullFunctions, "tan")) {
        stack = push(stack, tan(num1), Number, 0);
      } else if (!strcmp(fullFunctions, "asin")) {
        stack = push(stack, asin(num1), Number, 0);
      } else if (!strcmp(fullFunctions, "acos")) {
        stack = push(stack, acos(num1), Number, 0);
      } else if (!strcmp(fullFunctions, "atan")) {
        stack = push(stack, atan(num1), Number, 0);
      } else if (!strcmp(fullFunctions, "sqrt")) {
        stack = push(stack, sqrt(num1), Number, 0);
      } else if (!strcmp(fullFunctions, "log")) {
        stack = push(stack, log10(num1), Number, 0);
      } else if (!strcmp(fullFunctions, "ln")) {
        stack = push(stack, log(num1), Number, 0);
      } else if (!strcmp(fullFunctions, "mod")) {
        num2 = stack->value;
        stack = pop(stack);
        stack = push(stack, fmod(num2, num1), Number, 0);
      }
    }
  }
  return NAN;
}

stack_t* pop_last_two_el(stack_t* stack, double* num1, double* num2) {
  (void)num1;
  *num1 = stack->value;
  stack = pop(stack);
  (void)num2;
  *num2 = stack->value;
  stack = pop(stack);
  return stack;
}