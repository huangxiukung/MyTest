#-------------------------------------------------
#
# Project created by QtCreator 2016-09-08T15:08:00
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = LS_Demo
TEMPLATE = app


SOURCES += main.cpp\
        widget.cpp

HEADERS  += widget.h

FORMS    += widget.ui

TRANSLATIONS += trans/zh.ts \
                                         trans/en.ts \
                          trans/Ge.ts \

RESOURCES += \
    ls_demo.qrc
