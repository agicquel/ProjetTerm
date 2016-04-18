#include <QApplication>
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "setting.h"

// network
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

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // on initialise le graph
    ui->AnalysePlot->yAxis->setLabel("Le taux");
    ui->AnalysePlot->xAxis->setLabel("Le temps en heure");

    int sockfd, portno = 42; // need changes
    struct sockaddr_in serv_addr;
    struct hostent *server;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd < 0)
        error("ERROR opening socket");

                                        server = gethostbyname("localhost"); // need changes
/*
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
*/


qDebug() << "Connection !" << endl;

}

MainWindow::~MainWindow()
{
    close(sockfd);
    qDebug() << "déconnection !" << endl;

    delete ui;
}

void MainWindow::on_connectionButton_clicked()
{
    //QTcpSocket iprpi = ui->iprpiLineEdit->text();
    //qDebug() << "Connection bouton" << iprpi << endl;

    qDebug() << "Connection bouton" << endl;
    QString IP = ui->iprpiLineEdit->text();
    qDebug() << IP << endl;

    QVector<double> x(50), y(50);

    // ON RECUP LES VALEURS

    for (int i=0; i<50; ++i)
    {
      x[i] = i; // x goes from -1 to 1
      y[i] = x[i] * 0.4 + 3; // let's plot a quadratic function
    }

    ui->AnalysePlot->addGraph();
    ui->AnalysePlot->graph(0)->setPen(QPen(Qt::blue)); // line color blue for first graph
    ui->AnalysePlot->graph(0)->setBrush(QBrush(QColor(0, 0, 255, 20))); // first graph will

    ui->AnalysePlot->graph(0)->setData(x, y);

    // set axes ranges, so we see all data:
    ui->AnalysePlot->xAxis->setRange(0, 48);
    ui->AnalysePlot->yAxis->setRange(0, 15);
    ui->AnalysePlot->replot();
}

void MainWindow::on_settingButton_clicked()
{
    Setting fenetre;

    // GET CURRENT VALUES

    fenetre.setModal(true);
    fenetre.exec();

    // RETURN NEW VALUES
}

void MainWindow::on_analyseButton_clicked()
{
    // ON DIT AU RPI DE LANCER UNE ANALYSE !
}

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

