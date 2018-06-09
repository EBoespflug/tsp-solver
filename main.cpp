/**
 * main.cpp
 * Etienne Boespflug - 2018
 *
 * This software has no license, feel free to use,
 * modify and distribute.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY
 * OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT
 * LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE.
 * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY
 * CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN
 * ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR
 * THE USE OR OTHER DEALINGS IN THE SOFTWARE.
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
