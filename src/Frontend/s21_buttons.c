#include "frontend.h"

void attachButtonsToGrid(calc *calc) {
  // 0-9 Numbers Buttons
  gtk_grid_attach(GTK_GRID(calc->grid), mainInputBox, 0, 0, 3, 1);
  gtk_grid_attach(GTK_GRID(calc->grid), calc->button[0], 0, 5, 2, 1);
  gtk_grid_attach(GTK_GRID(calc->grid), calc->button[1], 0, 4, 1, 1);
  gtk_grid_attach(GTK_GRID(calc->grid), calc->button[2], 1, 4, 1, 1);
  gtk_grid_attach(GTK_GRID(calc->grid), calc->button[3], 2, 4, 1, 1);
  gtk_grid_attach(GTK_GRID(calc->grid), calc->button[4], 0, 3, 1, 1);
  gtk_grid_attach(GTK_GRID(calc->grid), calc->button[5], 1, 3, 1, 1);
  gtk_grid_attach(GTK_GRID(calc->grid), calc->button[6], 2, 3, 1, 1);
  gtk_grid_attach(GTK_GRID(calc->grid), calc->button[7], 0, 2, 1, 1);
  gtk_grid_attach(GTK_GRID(calc->grid), calc->button[8], 1, 2, 1, 1);
  gtk_grid_attach(GTK_GRID(calc->grid), calc->button[9], 2, 2, 1, 1);

  // 11-15 Simple operators Buttons
  gtk_grid_attach(GTK_GRID(calc->grid), calc->button[11], 3, 4, 1, 1);
  gtk_grid_attach(GTK_GRID(calc->grid), calc->button[12], 3, 3, 1, 1);
  gtk_grid_attach(GTK_GRID(calc->grid), calc->button[13], 3, 2, 1, 1);
  gtk_grid_attach(GTK_GRID(calc->grid), calc->button[14], 3, 1, 1, 1);
  gtk_grid_attach(GTK_GRID(calc->grid), calc->button[15], 2, 1, 1, 1);

  // 16 Dot Button
  gtk_grid_attach(GTK_GRID(calc->grid), calc->button[16], 2, 5, 1, 1);

  // 17-18 Equal and Clear
  gtk_grid_attach(GTK_GRID(calc->grid), calc->button[17], 3, 5, 1, 1);
  gtk_grid_attach(GTK_GRID(calc->grid), calc->button[18], 3, 0, 1, 1);

  // 19-24 Trigonometric Functions
  gtk_grid_attach(GTK_GRID(calc->grid), calc->button[19], 4, 1, 1, 1);
  gtk_grid_attach(GTK_GRID(calc->grid), calc->button[20], 4, 2, 1, 1);
  gtk_grid_attach(GTK_GRID(calc->grid), calc->button[21], 4, 3, 1, 1);
  gtk_grid_attach(GTK_GRID(calc->grid), calc->button[22], 5, 1, 1, 1);
  gtk_grid_attach(GTK_GRID(calc->grid), calc->button[23], 5, 2, 1, 1);
  gtk_grid_attach(GTK_GRID(calc->grid), calc->button[24], 5, 3, 1, 1);

  // 25-28 other functions
  gtk_grid_attach(GTK_GRID(calc->grid), calc->button[25], 6, 1, 1, 1);
  gtk_grid_attach(GTK_GRID(calc->grid), calc->button[26], 6, 2, 1, 1);
  gtk_grid_attach(GTK_GRID(calc->grid), calc->button[27], 6, 3, 1, 1);
  gtk_grid_attach(GTK_GRID(calc->grid), calc->button[28], 6, 4, 1, 1);

  // 29-32 Other Buttons
  gtk_grid_attach(GTK_GRID(calc->grid), calc->button[29], 0, 1, 1, 1);
  gtk_grid_attach(GTK_GRID(calc->grid), calc->button[30], 1, 1, 1, 1);
  gtk_grid_attach(GTK_GRID(calc->grid), calc->button[31], 4, 0, 1, 1);
  gtk_grid_attach(GTK_GRID(calc->grid), calc->button[32], 5, 0, 1, 1);
}

