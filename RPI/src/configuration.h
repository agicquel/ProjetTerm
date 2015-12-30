#ifndef CONFIGURATION_H_INCLUDED
#define CONFIGURATION_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <errno.h>
#include <libconfig.h>

#define CONF_FILENAME "configuration.txt"

struct Configuration
{
  // en minutes
  int frequenceNitrate;
  int frequenceTemp;
  // le niveau de nitrate souhaité
  int niveauNitrate;
};

int getConfiguration(char*);
void initConfiguration(struct Configuration*);

#endif
