#include <QApplication>
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "setting.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // on initialise le graph
    ui->AnalysePlot->yAxis->setLabel("Le taux");
    ui->AnalysePlot->xAxis->setLabel("Le temps en heure");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::connectTcp()
{
    QByteArray data; // <-- fill with data

    _pSocket = new QTcpSocket( this ); // <-- needs to be a member variable: QTcpSocket * _pSocket;
    connect( _pSocket, SIGNAL(readyRead()), SLOT(readTcpData()) );

    _pSocket->connectToHost(IP, port.toInt(NULL, 10));
    if( _pSocket->waitForConnected() ) {
        _pSocket->write( data );
        qDebug() << "Connected" << endl;
    }
}


void MainWindow::readTcpData()
{
    QByteArray data = _pSocket->readAll();
}

void MainWindow::EnvoieText(QString t)
{
    QTextStream texte(_pSocket); // on associe un flux à la socket
    texte << t<<endl;        // on écrit dans le flux le texte saisi dans l'IHM

}

void MainWindow::RecoieText(QString t)
{
     t = _pSocket->readAll();
}

void MainWindow::on_connectionButton_clicked()
{
    qDebug() << "Connection bouton" << endl;
    QString buffer;
    IP = ui->iprpiLineEdit->text();
    port = ui->portEdit->text();
    qDebug() << "IP = " << IP << endl;
    qDebug() << "port = " << port << endl;

    qDebug() << "On essaye de se connecter" << endl;

    connectTcp();

    RecoieText(buffer);

    qDebug() << "On dit qu'on quitte" << endl;
    EnvoieText(buffer);

    RecoieText(buffer);


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
