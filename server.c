

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

void getString(FILE* file, int numero, char buffer[])
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
    bzero(buffer,BUFFER_MAX);

    while (fin)
    {
        receiveString(newsockfd, buffer);
        //printf("Here is the message: \n-\n%s\n-\n",buffer);

        sendString(newsockfd, "OK");

        if (strcmp(buffer, "quit\n") == 0)
        {
            sendString(newsockfd, "quit");
            fin = 0;
        }
        else if (strcmp(buffer, "nitrite\n") == 0)
        {
            receiveFile(newsockfd, "./fichierecu");
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
          getString(fichier, i, buffer);

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
