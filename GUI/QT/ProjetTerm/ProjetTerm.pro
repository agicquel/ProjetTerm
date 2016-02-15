#-------------------------------------------------
#
# Project created by QtCreator 2016-01-02T16:10:43
#
#-------------------------------------------------

QT       += core gui printsupport network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ProjetTerm
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    qcustomplot.cpp \
    setting.cpp \
    clienttcp.cpp

HEADERS  += mainwindow.h \
    qcustomplot.h \
    setting.h \
    clienttcp.h

FORMS    += mainwindow.ui \
    setting.ui
