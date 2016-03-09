#include "analyse.h"

void *analyseTemp()
{
    int remaining = 1;
    int valeur = 0;
    int wait = getConfiguration("frequenceTemp");
    while (remaining)
    {
        valeur = 42; // appelle la fonction du termometre
        addAnalyse("temp", valeur);
        sleep(wait);
    }
    pthread_exit (NULL);
}

void *analyseNitrate()
{
    int remaining = 1;
    int valeur = 0;
    int wait = getConfiguration("frequenceNitrate");
    while (remaining)
    {
        valeur = 42; // appelle la fonction du termometre
        addAnalyse("nitrate", valeur);
        sleep(wait);
    }
    pthread_exit (NULL);
}

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
    FILE *data;
    FILE *date;
    //get the date
    time_t t;
    time(&t);

    if (strcmp(pattern, "nitrate") == 0)
    {
        if (NULL == (data = fopen (NITRATE_FILENAME, "a")))
        {
            fprintf(stderr, "Impossible d'ouvir le fichier de nitrate.txt\n");
            exit(EXIT_FAILURE);
        }
        if (NULL == (date = fopen (DATE_NITRATE_FILENAME, "a")))
        {
            fprintf(stderr, "Impossible d'ouvir le fichier de nitrate.date.txt\n");
            exit(EXIT_FAILURE);
        }
    }
    else if (strcmp(pattern, "temp") == 0)
    {
        if (NULL == (data = fopen (TEMP_FILENAME, "a")))
        {
            fprintf(stderr, "Impossible d'ouvir le fichier de nitrate.txt\n");
            exit(EXIT_FAILURE);
        }
        if (NULL == (date = fopen (DATE_TEMP_FILENAME, "a")))
        {
            fprintf(stderr, "Impossible d'ouvir le fichier de nitrate.date.txt\n");
            exit(EXIT_FAILURE);
        }
    }
    else
    {
        printf("%s dosent exist !\n", pattern);
    }

    fprintf(data, "%d\n", value);
    fprintf(date, "%ld\n", t);

    fclose (data);
    fclose (date);
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
    long int retour = 0;

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
