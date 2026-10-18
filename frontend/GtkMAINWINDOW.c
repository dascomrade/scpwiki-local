#include <stdio.h>
#include <stdlib.h>
#include "lib/cJSON.h"

#include <gtk/gtk.h>



int series1_whatscp(int scpNum){

    return 0;
}


/*
int whatseries(int inputID){

    if(inputID - 1 == 0){ //Catch SCP-001

        //call Unique Page for SCP-001

    }

    int series = (inputID / 1000) + 1; // SCP  999 is Series 1, while SCP 1000 is Series 2, to make calc cleaner we'll do this'

    switch(series){

        case 1:
            series1_whatscp(inputID);
            break;
        case 2:
            series2_whatscp(inputID);
            break;
        case 3:
            series3_whatscp(inputID);
            break;
        case 4:
            series4_whatscp(inputID);
            break;
        case 5:
            series5_whatscp(inputID);
            break;
        case 6:
            series6_whatscp(inputID);
            break;
        case 7:
            series7_whatscp(inputID);
            break;
        case 8:
            series8_whatscp(inputID);
            break;
        case 9:
            series9_whatscp(inputID);
            break;
        case 10:
            series10_whatscp(inputID);
            break;
        default:
            return(1);
    }

    return series;
}
*/

static void activate(GtkApplication *app, gpointer user_data){

    GtkWidget *window; //create thw window object
    GtkWidget *PageTitle; //Title Label
    GtkWidget *SearchBtn;
    GtkWidget *Vertbox;
    GtkWidget *Horbox;

    window = gtk_application_window_new(app); //tell GTK its a normal window, not a MODAL
    
    Vertbox = gtk_box_new(GTK_ORIENTATION_VERTICAL, 0);
    Horbox = gtk_box_new(GTK_ORIENTATION_HORIZONTAL,0);


    PageTitle = gtk_label_new("Foundation Document Archive"); //The "title", the large text on this main page
    SearchBtn = gtk_button_new_with_label("Search the archive for this SCP");
    
    gtk_container_add(GTK_CONTAINER(window), Vertbox);
    
    gtk_container_add(GTK_CONTAINER(Vertbox), PageTitle); //Add the title before the Searchbox so it is loaded first, without box formatting

    gtk_container_add(GTK_CONTAINER(Vertbox), Horbox);
    gtk_box_pack_end(GTK_BOX(Horbox), SearchBtn, TRUE, FALSE, 40);    

    gtk_window_set_default_size(GTK_WINDOW(window), 920, 1024); //a good size on a 1440p display

    gtk_widget_show_all(window); //show active windows

}

int main(int argc, char **argv)
{
    int suc; //success or fail

    int scpNum;
    


    GtkApplication *app;

    app = gtk_application_new("in.main", G_APPLICATION_DEFAULT_FLAGS);

    g_signal_connect(app, "activate", G_CALLBACK(activate), NULL);

    suc = g_application_run(G_APPLICATION(app), argc, argv);

    g_object_unref(app);

    return suc;
}
