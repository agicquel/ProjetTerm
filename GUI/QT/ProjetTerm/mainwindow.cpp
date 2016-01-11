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
    QTcpSocket iprpi = ui->iprpiLineEdit->text();
    qDebug() << "Connection bouton" << iprpi << endl;
}
