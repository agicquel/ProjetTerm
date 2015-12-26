#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QApplication>
#include <QWidget>
#include <QPushButton>
#include <QMessageBox>

class MainFenetre : public QWidget
{
    Q_OBJECT

    public:
    MainFenetre();

    public slots:
//    void ouvrirDialogue();

    private:
    QPushButton *m_boutonDialogue;
};

#endif // MAINWINDOW_H
