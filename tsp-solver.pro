#-------------------------------------------------
#
# Project created by QtCreator 2017-03-08T12:01:55
#
#-------------------------------------------------

QT       += core gui
CONFIG   += c++14

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = tsp-solver
TEMPLATE = app

DEFINES += QT_DEPRECATED_WARNINGS
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += main.cpp\
    UI/GUIEdge.cpp \
    UI/GraphWidget.cpp \
    UI/MainWindow.cpp \
    UI/GUINode.cpp \
    Core/Individual.cpp \
    Core/Population.cpp \
    Core/GeneticAlgorithm.cpp \
    UI/MainWindow_core.cpp

HEADERS  += UI/MainWindow.hpp \
    UI/GUIEdge.hpp \
    UI/GraphWidget.hpp \
    UI/GUINode.hpp \
    Core/Individual.hpp \
    Core/Population.hpp \
    Core/Node.hpp \
    Core/GeneticAlgorithm.hpp

RESOURCES += \
    rsc.qrc

DISTFILES += \
    UI/aboutApplication.txt
