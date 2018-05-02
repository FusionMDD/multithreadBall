#-------------------------------------------------
#
# Project created by QtCreator 2018-04-05T14:24:20
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = multi2
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    ball.cpp \
    db.cpp

HEADERS  += mainwindow.h \
    ball.h \
    db.h

FORMS    += mainwindow.ui

QMAKE_CXXFLAGS += -std=c++11

QMAKE_CXXFLAGS += -std=gnu++11


QT +=sql testlib

