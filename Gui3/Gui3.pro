#-------------------------------------------------
#
# Project created by QtCreator 2015-05-22T22:24:14
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Gui3
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp

HEADERS  += mainwindow.h

FORMS    += mainwindow.ui

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../Kernel/release/ -lKernel
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../Kernel/debug/ -lKernel
else:unix: LIBS += -L$$OUT_PWD/../Kernel/ -lKernel

INCLUDEPATH += $$PWD/../Kernel
DEPENDPATH += $$PWD/../Kernel

CONFIG += c++11
