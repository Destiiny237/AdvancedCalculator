#include "frontend.h"

void calculate() {
  const gchar *boxText = gtk_entry_get_text(GTK_ENTRY(mainInputBox));

  char buffer[MAX_STRING_LENGTH] = {0};
  char *expression;
  double doubleAnswer = 0;

  int isValidFlag = 1;

  if (isValid((char *)boxText)) {
    expression = expression_parser((char *)boxText);
    doubleAnswer = expression_solver(
        expression, atof(gtk_entry_get_text(GTK_ENTRY(XInputBox))));
    free(expression);
  } else {
    isValidFlag = 0;
  }

  if (isValidFlag == 1 && !isinf(doubleAnswer) && !isnan(doubleAnswer)) {
    snprintf(buffer, MAX_STRING_LENGTH - 1, "%.7f", doubleAnswer);
    gtk_entry_set_text(GTK_ENTRY(mainInputBox), buffer);
  } else {
    gtk_entry_set_text(GTK_ENTRY(mainInputBox), ((const gchar *)"notValid"));
  }
}