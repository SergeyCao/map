#-------------------------------------------------
#
# Project created by QtCreator 2017-07-09T19:52:33
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = newtest
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    point.cpp \
    route.cpp

HEADERS  += mainwindow.h \
    point.h \
    route.h

FORMS    += mainwindow.ui

RESOURCES += \
    hello.qrc
