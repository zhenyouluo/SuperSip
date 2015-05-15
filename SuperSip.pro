#-------------------------------------------------
#
# Project created by QtCreator 2015-05-10T12:53:23
#
#-------------------------------------------------

QT       += core concurrent network

QT       -= gui

TARGET = SuperSip
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += main.cpp \
    networkreaderthread.cpp \
    networkreader.cpp \
    sipparser.cpp \
    callinputter.cpp

HEADERS += \
    networkreaderthread.h \
    networkreader.h \
    sipparser.h \
    callinputter.h
