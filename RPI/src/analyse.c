#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <errno.h>

#include "analyse.h"

struct Analyse getAnalyse(char *pattern, int numero)
{
  FILE *data;
  FILE *date;
  struct Analyse analyse;

  if (strcmp(pattern, "nitrate") == 0)
  {
    if (NULL == (data = fopen (NITRATE_FILENAME, "r")))
    {
      fprintf(stderr, "Impossible d'ouvir le fichier de nitrate.txt\n");
      exit(EXIT_FAILURE);
    }
    if (NULL == (date = fopen (DATE_NITRATE_FILENAME, "r")))
    {
      fprintf(stderr, "Impossible d'ouvir le fichier de nitrate.date.txt\n");
      exit(EXIT_FAILURE);
    }
  }
  else if (strcmp(pattern, "temp") == 0)
  {
    if (NULL == (data = fopen (TEMP_FILENAME, "r")))
    {
      fprintf(stderr, "Impossible d'ouvir le fichier de nitrate.txt\n");
      exit(EXIT_FAILURE);
    }
    if (NULL == (date = fopen (DATE_TEMP_FILENAME, "r")))
    {
      fprintf(stderr, "Impossible d'ouvir le fichier de nitrate.date.txt\n");
      exit(EXIT_FAILURE);
    }
  }
  else
  {
    printf("%s dosent exist !\n", pattern);
  }

  if ((counterLine(data)) != (counterLine(date)))
  {
    fprintf(stderr, "nitrate: number of lines is different\n");
    exit(EXIT_FAILURE);
  }

  fseek(data, 0, SEEK_SET);
  fseek(date, 0, SEEK_SET);

  if (numero > (counterLine(data)) || numero < 0)
  {
    fprintf(stderr, "nitrate: this analyse doesnt exist\n");
    exit(EXIT_FAILURE);
  }

  analyse.value = getLine(data, numero);
  analyse.date = getLine(date, numero);

  fclose (data);
  fclose (date);

  return (analyse);
}

void addAnalyse (char *pattern, int value)
{
  
}

int getNumberOfAnalyse(char *pattern)
{
  int number = 0;
  FILE* file;

  if (strcmp(pattern, "nitrate") == 0)
  {
    if (NULL == (file = fopen (NITRATE_FILENAME, "r")))
    {
      fprintf(stderr, "Impossible d'ouvir le fichier de nitrate.txt\n");
      exit(EXIT_FAILURE);
    }
    number = counterLine(file);
  }
  else if (strcmp(pattern, "temp") == 0)
  {
    if (NULL == (file = fopen (TEMP_FILENAME, "r")))
    {
      fprintf(stderr, "Impossible d'ouvir le fichier de temp.txt\n");
      exit(EXIT_FAILURE);
    }
    number = counterLine(file);
  }
  else
  {
    printf("%s dosent exist !\n", pattern);
  }
  return number;
}

int counterLine (FILE* file) // the file have to be readable
{
    int line = 0;
    int buffer = 0;
    int buffer2 = '\0';

    if (file != NULL)
    {
        while((buffer=fgetc(file)) != EOF)
        {
        if(buffer=='\n')
            line++;
        buffer2 = buffer;
        }
        if(buffer2 != '\n')
            line++; // The last line
    }
    else
        printf("Can't read the file");

    return line;
}

int getLine(FILE* file, int numero)
{
  char line[BUFSIZ];
  int count = 0;
  int retour = 0;

  fseek(file, 0, SEEK_SET);

  while (fgets(line, BUFSIZ, file) != NULL)
    {
        if (count == numero)
        {
          retour = atoi(line);
        }
        count++;
    }
    return (retour);
}
