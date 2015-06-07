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
    sipvia.cpp \
    headerlineparser_call_id.cpp \
    headerlineparser_from.cpp \
    headerlineparser_cseq.cpp \
    headerlineparser_max_forwards.cpp \
    headerlineparser_contact.cpp \
    headerlineparser_expires.cpp \
    headerlineparser_content_length.cpp \
    appsettings.cpp \
    database.cpp \
    sipserver.cpp

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
    sipvia.h \
    headerlineparser_call_id.h \
    headerlineparser_from.h \
    headerlineparser_cseq.h \
    headerlineparser_max_forwards.h \
    headerlineparser_contact.h \
    headerlineparser_expires.h \
    headerlineparser_content_length.h \
    appsettings.h \
    database.h \
    sipserver.h

include(./QtWebApp/httpserver/httpserver.pri)
