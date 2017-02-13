TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt
QMAKE_LFLAGS += -pthread

SOURCES += main.cpp \
    event.cpp \
    eventmanager.cpp

HEADERS += \
    event.h \
    eventlistener.h \
    eventmanager.h

