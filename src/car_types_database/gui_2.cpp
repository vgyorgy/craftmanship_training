// GUI 2: Window
// thread-solution: https://stackoverflow.com/questions/30607429/gtk3-and-multithreading-replacing-deprecated-functions

#include <thread>
#include <gtk/gtk.h>
#include "gui.h"
using namespace std;

// Global variables through threads:
GMutex     mutex_interface;
GtkWidget  *label_obj;
string     new_str = "0";

void prepare_window(void)
{
    int argc = 0;
    char ***argv;
    GtkWidget *window;

    gtk_init(&argc, argv);

    // Declarations
    window    = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    label_obj = gtk_label_new("0");

    // Set window properties
    gtk_container_set_border_width (GTK_CONTAINER(window), 20);
    gtk_widget_set_size_request    (GTK_WIDGET(window), 150, 100);
    gtk_container_add              (GTK_CONTAINER(window), label_obj);

    // Draw
    gtk_widget_show_all (window);
    g_signal_connect(G_OBJECT(window), "destroy", G_CALLBACK(gtk_main_quit), NULL);
    
    gtk_main();
}

gboolean update_gui(gpointer data) // Unfortunatelly I couldn't decode "data", that's why I use the "new_str"
{
    g_mutex_lock(&mutex_interface);
    gchar *display;
    display = g_strdup_printf("%s", new_str.c_str());   // convert to str
    gtk_label_set_text(GTK_LABEL(label_obj), display);        // set label to "display"
    g_free(display);                                    // free display
    g_mutex_unlock(&mutex_interface);
    return(FALSE);
}

void set_label(string text)
{
    gpointer data = &text;
    g_idle_add(update_gui, data);
}

void start_gui_if_not_started(void)
{
    static bool started = false;
    if (started == false)
    {
        thread t1(prepare_window);
        t1.detach();            // do not wait for the thread to finish
     // t1.join();              // wait for thread to complete
        started = true;
    }
}

void display_text(string text)
{
    start_gui_if_not_started();
    new_str = text;
    set_label(text);
}
