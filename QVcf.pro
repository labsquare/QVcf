QT += core
QT -= gui

CONFIG += app

TARGET = QVcf
CONFIG += app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    vcfreader.cpp \
    record.cpp

HEADERS += \
    vcfreader.h \
    record.h