void initButtons(calc *calc) {
  // Numbers buttons
  calc->button[0] = gtk_button_new_with_label("0");
  calc->button[1] = gtk_button_new_with_label("1");
  calc->button[2] = gtk_button_new_with_label("2");
  calc->button[3] = gtk_button_new_with_label("3");
  calc->button[4] = gtk_button_new_with_label("4");
  calc->button[5] = gtk_button_new_with_label("5");
  calc->button[6] = gtk_button_new_with_label("6");
  calc->button[7] = gtk_button_new_with_label("7");
  calc->button[8] = gtk_button_new_with_label("8");
  calc->button[9] = gtk_button_new_with_label("9");

  // Draw graph button
  calc->button[10] = gtk_button_new_with_label("Draw");

  // Simple operators buttons
  calc->button[11] = gtk_button_new_with_label("+");
  calc->button[12] = gtk_button_new_with_label("-");
  calc->button[13] = gtk_button_new_with_label("*");
  calc->button[14] = gtk_button_new_with_label("/");
  calc->button[15] = gtk_button_new_with_label("^");

  // Dot button
  calc->button[16] = gtk_button_new_with_label(".");

  // Equal and Clear
  calc->button[17] = gtk_button_new_with_label("=");
  calc->button[18] = gtk_button_new_with_label("C");

  // Trignometric Functions Buttons
  calc->button[19] = gtk_button_new_with_label("sin");
  calc->button[20] = gtk_button_new_with_label("cos");
  calc->button[21] = gtk_button_new_with_label("tan");
  calc->button[22] = gtk_button_new_with_label("asin");
  calc->button[23] = gtk_button_new_with_label("acos");
  calc->button[24] = gtk_button_new_with_label("atan");

  // Other Functions
  calc->button[25] = gtk_button_new_with_label("mod");
  calc->button[26] = gtk_button_new_with_label("sqrt");
  calc->button[27] = gtk_button_new_with_label("log");
  calc->button[28] = gtk_button_new_with_label("ln");

  // Other Buttons
  calc->button[29] = gtk_button_new_with_label("(");
  calc->button[30] = gtk_button_new_with_label(")");
  calc->button[31] = gtk_button_new_with_label("⌫");
  calc->button[32] = gtk_button_new_with_label("x");
}

void connectSignalButtons(calc *calc) {
  for (int i = 0; i < 33; i++) {
    if (i == 10) continue;  // Draw Button
    if (i == 17) continue;  // Equal Button
    g_signal_connect(calc->button[i], "clicked", G_CALLBACK(inputText),
                     calc->graph_area);
  }

  g_signal_connect(calc->button[10], "clicked", G_CALLBACK(drawGraph_Clicked),
                   calc->graph_area);
  g_signal_connect(calc->button[17], "clicked", G_CALLBACK(calculate),
                   calc->graph_area);
  // gtk_widget_queue_draw_area(GTK_WIDGET(calc->graph_area), 0, 0, 500, 500);
}

gboolean drawGraph_Clicked(gpointer user_data) {
  draw_requested++;
  gtk_widget_queue_draw_area(GTK_WIDGET(user_data), 0, 0, 500, 500);
  return FALSE;
}

void inputText(GtkButton *button) {
  gchar *butonText = (gchar *)gtk_button_get_label(button);
  gchar *boxText = (gchar *)gtk_entry_get_text(GTK_ENTRY(mainInputBox));
  gchar *newText[MAX_STRING_LENGTH] = {0};

  if (!strcmp(butonText, "C")) {
    gtk_entry_set_text(GTK_ENTRY(mainInputBox), "");
  } else if (!strcmp(butonText, "⌫")) {
    if (boxText[0] != '\0') {
      g_strlcpy((gchar *)newText, (gchar *)boxText, strlen(boxText));
      newText[strlen((const gchar *)newText)] = '\0';
      gtk_entry_set_text(GTK_ENTRY(mainInputBox), (const gchar *)newText);
    }
  } else {
    const gchar *newText = g_strconcat(boxText, butonText, NULL);
    gtk_entry_set_text(GTK_ENTRY(mainInputBox), newText);
  }
}
