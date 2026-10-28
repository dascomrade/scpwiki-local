#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <gtk/gtk.h>
#include <string.h>
#include <ctype.h>
#include "lib/cJSON.h" // not a standard library, so we use quotes ("")




int RNG(){ //get a random number for the user to open a random SCP page we'd permit them to'

    int MAX = 9999; // its exclusive so the upperbound is not included .curently there is no SCP-9999 or 100000
    int MIN = 2; //never land the random page on SCP-001

    srand(time(NULL));
    int randomSCP =  rand() % (MAX - MIN) + MIN;

    return randomSCP;

}


bool InputValidation(const char *UserInput){
    int InputLength = strlen(UserInput);

    if(InputLength == 0){
        return false;
    }

    for(int i =0; i < InputLength; i++){
        if(!(isdigit((unsigned char)UserInput[i]))){
            return false;
        }
    }
    return true;
}


static void InputSystem(GtkButton *button, gpointer user_data){

    GtkEntry *entry = GTK_ENTRY(user_data);
    const gchar *SCPINPUT = gtk_entry_get_text(entry);

    if(InputValidation(SCPINPUT) == true){
        printf("User Entered %s \n", SCPINPUT);
    }

}

static void activate(GtkApplication *app, gpointer user_data){

    GtkWidget *window; //create thw window object
    GtkWidget *PageTitle; //Title Label
    GtkWidget *SearchBtn;
    GtkWidget *SearchInputbox;
    GtkWidget *MainContainerBox;
    GtkWidget *Vertbox;
    GtkWidget *Horbox;
    GtkWidget *MainLogo;


    window = gtk_application_window_new(app); //tell GTK its a normal window, not a MODAL

    Vertbox = gtk_box_new(GTK_ORIENTATION_VERTICAL, 0);
    Horbox = gtk_box_new(GTK_ORIENTATION_HORIZONTAL,0);
    MainContainerBox = gtk_box_new(GTK_ORIENTATION_VERTICAL, 40);

    PageTitle = gtk_label_new("Foundation Document Archive"); //The "title", the large text on this main page


    SearchInputbox = gtk_entry_new();
    SearchBtn = gtk_button_new_with_label("Search the archive for this SCP");
    MainLogo = gtk_image_new_from_file("imageAssets/header-logo.png");

    gtk_container_add(GTK_CONTAINER(window), MainContainerBox);
    gtk_container_add(GTK_CONTAINER(MainContainerBox), Vertbox);
    gtk_container_add(GTK_CONTAINER(Vertbox), MainLogo);
    gtk_container_add(GTK_CONTAINER(Vertbox), PageTitle); //Add the title before the Searchbox aka "Horbox" so it is loaded first, without box formatting
    

    gtk_container_add(GTK_CONTAINER(Vertbox), Horbox);
    gtk_box_pack_start(GTK_BOX(Horbox), SearchInputbox, TRUE, FALSE, 40);
    gtk_box_pack_end(GTK_BOX(Horbox), SearchBtn, TRUE, FALSE, 40);

    gtk_window_set_default_size(GTK_WINDOW(window), 920, 1024); //a good size on a 1440p display

    gtk_widget_show_all(window); //show active windows


    //Styling
    gtk_label_set_markup(GTK_LABEL(PageTitle), "<span font_family='Sans Normalcy' size='xx-large' weight='bold'> SCP Foundation Document Archive </span>");
    //Input handling


    g_signal_connect(SearchBtn, "clicked", G_CALLBACK(InputSystem), SearchInputbox);

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
