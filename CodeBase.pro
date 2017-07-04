#-------------------------------------------------
#
# Project created by QtCreator 2017-04-11T23:06:37
#
#-------------------------------------------------

QT       += core gui opengl

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = CodeBase
TEMPLATE = app

SOURCES += main.cpp\
        mainwindow.cpp \
    src/openglwidget.cpp

HEADERS  += mainwindow.h \
    include/openglwidget.h

LIBS += -lopengl32
