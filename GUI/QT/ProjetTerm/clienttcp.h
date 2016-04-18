#ifndef CLIENTTCP_H
#define CLIENTTCP_H

#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <strings.h>

#define BUFFER_MAX 256

void getString(FILE* file, int numero, char buffer[]);
void error(const char *msg);
void sendString (int socket, char string[]);
void receiveString (int socket, char string[BUFFER_MAX]);
void sendFile (int socket, char file[]);
void receiveFile (int socket, char file[]);

#endif // CLIENTTCP_H
