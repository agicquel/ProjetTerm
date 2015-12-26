#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication client(argc, argv);
    MainFenetre fenetre;
    fenetre.show();

    return client.exec();
}
