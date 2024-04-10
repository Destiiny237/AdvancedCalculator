#ifndef FRONTEND_H
#define FRONTEND_H

#include <glib.h>
#include <gtk/gtk.h>

#include "../SmartCalc.h"
#include "../Stack/s21_stack.h"
#include "../Backend/backend.h"

#define GRID_CELLS_COUNT 35
#define EPS 0.00001


extern GtkWidget* mainInputBox;
extern GtkWidget* XInputBox;
extern GtkWidget* scaleXInputBox;
extern GtkWidget* scaleYInputBox;

extern int draw_requested;

typedef struct{
	GtkWidget* window;
	GtkWidget* grid;
    GtkWidget* graph_area;
	GtkWidget* button[GRID_CELLS_COUNT];
}calc;

void initializeUI(int argc, char *argv[]);
void activate(GtkApplication *app);

void draw_callback(GtkWidget *widget, cairo_t *cr);
void drawGraph(GtkWidget *widget, cairo_t *cr);
void drawAxles(cairo_t *cr, double scaleX, double scaleY);
void drawFunction(cairo_t *cr, double scaleX, double scaleY);
void drawGrid(GtkWidget *widget, cairo_t *cr, double scaleX, double scaleY);
void drawTickMarks(cairo_t *cr, double scaleX, double scaleY, double stepX, double stepY);

double findLineWidth(double range);
int findStep(double range);

void attachButtonsToGrid(calc* calc);
void initButtons(calc* calc);
void connectSignalButtons(calc* calc);
gboolean drawGraph_Clicked(gpointer user_data);

void activate(GtkApplication *app);
void inputText(GtkButton *button);
void calculate();


#endif