#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication App(argc,argv);
    MainWindow Window;

    Window.show();
    return App.exec();
}
