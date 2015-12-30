#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <errno.h>
#include <time.h>
#include <unistd.h>

#include <pthread.h>

void *network()
{
  int val = 1;
  while (val)
  {
    scanf("%d", &val);
  }
  pthread_exit (NULL);
}
//sendAnalyse

//sendConfiguration
