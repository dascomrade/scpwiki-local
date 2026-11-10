#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <gtk/gtk.h>
#include <string.h>
#include <ctype.h>
#include "lib/cJSON.h" // not a standard library, so we use quotes ("")

#define gtk_label_set_css gtk_label_set_markup


int RNG(){ //get a random number for the user to open a random SCP page we'd permit them to'

    int MAX = 9999; // its exclusive so the upperbound is not included .curently there is no SCP-9999 or 100000
    int MIN = 2; //never land the random page on SCP-001

    srand(time(NULL));
    int randomSCP =  rand() % (MAX - MIN) + MIN;

    return randomSCP;

}


bool InputValidation(const char *UserInput){
    int InputLength = strlen(UserInput);

    bool SearchTerm = false;
    bool DirectNumber = false;

    if(InputLength == 0){
        return false;
    }


    for(int i =0; i < InputLength; i++){
        if(!(isdigit((unsigned char)UserInput[i]))){
            if(!(isalnum((unsigned char)UserInput[i]))){
             return false;
            }
            else{
            SearchTerm = true;
            UserInput[i] = tolower(UserInput[i]);
            }
        }
    }
    return true; //replace with log of either open file or initiate search engine
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
    GtkWidget *MainContainerBox;
    GtkWidget *ContentContainerBox;
    GtkWidget *Vertbox;
    GtkWidget *Horbox;
    GtkWidget *MainLogo;
    GtkWidget *PageTitle; //Title Label
    GtkWidget *RandomSearchBtn;
    GtkWidget *SearchInputbox;
    GtkWidget *SearchBtn;




    window = gtk_application_window_new(app); //tell GTK its a normal window, not a MODAL

    MainContainerBox = gtk_box_new(GTK_ORIENTATION_VERTICAL, 40);
    ContentContainerBox = gtk_box_new(GTK_ORIENTATION_VERTICAL, 40);
    Vertbox = gtk_box_new(GTK_ORIENTATION_VERTICAL, 0);
    Horbox = gtk_box_new(GTK_ORIENTATION_HORIZONTAL,0);


    PageTitle = gtk_label_new(NULL); //The "title", the large text on this main page. Defined with CSS later

    RandomSearchBtn = gtk_button_new_with_label("Search the archive for this SCP");
    SearchInputbox = gtk_entry_new();
    SearchBtn = gtk_button_new_with_label("Search the archive for this SCP");
    MainLogo = gtk_image_new_from_file("imageAssets/header-logo.png");

    gtk_container_add(GTK_CONTAINER(window), MainContainerBox);
    gtk_container_add(GTK_CONTAINER(MainContainerBox), ContentContainerBox);
    gtk_container_add(GTK_CONTAINER(ContentContainerBox), Vertbox);
    gtk_container_add(GTK_CONTAINER(Vertbox), MainLogo);
    gtk_container_add(GTK_CONTAINER(Vertbox), PageTitle); //Add the title before the Searchbox aka "Horbox" so it is loaded first, without box formatting
    

    gtk_container_add(GTK_CONTAINER(ContentContainerBox), Horbox);
    gtk_box_pack_start(GTK_BOX(Horbox), SearchInputbox, TRUE, FALSE, 40);
    gtk_box_pack_end(GTK_BOX(Horbox), SearchBtn, TRUE, FALSE, 40);

    gtk_window_set_default_size(GTK_WINDOW(window), 920, 1024); //a good size on a 1440p display

    gtk_widget_show_all(window); //show active windows


    //Styling
    gtk_label_set_css(GTK_LABEL(PageTitle), "<span font_family='Sans Normalcy' size='250%' weight='bold'> SCP Foundation Document Archive </span>");

    //Input handling
    g_signal_connect(SearchBtn, "clicked", G_CALLBACK(InputSystem), SearchInputbox);

}

int main(int argc, char **argv)
{
    GtkApplication *app;

    app = gtk_application_new("in.scpwiki-gtk", G_APPLICATION_DEFAULT_FLAGS);

    g_signal_connect(app, "activate", G_CALLBACK(activate), NULL);

    suc = g_application_run(G_APPLICATION(app), argc, argv);

    g_object_unref(app);
}
