#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QNetworkRequest>
#include <QTcpServer>
#include <QTcpSocket>
#include <QDebug>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:

    void on_connectionButton_clicked();

    void on_settingButton_clicked();

    void on_analyseButton_clicked();

    void connectTcp();

    void readTcpData();

    void EnvoieText(QString);

    void RecoieText(QString);

private:
    Ui::MainWindow *ui;
    QTcpSocket socketclient;
    QTcpSocket * _pSocket;

    QString IP;
    QString port;

    QString buffer;

};

#endif // MAINWINDOW_H
