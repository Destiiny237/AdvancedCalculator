#include "backend.h"

int isValid(char* expression) {
  if (bracketIsValid(expression) && functionsIsValid(expression) &&
      signsIsValid(expression)) {
    return 1;
  }
  return 0;
}

int bracketIsValid(char* expression) {
  int isValid = 0;
  int counter = 0;
  char signs[5] = "+-*/^";
  for (int i = 0; i < (int)strlen(expression); i++) {
    if (counter < 0) {
      return 0;
    }
    if (expression[i] == '(')
      counter++;
    else if (expression[i] == ')')
      counter--;
  }
  if (counter == 0) {
    isValid = 1;
  }

  // if brackets is empty or have only sign
  for (int i = 0; i < (int)strlen(expression) - 2; i++) {
    if (expression[i] == '(' && strchr(signs, expression[i + 1]) &&
        expression[i + 2] == ')') {
      return 0;
    }
    if (expression[i] == '(' && expression[i + 1] == ')') {
      return 0;
    }
  }

  return isValid;
}

int signsIsValid(char* expression) {
  int counter = 0;
  char signs[5] = "+-*/^";
  int expressionLength = strlen(expression);
  char checking_char = expression[expressionLength - 1];

  // if expression ends of sign
  if (strchr(signs, checking_char)) {
    return 0;
  }

  // if expression ends of the something else than number or close brackets or X
  int haveNumberEnd = 0;
  for (int i = expressionLength - 1; i >= 0; i--) {
    checking_char = expression[i];
    if (isdigit(checking_char) || checking_char == 'x')
      haveNumberEnd = 1;
    else if (haveNumberEnd == 0 && strchr(signs, checking_char))
      return 0;
  }

  // if double or more signs
  for (int i = 0; i < expressionLength; i++) {
    checking_char = expression[i];
    if (counter > 1) return 0;
    if (strchr(signs, checking_char)) {
      counter += 1;
    } else {
      counter = 0;
    }
  }

  return 1;
}

int functionsIsValid(char* expression) {
  int counter = 0;
  int expressionLength = strlen(expression);
  char checking_char = expression[0];
  char signs[7] = "+-*/^()";

  // if chars no more than 4
  for (int i = 0; i < expressionLength; i++) {
    checking_char = expression[i];
    if (counter > 4) return 0;
    if (isalpha(checking_char))
      counter++;
    else
      counter = 0;
  }

  // if last symbol is a letter
  if (isalpha(expression[expressionLength - 1]) &&
      expression[expressionLength - 1] != 'x')
    return 0;

  // if function doesn't have argument
  for (int i = 0; i < expressionLength; i++) {
    if (isalpha(expression[i]) && expression[i + 1] == '(' &&
        expression[i + 2] == ')') {
      return 0;
    }
  }

  // for MOD
  for (int i = 0; i < expressionLength; i++) {
    if (expression[i] == 'd' && expression[i + 1] != '(' &&
        !isdigit(expression[i + 1])) {
      return 0;
    }
  }
  for (int i = expressionLength - 1; i >= 0; i--) {
    if (i == 0 && expression[i] == 'm') {
      return 0;
    }
    if (expression[i] == 'm' && expression[i - 1] != '(' &&
        !isdigit(expression[i - 1])) {
      return 0;
    }
  }

  for (int i = 0; i < expressionLength; i++) {
    if (isdigit(expression[i]) && expression[i + 1] == '.' &&
        !isdigit(expression[i + 2])) {
      return 0;
    }
  }

  for (int i = 0; i < expressionLength; i++) {
    if (i == 0 && expression[i] == 'x' && !strchr(signs, expression[i + 1])) {
      return 0;
    } else if (expression[i] == 'x' && (!strchr(signs, expression[i - 1]) ||
                                        !strchr(signs, expression[i + 1]))) {
      return 0;
    }
  }

  return 1;
}