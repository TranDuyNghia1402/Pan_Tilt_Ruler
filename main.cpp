#include "mainwindow.h"
#include "graphic.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    Graphic graphic;

    w.show();
    return a.exec();
}
