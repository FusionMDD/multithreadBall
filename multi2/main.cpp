#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

  const  int wSizeX= 500;
   const int wSizeY= 300;

    w.setFixedSize(wSizeX,wSizeY);

    w.show();


    return a.exec();
}
