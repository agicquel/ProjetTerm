#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <errno.h>

#include <gtk/gtk.h>
#include "main.h"

/*#define height 600
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
*/

int main(int argc, char *argv [])
{
  GtkWidget *fenetre_principale = NULL;
  GtkBuilder *builder = NULL;
  GError *error = NULL;
  gchar *filename = NULL;
  /* Initialisation de la librairie Gtk. */
  gtk_init(&argc, &argv);

  /* Ouverture du fichier Glade de la fenêtre principale */
  builder = gtk_builder_new();

  /* Création du chemin complet pour accéder au fichier test.glade. */
  /* g_build_filename(); construit le chemin complet en fonction du système */
  /* d'exploitation. ( / pour Linux et \ pour Windows) */
  filename =  g_build_filename ("GUI-Projet.glade", NULL);

      /* Chargement du fichier test.glade. */
  gtk_builder_add_from_file (builder, filename, &error);
  g_free (filename);
  if (error)
  {
    gint code = error->code;
    g_printerr("%s\n", error->message);
    g_error_free (error);
    return code;
  }

    /* Récupération du pointeur de la fenêtre principale */
  fenetre_principale = GTK_WIDGET(gtk_builder_get_object (builder, "MainWindow"));

  /* Affectation du signal "destroy" à la fonction gtk_main_quit(); pour la */
  /* fermeture de la fenêtre. */
  g_signal_connect (G_OBJECT (fenetre_principale), "destroy", (GCallback)gtk_main_quit, NULL);

  /* Affichage de la fenêtre principale. */
  gtk_widget_show_all (fenetre_principale);

  gtk_main();

  return 0;
}
