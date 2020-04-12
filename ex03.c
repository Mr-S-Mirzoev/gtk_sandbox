#include <stdlib.h>
#include <stdio.h>
#include <gtk/gtk.h>

static GtkWidget *number1;
static GtkWidget *what_to_do;
static GtkWidget *number2;
static GtkWidget *result;
static GtkWidget *num1_label;
static GtkWidget *operation_label;
static GtkWidget *num2_label;
static GtkWidget *calc_label;
static GtkWidget *res_label;

void do_calculate(GtkWidget *calculate, gpointer data) {
    int num1 = atoi((char *)gtk_entry_get_text(GTK_ENTRY(number1)));
    int num2 = atoi((char *)gtk_entry_get_text(GTK_ENTRY(number2)));

    char buffer[32];
    char *x = (char *)gtk_entry_get_text(GTK_ENTRY(what_to_do));
    switch (*x) {
        case '+':
            snprintf(buffer, sizeof(buffer), "result: %d", num1 + num2);
            break;
        case '-':
            snprintf(buffer, sizeof(buffer), "result: %d", num1 - num2);
            break;
        case '*':
            snprintf(buffer, sizeof(buffer), "result: %d", num1 * num2);
            break;
        case '/':
            snprintf(buffer, sizeof(buffer), "result: %d", num1 / num2);
            break;
        default:
            snprintf(buffer, sizeof(buffer), "wrong entry, try again");
    }
    
    gtk_label_set_text(GTK_LABEL(result), buffer);
}

// gcc 007_gtk.c -o 007_gtk `pkg-config --cflags gtk+-3.0` `pkg-config --libs gtk+-3.0`
int main(int argc, char **argv) {
    GtkWidget *window, *grid, *calculate;
    gtk_init(&argc, &argv);

    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);

    grid = gtk_grid_new();
    gtk_container_add(GTK_CONTAINER(window), grid);
    
    num1_label = gtk_label_new("First number");
    gtk_grid_attach(GTK_GRID(grid), num1_label, 0, 0, 1, 1);
    
    operation_label = gtk_label_new("Operation");
    gtk_grid_attach(GTK_GRID(grid), operation_label, 1, 0, 1, 1);

    num2_label = gtk_label_new("Second number");
    gtk_grid_attach(GTK_GRID(grid), num2_label, 2, 0, 1, 1);

    calc_label = gtk_label_new("Press button");
    gtk_grid_attach(GTK_GRID(grid), calc_label, 3, 0, 1, 1);

    res_label = gtk_label_new("here is");
    gtk_grid_attach(GTK_GRID(grid), res_label, 4, 0, 1, 1);

    number1 = gtk_entry_new();
    gtk_grid_attach(GTK_GRID(grid), number1, 0, 1, 1, 1);
    
    what_to_do = gtk_entry_new();
    gtk_grid_attach(GTK_GRID(grid), what_to_do, 1, 1, 1, 1);

    number2 = gtk_entry_new();
    gtk_grid_attach(GTK_GRID(grid), number2, 2, 1, 1, 1);

    calculate = gtk_button_new_with_label("calculate");
    g_signal_connect(calculate, "clicked", G_CALLBACK(do_calculate), NULL);
    gtk_grid_attach(GTK_GRID(grid), calculate, 3, 1, 1, 1);

    result = gtk_label_new("result: ");
    gtk_grid_attach(GTK_GRID(grid), result, 4, 1, 1, 1);

    gtk_widget_show_all(window);
    gtk_main();

    return 0;
}
