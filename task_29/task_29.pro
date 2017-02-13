TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    event.cpp \
    eventmanager.cpp

HEADERS += \
    event.h \
    eventlistener.h \
    eventmanager.h

