#-------------------------------------------------
#
# Project created by QtCreator 2015-04-04T18:14:18
#
#-------------------------------------------------

QT       -= gui

TARGET = Kernel
TEMPLATE = lib

DEFINES += KERNEL_LIBRARY

SOURCES += kernel.cpp

HEADERS += kernel.h\
        kernel_global.h

unix {
    target.path = /usr/lib
    INSTALLS += target
}
