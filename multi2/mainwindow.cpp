#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QPainter>
#include <QTimer>
#include<iostream>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    exampleObject_1.setSize(100,100);


    connect(&thread_1, &QThread::started, &exampleObject_1, &Ball::run,Qt::DirectConnection);
    connect(&exampleObject_1, SIGNAL(moveData(int,int,int,int) ), &exampleObject_2,SLOT( takeData(int,int,int,int)),Qt::DirectConnection);
    connect(&exampleObject_1, &Ball::finished, &thread_1, &QThread::quit,Qt::DirectConnection);
    connect(&exampleObject_1, &Ball::finished, &thread_2, &QThread::quit,Qt::DirectConnection);
    connect(&exampleObject_1, &Ball::finished, &thread_3, &QThread::quit,Qt::DirectConnection);
    connect(this, &MainWindow::stop, &exampleObject_1, &Ball::finish);

    connect(&exampleObject_1, &Ball::write, &connection, &DB::writeDB,Qt::DirectConnection);

    connect(&connection, SIGNAL( sdata(int,int,bool)), &exampleObject_1, SLOT(takeData(int,int,bool)),Qt::DirectConnection);

    connection.connectDB();

    exampleObject_1.moveToThread(&thread_1);
    exampleObject_2.moveToThread(&thread_2);
    connection.moveToThread(&thread_3);



}

MainWindow::~MainWindow()
{
    delete ui;
    connection.close();
}


void MainWindow :: paintEvent(QPaintEvent *event)
{
    QPainter p (this);
    p.setBrush(Qt::red);

    if(paint_on)
    {
        p.drawEllipse(exampleObject_2.getX(),exampleObject_2.getY(),exampleObject_2.getSizeX(),exampleObject_2.getSizeY());
    }

    update();
}

void MainWindow::on_pushButton_clicked()
{
    thread_1.start();
    thread_2.start();
    thread_3.start();

    paint_on = true;

}

void MainWindow::on_pushButton_2_clicked()
{


    exampleObject_1.write(exampleObject_1.getX(),exampleObject_1.getY(),exampleObject_1.getDirect());

    if(thread_1.isRunning())
    {
        emit stop();
    }
}

void MainWindow::closeEvent (QCloseEvent *event)
{


    exampleObject_1.write(exampleObject_1.getX(),exampleObject_1.getY(),exampleObject_1.getDirect());

    if(thread_1.isRunning()||thread_2.isRunning())
    {
        emit stop();
    }
}
