#include "backend.h"

char* expression_parser(char* expression) {
  stack_t* stack = NULL;
  char* resultString = (char*)calloc(MAX_STRING_LENGTH, sizeof(char));
  char fullNumber[MAX_STRING_LENGTH] = {};
  char fullFunctions[MAX_STRING_LENGTH] = {};
  char checking_char = ' ';

  correctExpression(expression);

  int expressionLength = (int)strlen(expression);

  for (int i = 0; i < expressionLength; i++) {
    checking_char = expression[i];

    if (!isdigit(checking_char) &&
        !isalpha(checking_char)) {  // Обработка если лексема является знаком
      switch (checking_char) {
        case '(':
          stack = push(stack, 0, Bracket, BRACKET_PRIORITY);
          break;
        case '+':
          stack = addOperationToStack(stack, resultString, PLUS_PRIORITY, Plus);
          break;
        case '-':
          stack =
              addOperationToStack(stack, resultString, MINUS_PRIORITY, Minus);
          break;
        case '*':
          stack = addOperationToStack(stack, resultString, MULTIPLY_PRIORITY,
                                      Multiply);
          break;
        case '/':
          stack =
              addOperationToStack(stack, resultString, DIVIDE_PRIORITY, Divide);
          break;
        case '^':
          stack = addOperationToStack(stack, resultString, EXPONENT_PRIORITY,
                                      Exponent);
          break;
        case ')':
          while (stack != NULL &&
                 strcmp(returnOperationType(stack->lexeme_type), "(")) {
            strcat(resultString, " ");
            strcat(resultString, returnOperationType(stack->lexeme_type));
            stack = pop(stack);
          }
          stack = pop(stack);
          break;
      }
    } else if (isdigit(
                   checking_char)) {  // Обработка если лексема является числом
      strcpy(fullNumber, "");

      while (isdigit(checking_char) || checking_char == '.') {
        strncat(fullNumber, &checking_char, 1);
        checking_char = expression[++i];
      }
      strcat(resultString, " ");
      strcat(resultString, fullNumber);
      --i;
    } else if (isalpha(checking_char)) {  // Обработка если лексема является
                                          // буквой (функция)
      if (checking_char == 'x') {
        strcat(resultString, " x");
        continue;
      }
      strcpy(fullFunctions, "");

      while (isalpha(checking_char)) {
        strncat(fullFunctions, &checking_char, 1);
        checking_char = expression[++i];
      }

      --i;

      if (!strcmp(fullFunctions, "sin")) {
        stack = addOperationToStack(stack, resultString, FUNCTIONS_PRIORITY,
                                    s21_sin);
      } else if (!strcmp(fullFunctions, "cos")) {
        stack = addOperationToStack(stack, resultString, FUNCTIONS_PRIORITY,
                                    s21_cos);
      } else if (!strcmp(fullFunctions, "tan")) {
        stack = addOperationToStack(stack, resultString, FUNCTIONS_PRIORITY,
                                    s21_tan);
      } else if (!strcmp(fullFunctions, "asin")) {
        stack = addOperationToStack(stack, resultString, FUNCTIONS_PRIORITY,
                                    s21_asin);
      } else if (!strcmp(fullFunctions, "acos")) {
        stack = addOperationToStack(stack, resultString, FUNCTIONS_PRIORITY,
                                    s21_acos);
      } else if (!strcmp(fullFunctions, "atan")) {
        stack = addOperationToStack(stack, resultString, FUNCTIONS_PRIORITY,
                                    s21_atan);
      } else if (!strcmp(fullFunctions, "sqrt")) {
        stack =
            addOperationToStack(stack, resultString, FUNCTIONS_PRIORITY, Sqrt);
      } else if (!strcmp(fullFunctions, "log")) {
        stack =
            addOperationToStack(stack, resultString, FUNCTIONS_PRIORITY, Log);
      } else if (!strcmp(fullFunctions, "ln")) {
        stack =
            addOperationToStack(stack, resultString, FUNCTIONS_PRIORITY, Ln);
      } else if (!strcmp(fullFunctions, "mod")) {
        stack = addOperationToStack(stack, resultString, MOD_PRIORITY, Mod);
      }
    }
  }

  while (stack) {
    strcat(resultString, " ");
    strcat(resultString, returnOperationType(stack->lexeme_type));
    stack = pop(stack);
  }

  strcat(resultString, " =");

  return resultString;
}

char* returnOperationType(int num) {
  if (num == Bracket)
    return "(";
  else if (num == Plus)
    return "+";
  else if (num == Minus)
    return "-";
  else if (num == Multiply)
    return "*";
  else if (num == Divide)
    return "/";
  else if (num == Exponent)
    return "^";
  else if (num == s21_sin)
    return "sin";
  else if (num == s21_cos)
    return "cos";
  else if (num == s21_tan)
    return "tan";
  else if (num == s21_asin)
    return "asin";
  else if (num == s21_acos)
    return "acos";
  else if (num == s21_atan)
    return "atan";
  else if (num == Sqrt)
    return "sqrt";
  else if (num == Log)
    return "log";
  else if (num == Ln)
    return "ln";
  else if (num == Mod)
    return "mod";
  return "";
}

stack_t* addOperationToStack(stack_t* stack, char* resultString, int priority,
                             Lexeme lexeme) {
  while (stack != NULL && stack->priority >= priority) {
    strcat(resultString, " ");
    strcat(resultString, returnOperationType(stack->lexeme_type));
    stack = pop(stack);
  }
  stack = push(stack, 0, lexeme, priority);
  return stack;
}

// correct unaru minus/plus
void correctExpression(char* expression) {
  int expressionLength = strlen(expression);
  if (expression[0] == '-' || expression[0] == '+') {
    memmove(expression + 1, expression, expressionLength + 1);
    memset(expression, '0', 1);
  }
  for (int i = 1; i < (int)expressionLength; i++) {
    if ((expression[i] == '-' || expression[i] == '+') &&
        expression[i - 1] == '(') {
      expression = realloc(expression, (expressionLength + 2) * sizeof(char));
      memmove(expression + i + 1, expression + i,
              (expressionLength - i + 1) * sizeof(char));
      expression[i] = '0';
    }
  }
}
