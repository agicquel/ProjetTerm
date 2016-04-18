#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "setting.h"
#include "clienttcp.h"

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

