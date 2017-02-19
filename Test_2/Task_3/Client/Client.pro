TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG += qt


QT += network core
SOURCES += main.cpp \
    client.cpp \
    packet.cpp

HEADERS += \
    client.h \
    packet.h
