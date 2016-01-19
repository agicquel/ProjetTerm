#include "configuration.h"

int getConfiguration(char *pattern)
{
  config_t cfg;
  const char *str;
  int valeur = 0;

  /*Initialization */
  config_init(&cfg);

  /* Read the file. If there is an error, report it and exit. */
  if (!config_read_file(&cfg, CONF_FILENAME))
  {
      fprintf(stderr, "Impossible d'ouvir le fichier de configuration\n");
      config_destroy(&cfg);
      exit(EXIT_FAILURE);
  }

  config_lookup_string(&cfg, pattern, &str);
  valeur = atoi(str);

  config_destroy(&cfg);
  return (valeur);
}

void initConfiguration(struct Configuration *cfg)
{
  cfg->frequenceNitrate = getConfiguration("frequenceNitrate");
  cfg->frequenceTemp = getConfiguration("frequenceTemp");
  cfg->niveauNitrate = getConfiguration("niveauNitrate");
  cfg->port = getConfiguration("port");
}
