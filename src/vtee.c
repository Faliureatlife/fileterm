#include <vte/vte.h>

static void child(VteTerminal *terminal, GPid pid, Gerror *error, gpointer user_data) {
	if (!terminal) return;
	if (pid == -1) gtk_main_quit();
}

int main (int argc, char *argv[]){
	GtkWidget *window, *terminal;

	gtk_init(&argc, &argv);
	terminal = vte_terminal_new();
	window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	gtk_window_set_title(GTK_WINDOW(window), "File x Term");


	gchar **envp = g_get_environ();
	gchar **command = (gchar *[]){g_strdup(g_environ_getenv(envp, "SHELL")),NULL};
	g_strfreev(envp);

	vte_terminal_spawn_async(VVTE_TERMINAL(terminal),
			VTE_PTY_DEFAULT,
			NULL, //working dir
			command,
			NULL, //env
			0,    //flags
			NULL,NULL, //child
			NULL,      //child pid
			-1,   	   //timeout
			NULL,      //cancellable
			child_ready,
			NULL);  

	g_signal_connect(window, "delete-event", gtk_main_quit, NULL);
	g_signal_connect(terminal, "child-exited", gtk_main_quit, NULL);
	gtk_container_add(GTK_CONTAINER(window), terminal);
	gtk_widget_show_all(window);
    	gtk_main();
}






