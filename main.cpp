#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.setWindowTitle("Площа трикутника за трьома сторонами");
    w.resize(600, 190);
    w.show();
    return a.exec();
}
