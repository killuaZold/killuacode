#-------------------------------------------------
#
# Project created by QtCreator 2017-12-17T15:50:49
#
#-------------------------------------------------

QT       += core gui
QT       +=network
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = tcpSever
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    server.cpp \
    tcpclientsocket.cpp

HEADERS  += mainwindow.h \
    server.h \
    tcpclientsocket.h

FORMS    += mainwindow.ui

RESOURCES += \
    image.qrc
