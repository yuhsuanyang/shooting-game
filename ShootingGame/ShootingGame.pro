#-------------------------------------------------
#
# Project created by QtCreator 2017-04-20T19:17:02
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = untitled
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    bullet.cpp \
    enemy.cpp \
    info.cpp \
    character.cpp \
    bulletf.cpp \
    gameover.cpp \
    bulletp.cpp

HEADERS  += mainwindow.h \
    bullet.h \
    enemy.h \
    info.h \
    character.h \
    bulletf.h \
    gameover.h \
    bulletp.h

FORMS    += mainwindow.ui \
    info.ui \
    gameover.ui

RESOURCES += \
    res.qrc \
