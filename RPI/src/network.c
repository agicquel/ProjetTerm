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

  int port = 42; /* port number */
  int rqst; /* socket accepting the request */
  socklen_t alen; /* length of address structure */
  struct sockaddr_in my_addr; /* address of this service */
  struct sockaddr_in client_addr; /* client's address */
  int sockoptval = 1;

  int socket;

  //on crée le socket
  if ((socket = socket(AF_INET, SOCK_STREAM, 0)) < 0)
  {
    fprintf(stderr, "cant create socket\n");
  }

  struct sockaddr_in myaddr;
  /* bind to an arbitrary return address */
  /* because this is the client side, we don't care about the address */
  /* since no application will connect here: */
  /* INADDR_ANY is the IP address and 0 is the socket */
  /* htonl converts a long integer (e.g. address) to a network representation */
  /* htons converts a short integer (e.g. port) to a network representation */
  memset((char *)&myaddr, 0, sizeof(myaddr));
  myaddr.sin_family = AF_INET;
  myaddr.sin_addr.s_addr = htonl(INADDR_ANY);
  myaddr.sin_port = htons(port);

  if (bind(fd, (struct sockaddr *)&myaddr, sizeof(myaddr)) < 0)
  {
    fprintf(stderr, "bind failed\n");
    exit(1);
  }

  /* set the socket for listening (queue backlog of 5) */
  if (listen(svc, 5) < 0)
  {
    fprintf(stderr, "listen failed\n");
    exit(1);
    }

  /* loop, accepting connection requests */
  for (;;)
  {
    while ((rqst = accept(svc, (struct sockaddr *)&client_addr, &alen)) < 0)
    {
    }
  }



  pthread_exit (NULL);
}
//sendAnalyse

//sendConfiguration
