/**
 * main.cpp
 * Etienne Boespflug - 2017
 */

#include "UI/MainWindow.hpp"

#include <QApplication>
#include <QTime>
#include <QMainWindow>

#include <iostream>

int main(int argc, char **argv)
{
    QApplication app(argc, argv);
        app.setApplicationDisplayName("TSP Solver v1.0");
        app.setApplicationName("Traveler Salesman Problem Solver v1.0");
        app.setApplicationVersion("1.0");
        app.setWindowIcon(QIcon(":/img/ico"));

    qsrand(static_cast<unsigned>(QTime(0,0,0).secsTo(QTime::currentTime())));

    MainWindow w;

    w.show();
    return app.exec();
}
