TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG += qt

QT += network core

SOURCES += main.cpp \
    server.cpp \
    writer.cpp \
    reader.cpp

HEADERS += \
    server.h \
    writer.h \
    reader.h
