#include "s21_stack.h"

stack_t *push(stack_t *top, double value, Lexeme lexeme_type, int priority) {
  stack_t *ptr = calloc(1, sizeof(stack_t));
  ptr->value = value;
  ptr->next = top;
  ptr->lexeme_type = lexeme_type;
  ptr->priority = priority;
  return ptr;
}

stack_t *pop(stack_t *top) {
  if (top == NULL) {
    return NULL;
  }
  stack_t *ptr_next = top->next;
  free(top);

  return ptr_next;
}
