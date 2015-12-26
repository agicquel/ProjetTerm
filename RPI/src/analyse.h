#ifndef ANALYSE_H_INCLUDED
#define ANALYSE_H_INCLUDED

#define CONF_FILENAME "configuration.txt"
#define NITRATE_FILENAME "nitrate.txt"
#define DATE_NITRATE_FILENAME "nitrate.date.txt"
#define TEMP_FILENAME "temp.txt"
#define DATE_TEMP_FILENAME "temp.date.txt"

struct Configuration
{
  // en minutes
  int frequenceNitrate;
  int frequenceTemp;
  // le niveau de nitrate souhaité
  int niveauNitrate;
};

struct Analyse
{
  int value;
  int date;
};

struct Analyse getAnalyse(char*, int);
int getConfiguration(char*);
void initConfiguration(struct Configuration*);
int counterLine (FILE*);
int getNumberOfAnalyse(char*);
int getLine(FILE*, int);

#endif // ANALYSE_H_INCLUDED
