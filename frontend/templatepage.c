#include <stdio.h>
#include <stdlib.h>
#include "lib/cJSON.h"

#include <gtk/gtk.h>



static void activate(GtkApplication *app, gpointer user_data){
    

    GtkWidget *window; //create thw window object
    GtkWidget *PageTitle;
    
    char scpNum[5] = "999";

    window = gtk_application_window_new(app); //tell GTK its a normal window, not a MODAL
    
    gtk_window_set_title(GTK_WINDOW(window), ("SCP %s", scpNum)); 

    PageTitle = gtk_label_new(("SCP %s", scpNum)); //The "title", the large text on this main page

    gtk_container_add(GTK_CONTAINER(window), PageTitle);

    gtk_window_set_default_size(GTK_WINDOW(window), 920, 1024); //a good size on a 1440p display

    gtk_widget_show_all(window); //show active windows

}

int main(int argc, char **argv)
{
    int suc; //success or fail
    

    GtkApplication *app;

    app = gtk_application_new("in.main", G_APPLICATION_DEFAULT_FLAGS);

    g_signal_connect(app, "activate", G_CALLBACK(activate), NULL);

    suc = g_application_run(G_APPLICATION(app), argc, argv);

    g_object_unref(app);

    return suc;
}
