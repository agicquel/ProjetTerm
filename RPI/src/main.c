#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <errno.h>

#include "analyse.h"

int main(int argc, char **argv)
{
  struct Configuration defaultConfig;
  initConfiguration(&defaultConfig);

  //printf("%d, %d, %d\n", defaultConfig.frequenceNitrate, defaultConfig.frequenceTemp, defaultConfig.niveauNitrate);
  struct Analyse test = getAnalyse("nitrate", 0);
  printf("value : %d\n", test.value);
  printf("date : %d\n", test.date);

  printf("%d\n", getNumberOfAnalyse("nitrate"));

  return EXIT_SUCCESS;
}
