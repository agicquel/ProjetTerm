#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QNetworkRequest>
#include <QTcpServer>
#include <QTcpSocket>

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

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
