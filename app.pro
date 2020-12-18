TEMPLATE = lib
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt
LIBS += -pthread -Wall -pedantic



SOURCES += \
    main.cpp \
    particledatacontainer.cpp \
    particleemitter.cpp \
    particlegenerator.cpp \
    multithreadoverseer.cpp

HEADERS += \
    particledatacontainer.h \
    particleemitter.h \
    particlegenerator.h \
    multithreadoverseer.h
