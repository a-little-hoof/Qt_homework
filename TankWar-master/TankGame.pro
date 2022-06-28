#-------------------------------------------------
#
# Project created by QtCreator 2022-06-01T09:29:17
#
#-------------------------------------------------


QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = TankGame
TEMPLATE = app


SOURCES += main.cpp\
    mainwindow.cpp \
    dialog.cpp \
    dialog_1.cpp \
    Bullet.cpp \
    EnemyTank.cpp \
    PlayerTank.cpp \
    Tank.cpp \
    boss.cpp

HEADERS += mainwindow.h \
    dialog.h \
    dialog_1.h \
    Bullet.h \
    EnemyTank.h \
    PlayerTank.h \
    Tank.h \
    boss.h

FORMS += mainwindow.ui \
    dialog.ui \
    dialog_1.ui

RESOURCES += \
    test.qrc
RC_FILE = myapp.rc
