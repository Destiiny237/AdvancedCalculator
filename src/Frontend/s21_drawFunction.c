#include "frontend.h"

cairo_surface_t *surface = NULL;
int draw_requested = 1;

void draw_callback(GtkWidget *widget, cairo_t *cr) {
  if (draw_requested) {
    if (isValid((char *)gtk_entry_get_text(GTK_ENTRY(mainInputBox)))) {
      drawGraph(widget, cr);
    }
  } else {
    cairo_set_source_surface(cr, surface, 0, 0);
    cairo_paint(cr);
  }
  draw_requested = 0;
}

void drawGraph(GtkWidget *widget, cairo_t *cr) {
  surface = cairo_image_surface_create(CAIRO_FORMAT_ARGB32, 500, 500);
  cr = cairo_create(surface);

  guint width, height;
  GtkStyleContext *context;
  context = gtk_widget_get_style_context(widget);
  width = gtk_widget_get_allocated_width(widget);
  height = gtk_widget_get_allocated_height(widget);
  gtk_render_background(context, cr, 0, 0, width, height);
  cairo_set_line_width(cr, 0.05);  // Line Width

  double scaleX =
      atof((const char *)gtk_entry_get_text(GTK_ENTRY(scaleXInputBox)));
  double scaleY =
      atof((const char *)gtk_entry_get_text(GTK_ENTRY(scaleYInputBox)));

  if (scaleX > 2000000) {
    scaleX = 2000000.0;
    gtk_entry_set_text(GTK_ENTRY(scaleXInputBox), "2000000");
  }

  if (scaleY > 2000000) {
    scaleY = 2000000.0;
    gtk_entry_set_text(GTK_ENTRY(scaleYInputBox), "2000000");
  }

  cairo_translate(cr, width / 2.0, height / 2.0);
  cairo_scale(cr, width / (scaleX), height / (scaleY));

  drawGrid(widget, cr, scaleX, scaleY);
  drawFunction(cr, scaleX, scaleY);
  drawAxles(cr, scaleX, scaleY);
}

void drawAxles(cairo_t *cr, double scaleX, double scaleY) {
  if (scaleX >= scaleY) {
    cairo_set_line_width(cr, findLineWidth(scaleX) + 0.01);
  } else {
    cairo_set_line_width(cr, findLineWidth(scaleY) + 0.01);
  }
  cairo_set_source_rgb(cr, 0, 0, 0);
  cairo_move_to(cr, -scaleX / 2, 0);
  cairo_line_to(cr, scaleX / 2, 0);
  cairo_move_to(cr, 0, scaleY / 2);
  cairo_line_to(cr, 0, -scaleY / 2);
  cairo_stroke(cr);
}

void drawFunction(cairo_t *cr, double scaleX, double scaleY) {
  if (scaleX >= scaleY) {
    cairo_set_line_width(cr, findLineWidth(scaleX));
  } else {
    cairo_set_line_width(cr, findLineWidth(scaleY));
  }

  cairo_set_source_rgb(cr, 0, 0, 1);

  const char *expression = gtk_entry_get_text(GTK_ENTRY(mainInputBox));
  char *polishExpression = expression_parser((char *)expression);

  double x_min = -scaleX / 2;
  double x_max = scaleX / 2;
  double step = (scaleX / 25000.0);
  // cairo_move_to(cr, x_min, -expression_solver(polishExpression, top, x_min));
  for (double x = x_min; x <= x_max; x += step) {
    if (fabs(x) <= step) {
      x *= -1;
    }

    double y = -expression_solver(polishExpression, x);
    if (!isnan(y)) {
      if (fabs(cos(x)) < 0.01 && strstr(polishExpression, "tan")) {
        cairo_stroke(cr);
        cairo_move_to(cr, x, y);
      } else {
        cairo_line_to(cr, x, y);
      }
    }
    // printf("X = %lf, Y = %lf, isnan = %d \n", x, y, isnan(y));
  }
  cairo_stroke(cr);
}

