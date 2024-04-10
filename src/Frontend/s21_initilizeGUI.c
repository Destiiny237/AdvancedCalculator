#include "frontend.h"
GtkWidget *mainInputBox;
GtkWidget *XInputBox;
GtkWidget *scaleXInputBox;
GtkWidget *scaleYInputBox;

void initializeUI(int argc, char *argv[]) {
  GtkApplication *app;
  gtk_init(&argc, &argv);

  app = gtk_application_new("org.gtk.calculator", G_APPLICATION_FLAGS_NONE);

  g_signal_connect(app, "activate", G_CALLBACK(activate), NULL);
  g_application_run(G_APPLICATION(app), argc, argv);
  g_object_unref(app);
}

void activate(GtkApplication *app) {
  calc calc;

  mainInputBox = gtk_entry_new();
  XInputBox = gtk_entry_new();
  scaleXInputBox = gtk_entry_new();
  scaleYInputBox = gtk_entry_new();
  gtk_editable_set_editable(GTK_EDITABLE(mainInputBox), FALSE);
  // gtk_widget_set_size_request(scaleXInputBox, 100, 100);
  // gtk_widget_set_size_request(scaleYInputBox, 100, 100);
  gtk_entry_set_text(GTK_ENTRY(scaleXInputBox), "25");
  gtk_entry_set_text(GTK_ENTRY(scaleYInputBox), "25");
  gtk_entry_set_text(GTK_ENTRY(XInputBox), "0");
  // Main Window init
  calc.window = gtk_application_window_new(app);
  gtk_window_set_resizable(GTK_WINDOW(calc.window), FALSE);
  gtk_window_set_position(GTK_WINDOW(calc.window), GTK_WIN_POS_CENTER);
  gtk_window_set_title(GTK_WINDOW(calc.window), "s21_Calculator");
  gtk_window_set_default_size(GTK_WINDOW(calc.window), 500, 500);
  gtk_container_set_border_width(GTK_CONTAINER(calc.window), 15);

  // Grid init
  calc.grid = gtk_grid_new();
  gtk_grid_set_column_spacing((GtkGrid *)calc.grid, 2);
  gtk_grid_set_row_spacing((GtkGrid *)calc.grid, 2);

  // Graph Area init
  calc.graph_area = gtk_drawing_area_new();
  gtk_widget_set_app_paintable(calc.graph_area, TRUE);
  gtk_widget_set_size_request(calc.graph_area, 500, 500);
  g_signal_connect(G_OBJECT(calc.graph_area), "draw", G_CALLBACK(draw_callback),
                   NULL);
  gtk_widget_set_events(calc.graph_area, GDK_EXPOSURE_MASK);

  GtkWidget *hbox1 = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 5);
  GtkWidget *hbox2 = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 5);
  GtkWidget *vbox3 = gtk_box_new(GTK_ORIENTATION_VERTICAL, 5);

  GtkWidget *vsep = gtk_separator_new(GTK_ORIENTATION_VERTICAL);

  initButtons(&calc);
  attachButtonsToGrid(&calc);
  connectSignalButtons(&calc);

  gtk_grid_attach(GTK_GRID(calc.grid), XInputBox, 6, 0, 1, 1);

  gtk_box_pack_start(GTK_BOX(hbox1), vsep, TRUE, TRUE, 1);
  gtk_box_pack_start(GTK_BOX(hbox1), calc.button[10], TRUE, TRUE, 1);
  gtk_box_pack_start(GTK_BOX(hbox1), calc.graph_area, TRUE, TRUE, 1);
  gtk_box_pack_start(GTK_BOX(vbox3), scaleXInputBox, FALSE, TRUE, 1);
  gtk_box_pack_start(GTK_BOX(vbox3), scaleYInputBox, FALSE, TRUE, 1);

  gtk_container_add(GTK_CONTAINER(hbox2), calc.grid);
  gtk_container_add(GTK_CONTAINER(hbox2), hbox1);
  gtk_container_add(GTK_CONTAINER(hbox2), vbox3);

  gtk_container_add(GTK_CONTAINER(calc.window), hbox2);

  gtk_widget_show_all(calc.window);
}