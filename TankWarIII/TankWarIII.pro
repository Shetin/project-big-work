#-------------------------------------------------
#
# Project created by QtCreator 2018-06-04T20:07:19
#
#-------------------------------------------------

QT       += core gui
QT += multimedia multimediawidgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = TankWarII
TEMPLATE = app


SOURCES += main.cpp\
        widget.cpp \
    one.cpp \
    two.cpp \
    three.cpp \
    world.cpp \
    icon.cpp \
    rpgobj.cpp \
    tank.cpp \
    start.cpp \
    dialogone.cpp \
    dialogtwo.cpp \
    dialogthree.cpp \
    player_bullet.cpp \
    enemy.cpp \
    enemy_bullet.cpp \
    helper.cpp \
    dlglose1.cpp \
    dlglose2.cpp \
    dlglose3.cpp \
    level.cpp

HEADERS  += widget.h \
    one.h \
    two.h \
    three.h \
    world.h \
    icon.h \
    rpgobj.h \
    tank.h \
    start.h \
    dialogone.h \
    dialogtwo.h \
    dialogthree.h \
    player_bullet.h \
    enemy.h \
    enemy_bullet.h \
    helper.h \
    dlglose1.h \
    dlglose2.h \
    dlglose3.h \
    level.h

FORMS    += widget.ui \
    one.ui \
    two.ui \
    three.ui \
    world.ui \
    start.ui \
    dialogone.ui \
    dialogtwo.ui \
    dialogthree.ui \
    dlglose1.ui \
    dlglose2.ui \
    dlglose3.ui \
    level.ui

RESOURCES += \
    res.qrc
