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
    callinputter.cpp \
    callhandler.cpp \
    sipmessage.cpp \
    sipdefinitions.cpp \
    sipuri.cpp \
    headerlineparser.cpp \
    headerlineparser_to.cpp \
    headerlineparser_via.cpp \
    sipvia.cpp

HEADERS += \
    networkreaderthread.h \
    networkreader.h \
    sipparser.h \
    callinputter.h \
    callhandler.h \
    sipmessage.h \
    sipdefinitions.h \
    sipuri.h \
    headerlineparser.h \
    headerlineparser_to.h \
    headerlineparser_via.h \
    sipvia.h