void drawGrid(GtkWidget *widget, cairo_t *cr, double scaleX, double scaleY) {
  double stepX = findStep(scaleX);
  double stepY = findStep(scaleY);

  if (scaleX >= scaleY) {
    cairo_set_line_width(cr, findLineWidth(scaleX));
  } else {
    cairo_set_line_width(cr, findLineWidth(scaleY));
  }

  cairo_set_source_rgb(cr, 1, 0, 0);
  double width = gtk_widget_get_allocated_width(widget);
  double height = gtk_widget_get_allocated_height(widget);
  // Вычисление количества линий сетки по осям
  int numLinesX = scaleX * width / (stepX);
  int numLinesY = scaleY * height / (stepY);
  double fontSize = fmin(scaleX, scaleY) / 50;

  cairo_set_font_size(cr, fontSize);

  double mainScale = fmax(scaleX, scaleY);

  for (int i = -numLinesX; i <= numLinesX; ++i) {
    double x = i * stepX;
    cairo_move_to(cr, x, -mainScale / 2);
    cairo_line_to(cr, x, mainScale / 2);

    // Отрисовка чисел рядом с линиями по оси X
    char label[MAX_STRING_LENGTH];
    snprintf(label, sizeof(label), "%.1f", x);
    cairo_move_to(cr, x, 0);
    cairo_show_text(cr, label);
  }
  for (int i = -numLinesY; i <= numLinesY; ++i) {
    double y = i * stepY;
    cairo_move_to(cr, -mainScale / 2, y);
    cairo_line_to(cr, mainScale / 2, y);

    // Отрисовка чисел рядом с линиями по оси Y
    char label[MAX_STRING_LENGTH];
    snprintf(label, sizeof(label), "%.1f", y);
    cairo_move_to(cr, 0, y);
    cairo_show_text(cr, label);
  }
  cairo_set_source_rgb(cr, 0.5, 0.5, 0.5);
  // cairo_set_line_width(cr, 0.1);
  cairo_stroke(cr);
}

double findLineWidth(double range) {
  double width = 1;
  if (range < 10.5) {
    width = 0.05;
  } else if (range < 20.5) {
    width = 0.1;
  } else if (range < 50.5) {
    width = 0.1;
  } else if (range < 100.5) {
    width = 0.2;
  } else if (range < 250.5) {
    width = 0.7;
  } else if (range < 500.5) {
    width = 1;
  } else if (range < 1000.5) {
    width = 2;
  } else if (range < 2500.5) {
    width = 3;
  } else if (range < 5000.5) {
    width = 4;
  } else if (range < 10000.5) {
    width = 10;
  } else if (range < 40000.5) {
    width = 30;
  } else if (range < 100000.5) {
    width = 60;
  } else if (range < 200000.5) {
    width = 150;
  } else if (range < 1000000.5) {
    width = 500;
  } else {
    width = 10000;
  }
  return width;
}

int findStep(double range) {
  int step = 1;
  if (range < 10.5) {
    step = 1;
  } else if (range < 20.5) {
    step = 2;
  } else if (range < 25.5) {
    step = 5;
  } else if (range < 50.5) {
    step = 7;
  } else if (range < 100.5) {
    step = 20;
  } else if (range < 250.5) {
    step = 40;
  } else if (range < 500.5) {
    step = 100;
  } else if (range < 1000.5) {
    step = 200;
  } else if (range < 2500.5) {
    step = 500;
  } else if (range < 5000.5) {
    step = 1000;
  } else if (range < 10000.5) {
    step = 2000;
  } else if (range < 40000.5) {
    step = 5000;
  } else if (range < 100000.5) {
    step = 10000;
  } else if (range < 200000.5) {
    step = 20000;
  } else if (range < 1000000.5) {
    step = 100000;
  } else {
    step = 150000;
  }
  return step;
}