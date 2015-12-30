#ifndef ANALYSE_H_INCLUDED
#define ANALYSE_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <errno.h>
#include <time.h>
#include <unistd.h>
#include <pthread.h>

#define NITRATE_FILENAME "nitrate.txt"
#define DATE_NITRATE_FILENAME "nitrate.date.txt"
#define TEMP_FILENAME "temp.txt"
#define DATE_TEMP_FILENAME "temp.date.txt"

struct Analyse
{
  int value;
  long int date;
};

int counterLine (FILE*);
int getLine(FILE*, int);
int getNumberOfAnalyse(char*);
struct Analyse getAnalyse(char*, int);
void addAnalyse (char*, int);

int getConfiguration(char*);

void *analyseNitrate();
void *analyseTemp();

#endif // ANALYSE_H_INCLUDED
