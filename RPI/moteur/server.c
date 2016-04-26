

/* A simple server in the internet domain using TCP
   The port number is passed as an argument */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define BUFFER_MAX 256

//#include "analyse.h"
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

void getLine(FILE* file, int numero, char buffer[])
{
    char line[BUFFER_MAX];
    int count = 0;

    fseek(file, 0, SEEK_SET);

    while (fgets(line, BUFSIZ, file) != NULL)
    {
        if (count == numero)
        {
            strncpy(line, buffer, BUFFER_MAX);
        }
        count++;
    }
}

void sendString (int socket, char string[]);
void error(const char *msg);
void receiveString (int socket, char string[BUFFER_MAX]);
void sendFile (int socket, char file[]);
void receiveFile (int socket, char file[]);

int main(int argc, char *argv[])
{
    int fin = 1;
    int sockfd, newsockfd, portno;
    socklen_t clilen;
    char buffer[BUFFER_MAX];
    struct sockaddr_in serv_addr, cli_addr;
    if (argc < 2)
    {
        fprintf(stderr,"ERROR, no port provided\n");
        exit(1);
    }
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0)
        error("ERROR opening socket");
    bzero((char *) &serv_addr, sizeof(serv_addr));
    portno = atoi(argv[1]);
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(portno);
    if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0)
        error("ERROR on binding");
    listen(sockfd,1); // 1 client max
    clilen = sizeof(cli_addr);
    newsockfd = accept(sockfd, (struct sockaddr *) &cli_addr, &clilen);
    if (newsockfd < 0)
        error("ERROR on accept");
    bzero(buffer,256);

    while (fin)
    {

        receiveString(newsockfd, buffer);
        printf("Here is the message: \n-\n%s\n-\n",buffer);

        sendString(newsockfd, "OK");

        printf("On compare : %d\n", strcmp(buffer, "quit\n"));

        if (strcmp(buffer, "quit\n") == 0)
        {
            sendString(newsockfd, "quit");
            fin = 0;
        }
        else if (strcmp(buffer, "nitrite\n") == 0)
        {
            receiveString(newsockfd, "fichierecu");
        }
    }

    close(newsockfd);
    close(sockfd);
    return 0;
}

void error(const char *msg)
{
    perror(msg);
    exit(1);
}

void sendString (int socket, char string[])
{
    int n;
    n = write(socket, string, strlen(string));
    if (n < 0)
    {
        error("ERROR writing to socket");
    }
}

void receiveString (int socket, char string[BUFFER_MAX])
{
    int n;
    bzero(string,256);
    n = read(socket ,string,BUFFER_MAX);
    if (n < 0)
    {
        error("ERROR reading from socket");
    }
}
void sendFile (int socket, char file[])
{
    FILE *fichier;
    char buffer[BUFFER_MAX];
    char size[10] = {0};
    int i = 0;

    if (NULL == (fichier = fopen (file, "r")))
    {
        fprintf(stderr, "Impossible d'ouvir le fichier\n");
        exit(EXIT_FAILURE);
    }

    //itoa (counterLine(fichier),size,10);
    snprintf(buffer, 10, "%d", counterLine(fichier));

    sendString(socket, "sendFile");
    receiveString(socket, buffer);
    if (strcmp(buffer, "size ?") == 0)
    {
        sendString(socket, size);
    }
    else
    {
        error("Error with sendFile");
    }

    receiveString(socket, buffer);
    if (strcmp(buffer, "OK sendFile"))
    {
        for (i = counterLine(fichier); counterLine(fichier) > 0; i--)
        {
          getLine(fichier, i, buffer);
          sendString(socket, buffer);
          receiveString(socket, buffer);
          if (strcmp(buffer, "OK") != 0)
          {
            error("Error with sendFile");
            break;
          }
        }
    }
    else
    {
        error("Error with sendFile");
    }

    fclose(fichier);
}

void receiveFile (int socket, char file[])
{
    FILE *fichier;
    char buffer[BUFFER_MAX];
    int size;
    int i = 0;

    if (NULL == (fichier = fopen (file, "a")))
    {
        fprintf(stderr, "Impossible d'ouvir le fichier\n");
        exit(EXIT_FAILURE);
    }
    size = counterLine(fichier);

    sendString(socket, "size ?");
    receiveString(socket, buffer);

    size = atoi(buffer);

    sendString(socket, "OK sendFile");

    for  ( i = 0; i < size; i++)
    {
      receiveString(socket, buffer);
      fprintf(fichier, "%s\n", buffer);
      sendString(socket, "OK");
    }

    fclose(fichier);
}