#include <gtk/gtk.h>
#include <glib/gstdio.h>
#include <string.h>

static void printI(GtkWidget *widget, gpointer data) {
  g_print("Herrow\n");
}

static void quit (GtkWindow *window){
	gtk_window_close(window);
}

static void activate(GtkApplication *app, gpointer user_data){
	//create a GtkBuilder
	GtkBuilder *builder = gtk_builder_new();
	gtk_builder_add_from_file(builder, "builder.ui", NULL);

	//connect signal to window
  GObject *window = gtk_builder_get_object(builder, "window");
  gtk_window_set_application (GTK_WINDOW (window), app);

  //connect signal to widgets
  GObject *button = gtk_builder_get_object(builder, "button1");
  g_signal_connect(button, "clicked", G_CALLBACK (printI),NULL);

  button = gtk_builder_get_object (builder, "button2");
  g_signal_connect(button, "clicked", G_CALLBACK(printI), NULL);

  button =gtk_builder_get_object(builder, "quit");
  g_signal_connect_swapped(button,"clicked",G_CALLBACK(quit), window);

  gtk_widget_set_visible(GTK_WIDGET(window), TRUE);


  //builder no longer needed
  g_object_unref(builder);
}

int main (int argc, char *argv[]) {
#ifdef GTK_SRCDIR
  g_chdir(GTK_SRCDIR);
#endif

  GtkApplication *app = gtk_application_new("com.example.myapp", G_APPLICATION_DEFAULT_FLAGS);
  g_signal_connect(app, "activate", G_CALLBACK(activate),NULL);

  int status = g_application_run(G_APPLICATION(app), argc, argv);
  g_object_unref (app);

  return status;

}



    
