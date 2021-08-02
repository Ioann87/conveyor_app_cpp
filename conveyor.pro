TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        main.cpp \
        motor.cpp \
        schalter.cpp \
        table.cpp

HEADERS += \
    motor.h \
    requirements.h \
    schalter.h \
    table.h
