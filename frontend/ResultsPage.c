#include <gtk/gtk.h>




void loadResult(char **result, scrollable, ResultsList){

    GtkWidget *ResultContainer;
    GtkWidget *ResultTitle= gtk_link_button_new_with_label (const gchar* uri, ResultItem);
    GtkWidget *QuickDesc;
    ResultContainer = gtk_box_new(GTK_ORIENTATION_VERTICAL, 0);




}




int main (int argc, char **argv){

gtk_init (&argc, &argv);

GtkWidget *window = gtk_window_new (GTK_WINDOW_TOPLEVEL);
g_signal_connect (window, "destroy", G_CALLBACK (gtk_main_quit), NULL);
GtkWidget *scrollable = gtk_scrolled_window_new (NULL, NULL);


gtk_container_add(GTK_CONTAINER(window), scrollable);

GtkWidget *ResultsList;
ResultsList = gtk_box_new(GTK_ORIENTATION_VERTICAL, 0);
gtk_container_add(GTK_CONTAINER(window), ResultsList);
loadResult(scrollable, ResultsList);


gtk_window_set_default_size(GTK_WINDOW(window), 720, 1024);

gtk_widget_show_all(window);


gtk_main();



}
