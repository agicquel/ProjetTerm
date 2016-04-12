#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <strings.h>
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

    while (fgets(line, BUFFER_MAX, file) != NULL)
    {
        if (count == numero)
        {
            // remove the \n at the end of the line
            strtok(line, "\n");
            // copy the good line into the buffer
            strncpy(buffer, line, BUFFER_MAX);
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
    int sockfd, portno; //, n, reply;
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
    receiveString(sockfd, buffer);
    if (strcmp(buffer, "OK") == 0)
    {
      printf("On essaye d'envoyer le fichier\n");
      sendFile(sockfd, "./onessayelereseau");
      printf("Voila ! \n");
    }
    sendString(sockfd, "quit\n");

    /*while (strcmp(buffer, "quit") != 0 || reply < 0)
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

    }*/
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
    int lim_i = 0;
    int i = 0;

    if ((fichier = fopen (file, "r")) == NULL)
    {
        fprintf(stderr, "Impossible d'ouvir le fichier\n");
        exit(EXIT_FAILURE);
    }
    printf("On a ouvert le fichier\n");

    //itoa (counterLine(fichier),size,10);
    snprintf(size, 10, "%d", counterLine(fichier));
    printf("La taille : %s\n", buffer);

    lim_i = atoi(size);
    printf("Taille lim_i : %d\n", lim_i);

    printf("On envoie sendFile\n");
    sendString(socket, "sendFile");
    printf("On reçoit size ?\n");
    receiveString(socket, buffer);
    if (strcmp(buffer, "size ?") == 0)
    {
        sendString(socket, size);
    }
    else
    {
        printf("Merde pas reçu !\n");
        error("Error with sendFile : size ?");
    }

    receiveString(socket, buffer);
    printf("Ce qu'on a reçu : %s\n", buffer);
    if (strcmp(buffer, "OK sendFile") == 0)
    {
        for (i = 0; i < lim_i; i++)
        {
          bzero(buffer,BUFFER_MAX);
          printf("On lit ligne no %d\n", i);
          getLine(fichier, i, buffer);

          printf("ce qu'on a lu : %s\n", buffer);
          printf("On envoie\n");
          sendString(socket, buffer);
          printf("On attend le OK\n");
          bzero(buffer,BUFFER_MAX);
          receiveString(socket, buffer);
          if (strcmp(buffer, "OK") != 0)
          {
            error("Error with sendFile : not OK");
            break;
          }
        }
    }
    else
    {
        error("Error with sendFile : not OK sendFile");
    }

    fclose(fichier);
}

void receiveFile (int socket, char file[])
{
    printf("La fonction demare ?\n");
    FILE *fichier;
    char buffer[BUFFER_MAX];
    int size = 0;
    int i = 0;

    printf("On essaye d'ouvrir le fichier\n");

    if ((fichier = fopen (file, "w+")) == NULL)
    {
        fprintf(stderr, "Impossible d'ouvir le fichier\n");
        exit(EXIT_FAILURE);
    }
    printf("On a ouvert le fichier\n");
    //size = counterLine(fichier);

    receiveString(socket, buffer);
    if (strcmp(buffer, "sendFile") == 0)
    {
        printf("On envoie size ?\n");
        sendString(socket, "size ?");
    }
    else
    {
        error("Don't receive the signal for sendFile");
    }

    receiveString(socket, buffer);
    printf("Le buffer %s\n", buffer);
    size = atoi(buffer);
    printf("Size = %d\n", size);

    sendString(socket, "OK sendFile");

    for  ( i = 0; i < size; i++)
    {
      bzero(buffer,BUFFER_MAX);
      printf("On reçoit no : %d\n", i);
      receiveString(socket, buffer);
      printf("On a reçu : %s\n", buffer);
      printf("On écrit dans le fichier\n");
      fprintf(fichier, "%s\n", buffer);
      printf("On envoie OK\n");
      sendString(socket, "OK");
    }

    fclose(fichier);
    printf("On a recu le fichier\n");
}
