#-------------------------------------------------
#
# Project created by QtCreator 2017-04-11T23:06:37
#
#-------------------------------------------------

QT       += core gui opengl

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = UrbanPilot
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    shape/dbfopen.c \
    shape/safileio.c \
    shape/shpopen.c \
    src/mapglwidget.cpp \

HEADERS  += mainwindow.h \
    include/shapefil.h \
    include/mapglwidget.h \

LIBS += -lopengl32
