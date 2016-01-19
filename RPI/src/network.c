#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <errno.h>
#include <time.h>
#include <unistd.h>

#include <pthread.h>

#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>

#include "analyse.h"

#define MAXPENDING 5    /* Max connection requests */
#define BUFFSIZE 32

void *network()
{
  printf("Network Thread\n");
  /*
  int val = 1;
  while (val)
  {
    scanf("%d", &val);
  }
  pthread_exit (NULL);
  */

  int port = getConfiguration("port"); /* port number */

  printf("\nport = %d\n", port);


  pthread_exit (NULL);
}
//sendAnalyse

//sendConfiguration
