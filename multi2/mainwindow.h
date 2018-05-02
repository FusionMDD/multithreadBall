#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QThread>
#include"ball.h"
#include<QtSql>
#include<QtDebug>
#include<QFileInfo>
#include<QSqlDatabase>
#include<QSqlQuery>
#include<QTest>
#include<QSignalSpy>
#include <QCloseEvent>
#include<db.h>


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void paintEvent(QPaintEvent *event);
    void closeEvent (QCloseEvent *event);

signals:
    void stop();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();


private:
    Ui::MainWindow *ui;

    QThread thread_1;
    QThread thread_2;
    QThread thread_3;

    Ball exampleObject_1;
    Ball exampleObject_2;

   DB connection;

    bool paint_on;

};


#endif // MAINWINDOW_H
