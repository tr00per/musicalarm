# -------------------------------------------------
# Project created by QtCreator 2011-01-26T12:52:39
# -------------------------------------------------
QT += phonon
TARGET = alarm
TEMPLATE = app
QMAKE_CXXFLAGS += -std=c++0x
DESTDIR = bin
OBJECTS_DIR = build
MOC_DIR = build
UI_HEADERS_DIR = build
SOURCES += main.cpp \
    MainWindow.cpp \
    Sound.cpp
HEADERS += MainWindow.h \
    Sound.h
FORMS += MainWindow.ui
