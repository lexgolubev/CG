#-------------------------------------------------
#
# Project created by QtCreator 2015-04-04T18:14:18
#
#-------------------------------------------------

QT -= gui
QT += opengl

TARGET = Kernel
TEMPLATE = lib

DEFINES += KERNEL_LIBRARY

SOURCES += kernel.cpp \
    point.cpp \
    rectangle.cpp \
    quadtreerangesearch.cpp \
    quadtreenode.cpp \
    quadtree.cpp \
    random.cpp \
    linearrangesearch.cpp \
    liangbarskyclipping.cpp \
    grahamhull.cpp \
    zbuffer.cpp \
    beziercurve.cpp

HEADERS += kernel.h\
        kernel_global.h \
    irangesearch.h \
    point.h \
    rectangle.h \
    quadtreerangesearch.h \
    quadtreenode.h \
    quadtree.h \
    random.h \
    linearrangesearch.h \
    iclipping.h \
    liangbarskyclipping.h \
    ihull.h \
    grahamhull.h \
    zbuffer.h \
    beziercurve.h

unix {
    target.path = /usr/lib
    INSTALLS += target
}

CONFIG += c++11
