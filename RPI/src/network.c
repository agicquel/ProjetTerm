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
#include <strings.h>

#include "analyse.h"

void *network()
{
  printf("Network Thread\n");

  int port = getConfiguration("port"); /* port number */
  printf("\nport = %d\n", port);
  int sockfd, newsockfd;
  socklen_t clilen;
  char buffer[256];
  struct sockaddr_in serv_addr, cli_addr;
  int n;

  sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd < 0)
  {
    fprintf(stderr, "ERROR opening socket\n");
  }
  bzero((char *) &serv_addr, sizeof(serv_addr));

  serv_addr.sin_family = AF_INET;
  serv_addr.sin_addr.s_addr = INADDR_ANY;
  serv_addr.sin_port = htons(port);
  if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0)
  {
    fprintf(stderr, "ERROR on binding\n");
  }

  listen(sockfd,1);
  clilen = sizeof(cli_addr);
  newsockfd = accept(sockfd, (struct sockaddr *) &cli_addr, &clilen);
  if (newsockfd < 0)
  {
    fprintf(stderr, "ERROR on accept\n");
  }
  bzero(buffer,256);

  while ((strcmp(buffer, "quitter") != 0) || n != 0)
  {
    /* Accept actual connection from the client */
    if (newsockfd < 0) {
      newsockfd = accept(sockfd, (struct sockaddr *)&cli_addr, &clilen);
    }
    while (newsockfd > 0)
    {
      n = read(newsockfd,buffer,255 || n != 0);
      printf("Here is the message: %s\n",buffer);
    }
  }

  close(newsockfd);
  close(sockfd);
  pthread_exit (NULL);
}
//sendAnalyse

//sendConfiguration
