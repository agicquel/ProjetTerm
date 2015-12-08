#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <errno.h>

#include <gtk/gtk.h>
#include "main.h"

static void  Preferences_init (Preferences *prefs)
{
	Preferences priv;

	priv = example_app_prefs_get_instance_private (prefs);
	gtk_widget_init_template (GTK_WIDGET (prefs));
	priv->settings = g_settings_new ("org.gtk.exampleapp");

	g_settings_bind (priv->settings, "refresh", priv->refresh, "refresh", G_SETTINGS_BIND_DEFAULT);
	g_settings_bind (priv->settings, "nitrate", priv->nitrate, "active-id", G_SETTINGS_BIND_DEFAULT);

}
