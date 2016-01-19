#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
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

    QVector<double> x(26), y(26);
    QVector<double> x1(26), y1(26);

    for (int i=0; i<26; ++i)
    {
      x[i] = i; // x goes from -1 to 1
      y[i] = x[i] * 0.5; // let's plot a quadratic function
      x1[i] = i; // x goes from -1 to 1
      y1[i] = x1[i] * 0.2;
    }

    ui->AnalysePlot->addGraph();
    ui->AnalysePlot->graph(0)->setPen(QPen(Qt::blue)); // line color blue for first graph
    //ui->AnalysePlot->graph(0)->setBrush(QBrush(QColor(0, 0, 255, 20))); // first graph will

    ui->AnalysePlot->addGraph();
    ui->AnalysePlot->graph(1)->setPen(QPen(Qt::red)); // line color red for second graph

    ui->AnalysePlot->graph(0)->setData(x, y);
    ui->AnalysePlot->graph(1)->setData(x1, y1);

    ui->AnalysePlot->yAxis->setLabel("Le taux");
    ui->AnalysePlot->xAxis->setLabel("Le temps en heure");
    // set axes ranges, so we see all data:
    ui->AnalysePlot->xAxis->setRange(0, 26);
    ui->AnalysePlot->yAxis->setRange(0, 15);
    ui->AnalysePlot->replot();
}
