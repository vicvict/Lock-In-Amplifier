#include "mainwindow.h"
#include "sr844graphics.h"
#include <QApplication>


int main(int argc, char *argv[])
{

    QApplication a(argc, argv);
    MainWindow w;
    SR844Graphics q;
    q.show();

    return a.exec();
}
