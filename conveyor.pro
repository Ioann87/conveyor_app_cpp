TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

LIBS += -lsfml-audio
LIBS += -lsfml-graphics
LIBS += -lsfml-network
LIBS += -lsfml-window
LIBS += -lsfml-system

SOURCES += \
        controller.cpp \
        main.cpp \
        motor.cpp \
        schalter.cpp \
        table.cpp

HEADERS += \
    controller.h \
    motor.h \
    requirements.h \
    schalter.h \
    table.h
