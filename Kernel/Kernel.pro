#-------------------------------------------------
#
# Project created by QtCreator 2015-04-04T18:14:18
#
#-------------------------------------------------

QT       -= gui

TARGET = Kernel
TEMPLATE = lib

DEFINES += KERNEL_LIBRARY

SOURCES += kernel.cpp \
    point.cpp \
    rectangle.cpp \
    quadtreerangesearch.cpp \
    quadtreenode.cpp \
    quadtree.cpp

HEADERS += kernel.h\
        kernel_global.h \
    irangesearch.h \
    point.h \
    rectangle.h \
    quadtreerangesearch.h \
    quadtreenode.h \
    quadtree.h

unix {
    target.path = /usr/lib
    INSTALLS += target
}

CONFIG += c++11
