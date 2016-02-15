#ifndef CLIENTTCP_H
#define CLIENTTCP_H

#include <QNetworkRequest>
#include <QTcpServer>
#include <QTcpSocket>

class ClientTCP : public QObject
{
Q_OBJECT
public :
    ClientTCP() {
        port=4000; // choix arbitraire (>1024)
        QObject::connect(&soc,SIGNAL(connected()),this,SLOT(connexion_OK()));
        // signal émis lors de la connexion au serveur
        QObject:: connect(&soc, SIGNAL(readyRead()), this, SLOT(lecture()));
        // signal émis lorsque des données sont prêtes à être lues
    }

public slots :
    void recoit_IP(QString IP2)  // en provenance de l'IHM et se connecte au serveur
    {
        IP=IP2;
        soc.connectToHost(IP,port); // pour se connecter au serveur
    }

    void recoit_texte(QString t) // en provenance de l'IHM et écrit sur la socket
    {
        QTextStream texte(&soc); // on associe un flux à la socket
        texte << t<<endl;        // on écrit dans le flux le texte saisi dans l'IHM
    }
private slots :
    void connexion_OK()  // en provenance de la socket et émet un signal vers l'IHM
    {
        emit vers_IHM_connexion_OK(); // on envoie un signal à l'IHM
    }
    void lecture()       // en provenance de la socket, lit la socket, émet un signal vers l'IHM
    {
        QString ligne;
        while(soc.canReadLine()) // tant qu'il y a quelque chose à lire dans la socket
        {
            ligne = soc.readLine();     // on lit une ligne
            emit vers_IHM_texte(ligne); // on envoie à l'IHM
        }
    }
signals :
    void vers_IHM_connexion_OK();
    void vers_IHM_texte(QString);
private :
    QString IP;
    int port;
    QTcpSocket soc;
};

#endif // CLIENTTCP_H
