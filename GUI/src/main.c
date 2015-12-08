#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <errno.h>

#include <gtk/gtk.h>
#include "main.h"

#define height 600
#define width 800


int main(int argc, char *argv[]) {

	// create Widget and item
	GtkWidget *fenetre;
	GtkWidget *vbox;

	GtkWidget *toolbar;
	GtkToolItem *exitTb;
	GtkToolItem *paramTb;
	
	// Init GTK
	gtk_init(&argc, &argv);

	// Initialisation de la fenetre
	fenetre = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	gtk_window_set_title(GTK_WINDOW(fenetre), "Purificateur d'eau");
	gtk_window_set_default_size(GTK_WINDOW(fenetre), width, height);
	gtk_window_set_position(GTK_WINDOW(fenetre), GTK_WIN_POS_CENTER);

	// Toolbar
	vbox = gtk_vbox_new(FALSE, 0);
	gtk_container_add(GTK_CONTAINER(fenetre), vbox);

	toolbar = gtk_toolbar_new();
	gtk_toolbar_set_style(GTK_TOOLBAR(toolbar), GTK_TOOLBAR_ICONS);

		// parametre button
	paramTb = gtk_tool_button_new_from_stock(GTK_STOCK_PREFERENCES);
	gtk_toolbar_insert(GTK_TOOLBAR(toolbar), paramTb, -1);	

		// exit button
	exitTb = gtk_tool_button_new_from_stock(GTK_STOCK_QUIT);
	gtk_toolbar_insert(GTK_TOOLBAR(toolbar), exitTb, -1);
	g_signal_connect(fenetre, "destroy", G_CALLBACK(gtk_main_quit), NULL);
	g_signal_connect(G_OBJECT(exitTb), "clicked", G_CALLBACK(gtk_main_quit), NULL);
	
	gtk_box_pack_start(GTK_BOX(vbox), toolbar, FALSE, FALSE, 5);

	// affiche la fenetre
	gtk_widget_show_all(fenetre);

	// Loop GTK
	gtk_main();

	return 0;
}
