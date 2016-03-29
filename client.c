#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

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
    int sockfd, portno, n, reply;
    struct sockaddr_in serv_addr;
    struct hostent *server;

    char buffer[BUFFER_MAX];

    if (argc < 3)
    {
        fprintf(stderr,"usage %s hostname port\n", argv[0]);
        exit(0);
    }

    portno = atoi(argv[2]);
    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd < 0)
        error("ERROR opening socket");

    server = gethostbyname(argv[1]);

    if (server == NULL)
    {
        fprintf(stderr,"ERROR, no such host\n");
        exit(0);
    }

    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;

    bcopy((char *)server->h_addr,
          (char *)&serv_addr.sin_addr.s_addr,
          server->h_length);

    serv_addr.sin_port = htons(portno);

    if (connect(sockfd,(struct sockaddr *) &serv_addr,sizeof(serv_addr)) < 0)
        error("ERROR connecting");


    printf("Send the file ez\n");
    sendString(sockfd, "nitrite\n");
    sendFile(sockfd, "onessayelereseau");
    printf("Voila ! \n");


    while (strcmp(buffer, "quit") != 0 || reply < 0)
    {
        printf("Please enter the message: ");
        bzero(buffer,BUFFER_MAX);
        fgets(buffer,BUFFER_MAX,stdin);
        n = write(sockfd,buffer,strlen(buffer));

        if (n < 0)
            error("ERROR writing to socket");
        bzero(buffer,BUFFER_MAX);
        reply = read(sockfd,buffer,BUFFER_MAX);
        if (reply < 0)
            error("ERROR reading from socket");
        printf("\n%s\n",buffer);

    }
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
