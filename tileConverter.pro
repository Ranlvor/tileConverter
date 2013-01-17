#-------------------------------------------------
#
# Project created by QtCreator 2013-01-17T14:13:38
#
#-------------------------------------------------

QT       += core

#QT       -= gui

TARGET = tileConverter
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += main.cpp \
    TileIOInterfaces/FolderInterface.cpp \
    TileIOInterfaces/PictureInterface.cpp

HEADERS += \
    TileIOInterface.h \
    TileIOInterfaces/FolderInterface.h \
    TileIOInterfaces/PictureInterface.h
