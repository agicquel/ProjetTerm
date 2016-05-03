#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <wiringPi.h>

#define speed 4

void moteur1 (int nbr_de_tours, char *sens) // avant ou arriere
{
  wiringPiSetup();
  int i = 0;
  int A, B, C , D;
  if (strcmp(sens, "avant") == 0)
  {
    A = 0;
    B = 1;
    D = 2;
    C  = 3;
  }
  else if (strcmp(sens, "arriere") == 0)
  {
    A = 3;
    B = 2;
    D = 1;
    C = 0;
  }
  else
  {
    printf("Sens impossible");
  }

  pinMode (A, OUTPUT);
  pinMode (B, OUTPUT);
  pinMode (C, OUTPUT);
  pinMode (D, OUTPUT);

  for (i = 0; i < (512 * nbr_de_tours); i++)
  {
    digitalWrite (A, HIGH) ;
    digitalWrite (B, HIGH) ; delay (speed) ;
    digitalWrite (A, LOW) ;
    digitalWrite (C, HIGH); delay (speed) ;
    digitalWrite (B, LOW);
    digitalWrite (D, HIGH); delay (speed) ;
    digitalWrite (C, LOW) ;
    digitalWrite (A, HIGH) ; delay (speed) ;
    digitalWrite (D, LOW) ;
  }
}

void moteur2 (int nbr_de_tours, char *sens) // avant ou arriere
{
  wiringPiSetup();
  int i = 0;
  int A, B, C , D;
  if (strcmp(sens, "avant") == 0)
  {
    D = 5;
    A = 6;
    B = 10;
    C = 11;
  }
  else if (strcmp(sens, "arriere") == 0)
  {
    D = 11;
    A = 10;
    B = 6;
    C = 5;
  }
  else
  {
    printf("Sens impossible");
  }

  pinMode (A, OUTPUT);
  pinMode (B, OUTPUT);
  pinMode (C, OUTPUT);
  pinMode (D, OUTPUT);

  for (i = 0; i < (512 * nbr_de_tours); i++)
  {
    digitalWrite (A, HIGH) ;
    digitalWrite (B, HIGH) ; delay (speed) ;
    digitalWrite (A, LOW) ;
    digitalWrite (C, HIGH); delay (speed) ;
    digitalWrite (B, LOW);
    digitalWrite (D, HIGH); delay (speed) ;
    digitalWrite (C, LOW) ;
    digitalWrite (A, HIGH) ; delay (speed) ;
    digitalWrite (D, LOW) ;
  }
}

void moteur3 (int nbr_de_tours, char *sens) // avant ou arriere
{
  wiringPiSetup();
  int i = 0;
  int A, B, C , D;
  if (strcmp(sens, "avant") == 0)
  {
    C = 17;
    B = 18;
    D = 19;
    A = 20;
  }
  else if (strcmp(sens, "arriere") == 0)
  {
    C = 20;
    B = 19;
    D = 18;
    A = 17;
  }
  else
  {
    printf("Sens impossible");
  }

  pinMode (A, OUTPUT);
  pinMode (B, OUTPUT);
  pinMode (C, OUTPUT);
  pinMode (D, OUTPUT);

  for (i = 0; i < (512 * nbr_de_tours); i++)
  {
    digitalWrite (A, HIGH) ;
    digitalWrite (B, HIGH) ; delay (speed) ;
    digitalWrite (A, LOW) ;
    digitalWrite (C, HIGH); delay (speed) ;
    digitalWrite (B, LOW);
    digitalWrite (D, HIGH); delay (speed) ;
    digitalWrite (C, LOW) ;
    digitalWrite (A, HIGH) ; delay (speed) ;
    digitalWrite (D, LOW) ;
  }
}

int rouge()
{
  wiringPiSetup();
  pinMode (15, OUTPUT);

  digitalWrite (15, HIGH);
  delay(1000);
  system("python ./rgb.py");

  char resultat[10] = {0};
  FILE* file;
  if (NULL == (file = fopen ("rouge.tmp", "r")))
  {
      fprintf(stderr, "Impossible d'ouvir le fichier de rouge\n");
      exit(EXIT_FAILURE);
  }
  fseek(file, 0, SEEK_SET);;
  fgets(resultat, 10, file);

  digitalWrite (15, LOW);

  return atoi(resultat);
}

void relais (char *etat)
{
  wiringPiSetup();
  pinMode(16, OUTPUT);

  if (strcmp(etat, "on") == 0)
  {
    digitalWrite(16, HIGH);
  }
  else if (strcmp(etat, "off") == 0)
  {
    digitalWrite(16, LOW);
  }
  else
  {
    printf("état impossible");
  }
}
