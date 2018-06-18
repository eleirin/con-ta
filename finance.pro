TARGET = finance
DESTDIR = bin/
DISTFILES=facture.png
OBJECTS_DIR=obj/
MOC_DIR=obj/

CONFIG  += qt debug c++14  x11
QT += widgets core sql
INCLUDEPATH += .
DEFINES += QT_DEPRECATED_WARNINGS QT_DISABLE_DEPRECATED_BEFORE=0x060000

# Inputs
HEADERS += NewBill.h MainWindow.h
SOURCES += main.cpp NewBill.cpp MainWindow.cpp
