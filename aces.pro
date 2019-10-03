#-------------------------------------------------
#
# Project created by QtCreator 2019-09-17T08:14:22
#
#-------------------------------------------------

QT += core gui
QT += sql
QT += serialport
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = aces
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
        mainwindow.cpp \
    lock_screen.cpp \
    user_screen.cpp \
    manage_access_item.cpp \
    access_group.cpp

HEADERS += \
        mainwindow.h \
    lock_screen.h \
    user_screen.h \
    manage_access_item.h \
    access_group.h

FORMS += \
        mainwindow.ui \
    lock_screen.ui \
    user_screen.ui \
    manage_access_item.ui \
    access_group.ui
