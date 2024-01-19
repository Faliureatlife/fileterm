#include <gtk/gtk.h> 
static void print_hello (GtkWidget *widget, gpointer data)
{
	g_print("based\n");
}

static void print_cr(GtkWidget *widget, gpointer data) {
	g_print("cringe\n");
}

static void
activate (GtkApplication* app,
          gpointer        user_data)
{
// all setup info goes here

  GtkWidget *window;
  GtkWidget *button;
  GtkWidget *button2;
  GtkWidget *box;
 // GtkWidget *box2;

  window = gtk_application_window_new (app);
  gtk_window_set_title (GTK_WINDOW (window), "Based button");
  gtk_window_set_default_size (GTK_WINDOW (window), 200, 200);
  gtk_window_present (GTK_WINDOW (window));

  //setup of elements
  //assign blank to gtk version
  box = gtk_box_new(GTK_ORIENTATION_HORIZONTAL,10); 
  //box2 = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 0);
  //align vert & horizontal
  gtk_widget_set_halign(box, GTK_ALIGN_CENTER);
  gtk_widget_set_valign(box, GTK_ALIGN_CENTER);

  //gtk_widget_set_halign(box2, GTK_ALIGN_CENTER);
  //gtk_widget_set_valign(box2, GTK_ALIGN_CENTER);
  //assign ownership
  gtk_window_set_child(GTK_WINDOW(window), box);
  //gtk_window_set_child(GTK_WINDOW(window), box2);
  
  button = gtk_button_new_with_label("based");
  button2 = gtk_button_new_with_label("cringe");
  g_signal_connect(button2,"clicked", G_CALLBACK (print_cr), NULL);
  g_signal_connect(button, "clicked", G_CALLBACK (print_hello), NULL);
  //g_signal_connect_swapped(button, "clicked", G_CALLBACK(gtk_window_destroy), window);
  gtk_box_append(GTK_BOX (box), button);
  gtk_box_append(GTK_BOX(box), button2);
  gtk_window_present (GTK_WINDOW (window));
}

int
main (int    argc,
      char **argv)
{
  GtkApplication *app;
  int status;

  app = gtk_application_new ("org.gtk.example", G_APPLICATION_DEFAULT_FLAGS);
  g_signal_connect (app, "activate", G_CALLBACK (activate), NULL);
  status = g_application_run (G_APPLICATION (app), argc, argv);
  g_object_unref (app);

  return status;
}
