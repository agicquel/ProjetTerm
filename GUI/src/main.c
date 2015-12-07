#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <errno.h>

#include <gtk/gtk.h>

#define height 600
#define width 800

int main(int argc, char *argv[]) {

	GtkWidget *fenetre;
		
	gtk_init(&argc, &argv);

	fenetre = gtk_window_new(GTK_WINDOW_TOPLEVEL);

	gtk_window_set_title(GTK_WINDOW(fenetre), "Purificateur d'eau");
	gtk_window_set_default_size(GTK_WINDOW(fenetre), width, height);
	gtk_window_set_position(GTK_WINDOW(fenetre), GTK_WIN_POS_CENTER);

	gtk_widget_show(fenetre);

	g_signal_connect(fenetre, "destroy", G_CALLBACK(gtk_main_quit), NULL);

	gtk_main();

	g_printf("GTK+ version: %d.%d.%d\n", gtk_major_version, gtk_minor_version, gtk_micro_version);
	g_printf("Glib version: %d.%d.%d\n", glib_major_version, glib_minor_version, glib_micro_version);    
        
    return 0;
}
