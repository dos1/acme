#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QApplication::setApplicationName("ACME");

    MainWindow w;
    w.setFilename(argv[1]);
    w.show();

    return a.exec();
}
